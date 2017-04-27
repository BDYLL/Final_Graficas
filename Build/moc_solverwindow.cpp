/****************************************************************************
** Meta object code from reading C++ file 'solverwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../solverwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'solverwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SolverWindow_t {
    QByteArrayData data[9];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SolverWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SolverWindow_t qt_meta_stringdata_SolverWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SolverWindow"
QT_MOC_LITERAL(1, 13, 17), // "restoreMainWindow"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 15), // "receiveCubeData"
QT_MOC_LITERAL(4, 48, 29), // "vector<vector<vector<int> > >"
QT_MOC_LITERAL(5, 78, 5), // "faces"
QT_MOC_LITERAL(6, 84, 22), // "on_scanNewCube_clicked"
QT_MOC_LITERAL(7, 107, 21), // "on_exitButton_clicked"
QT_MOC_LITERAL(8, 129, 16) // "resolveRubikCube"

    },
    "SolverWindow\0restoreMainWindow\0\0"
    "receiveCubeData\0vector<vector<vector<int> > >\0"
    "faces\0on_scanNewCube_clicked\0"
    "on_exitButton_clicked\0resolveRubikCube"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SolverWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SolverWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SolverWindow *_t = static_cast<SolverWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->restoreMainWindow(); break;
        case 1: _t->receiveCubeData((*reinterpret_cast< vector<vector<vector<int> > >(*)>(_a[1]))); break;
        case 2: _t->on_scanNewCube_clicked(); break;
        case 3: _t->on_exitButton_clicked(); break;
        case 4: _t->resolveRubikCube(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SolverWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SolverWindow::restoreMainWindow)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SolverWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SolverWindow.data,
      qt_meta_data_SolverWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SolverWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SolverWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SolverWindow.stringdata0))
        return static_cast<void*>(const_cast< SolverWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SolverWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SolverWindow::restoreMainWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
