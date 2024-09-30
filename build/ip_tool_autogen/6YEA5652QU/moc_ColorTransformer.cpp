/****************************************************************************
** Meta object code from reading C++ file 'ColorTransformer.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/ColorTransformer.hpp"
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
#error "The header file 'ColorTransformer.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSColorTransformerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSColorTransformerENDCLASS = QtMocHelpers::stringData(
    "ColorTransformer",
    "QML.Element",
    "auto",
    "transform",
    "",
    "QImage*",
    "image",
    "method",
    "jsList",
    "getDistribution"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSColorTransformerENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[17];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[10];
    char stringdata4[1];
    char stringdata5[8];
    char stringdata6[6];
    char stringdata7[7];
    char stringdata8[7];
    char stringdata9[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSColorTransformerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSColorTransformerENDCLASS_t qt_meta_stringdata_CLASSColorTransformerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "ColorTransformer"
        QT_MOC_LITERAL(17, 11),  // "QML.Element"
        QT_MOC_LITERAL(29, 4),  // "auto"
        QT_MOC_LITERAL(34, 9),  // "transform"
        QT_MOC_LITERAL(44, 0),  // ""
        QT_MOC_LITERAL(45, 7),  // "QImage*"
        QT_MOC_LITERAL(53, 5),  // "image"
        QT_MOC_LITERAL(59, 6),  // "method"
        QT_MOC_LITERAL(66, 6),  // "jsList"
        QT_MOC_LITERAL(73, 15)   // "getDistribution"
    },
    "ColorTransformer",
    "QML.Element",
    "auto",
    "transform",
    "",
    "QImage*",
    "image",
    "method",
    "jsList",
    "getDistribution"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSColorTransformerENDCLASS[] = {

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
       3,    3,   28,    4, 0x02,    1 /* Public */,
       9,    1,   35,    4, 0x02,    5 /* Public */,

 // methods: parameters
    QMetaType::Bool, 0x80000000 | 5, QMetaType::QString, QMetaType::QVariantList,    6,    7,    8,
    QMetaType::QVariantMap, 0x80000000 | 5,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject ColorTransformer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSColorTransformerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSColorTransformerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // Q_OBJECT / Q_GADGET
        ColorTransformer,
        // method 'transform'
        bool,
        QImage *,
        QString,
        QVariantList,
        // method 'getDistribution'
        QVariantMap,
        QImage *
    >,
    nullptr
} };

void ColorTransformer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ColorTransformer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->transform((*reinterpret_cast< std::add_pointer_t<QImage*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { QVariantMap _r = _t->getDistribution((*reinterpret_cast< std::add_pointer_t<QImage*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *ColorTransformer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorTransformer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSColorTransformerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ColorTransformer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
