import QtQuick 2.0
import QtQuick.Window 2.2

Item {
    property int defaultMargin: Screen.pixelDensity*2
    property int menuWidth: Screen.pixelDensity*25
    Column{
        width: menuWidth
        id: controlsMenu
        spacing: defaultMargin
        Button{
            text: "Manual"
            width: parent.width
        }
        Button{
            text: "Semi-Auto"
            width: parent.width
        }
        Button{
            text: "Auto"
            width: parent.width
        }

    }

    ControlPad{
        visible: false
        anchors.left: controlsMenu.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
    }

    SemiAuto{
        anchors.left: controlsMenu.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
    }
}
