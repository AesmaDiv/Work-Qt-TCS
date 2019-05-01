#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <QObject>
#include <QString>

#include "./globals.hpp"

namespace Events {
    void RegisterEvent(const QString &child_name, const char* signal, const char* slot);
    void EventString(const QString &message);
    void EventVariant(const QVariant &variant);
}
/* ************************************************************************************************************************ */
void Events::RegisterEvent(const QString &child_name, const char* signal, const char* slot) {
    QObject* child = Globals::Vars::root_wnd->findChild<QObject*>(child_name);
    if(!child) return;
    QObject::connect(child, signal, Globals::Vars::dispatcher, slot);
}
void Events::EventString(const QString &message) {
    QStringList params = message.split('-');

    return;
}
void Events::EventVariant(const QVariant &variant) {
    QVariantList params = variant.toList();
    return;
}
/* ************************************************************************************************************************ */
#endif // EVENTS_HPP
