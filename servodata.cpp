#include "servodata.h"
#include <zmq.hpp>
#include "proto/command.pb.h"
#include <QDebug>
ServoData::ServoData(QObject *parent)
    : QObject(parent)
    , context(1)
    , socket(context,ZMQ_REQ)
{
    sensorDistance.setValue("No data");
    sensorDistance.setParameter("Distance");
    sensorTemp.setValue("Read failure");
    sensorTemp.setParameter("Temperature");
    sensorVoltage.setValue("Not connected");
    sensorVoltage.setParameter("Voltage");
}

bool ServoData::connect(QString ip)
{
    socket.connect (ip.toStdString().c_str());
    ReadTCPData();
    return true;
}

void ServoData::stepForward(int steps)
{

}

void ServoData::stepBackward(int steps)
{

}

void ServoData::stepLeft(int steps)
{

}

void ServoData::stepRight(int steps)
{

}

void ServoData::GetSensorsInfo()
{
    double voltage = readServo0Sensor("GetVoltage");
    sensorVoltage.setValue(QString::number(voltage));
    int temperature = readServo0Sensor("GetTemperature");
    sensorTemp.setValue(QString::number(temperature));



}

void ServoData::ReadTCPData()
{



}

int ServoData::readServo0Sensor(QString command)
{
    Command::CommandToServo  toServo;
    toServo.set_name(command.toStdString().c_str());
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
    return fromServo.result();
}


