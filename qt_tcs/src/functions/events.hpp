#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <QObject>
#include <QString>

#include "gui.hpp"

namespace Events {
    void EventString(const QString &message);
    void EventVariant(const QVariant &variant);
};
#endif // EVENTS_HPP
