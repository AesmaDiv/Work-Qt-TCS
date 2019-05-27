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
#endif // DISPATCHER_H
