#include "record.hpp"
/* ************************************************************************************************************************ */
Record::Record(const QString path_to_db, const QString &table, const QStringList &columns) :
    _PATH_TO_DB(path_to_db), _TABLE(table) {
    for(auto column : columns)
        _pairs.append({column, "" });
    _command = _buildSelectCommand(columns);
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName(_PATH_TO_DB);
}

bool Record::read(const int &id) {
    bool result = false;
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName(_PATH_TO_DB);
    if (_db.open()){
        result = _readPairs(id);
        if (!result)
            qDebug("Record::Read::Error::Failed to read pairs.");
        _db.close();
    } else {
        qDebug("Record::Read::Error::Cant open database.");
    }
    _is_new = !result;

    return result;
}
bool Record::save(const int &id) {
    try {
        QString rec_id = (id != 0) ? QString::number(id) : getValue("ID");
        QString command;
        if (rec_id == "") {
            command = _buildInsertCommand(_pairs);
            int result = _executeInsert(command);
            setValue("ID", QString::number(result));
        } else {
            command = _buildUpdateCommand(_pairs);
            command.append(rec_id + ";");
            _executeInsert(command);
        }
    } catch (int ex) {
        qDebug() << "Record::Save::Error::Exception " << ex;
        return false;
    }

    return true;
}

QString Record::getValue(const QString &name) const {
    for(auto item : _pairs)
        if (item.Name == name)
            return item.Value;

    return "Not found";
}
bool Record::setValue(const QString &name, const QString value) {
    int count = _pairs.count();
    for(int i = 0; i < count; ++i)
        if (_pairs[i].Name == name) {
            _pairs[i].Value = value;
            return true;
        }

    return false;
}

QString Record::_buildSelectCommand(const QStringList &columns) {
    QString result = "Select ";
    for (auto pair : _pairs)
        result.append(pair.Name + ',');
    result.chop(1);
    result.append(" From " + _TABLE + " Where ID=");

    return result;
}
QString Record::_buildInsertCommand(const QList<Pair> &pairs) {
    QString result = "Insert Into " + _TABLE + " (";
    for (auto pair : pairs)
        result.append(pair.Name + ',');
    result.chop(1);
    result.append(") Output Inserted.ID Values (");
    for (auto pair : pairs)
        result.append("'" + pair.Value + "',");
    result.chop(1);
    result.append(");");

    return result;
}
QString Record::_buildUpdateCommand(const QList<Pair> &pairs) {
    QString result = "Update " + _TABLE + " Set ";
    for (auto pair : pairs)
        result.append(pair.Name + "='" + pair.Value + "',");
    result.chop(1);
    result.append(" Where ID=" );

    return result;
}

int Record::_executeInsert(const QString &command) {
    int result = -1;
    if (_db.open()) {
        QSqlQuery query;
        if (!query.exec(command)) {
            if(query.next())
                result = query.value(0).toInt();
        } else {
            qDebug("Record::Create::Error::Failed to create record.");
        }
        _db.close();
    } else {
        qDebug("Record::Create::Error::Cant open database.");
    }

    return result;
}
bool Record::_readPairs(const int &id) {
    QSqlQuery query;
    QString command = _command + QString::number(id) + ";";
    if (query.exec(command)) {
        if (query.next()){
            QSqlRecord rec = query.record();
            int count = rec.count();
            for (int i = 0; i < count; ++i)
                setValue(rec.fieldName(i), query.value(i).toString());
        }
        return true;
    } else {
        qDebug() << query.lastError();
        return false;
    }
}
/* ************************************************************************************************************************ */
