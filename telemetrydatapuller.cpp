#include "telemetrydatapuller.h"
#include "proto/command.pb.h"
void TelemetryDataPuller::run()
{
    std::cout<<"Connecting to "<<robotTelemetryAddress<<std::endl;
    telemetryStreamSocket.connect (robotTelemetryAddress.c_str());
    while(true)
    {
        zmq::message_t telemetryMessage;

        //  Wait for next request from client
        telemetryStreamSocket.recv (&telemetryMessage);
        std::cout << "telemetry received"<<std::endl;

        TelemetryController::ListElement e;
        Command::TelemetryUpdate telUpdate;
        telUpdate.ParseFromArray(static_cast<char*>(telemetryMessage.data()),static_cast<int>(telemetryMessage.size()));
        e.name = QString(telUpdate.name().c_str());
        if(telUpdate.has_bvalue()){
             std::cout << "telemetry B received"<<std::endl;
            e.paramType = TelemetryController::ListElement::btype;
            e.value=telUpdate.bvalue() ? QString("ON") : QString("OFF");
        }
        if(telUpdate.has_svalue()) {
             std::cout << "telemetry F received"<<std::endl;
            e.paramType = TelemetryController::ListElement::ftype;
            e.value = QString(telUpdate.svalue().c_str());
        }

        if(telUpdate.has_fvalue()) {
             std::cout << "telemetry received"<<std::endl;
            e.paramType = TelemetryController::ListElement::stype;
            e.value = QString::number(int(telUpdate.fvalue()));
        }
        telecon_->addOrModify(e);
    }
}

TelemetryDataPuller::TelemetryDataPuller()
    :telecon_(nullptr)
    , context(2)
    , telemetryStreamSocket(context,ZMQ_PAIR)
{

}
