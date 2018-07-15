#include "servodata.h"
#include <zmq.hpp>
#include "proto/command.pb.h"
#include <QDebug>
ServoData::ServoData(QObject *parent)
    : QObject(parent)
    , context(1)
    , socket(context,ZMQ_REQ)
{
}

bool ServoData::connect(QString ip)
{
    socket.connect ("tcp://127.0.0.1:5555");
    ReadTCPData();
    return true;
}

void ServoData::ReadTCPData()
{
    Command::CommandToServo  toServo;
    toServo.set_name("GetVoltge");
    toServo.set_servoid(0);
    std::string reqString(toServo.SerializeAsString());
    zmq::message_t req (reqString.length());
    memcpy (req.data (), reqString.c_str(), reqString.length());
    socket.send (req);
    zmq::message_t reply;
    //  Wait for next request from client
    socket.recv (&reply);
    Command::ResponceFromServo  fromServo;
    fromServo.ParseFromArray(reply.data(),reply.size());
    if(fromServo.has_name())
        qDebug()<<"Got responce : "<<QString(fromServo.name().c_str());

}


