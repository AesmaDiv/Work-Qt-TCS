#include "funcs.hpp"
/* ************************************************************************************************************************ */
std::string Funcs::Tools::Combine(const std::vector<std::string> &input, const std::string delimiter) {
    std::string result = "";
    size_t s = input.size();
    if (s > 0) {
        result.append(input[0]);
        for(size_t i = 1; i < s; ++i){
            result.append(delimiter);
            result.append(input[i]);
        }
    }

    return result;
}
QString Funcs::Tools::GetCurrentDateTime() {
    QDateTime now = QDateTime::currentDateTime();
    QString format = "yyyy-MM-dd hh:mm";
    QString result = now.toString(format);
    return result;
}
/* ************************************************************************************************************************ */
QVariantList Funcs::SQLite::GetNames(const QString &path_to_db, const QString &names){
    QVariantList result;
    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path_to_db);
    if (db.open()) {
        QSqlQuery query;
        if (query.exec("Select Name From " + names + ";")) {
            while (query.next()) {
                result.append(query.value(0));
            }
        } else {
            qDebug() << "Funcs::SQLite::Query Error:: " << query.lastError().text();
        }
        db.close();
    } else {
        qDebug() << "Funcs::SQLite::Error::Can`t open database " << path_to_db;
    }
    return result;
}
QVariantList Funcs::SQLite::GetPairs(const QString &path_to_db, const QString &command) {
    QVariantList result;
    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path_to_db);
    if (db.open()) {
        QSqlQuery query;
        if (query.exec(command)) {
            QVariantList pair;
            while (query.next()) {
                pair = QVariantList{query.value(0).toInt(), query.value(1).toString()};
                result.append(QVariant::fromValue(pair));
            }
        } else {
            qDebug() << "Funcs::SQLite::Query Error:: " << query.lastError().text();
        }
        db.close();
    } else {
        qDebug() << "Funcs::SQLite::Error::Can`t open database " << path_to_db;
    }
    return result;
}
bool Funcs::SQLite::Read(Record* &record,  const int &id) {
    bool result = false;
    //record = new Record(Globals::Vars::path_to_db, "Tests", Globals::Consts::TEST_RECORD_COLUMNS);
    result = record->read(id);
    if (!result)
        qDebug("Funcs::SQLite::ReadRecord::Can`t read record.");
    return result;
}
/* ************************************************************************************************************************ */
