/****************************************************************************
** Meta object code from reading C++ file 'newstaffdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../newstaffdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newstaffdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NewStaffDialog_t {
    QByteArrayData data[8];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewStaffDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewStaffDialog_t qt_meta_stringdata_NewStaffDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "NewStaffDialog"
QT_MOC_LITERAL(1, 15, 28), // "on_trebleRadioButton_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 26), // "on_altoRadioButton_clicked"
QT_MOC_LITERAL(4, 72, 27), // "on_tenorRadioButton_clicked"
QT_MOC_LITERAL(5, 100, 26), // "on_bassRadioButton_clicked"
QT_MOC_LITERAL(6, 127, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(7, 149, 5) // "index"

    },
    "NewStaffDialog\0on_trebleRadioButton_clicked\0"
    "\0on_altoRadioButton_clicked\0"
    "on_tenorRadioButton_clicked\0"
    "on_bassRadioButton_clicked\0"
    "on_comboBox_activated\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewStaffDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void NewStaffDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewStaffDialog *_t = static_cast<NewStaffDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_trebleRadioButton_clicked(); break;
        case 1: _t->on_altoRadioButton_clicked(); break;
        case 2: _t->on_tenorRadioButton_clicked(); break;
        case 3: _t->on_bassRadioButton_clicked(); break;
        case 4: _t->on_comboBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject NewStaffDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewStaffDialog.data,
      qt_meta_data_NewStaffDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NewStaffDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewStaffDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NewStaffDialog.stringdata0))
        return static_cast<void*>(const_cast< NewStaffDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewStaffDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
