#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <QQmlEngine>
#include <QQmlComponent>
#include <QStandardItemModel>
#include <QObject>
#include <QQmlContext>
#include <QDebug>

#include <QSqlError>

#include <vector>
#include <string>

#include "./globals.hpp"
#include "../classes/database.hpp"

namespace Funcs {
    namespace Tools {
        std::string Combine(const std::vector<std::string> &input, const std::string delimiter);
        void FillCombobox(QString name, QStringList values);
    }
    namespace SQLite {
        QVariantList GetNames(QString query);
        bool ReadRecord(const int &id);
        bool ReadStationType(const int &id);
    }
}
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
/* ************************************************************************************************************************ */
/* ************************************************************************************************************************ */
QVariantList Funcs::SQLite::GetNames(QString names){
    QVariantList result;
    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(Globals::Vars::path_to_db);
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
        qDebug() << "Funcs::SQLite::Error::Can`t open database " << Globals::Vars::path_to_db;
    }
    return result;
}
bool Funcs::SQLite::ReadRecord(const int &id) {
    bool result = false;
    using namespace Globals::Vars;
    record = new Record(path_to_db, "Tests");
    result = record->read(id);
    if (!result)
        qDebug("Funcs::SQLite::ReadRecord::Can`t read record.");
    return result;
}
bool Funcs::SQLite::ReadStationType(const int &id) {
    bool result = false;
    using namespace Globals::Vars;
    stationType = new Record(path_to_db, "StationTypes");
    result = stationType->read(id);
    if (!result)
        qDebug("Funcs::SQLite::ReadStationType::Can`t read station type.");
    return result;
}
/* ************************************************************************************************************************ */
#endif // FUNCS_HPP
