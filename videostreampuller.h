#ifndef VIDEOSTREAMPULLER_H
#define VIDEOSTREAMPULLER_H
#include <QThread>
#include <zmq.hpp>
#include <QPixmap>


class VideoStreamPuller : public QThread
{
    Q_OBJECT
    void run() override;
public:
    VideoStreamPuller();
signals:
    void frameReady();
public:
    std::string robotVideoAddress;
    QImage GetFrame();
private:
    void RefreshPicture(QImage newpic);

    zmq::context_t context;
    zmq::socket_t videoStreamSocket;
    QImage pic;

};

#endif // VIDEOSTREAMPULLER_H
