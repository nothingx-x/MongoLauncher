#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "piston/version_manifest.h"

int main(int argc, char *argv[]) {
    QGuiApplication a(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return QGuiApplication::exec();
}
