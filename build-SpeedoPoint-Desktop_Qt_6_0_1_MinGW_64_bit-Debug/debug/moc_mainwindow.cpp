/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SpeedoPoint/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[38];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 11), // "SwitchLogin"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 12), // "SwitchSignup"
QT_MOC_LITERAL(37, 5), // "Login"
QT_MOC_LITERAL(43, 6), // "Signup"
QT_MOC_LITERAL(50, 14), // "countryChange1"
QT_MOC_LITERAL(65, 4), // "text"
QT_MOC_LITERAL(70, 4), // "type"
QT_MOC_LITERAL(75, 14), // "countryChange2"
QT_MOC_LITERAL(90, 18), // "countryChangeHotel"
QT_MOC_LITERAL(109, 19), // "countryChangeCruise"
QT_MOC_LITERAL(129, 11), // "SortCruises"
QT_MOC_LITERAL(141, 14), // "DisplayFlights"
QT_MOC_LITERAL(156, 13), // "DisplayHotels"
QT_MOC_LITERAL(170, 14), // "DisplayCruises"
QT_MOC_LITERAL(185, 11), // "SortFlights"
QT_MOC_LITERAL(197, 10), // "SortHotels"
QT_MOC_LITERAL(208, 11) // "DetailsBack"

    },
    "MainWindow\0SwitchLogin\0\0SwitchSignup\0"
    "Login\0Signup\0countryChange1\0text\0type\0"
    "countryChange2\0countryChangeHotel\0"
    "countryChangeCruise\0SortCruises\0"
    "DisplayFlights\0DisplayHotels\0"
    "DisplayCruises\0SortFlights\0SortHotels\0"
    "DetailsBack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x08,    0 /* Private */,
       3,    0,  105,    2, 0x08,    1 /* Private */,
       4,    0,  106,    2, 0x08,    2 /* Private */,
       5,    0,  107,    2, 0x08,    3 /* Private */,
       6,    2,  108,    2, 0x08,    4 /* Private */,
       9,    2,  113,    2, 0x08,    7 /* Private */,
      10,    2,  118,    2, 0x08,   10 /* Private */,
      11,    2,  123,    2, 0x08,   13 /* Private */,
      12,    1,  128,    2, 0x08,   16 /* Private */,
      13,    0,  131,    2, 0x08,   18 /* Private */,
      14,    0,  132,    2, 0x08,   19 /* Private */,
      15,    0,  133,    2, 0x08,   20 /* Private */,
      16,    1,  134,    2, 0x08,   21 /* Private */,
      17,    1,  137,    2, 0x08,   23 /* Private */,
      18,    0,  140,    2, 0x08,   25 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SwitchLogin(); break;
        case 1: _t->SwitchSignup(); break;
        case 2: _t->Login(); break;
        case 3: _t->Signup(); break;
        case 4: _t->countryChange1((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->countryChange2((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->countryChangeHotel((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->countryChangeCruise((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->SortCruises((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->DisplayFlights(); break;
        case 10: _t->DisplayHotels(); break;
        case 11: _t->DisplayCruises(); break;
        case 12: _t->SortFlights((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->SortHotels((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->DetailsBack(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
