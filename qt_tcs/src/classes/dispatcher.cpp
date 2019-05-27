#include "dispatcher.hpp"
/* ************************************************************************************************************************ */
bool Dispatcher::setProperty(const QString &object_name, const QString &property_name, const QVariant &value) {
    QObject* obj = this->parent()->findChild<QObject*>(object_name);
    if (obj == nullptr) {
        return false;
    }
    return obj->setProperty(property_name.toStdString().c_str(), value);
}
QVariant Dispatcher::getProperty(const QString &object_name, const QString &property_name) {
    QObject* obj = this->parent()->findChild<QObject*>(object_name);
    if (obj == nullptr) {
        return false;
    }
    return obj->property(property_name.toStdString().c_str());
}
void Dispatcher::eventSlot_String(const QString &message) {
    this->eventSignal_String(message);
}
void Dispatcher::eventSlot_Variant(const QVariant &variant) {
    this->eventSignal_Variant(variant);
}
/* ************************************************************************************************************************ */
