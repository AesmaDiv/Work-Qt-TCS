/****************************************************************************
** Meta object code from reading C++ file 'testlistrow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt_tcs/src/classes/testlistrow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testlistrow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestListRow_t {
    QByteArrayData data[10];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestListRow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestListRow_t qt_meta_stringdata_TestListRow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TestListRow"
QT_MOC_LITERAL(1, 12, 13), // "recordChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "dateTimeChanged"
QT_MOC_LITERAL(4, 43, 12), // "orderChanged"
QT_MOC_LITERAL(5, 56, 13), // "serialChanged"
QT_MOC_LITERAL(6, 70, 6), // "record"
QT_MOC_LITERAL(7, 77, 8), // "dateTime"
QT_MOC_LITERAL(8, 86, 5), // "order"
QT_MOC_LITERAL(9, 92, 6) // "serial"

    },
    "TestListRow\0recordChanged\0\0dateTimeChanged\0"
    "orderChanged\0serialChanged\0record\0"
    "dateTime\0order\0serial"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestListRow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::QString, 0x00495103,
       7, QMetaType::QString, 0x00495103,
       8, QMetaType::QString, 0x00495103,
       9, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void TestListRow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestListRow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recordChanged(); break;
        case 1: _t->dateTimeChanged(); break;
        case 2: _t->orderChanged(); break;
        case 3: _t->serialChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TestListRow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestListRow::recordChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TestListRow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestListRow::dateTimeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TestListRow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestListRow::orderChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TestListRow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestListRow::serialChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<TestListRow *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->record(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->dateTime(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->order(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->serial(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<TestListRow *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRecord(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setDateTime(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setOrder(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setSerial(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TestListRow::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_TestListRow.data,
    qt_meta_data_TestListRow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TestListRow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestListRow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestListRow.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestListRow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void TestListRow::recordChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TestListRow::dateTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TestListRow::orderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TestListRow::serialChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
