#include "events.hpp"
/* ************************************************************************************************************************ */
void Events::EventString(const QString &message) {
    QStringList params = message.split(':');
    if (params.size() > 1) {
        if (QString::compare(params[0], "TestList") == 0) {
            if (QString::compare(params[1], "ItemSelected") == 0)
                GUI::TestList::ProcessItemSelect(params[2]);
            else if (QString::compare(params[1], "NewTest") == 0)
                GUI::TestList::ProcessNewTest();
        }
    }

    return;
}
void Events::EventVariant(const QVariant &variant) {
    QVariantList params = variant.toList();
    if (params.size() > 0)
        if (QString::compare(params[0].toString(), "TcsInfo") == 0)
            GUI::TcsInfo::ProcessItemSelect(params);

    return;
}
/* ************************************************************************************************************************ */
