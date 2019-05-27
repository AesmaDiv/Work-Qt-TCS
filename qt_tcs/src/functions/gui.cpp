#include "gui.hpp"

Globals* GUI::gui_globals = nullptr;
/* ************************************************************************************************************************ */
DataBase::DBTable GUI::TestList::ReadTable() {
    std::string columns = Funcs::Tools::Combine(gui_globals->consts.TESTLIST_COLUMNS, ", ");
    std::string select_value = "Select " + columns + " from Tests;";
    DataBase db(gui_globals->vars.path_to_db.toStdString());
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
void GUI::TestList::Fill() {
    DataBase::DBTable table = ReadTable();
    if (table.size() > 0) {
        QList<QObject*> rows = CreateRows(table);
        if (rows.size() > 0) {
            QObject* testList = gui_globals->vars.root_wnd->findChild<QObject*>("testList");
            if (testList) {
                QQmlEngine *engine = QtQml::qmlEngine(testList);
                if (engine)
                    engine->rootContext()->setContextProperty("testListModel", QVariant::fromValue(rows));
            }
        }
    }
}
void GUI::TestList::ProcessItemSelect(const QString &rec_id) {
    try {
        // переключаемся на закладку информации по тесту
        SwitchToTestInfo();
        // читаем и заполняем запись по тесту
        int id = rec_id.toInt();
        GUI::TcsInfo::ProcessSelectedTest(id);
    } catch (...) {
        qDebug() << "GUI::TestList::ProcessItemSelect:Error reading record\n";
    }
}
void GUI::TestList::ProcessNewTest() {
    SwitchToTestInfo();
    GUI::TcsInfo::ProcessNewTest();
}
/// Переключение на информацию о испытании
void GUI::TestList::SwitchToTestInfo() {
    gui_globals->vars.dispatcher->setProperty("switchTestList", "checked", true);
}
/* ************************************************************************************************************************ */
/* ************************************************************************************************************************ */
void GUI::TcsInfo::Prepare() {
    QVariantList customers = Funcs::SQLite::GetPairs(gui_globals->vars.path_to_db, "Select ID, Customer From Customers;");
    QVariantList producers = Funcs::SQLite::GetPairs(gui_globals->vars.path_to_db, "Select ID, Producer From Producers;");
    QVariantList station_types = Funcs::SQLite::GetPairs(gui_globals->vars.path_to_db, "Select ID, StationType From StationTypes;");

    customers.push_front(QVariant::fromValue(QVariantList{0, " < добавить нового > "}));
    producers.push_front(QVariant::fromValue(QVariantList{0, " < все > "}));
    station_types.push_front(QVariant::fromValue(QVariantList{0, " < добавить новый тип > "}));

    PrepareCombobox("dfCustomer", customers);
    PrepareCombobox("dfProducer", producers);
    PrepareCombobox("dfStationType", station_types);
}
void GUI::TcsInfo::PrepareCombobox(const QString &name, const QVariantList &values) {
    QObject* obj = gui_globals->vars.root_wnd->findChild<QObject*>(name);
    if(obj) {
        obj->setProperty("values", values);
        obj->setProperty("currentIndex", -1);
    } else {
        qDebug() << "Funcs::Tools::FillCombobox::Error: Can`t find object";
    }
}
void GUI::TcsInfo::ProcessItemSelect(const QVariantList &args) {
    // Проверяем кол-во аргументов события
    if (args.size() == 4) {
        QString source = args[1].toString();                // источник (имя комбобокса)
        int rec_id = args[2].toInt();                       // индекс элемента
        QString name = args[3].toString();                  // текст элемента
        // обработка в зависимости от источника
        if (QString::compare(source, "Producer") == 0) {    // если Производитель
            ProcessProducerSelect(rec_id);
            return;
        }
        if (QString::compare(source, "StationType") == 0) { // если Тип станции
            ProcessStationTypeSelect(rec_id);
            return;
        }
    }
}

void GUI::TcsInfo::ProcessProducerSelect(const int &rec_id) {
    QString command = "Select ID, StationType From StationTypes";
    command.append(rec_id > 0 ? " Where Producer=" + QString::number(rec_id) + ";" : ";");
    QVariantList station_types = Funcs::SQLite::GetPairs(gui_globals->vars.path_to_db, command);
    if (station_types.size() > 0) {
        PrepareCombobox("dfStationType", station_types);
        ClearInfo(gui_globals->consts.STATION_INFO_COLUMNS, {"StationType"});
    }
}
void GUI::TcsInfo::ProcessStationTypeSelect(const int &rec_id) {
    if (Funcs::SQLite::Read(gui_globals->vars.stationType, rec_id))
        FillInfo(gui_globals->vars.stationType, {"Inom","Imax","Pnom","Usec","MaxRPM","MinRPM"});
}

void GUI::TcsInfo::ProcessNewTest() {
    ClearInfo(gui_globals->consts.TEST_INFO_COLUMNS, {"Customer"});
    ClearInfo(gui_globals->consts.STATION_INFO_COLUMNS, {"Producer", "StationType"});
    gui_globals->vars.newTest = gui_globals->vars.currentTest;
    gui_globals->vars.isCreatingNewRecord = true;
}
void GUI::TcsInfo::ProcessSelectedTest(const int &id) {
    if (Funcs::SQLite::Read(gui_globals->vars.currentTest, id)){
        FillFields(gui_globals->consts.TEST_INFO_COLUMNS, gui_globals->vars.currentTest, {"Customer"});
        int customer_id = gui_globals->vars.currentTest->getValue("Customer").toInt();
        SetComboBoxValue("Customer", customer_id);
        // читаем и заполняем данные по типу станции
        int station_id = gui_globals->vars.currentTest->getValue("StationType").toInt();
        if (Funcs::SQLite::Read(gui_globals->vars.stationType, station_id)) {
            SetComboBoxValue("StationType", station_id);
            int producer_id = gui_globals->vars.stationType->getValue("Producer").toInt();
            SetComboBoxValue("Producer", producer_id, false);
        }
    }
}

void GUI::TcsInfo::ClearInfo(const QStringList &columns, const QStringList &skip) {
    FillFields(columns, nullptr, skip);
    for(int i=0; i < skip.count(); ++i)
        SetComboBoxValue(skip[i], "", false);
}
void GUI::TcsInfo::FillInfo(const Record* record, const QStringList &columns, const QStringList &skip) {
    FillFields(columns, record, skip);
}
void GUI::TcsInfo::FillFields(const QStringList &columns, const Record* record, const QStringList &skip) {
    QObject* stationInfo = gui_globals->vars.root_wnd->findChild<QObject*>("tcsInfo");
    if (stationInfo) {
        Dispatcher* disp = new Dispatcher(stationInfo);
        QString object_name = "";
        QString property = "value";
        QVariant value;
        for(auto field : columns){
            if (skip.contains(field))
                continue;

            object_name = "df";
            object_name.append(field);

            value = (record == nullptr) ? "" : record->getValue(field);
            disp->setProperty(object_name, "value", value);
        }
    }
}
/// Изменение значения комбо-бокса
void GUI::TcsInfo::SetComboBoxValue(const QString &name, const QVariant &value, const bool &raise_event) {
    // читаем значение свойство включены ли события
    bool is_event_enabled = gui_globals->vars.dispatcher->getProperty("tcsInfo", "is_event_enabled").toBool();
    // если отличается от устанавливаемого - устанавливаем новое
    if (raise_event != is_event_enabled)
        gui_globals->vars.dispatcher->setProperty("tcsInfo", "is_event_enabled", raise_event);
    // задаем свойства в зависимости от типа передаваемого значения:  число - текущий индекс, строка - текущий текст
    QString property = value.userType() == QMetaType::Int ? "currentIndex" : "currentText";
    gui_globals->vars.dispatcher->setProperty("df" + name, property, value);
    // если свойства событий отличались, возвращаем то что было
    if (raise_event != is_event_enabled)
        gui_globals->vars.dispatcher->setProperty("tcsInfo", "is_event_enabled", is_event_enabled);
}
/* ************************************************************************************************************************ */

