/****************************************************************************
** Meta object code from reading C++ file 'Editor.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/Editor.hpp"
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
#error "The header file 'Editor.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSEditorENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSEditorENDCLASS = QtMocHelpers::stringData(
    "Editor",
    "QML.Element",
    "auto",
    "loaded",
    "",
    "temp_path",
    "load",
    "url",
    "save",
    "close",
    "image",
    "QImage*",
    "path"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSEditorENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[7];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[7];
    char stringdata4[1];
    char stringdata5[10];
    char stringdata6[5];
    char stringdata7[4];
    char stringdata8[5];
    char stringdata9[6];
    char stringdata10[6];
    char stringdata11[8];
    char stringdata12[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSEditorENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSEditorENDCLASS_t qt_meta_stringdata_CLASSEditorENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Editor"
        QT_MOC_LITERAL(7, 11),  // "QML.Element"
        QT_MOC_LITERAL(19, 4),  // "auto"
        QT_MOC_LITERAL(24, 6),  // "loaded"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 9),  // "temp_path"
        QT_MOC_LITERAL(42, 4),  // "load"
        QT_MOC_LITERAL(47, 3),  // "url"
        QT_MOC_LITERAL(51, 4),  // "save"
        QT_MOC_LITERAL(56, 5),  // "close"
        QT_MOC_LITERAL(62, 5),  // "image"
        QT_MOC_LITERAL(68, 7),  // "QImage*"
        QT_MOC_LITERAL(76, 4)   // "path"
    },
    "Editor",
    "QML.Element",
    "auto",
    "loaded",
    "",
    "temp_path",
    "load",
    "url",
    "save",
    "close",
    "image",
    "QImage*",
    "path"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSEditorENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       1,   14, // classinfo
       4,   16, // methods
       3,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   40,    4, 0x06,    4 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   43,    4, 0x02,    6 /* Public */,
       8,    1,   46,    4, 0x02,    8 /* Public */,
       9,    0,   49,    4, 0x02,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QUrl,    5,

 // methods: parameters
    QMetaType::Void, QMetaType::QUrl,    7,
    QMetaType::Bool, QMetaType::QUrl,    7,
    QMetaType::Void,

 // properties: name, type, flags
      10, 0x80000000 | 11, 0x00015009, uint(-1), 0,
       5, QMetaType::QUrl, 0x00015003, uint(-1), 0,
      12, QMetaType::QUrl, 0x00015003, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Editor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSEditorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSEditorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'image'
        QImage*,
        // property 'temp_path'
        QUrl,
        // property 'path'
        QUrl,
        // Q_OBJECT / Q_GADGET
        Editor,
        // method 'loaded'
        void,
        QUrl,
        // method 'load'
        void,
        QUrl,
        // method 'save'
        bool,
        QUrl,
        // method 'close'
        void
    >,
    nullptr
} };

void Editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Editor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loaded((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 1: _t->load((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 2: { bool _r = _t->save((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->close(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Editor::*)(QUrl );
            if (_t _q_method = &Editor::loaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Editor *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QImage**>(_v) = _t->getImage(); break;
        case 1: *reinterpret_cast< QUrl*>(_v) = _t->_temp_path; break;
        case 2: *reinterpret_cast< QUrl*>(_v) = _t->_path; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Editor *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1:
            if (_t->_temp_path != *reinterpret_cast< QUrl*>(_v)) {
                _t->_temp_path = *reinterpret_cast< QUrl*>(_v);
            }
            break;
        case 2:
            if (_t->_path != *reinterpret_cast< QUrl*>(_v)) {
                _t->_path = *reinterpret_cast< QUrl*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSEditorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Editor::loaded(QUrl _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
