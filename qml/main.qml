import QtQuick 2.3
import QtQuick.Window 2.2
import mr.jb 1.0

//import QtGraphicalEffects 1.0
import "qrc:/"

Window {
    property int perfectWidth: Screen.pixelDensity * 80
    property int subMenuWidth: Screen.pixelDensity * 20
    width: Screen.width
    height: Screen.height
    visible: true
    Rectangle {
        anchors.fill: parent
        anchors.centerIn: parent
        color: "DarkBlue"

        SubScreen {
            id: videoWindow
            anchors.left: parent.left
            anchors.top: parent.top
            width: parent.width / 2 - subMenuWidth
            height: parent.height / 2
            windowName: "Video input"
            VideoImage {
                id: videoFrame
                objectName: "VideoFrame"
                anchors.fill: parent
            }
        }

        SubScreen {
            id: mapWindow
            anchors.right: parent.right
            anchors.top: parent.top
            width: parent.width / 2 - subMenuWidth
            height: parent.height / 2
            windowName: "Tactical map"

            Image {
                id: imageNav
                source: "qrc:/qml/svg/navigation.svg"
                anchors.centerIn: parent
                width: Screen.pixelDensity * 10
                height: Screen.pixelDensity * 10
            }
        }

        SubScreen {
            id: sensorsWindow
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            width: parent.width / 2 - subMenuWidth
            height: parent.height / 2
            windowName: "Telemetry"
            TelemetryView {
                anchors.fill: parent
            }
        }
        SubScreen {
            id: controlsWindow
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            width: parent.width / 2 - subMenuWidth
            height: parent.height / 2
            windowName: "Controls"
            ControlWindow {
                anchors.fill: parent
            }
        }

        MainMenu {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
        }
        ConnectData {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
        }
    }
}
