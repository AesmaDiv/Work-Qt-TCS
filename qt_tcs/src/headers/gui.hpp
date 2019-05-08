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

#include "./globals.hpp"
#include "./funcs.hpp"

#include "../classes/testlistrow.hpp"

namespace GUI {
    namespace TestList {
        DataBase::DBTable ReadTable();
        QList<QObject*> CreateRows(const DataBase::DBTable &table);
        void Fill(QObject* root);
        void ProcessItemSelect(const QString &id);
    }
    namespace TcsInfo {
        void Prepare();
        void Process(const QString &recId);

        void FillInfo();
        void FillCombobox(const QString &name, const QVariantList &values);
    }
}
/* ************************************************************************************************************************ */
/* ******************************************************** TestList ****************************************************** */
/* ************************************************************************************************************************ */
DataBase::DBTable GUI::TestList::ReadTable() {
    std::string columns = Funcs::Tools::Combine(Globals::Consts::TESTLIST_COLUMNS, ", ");
    std::string select_value = "Select " + columns + " from Tests;";
    DataBase db(Globals::Vars::path_to_db.toStdString());
    DataBase::DBTable result;
    db.ExecuteSqlQuery(select_value, result);

    return result;
}
QList<QObject*> GUI::TestList::CreateRows(const DataBase::DBTable &table) {
    QList<QObject*> result;
    for(auto rec : table) {
        TestListRow* row = new TestListRow();
        row->setRecord(QString::fromStdString(rec[0]));
        row->setDateTime(QString::fromStdString(rec[1]));
        row->setOrder(QString::fromStdString(rec[2]));
        row->setSerial(QString::fromStdString(rec[3]));
        result.append(row);
    }

    return result;
}
void GUI::TestList::Fill(QObject* root) {
    DataBase::DBTable table = ReadTable();
    if (table.size() > 0) {
        QList<QObject*> rows = CreateRows(table);
        if (rows.size() > 0) {
            QObject* testList = root->findChild<QObject*>("testList");
            if (testList) {
                QQmlEngine *engine = QtQml::qmlEngine(testList);
                if (engine)
                    engine->rootContext()->setContextProperty("testListModel", QVariant::fromValue(rows));
            }
        }
    }
}
void GUI::TestList::ProcessItemSelect(const QString &id) {
    try {
        int rec_id = id.toInt();
        if (Funcs::SQLite::ReadRecord(rec_id)){
            int station_id = Globals::Vars::record->getValue("StationType").toInt();
            if (Funcs::SQLite::ReadStationType(station_id))
                GUI::TcsInfo::FillInfo();
        }
    } catch (...) {
        qDebug() << "GUI::TestList::ProcessItemSelect:Error reading record\n";
    }
}
/* ************************************************************************************************************************ */
void GUI::TcsInfo::Prepare() {
    QVariantList producers = Funcs::SQLite::GetNames("Producers");
    QVariantList customers = Funcs::SQLite::GetNames("Customers");
    QVariantList station_types = Funcs::SQLite::GetNames("StationTypes");

    FillCombobox("dfProducer", producers);
    FillCombobox("dfCustomer", customers);
    FillCombobox("dfStationType", station_types);
}
void GUI::TcsInfo::FillCombobox(const QString &name, const QVariantList &values) {
    QObject* obj = Globals::Vars::root_wnd->findChild<QObject*>(name);
    if(obj) {
        obj->setProperty("values", values);
    } else {
        qDebug() << "Funcs::Tools::FillCombobox::Error: Can`t find object";
    }
}

void GUI::TcsInfo::Process(const QString &recId) {

}

void GUI::TcsInfo::FillInfo() {
    using namespace Globals;

    QObject* stationInfo = Vars::root_wnd->findChild<QObject*>("tcsInfo");
    if (stationInfo) {
        Dispatcher* disp = new Dispatcher(stationInfo);
        QString object_name = "";
        QString property = "value";
        QVariant value;
        for(auto field : Consts::STATION_INFO_COLUMNS){
            using namespace Vars;

            object_name = "df";
            object_name.append(field);


            if ((field != "StationType") && (field != "Producer")) {
                property = "value";
                value = stationType->getValue(field);
            } else {
                value = record->getValue(field);
                value = value.toInt() - 1;
                }
            } else {
                property = "current_index";
                value = record->getValue(field);
                value = value.toInt() - 1;
            }
            disp->setProperty(object_name, property, value);
        }
    }
}
/* ************************************************************************************************************************ */
/* ************************************************************************************************************************ */

#endif // GUI_HPP
