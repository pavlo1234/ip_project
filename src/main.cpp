#include <QtGui>
#include <QtQml>

int main(int argc, char *argv[])
{
    // створення середовища виконання програми
    QGuiApplication app(argc, argv);

    // завантаження основного об'єкту компоненти програми в QML-рушій
    QQmlApplicationEngine engine("qrc:/main/ui/default.qml");

    // запуск циклу подій програми
    return app.exec();

}