#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <QQmlEngine>
#include <QQmlComponent>
#include <QStandardItemModel>
#include <QObject>
#include <QQmlContext>
#include <QDebug>
#include <QDateTime>

#include <QSqlError>

#include <vector>
#include <string>

#include "../classes/record.hpp"

namespace Funcs {
    namespace Tools {
        std::string Combine(const std::vector<std::string> &input, const std::string delimiter);
        void FillCombobox(QString name, QStringList values);
        QString GetCurrentDateTime();
    };
    namespace SQLite {
        QVariantList GetNames(const QString &path_to_db, const QString &query);
        QVariantList GetPairs(const QString &path_to_db, const QString &command);
        bool Read(Record* &rec,  const int &id);
        bool ReadRecord(const int &id);
        bool ReadStationType(const int &id);
    };
};
#endif // FUNCS_HPP
