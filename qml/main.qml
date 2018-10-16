import QtQuick 2.3
import QtQuick.Window 2.2
import mr.jb 1.0

import "qrc:/"
Window {
    property int perfectWidth:  Screen.pixelDensity*80
    width: Screen.width
    height:Screen.height
    visible: true
    Rectangle {
        anchors.fill: parent
        anchors.centerIn: parent
        color:"DarkBlue"

        VideoImage {
            id: videoFrame
            objectName: "VideoFrame"
            anchors.fill: parent

        }

        Label{
            anchors.centerIn: parent
            text: "No video signal"
        }

        ConnectData{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
        }
        MainMenu{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
        }
        SensorsView{
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
        }
        ControlPad {
            anchors.right: parent.right
            anchors.bottom: parent.bottom
        }
    }
}

