/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Cviewer/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "updateFileTreeRoot"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "itemSelected"
QT_MOC_LITERAL(4, 44, 3), // "idx"
QT_MOC_LITERAL(5, 48, 14), // "showClickedDir"
QT_MOC_LITERAL(6, 63, 13), // "resizeOnClick"
QT_MOC_LITERAL(7, 77, 16), // "focusToUserInput"
QT_MOC_LITERAL(8, 94, 18), // "functionListFilter"
QT_MOC_LITERAL(9, 113, 4), // "text"
QT_MOC_LITERAL(10, 118, 23), // "functionListSelectedAll"
QT_MOC_LITERAL(11, 142, 24), // "functionListSelectedNone"
QT_MOC_LITERAL(12, 167, 27), // "functionListSelectedChanged"
QT_MOC_LITERAL(13, 195, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(14, 212, 4), // "item"
QT_MOC_LITERAL(15, 217, 13), // "generateGraph"
QT_MOC_LITERAL(16, 231, 10), // "viewerOpen"
QT_MOC_LITERAL(17, 242, 12), // "viewerClosed"
QT_MOC_LITERAL(18, 255, 3) // "ret"

    },
    "MainWindow\0updateFileTreeRoot\0\0"
    "itemSelected\0idx\0showClickedDir\0"
    "resizeOnClick\0focusToUserInput\0"
    "functionListFilter\0text\0functionListSelectedAll\0"
    "functionListSelectedNone\0"
    "functionListSelectedChanged\0"
    "QListWidgetItem*\0item\0generateGraph\0"
    "viewerOpen\0viewerClosed\0ret"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    1,   75,    2, 0x0a /* Public */,
       5,    1,   78,    2, 0x0a /* Public */,
       6,    0,   81,    2, 0x0a /* Public */,
       7,    0,   82,    2, 0x0a /* Public */,
       8,    1,   83,    2, 0x0a /* Public */,
      10,    0,   86,    2, 0x0a /* Public */,
      11,    0,   87,    2, 0x0a /* Public */,
      12,    1,   88,    2, 0x0a /* Public */,
      15,    0,   91,    2, 0x0a /* Public */,
      16,    0,   92,    2, 0x0a /* Public */,
      17,    1,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->updateFileTreeRoot(); break;
        case 1: _t->itemSelected((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->showClickedDir((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 3: _t->resizeOnClick(); break;
        case 4: _t->focusToUserInput(); break;
        case 5: _t->functionListFilter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->functionListSelectedAll(); break;
        case 7: _t->functionListSelectedNone(); break;
        case 8: _t->functionListSelectedChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->generateGraph(); break;
        case 10: _t->viewerOpen(); break;
        case 11: _t->viewerClosed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
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
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
