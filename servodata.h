#ifndef SERVODATA_H
#define SERVODATA_H
#include <QTcpSocket>
#include <QObject>
#include <zmq.hpp>



class ServoData : public QObject
{
    Q_OBJECT




public:
    explicit ServoData(QObject *parent = 0);
    Q_INVOKABLE bool connect(QString ip);


signals:

public slots:
    void ReadTCPData();

private:
    zmq::context_t context;
    zmq::socket_t socket;
};

#endif // SERVODATA_H
