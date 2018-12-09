#include "videostreampuller.h"
#include <iostream>
#include <QImage>

void VideoStreamPuller::run() {
    //here connect and pull data
    std::cout<<"Connecting to "<<robotVideoAddress<<std::endl;
    videoStreamSocket.connect (robotVideoAddress.c_str());
    while(true)
    {
        zmq::message_t frameMessage;

        //  Wait for next request from client
        videoStreamSocket.recv (&frameMessage);
        //std::cout << "frame received"<<std::endl;
        int frameSize = 0;
        frameSize=frameMessage.size();
        //std::cout << frameSize <<std::endl;
        QImage pix;
        pix.loadFromData((const uchar*)frameMessage.data(), frameSize, "JPG");
        if(needToSaveCurrentFrame){
            needToSaveCurrentFrame=false;
            pix.save ("screen.jpg");
        }
        //std::cout << "do refresh" <<std::endl;
        RefreshPicture(pix);
        emit frameReady();
    }
}

VideoStreamPuller::VideoStreamPuller()
    :context(2)
    , videoStreamSocket(context,ZMQ_PAIR)
    , needToSaveCurrentFrame(false)
{
    std::cout <<"Socket prepared " <<std::endl;
}

void VideoStreamPuller::takeAPicture()
{
    needToSaveCurrentFrame = true;
}

QImage VideoStreamPuller::GetFrame()
{
    return pic;
}

void VideoStreamPuller::RefreshPicture(QImage newpic)
{
    pic = newpic;
}
