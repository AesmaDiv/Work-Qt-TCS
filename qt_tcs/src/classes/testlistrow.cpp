#include "testlistrow.hpp"
/* ************************************************************************************************************************ */
void TestListRow::setRecord(const QString &record) {
    if (m_record != record) {
        m_record = record;
        emit recordChanged();
    }
}
void TestListRow::setDateTime(const QString &dateTime) {
    if (m_dateTime != dateTime) {
        m_dateTime = dateTime;
        emit dateTimeChanged();
    }
}
void TestListRow::setOrder(const QString &order) {
    if (m_order != order) {
        m_order = order;
        emit orderChanged();
    }
}
void TestListRow::setSerial(const QString &serial) {
    if (m_serial != serial) {
        m_serial = serial;
        emit serialChanged();
    }
}
/* ************************************************************************************************************************ */
