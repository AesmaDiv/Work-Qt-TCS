#ifndef RECORD_HPP
#define RECORD_HPP

#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>


class Record
{
public:
    struct Pair {
        QString Name;
        QString Value;
    };

    Record(const QString path_to_db, const QString table) : _path_to_db(path_to_db), _table(table) {}
    ~Record() = default;

    bool read(const int &id);
    QString getValue(const QString &name);
    bool setValue(const QString &name, const QString value);

    QList<Pair> pairs() const { return _pairs; }
private:
    QList<Pair> _pairs;
    QString _path_to_db;
    QString _table;
    bool _fillPairs(const int &id);
};

inline bool Record::read(const int &id) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(_path_to_db);
    if (db.open()) {
        if (!_fillPairs(id)) {
            qDebug("StationType::Read::Error::Failed to read pairs.");
            db.close();
            return false;
        }
        db.close();        
    } else {
        qDebug("StationType::Read::Error::Cant open database.");
        return false;
    }
    return true;
}
inline QString Record::getValue(const QString &name) {
    QString result = "Not found";
    for(auto item : _pairs)
        if (item.Name == name) {
            result = item.Value;
            break;
        }
    return result;
}
inline bool Record::setValue(const QString &name, const QString value) {
    bool result = false;
    for(auto item : _pairs)
        if (item.Name != name){
            item.Value = value;
            result = true;
            break;
        }
    return result;
}

inline bool Record::_fillPairs(const int &id) {
    QSqlQuery query;
    QString command = "Select * From " + _table + " Where ID=" + QString::number(id) + ";";
    if (query.exec(command)) {
        if (query.next()){
            QSqlRecord rec = query.record();
            int count = rec.count();
            int index = 0;
            while (index < count) {
                _pairs.append({
                                  rec.fieldName(index),         // Name
                                  query.value(index).toString() // Value
                              });
                ++index;
            }

        }
        return true;
    } else {
        qDebug() << query.lastError();
        return false;
    }
}


#endif // RECORD_HPP

