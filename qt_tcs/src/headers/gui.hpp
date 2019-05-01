#ifndef GUI_HPP
#define GUI_HPP

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QHostAddress>
#include <QObject>
#include <QString>
#include <QVariant>

#include "./globals.hpp"
#include "./events.hpp"
#include "./funcs.hpp"

#include "../classes/testlistrow.hpp"

namespace GUI {
    namespace TestList {
        DataBase::DBTable ReadTable();
        QList<QObject*> CreateRows(const DataBase::DBTable &table);
        void Fill(QObject* root);
    }
}
/* ************************************************************************************************************************ */
/* ******************************************************** TestList ****************************************************** */
/* ************************************************************************************************************************ */
DataBase::DBTable GUI::TestList::ReadTable() {
    std::string columns = Funcs::Tools::Combine(Globals::Consts::TESTLIST_COLUMNS, ", ");
    std::string select_value = "Select " + columns + " from Tests;";
    DataBase db(Globals::Vars::path_to_db);
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
/* ************************************************************************************************************************ */
/* ************************************************************************************************************************ */
/* ************************************************************************************************************************ */

#endif // GUI_HPP
