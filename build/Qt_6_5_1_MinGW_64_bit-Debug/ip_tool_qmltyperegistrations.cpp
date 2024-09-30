/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <ColorTransformer.hpp>
#include <Editor.hpp>
#include <Filter.hpp>


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_main()
{
    qmlRegisterModule("main", 254, 0);
    qmlRegisterTypesAndRevisions<ColorTransformer>("main", 254);
    qmlRegisterTypesAndRevisions<Editor>("main", 254);
    qmlRegisterTypesAndRevisions<Filter>("main", 254);
    qmlRegisterModule("main", 254, 254);
}

static const QQmlModuleRegistration registration("main", qml_register_types_main);
