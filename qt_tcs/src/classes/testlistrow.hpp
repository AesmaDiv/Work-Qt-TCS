#ifndef TESTLISTROW_HPP
#define TESTLISTROW_HPP

#include <QObject>

class TestListRow : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString record READ record WRITE setRecord NOTIFY recordChanged)
    Q_PROPERTY(QString dateTime READ dateTime WRITE setDateTime NOTIFY dateTimeChanged)
    Q_PROPERTY(QString order READ order WRITE setOrder NOTIFY orderChanged)
    Q_PROPERTY(QString serial READ serial WRITE setSerial NOTIFY serialChanged)

public:
    TestListRow(QObject *parent = nullptr) : QObject(parent) {}
    TestListRow(const QString &record, const QString &dateTime, const QString &order, const QString &serial, QObject *parent = 0) :
        QObject(parent), m_record(record), m_dateTime(dateTime), m_order(order), m_serial(serial) {}


    QString record() const { return m_record; }
    void setRecord(const QString &record);

    QString dateTime() const { return m_dateTime; }
    void setDateTime(const QString &dateTime);

    QString order() const { return m_order; }
    void setOrder(const QString &order);

    QString serial() const { return m_serial; }
    void setSerial(const QString &serial);

signals:
    void recordChanged();
    void dateTimeChanged();
    void orderChanged();
    void serialChanged();

private:
    QString m_record;
    QString m_dateTime;
    QString m_order;
    QString m_serial;

};

inline void TestListRow::setRecord(const QString &record) {
    if (m_record != record) {
        m_record = record;
        emit recordChanged();
    }
}
inline void TestListRow::setDateTime(const QString &dateTime) {
    if (m_dateTime != dateTime) {
        m_dateTime = dateTime;
        emit dateTimeChanged();
    }
}
inline void TestListRow::setOrder(const QString &order) {
    if (m_order != order) {
        m_order = order;
        emit orderChanged();
    }
}
inline void TestListRow::setSerial(const QString &serial) {
    if (m_serial != serial) {
        m_serial = serial;
        emit serialChanged();
    }
}

#endif // TESTLISTROW_HPP
