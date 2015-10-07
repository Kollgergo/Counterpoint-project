/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata0[537];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 26), // "on_actionAddNote_triggered"
QT_MOC_LITERAL(4, 63, 7), // "checked"
QT_MOC_LITERAL(5, 71, 26), // "on_actionAddRest_triggered"
QT_MOC_LITERAL(6, 98, 24), // "on_actionWhole_triggered"
QT_MOC_LITERAL(7, 123, 23), // "on_actionHalf_triggered"
QT_MOC_LITERAL(8, 147, 26), // "on_actionQuarter_triggered"
QT_MOC_LITERAL(9, 174, 25), // "on_actionEighth_triggered"
QT_MOC_LITERAL(10, 200, 28), // "on_action_newStaff_triggered"
QT_MOC_LITERAL(11, 229, 27), // "on_actionAddSharp_triggered"
QT_MOC_LITERAL(12, 257, 26), // "on_actionAddFlat_triggered"
QT_MOC_LITERAL(13, 284, 27), // "on_actionNewScore_triggered"
QT_MOC_LITERAL(14, 312, 34), // "on_actionNewCounterpoint_trig..."
QT_MOC_LITERAL(15, 347, 33), // "on_actionChangeNoteRest_trigg..."
QT_MOC_LITERAL(16, 381, 31), // "on_actionOpenLilypond_triggered"
QT_MOC_LITERAL(17, 413, 31), // "on_actionSaveLilypond_triggered"
QT_MOC_LITERAL(18, 445, 13), // "vNoteSelected"
QT_MOC_LITERAL(19, 459, 6), // "VNote*"
QT_MOC_LITERAL(20, 466, 4), // "note"
QT_MOC_LITERAL(21, 471, 15), // "vNotePosChanged"
QT_MOC_LITERAL(22, 487, 14), // "vstaffSelected"
QT_MOC_LITERAL(23, 502, 7), // "VStaff*"
QT_MOC_LITERAL(24, 510, 6), // "vstaff"
QT_MOC_LITERAL(25, 517, 13), // "newVNoteAdded"
QT_MOC_LITERAL(26, 531, 5) // "vnote"

    },
    "MainWindow\0on_actionExit_triggered\0\0"
    "on_actionAddNote_triggered\0checked\0"
    "on_actionAddRest_triggered\0"
    "on_actionWhole_triggered\0"
    "on_actionHalf_triggered\0"
    "on_actionQuarter_triggered\0"
    "on_actionEighth_triggered\0"
    "on_action_newStaff_triggered\0"
    "on_actionAddSharp_triggered\0"
    "on_actionAddFlat_triggered\0"
    "on_actionNewScore_triggered\0"
    "on_actionNewCounterpoint_triggered\0"
    "on_actionChangeNoteRest_triggered\0"
    "on_actionOpenLilypond_triggered\0"
    "on_actionSaveLilypond_triggered\0"
    "vNoteSelected\0VNote*\0note\0vNotePosChanged\0"
    "vstaffSelected\0VStaff*\0vstaff\0"
    "newVNoteAdded\0vnote"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x08 /* Private */,
       3,    1,  110,    2, 0x08 /* Private */,
       5,    1,  113,    2, 0x08 /* Private */,
       6,    1,  116,    2, 0x08 /* Private */,
       7,    1,  119,    2, 0x08 /* Private */,
       8,    1,  122,    2, 0x08 /* Private */,
       9,    1,  125,    2, 0x08 /* Private */,
      10,    0,  128,    2, 0x08 /* Private */,
      11,    1,  129,    2, 0x08 /* Private */,
      12,    1,  132,    2, 0x08 /* Private */,
      13,    0,  135,    2, 0x08 /* Private */,
      14,    0,  136,    2, 0x08 /* Private */,
      15,    0,  137,    2, 0x08 /* Private */,
      16,    0,  138,    2, 0x08 /* Private */,
      17,    0,  139,    2, 0x08 /* Private */,
      18,    1,  140,    2, 0x0a /* Public */,
      21,    1,  143,    2, 0x0a /* Public */,
      22,    1,  146,    2, 0x0a /* Public */,
      25,    1,  149,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, 0x80000000 | 19,   26,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionExit_triggered(); break;
        case 1: _t->on_actionAddNote_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_actionAddRest_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_actionWhole_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_actionHalf_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_actionQuarter_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_actionEighth_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_action_newStaff_triggered(); break;
        case 8: _t->on_actionAddSharp_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_actionAddFlat_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_actionNewScore_triggered(); break;
        case 11: _t->on_actionNewCounterpoint_triggered(); break;
        case 12: _t->on_actionChangeNoteRest_triggered(); break;
        case 13: _t->on_actionOpenLilypond_triggered(); break;
        case 14: _t->on_actionSaveLilypond_triggered(); break;
        case 15: _t->vNoteSelected((*reinterpret_cast< VNote*(*)>(_a[1]))); break;
        case 16: _t->vNotePosChanged((*reinterpret_cast< VNote*(*)>(_a[1]))); break;
        case 17: _t->vstaffSelected((*reinterpret_cast< VStaff*(*)>(_a[1]))); break;
        case 18: _t->newVNoteAdded((*reinterpret_cast< VNote*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VNote* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VNote* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VStaff* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VNote* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
