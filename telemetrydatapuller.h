#ifndef TELEMETRYDATAPULLER_H
#define TELEMETRYDATAPULLER_H
#include <QThread>
#include <QObject>
#include <zmq.hpp>
#include "telemetrycontroller.h"
class TelemetryDataPuller : public QThread
{
    Q_OBJECT
        void run() override;
public:
    TelemetryDataPuller();
public:
    std::string robotTelemetryAddress;
    TelemetryController * telecon_;
private:

    zmq::context_t context;
    zmq::socket_t telemetryStreamSocket;
};

#endif // TELEMETRYDATAPULLER_H
