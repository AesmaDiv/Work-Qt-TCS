#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QHostAddress>

#include "./headers/globals.hpp"
#include "./headers/funcs.hpp"
#include "./headers/events.hpp"
#include "./headers/gui.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    Globals::Vars::root_wnd = engine.rootObjects()[0];
    Globals::Vars::dispatcher = new Dispatcher(Globals::Vars::root_wnd);

    QObject::connect(Globals::Vars::dispatcher, &Dispatcher::eventSignal_String, Events::EventString);
    QObject::connect(Globals::Vars::dispatcher, &Dispatcher::eventSignal_Variant, Events::EventVariant);

    GUI::TcsInfo::Prepare();
    GUI::TestList::Fill(Globals::Vars::root_wnd);

    Events::RegisterEvent("testList",SIGNAL(onItemClicked(QString)), SLOT(eventSlot_String(QString)));

    return app.exec();
}





