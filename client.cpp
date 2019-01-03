#include "client.h"
#include <zmq.hpp>
#include "proto/command.pb.h"
#include <QDebug>
#include "Communication.h"


Client::Client(QObject *parent)
    : QObject(parent)
    , context(1)
    , commandSocket(context,ZMQ_REQ)
    , settingsSocket(context, ZMQ_PAIR)

    , m_connected(false)
    , imagewriter(nullptr)
{
    connect(&videoStreamPuller, &VideoStreamPuller::frameReady, this, &Client::updateFrame);
}

bool Client::connectToRobot(QString ip)
{
    std::cout<<"Connecting to "<<ip.toStdString()<<std::endl;
    std::string commandSocketConnectAddr("tcp://");
    commandSocketConnectAddr += ip.toStdString();
    commandSocketConnectAddr += ":5555";

    std::string settingsSocketConnectAddr("tcp://");
    settingsSocketConnectAddr += ip.toStdString();
    settingsSocketConnectAddr += ":5556";

    std::string videoSocketConnectAddr("tcp://");
    videoSocketConnectAddr += ip.toStdString();
    videoSocketConnectAddr += ":5557";

    std::cout<<"Connecting to "<<commandSocketConnectAddr<<std::endl;
    commandSocket.connect (commandSocketConnectAddr.c_str());
    std::cout<<"Connecting to "<<settingsSocketConnectAddr<<std::endl;
    settingsSocket.connect (settingsSocketConnectAddr.c_str());


    videoStreamPuller.robotVideoAddress = videoSocketConnectAddr;

    setConnected(true);

    return true;
}

void Client::moveToCoordinates(int x, int y)
{
    Command::MoveCommand mc;
    mc.set_command("Move");
    mc.set_x(x);
    mc.set_y(y);
    std::string commString(mc.SerializeAsString());
    char commndType[]={MOVE_COMMAND,0};
    std::string reqString(commndType);
    reqString+=commString;
    zmq::message_t req (reqString.length());
    memcpy (req.data (), reqString.c_str(), reqString.length());
    commandSocket.send (req);
    zmq::message_t reply;
    //  Wait for next request from client
    commandSocket.recv (&reply);
    assert(reply.size()==1);
}

void Client::turnToAngle(int angle)
{
    Command::MoveCommand mc;
    mc.set_command("Move");
    mc.set_rotation_before(angle);
    std::string commString(mc.SerializeAsString());
    char commndType[]={MOVE_COMMAND,0};
    std::string reqString(commndType);
    reqString+=commString;
    zmq::message_t req (reqString.length());
    memcpy (req.data (), reqString.c_str(), reqString.length());
    commandSocket.send (req);
    zmq::message_t reply;
    //  Wait for next request from client
    commandSocket.recv (&reply);
    assert(reply.size()==1);
}



void Client::setAngle(unsigned int servo, int angle)
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
    commandSocket.send (req);

    zmq::message_t reply;
    //  Wait for next request from client
    commandSocket.recv (&reply);
}

void Client::setBodyHeight(unsigned int height)
{
    /*Command::MoveCommand mc;
    mc.set_command("SetBodyHeight");
    mc.set_parameter(static_cast<int>(height));
    std::string commString(mc.SerializeAsString());
    char commndType[]={MOVE_COMMAND,0};
    std::string reqString(commndType);
    reqString+=commString;
    zmq::message_t req (reqString.length());
    memcpy (req.data (), reqString.c_str(), reqString.length());
    commandSocket.send (req);
       zmq::message_t reply;
    commandSocket.recv (&reply);
    assert(reply.size()==1);*/
}

void Client::setXY(unsigned int leg, int x, int y)
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
    commandSocket.send (req);
    zmq::message_t reply;
    //  Wait for next request from client
    commandSocket.recv (&reply);
    assert(reply.size()==1);
}

void Client::runVideo()
{
    static bool videoStarted=false;
    if (videoStarted) return;
    std::cout << "Running video" <<std::endl;


    QQuickItem *myItem = engine_->rootObjects()[0]->findChild<QQuickItem *>("VideoFrame");
    assert(myItem);
    imagewriter = dynamic_cast<ImageWriter*>(myItem);

    if(imagewriter != nullptr) std::cout << "Got frame item"<<std::endl;

    Command::CommandToCamera c2c;
    c2c.set_command("ON");


    std::string commString(c2c.SerializeAsString());
    char commndType[]={COMMAND_TO_CAMERA,0};
    std::string reqString(commndType);
    reqString+=commString;
    zmq::message_t req (reqString.length());
    memcpy (req.data (), reqString.c_str(), reqString.length());
    settingsSocket.send (req);
    videoStreamPuller.start();
    videoStarted = true;
}

void Client::takeScreenshot()
{
    videoStreamPuller.takeAPicture ();
}

/*sensorsControl *Client::GetSensorById(int id)
{
    return &sensorData[id];
}*/



bool Client::connected() const
{
    return m_connected;
}

QPixmap Client::videoFrame() const
{
    return m_videoFrame;
}

void Client::ReadTCPData()
{



}

void Client::updateFrame()
{
    imagewriter->image = (videoStreamPuller.GetFrame());
    imagewriter->update();
    std::cout<<"f";
}

void Client::setConnected(bool connected)
{
    if (m_connected == connected)
        return;

    m_connected = connected;
    emit connectedChanged(m_connected);
}

void Client::setVideoFrame(QPixmap videoFrame)
{
  //  if (m_videoFrame == videoFrame)
  //      return;

    m_videoFrame = videoFrame;
    emit videoFrameChanged(m_videoFrame);
}




