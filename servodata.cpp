#include "servodata.h"
#include <zmq.hpp>
#include "proto/command.pb.h"
#include <QDebug>
#include "Communication.h"
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
    std::cout<<"Connecting to "<<ip.toStdString()<<std::endl;
    socket.connect (ip.toStdString().c_str());

    GetSensorsInfo();
    return true;
}

void ServoData::stepForward(int steps)
{
    Command::MoveCommand mc;
    mc.set_command("StepForward");
    mc.set_steps(steps);
    std::string commString(mc.SerializeAsString());
    char commndType[]={MOVE_COMMAND,0};
    std::string reqString(commndType);
    reqString+=commString;
    zmq::message_t req (reqString.length());
    memcpy (req.data (), reqString.c_str(), reqString.length());
    socket.send (req);
    zmq::message_t reply;
    //  Wait for next request from client
    socket.recv (&reply);
    assert(reply.size()==1);
}

void ServoData::stepBackward(int steps)
{
    Command::MoveCommand mc;
    mc.set_command("StepBack");
    mc.set_steps(steps);
    std::string commString(mc.SerializeAsString());
    char commndType[]={MOVE_COMMAND,0};
    std::string reqString(commndType);
    reqString+=commString;
    zmq::message_t req (reqString.length());
    memcpy (req.data (), reqString.c_str(), reqString.length());
    socket.send (req);
    zmq::message_t reply;
    //  Wait for next request from client
    socket.recv (&reply);
    assert(reply.size()==1);
}

void ServoData::stepLeft(int steps)
{
    Command::MoveCommand mc;
    mc.set_command("TurnLeft");
    mc.set_steps(steps);
    std::string commString(mc.SerializeAsString());
    char commndType[]={MOVE_COMMAND,0};
    std::string reqString(commndType);
    reqString+=commString;
    zmq::message_t req (reqString.length());
    memcpy (req.data (), reqString.c_str(), reqString.length());
    socket.send (req);
    zmq::message_t reply;
    //  Wait for next request from client
    socket.recv (&reply);
    assert(reply.size()==1);
}

void ServoData::stepRight(int steps)
{
    Command::MoveCommand mc;
    mc.set_command("TurnRight");
    mc.set_steps(steps);
    std::string commString(mc.SerializeAsString());
    char commndType[]={MOVE_COMMAND,0};
    std::string reqString(commndType);
    reqString+=commString;
    zmq::message_t req (reqString.length());
    memcpy (req.data (), reqString.c_str(), reqString.length());
    socket.send (req);
    zmq::message_t reply;
    //  Wait for next request from client
    socket.recv (&reply);
    assert(reply.size()==1);
}

void ServoData::setAngle(unsigned int servo, int angle)
{
    Command::CommandToServo  toServo;
    toServo.set_name("SetAngle");
    toServo.set_servoid(servo);
    toServo.set_param1(angle);
    char commndType[]={COMMAND_TO_SERVO,0};
    std::string reqString(commndType);
    reqString+=toServo.SerializeAsString();
    zmq::message_t req (reqString.length());
    memcpy (req.data (), reqString.c_str(), reqString.length());
    socket.send (req);

    zmq::message_t reply;
    //  Wait for next request from client
    socket.recv (&reply);
}

void ServoData::setBodyHeight(unsigned int height)
{
    Command::MoveCommand mc;
    mc.set_command("SetBodyHeight");
    mc.set_parameter(static_cast<int>(height));
    std::string commString(mc.SerializeAsString());
    char commndType[]={MOVE_COMMAND,0};
    std::string reqString(commndType);
    reqString+=commString;
    zmq::message_t req (reqString.length());
    memcpy (req.data (), reqString.c_str(), reqString.length());
    socket.send (req);
    zmq::message_t reply;
    //  Wait for next request from client
    socket.recv (&reply);
    assert(reply.size()==1);
}

void ServoData::setXY(unsigned int leg, int x, int y)
{
    Command::LegMoveCommand mc;
    mc.set_x(-y+50);
    mc.set_y(x+50);
    mc.set_z(0);
    mc.set_leg(leg);

    std::string commString(mc.SerializeAsString());
    char commndType[]={LEG_MOVEMENT,0};
    std::string reqString(commndType);
    reqString+=commString;
    zmq::message_t req (reqString.length());
    memcpy (req.data (), reqString.c_str(), reqString.length());
    socket.send (req);
    zmq::message_t reply;
    //  Wait for next request from client
    socket.recv (&reply);
    assert(reply.size()==1);
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
    char commndType[]={COMMAND_TO_SERVO,0};
    std::string reqString(commndType);
    reqString+=toServo.SerializeAsString();
    zmq::message_t req (reqString.length());
    memcpy (req.data (), reqString.c_str(), reqString.length());
    socket.send (req);

    zmq::message_t reply;
    //  Wait for next request from client
    socket.recv (&reply);
    Command::ResponceFromServo  fromServo;
    fromServo.ParseFromArray(reply.data(),static_cast<int>(reply.size()));
    return fromServo.result();
}


