#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QHostAddress>

#include "./functions/events.hpp"
//#include "./functions/gui.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    Globals* globals = new Globals;
    globals->vars.root_wnd = engine.rootObjects()[0];
    globals->vars.dispatcher = new Dispatcher(globals->vars.root_wnd);
    globals->vars.currentTest = new Record(globals->vars.path_to_db, "Tests", globals->consts.TEST_RECORD_COLUMNS);
    globals->vars.stationType = new Record(globals->vars.path_to_db, "StationTypes", globals->consts.STATION_RECORD_COLUMNS);

    GUI::gui_globals = globals;


    QObject* testList = globals->vars.root_wnd->findChild<QObject*>("testList");
    QObject* tcsInfo = globals->vars.root_wnd->findChild<QObject*>("tcsInfo");

    QObject::connect(testList, SIGNAL(onEvent(QString)), globals->vars.dispatcher, SLOT(eventSlot_String(QString)));
    QObject::connect(tcsInfo, SIGNAL(onEvent(QString)), globals->vars.dispatcher, SLOT(eventSlot_String(QString)));
    QObject::connect(tcsInfo, SIGNAL(onComboItemSelected(QVariant)), globals->vars.dispatcher, SLOT(eventSlot_Variant(QVariant)));


    QObject::connect(globals->vars.dispatcher, &Dispatcher::eventSignal_String, Events::EventString);
    QObject::connect(globals->vars.dispatcher, &Dispatcher::eventSignal_Variant, Events::EventVariant);

    GUI::TcsInfo::Prepare();
    GUI::TestList::Fill();

    return app.exec();
}





