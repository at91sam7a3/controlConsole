#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>
#include "servodata.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    ServoData sData;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("sData",&sData);
    engine.rootContext()->setContextProperty("sensorTemp",&sData.sensorTemp);
    engine.rootContext()->setContextProperty("sensorDistance",&sData.sensorDistance);
    engine.rootContext()->setContextProperty("sensorVoltage",&sData.sensorVoltage);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}

