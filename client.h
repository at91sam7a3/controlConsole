#ifndef SERVODATA_H
#define SERVODATA_H
#include <QTcpSocket>
#include <QObject>
#include <zmq.hpp>
#include "sensorscontrol.h"
#include "videostreampuller.h"
#include "imagewriter.h"
#include <QQmlApplicationEngine>


class Client : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ connected WRITE setConnected NOTIFY connectedChanged)
    Q_PROPERTY(QPixmap videoFrame READ videoFrame WRITE setVideoFrame NOTIFY videoFrameChanged)
   // Q_PROPERTY(int sensorDataCount READ sensorDataCount WRITE setSensorDataCount NOTIFY sensorDataCountChanged)
public:
    explicit Client(QObject *parent = 0);
    Q_INVOKABLE bool connectToRobot(QString ip);

    Q_INVOKABLE void stepForward(int steps);
    Q_INVOKABLE void stepBackward(int steps);
    Q_INVOKABLE void stepLeft(int steps);
    Q_INVOKABLE void stepRight(int steps);

    Q_INVOKABLE void setAngle(unsigned int servo, int angle);

    Q_INVOKABLE void setBodyHeight(unsigned int height);

    Q_INVOKABLE void setXY(unsigned int leg, int x, int y);

    Q_INVOKABLE void runVideo();

    Q_INVOKABLE void takeScreenshot();

   // Q_INVOKABLE sensorsControl *GetSensorById(int id);


    bool connected() const;

    QPixmap videoFrame() const;

signals:

    void connectedChanged(bool connected);

    void videoFrameChanged(QPixmap videoFrame);

public slots:
    void ReadTCPData();
    void updateFrame();
    void setConnected(bool connected);

    void setVideoFrame(QPixmap videoFrame);

private:

    zmq::context_t context;
    zmq::socket_t commandSocket;
    zmq::socket_t settingsSocket;

    bool m_connected;

    VideoStreamPuller videoStreamPuller;
    QPixmap m_videoFrame;
    ImageWriter * imagewriter;
 //   std::vector<sensorsControl> sensorData;
public:
    QQmlApplicationEngine * engine_;
};

#endif // SERVODATA_H
