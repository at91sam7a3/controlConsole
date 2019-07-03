import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle {
    property int defaultMargin: Screen.pixelDensity * 2
    property int defaultWidth: Screen.pixelDensity * 30
    width: defaultWidth
    height: parent.height
    color: "blue"
    id: root
    border.color: "yellow"
    border.width: 2

    Column {
        id: buttonsRow
        anchors.fill: parent
        spacing: defaultMargin
        anchors.bottomMargin: defaultMargin
        anchors.topMargin: defaultMargin
        anchors.leftMargin: defaultMargin
        Button {
            width: root.width - defaultMargin * 2
            text: "Video RGB"
            onClick: {
                client.runVideo()
            }
        }
        Button {
            width: root.width - defaultMargin * 2
            text: "Video Depth"
            onClick: {
                client.runVideo()
            }
        }
        Button {
            width: root.width - defaultMargin * 2
            text: "Video ArUco"
            onClick: {
                client.runVideo()
            }
        }
        ButtonWithIcon {
            onClick: {
                client.takeScreenshot()
            }
        }
        Button {
            width: root.width - defaultMargin * 2
            text: "Toggle Power"
            onClick: {
                client.runVideo()
            }
        }
    }
}
