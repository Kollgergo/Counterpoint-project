/****************************************************************************
** Meta object code from reading C++ file 'vstaff.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/vstaff.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vstaff.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VStaff_t {
    QByteArrayData data[11];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VStaff_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VStaff_t qt_meta_stringdata_VStaff = {
    {
QT_MOC_LITERAL(0, 0, 6), // "VStaff"
QT_MOC_LITERAL(1, 7, 12), // "vstaffSelect"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "VStaff*"
QT_MOC_LITERAL(4, 29, 6), // "vstaff"
QT_MOC_LITERAL(5, 36, 11), // "newVNoteAdd"
QT_MOC_LITERAL(6, 48, 6), // "VNote*"
QT_MOC_LITERAL(7, 55, 5), // "vnote"
QT_MOC_LITERAL(8, 61, 18), // "vNoteAccentChanged"
QT_MOC_LITERAL(9, 80, 16), // "setVNoteDistance"
QT_MOC_LITERAL(10, 97, 4) // "dist"

    },
    "VStaff\0vstaffSelect\0\0VStaff*\0vstaff\0"
    "newVNoteAdd\0VNote*\0vnote\0vNoteAccentChanged\0"
    "setVNoteDistance\0dist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VStaff[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       8,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void VStaff::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VStaff *_t = static_cast<VStaff *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->vstaffSelect((*reinterpret_cast< VStaff*(*)>(_a[1]))); break;
        case 1: _t->newVNoteAdd((*reinterpret_cast< VNote*(*)>(_a[1]))); break;
        case 2: _t->vNoteAccentChanged((*reinterpret_cast< VNote*(*)>(_a[1]))); break;
        case 3: _t->setVNoteDistance((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VStaff* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VNote* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VNote* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VStaff::*_t)(VStaff * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VStaff::vstaffSelect)) {
                *result = 0;
            }
        }
        {
            typedef void (VStaff::*_t)(VNote * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VStaff::newVNoteAdd)) {
                *result = 1;
            }
        }
        {
            typedef void (VStaff::*_t)(VNote * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VStaff::vNoteAccentChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject VStaff::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_VStaff.data,
      qt_meta_data_VStaff,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VStaff::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VStaff::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VStaff.stringdata0))
        return static_cast<void*>(const_cast< VStaff*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int VStaff::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void VStaff::vstaffSelect(VStaff * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VStaff::newVNoteAdd(VNote * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VStaff::vNoteAccentChanged(VNote * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
