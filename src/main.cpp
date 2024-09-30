#include <QtGui>
#include <QtQml>

#include "Editor.hpp"
#include "Filter.hpp"
#include "ColorTransformer.hpp"

int main(int argc, char *argv[])
{
    // створення середовища виконання програми
    QGuiApplication app(argc, argv);

    qmlRegisterType<Editor>("com.editing", 1, 0, "Editor");
    qmlRegisterType<Filter>("com.editing", 1, 0, "Filter");
    qmlRegisterType<ColorTransformer>("com.editing", 1, 0, "ColorTransformer");

    // завантаження основного об'єкту компоненти програми в QML-рушій
    QQmlApplicationEngine engine("qrc:/main/ui/default.qml");

    // запуск циклу подій програми
    return app.exec();

}