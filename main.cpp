#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>
#include "client.h"
#include "imagewriter.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Client client;
    client.engine_ = &engine;

    qmlRegisterType<ImageWriter>("mr.jb",1,0,"VideoImage");

    engine.rootContext()->setContextProperty("client",&client);
    //engine.rootContext()->setContextProperty("sensorTemp",&client.sensorTemp);
    //engine.rootContext()->setContextProperty("sensorDistance",&client.sensorDistance);
    //engine.rootContext()->setContextProperty("sensorVoltage",&client.sensorVoltage);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}

