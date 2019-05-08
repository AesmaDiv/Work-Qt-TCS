#ifndef DISPATCHER_HPP
#define DISPATCHER_HPP

#include <QObject>
#include <QVariant>

class Dispatcher : public QObject
{
    Q_OBJECT
public:
    explicit Dispatcher(QObject *parent = nullptr) : QObject(parent) {}

    bool setProperty(const QString &object_name, const QString &property_name, const QVariant &value);
    QVariant getProperty(const QString &object_name, const QString &property_name);
signals:
    void eventSignal_String(const QString &message);
    void eventSignal_Variant(const QVariant &variant);
public slots:
    void eventSlot_String(const QString &message);
    void eventSlot_Variant(const QVariant &variant);
};


inline bool Dispatcher::setProperty(const QString &object_name, const QString &property_name, const QVariant &value) {
    QObject* obj = this->parent()->findChild<QObject*>(object_name);
    if (obj == nullptr) {
        return false;
    }
    return obj->setProperty(property_name.toStdString().c_str(), value);
}
inline QVariant Dispatcher::getProperty(const QString &object_name, const QString &property_name) {
    QObject* obj = this->parent()->findChild<QObject*>(object_name);
    if (obj == nullptr) {
        return false;
    }
    return obj->property(property_name.toStdString().c_str());
}
inline void Dispatcher::eventSlot_String(const QString &message) {
    this->eventSignal_String(message);
}
inline void Dispatcher::eventSlot_Variant(const QVariant &variant) {
    this->eventSignal_Variant(variant);
}
#endif // DISPATCHER_H
