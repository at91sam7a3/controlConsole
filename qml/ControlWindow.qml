import QtQuick 2.0
import QtQuick.Window 2.2

Item {
    property int defaultMargin: Screen.pixelDensity * 2
    property int menuWidth: Screen.pixelDensity * 25
    property int selectedTab: 1
    Column {
        width: menuWidth
        id: controlsMenu
        spacing: defaultMargin
        Button {
            text: "Manual"
            width: parent.width
            onClick: selectedTab = 1
            border.width: selectedTab == 1 ? 4 : 2
        }
        Button {
            text: "Semi-Auto"
            width: parent.width
            onClick: selectedTab = 2
            border.width: selectedTab == 2 ? 4 : 2
        }
        Button {
            text: "Auto"
            width: parent.width
            onClick: selectedTab = 3
            border.width: selectedTab == 3 ? 4 : 2
        }
    }

    ControlPad {
        visible: selectedTab == 1
        anchors.left: controlsMenu.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
    }

    SemiAuto {
        visible: selectedTab == 2
        anchors.left: controlsMenu.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
    }
}
