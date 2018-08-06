#ifndef SERVODATA_H
#define SERVODATA_H
#include <QTcpSocket>
#include <QObject>
#include <zmq.hpp>
#include "sensorscontrol.h"


class ServoData : public QObject
{
    Q_OBJECT
public:
    explicit ServoData(QObject *parent = 0);
    Q_INVOKABLE bool connect(QString ip);

    Q_INVOKABLE void stepForward(int steps);
    Q_INVOKABLE void stepBackward(int steps);
    Q_INVOKABLE void stepLeft(int steps);
    Q_INVOKABLE void stepRight(int steps);

    sensorsControl sensorTemp;
    sensorsControl sensorVoltage;
    sensorsControl sensorDistance;
    void GetSensorsInfo(void);
signals:

public slots:
    void ReadTCPData();

private:
    int readServo0Sensor(QString command);
    zmq::context_t context;
    zmq::socket_t socket;
};

#endif // SERVODATA_H
