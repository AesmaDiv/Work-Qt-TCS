#ifndef GUI_HPP
#define GUI_HPP

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QHostAddress>
#include <QObject>
#include <QString>
#include <QVariant>
#include <QStringListModel>

#include <QSqlRecord>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "../classes/globals.hpp"
#include "funcs.hpp"


namespace GUI {
    extern Globals* gui_globals;
    namespace TestList {
        DataBase::DBTable ReadTable();
        QList<QObject*> CreateRows(const DataBase::DBTable &table);
        void Fill();
        void ProcessItemSelect(const QString &id);
        void ProcessNewTest();

        void SwitchToTestInfo();
    };
    namespace TcsInfo {
        void Prepare();
        void PrepareCombobox(const QString &name, const QVariantList &values);

        void ProcessNewTest();
        void ProcessSelectedTest(const int &id);
        void ProcessItemSelect(const QVariantList &args);

        void ProcessProducerSelect(const int &rec_id);
        void ProcessStationTypeSelect(const int &rec_id);

        void ClearInfo(const QStringList &columns, const QStringList &combos = {});
        void FillInfo(const Record* record, const QStringList &columns, const QStringList &skip = {});
        void FillFields(const QStringList &columns, const Record* record = nullptr, const QStringList &skip = {});

        void SetComboBoxValue(const QString &combo_name, const QVariant &value, const bool &raise_event = true);
    };
};
#endif // GUI_HPP
