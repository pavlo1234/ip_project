/****************************************************************************
** Meta object code from reading C++ file 'Filter.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/Filter.hpp"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Filter.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSFilterENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSFilterENDCLASS = QtMocHelpers::stringData(
    "Filter",
    "QML.Element",
    "auto",
    "process",
    "",
    "QImage*",
    "image",
    "setKernel",
    "array",
    "N",
    "R"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFilterENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[7];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[8];
    char stringdata4[1];
    char stringdata5[8];
    char stringdata6[6];
    char stringdata7[10];
    char stringdata8[6];
    char stringdata9[2];
    char stringdata10[2];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFilterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFilterENDCLASS_t qt_meta_stringdata_CLASSFilterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Filter"
        QT_MOC_LITERAL(7, 11),  // "QML.Element"
        QT_MOC_LITERAL(19, 4),  // "auto"
        QT_MOC_LITERAL(24, 7),  // "process"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 7),  // "QImage*"
        QT_MOC_LITERAL(41, 5),  // "image"
        QT_MOC_LITERAL(47, 9),  // "setKernel"
        QT_MOC_LITERAL(57, 5),  // "array"
        QT_MOC_LITERAL(63, 1),  // "N"
        QT_MOC_LITERAL(65, 1)   // "R"
    },
    "Filter",
    "QML.Element",
    "auto",
    "process",
    "",
    "QImage*",
    "image",
    "setKernel",
    "array",
    "N",
    "R"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFilterENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       1,   14, // classinfo
       2,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   28,    4, 0x02,    1 /* Public */,
       7,    3,   31,    4, 0x02,    3 /* Public */,

 // methods: parameters
    QMetaType::Bool, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QVariantList, QMetaType::Int, QMetaType::Double,    8,    9,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject Filter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSFilterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFilterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // Q_OBJECT / Q_GADGET
        Filter,
        // method 'process'
        bool,
        QImage *,
        // method 'setKernel'
        void,
        QVariantList,
        int,
        double
    >,
    nullptr
} };

void Filter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Filter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->process((*reinterpret_cast< std::add_pointer_t<QImage*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->setKernel((*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject *Filter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Filter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFilterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Filter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
