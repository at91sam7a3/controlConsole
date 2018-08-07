import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle{
    width: Screen.width/4
    height: Screen.height/4
    property int defaultMargin: Screen.pixelDensity*2
    border.width: 2
    border.color: "yellow"
    color: "blue"

    InputField{
        id: stepsCount
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.leftMargin: defaultMargin
        anchors.rightMargin: defaultMargin
        anchors.bottomMargin: defaultMargin
        value: "1"
    }

    Label{
        id: label
        text: "Direct control"
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: defaultMargin
    }
    Button{
        id: forwardButton
        anchors.top: label.bottom
        anchors.horizontalCenter: label.horizontalCenter
        anchors.topMargin: defaultMargin
        text: "Forward"
    }

    Button{
        id: leftButton
        anchors.top: forwardButton.bottom
        anchors.right: forwardButton.left
        anchors.topMargin: defaultMargin
        text: "Left"
    }

    Button{
        id: rightButton
        anchors.top: forwardButton.bottom
        anchors.left: forwardButton.right
        anchors.topMargin: defaultMargin
        text: "Right"
    }
    Button{
        id: backButton
        anchors.top: rightButton.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: defaultMargin
        text: "Back"
    }

    Column{
        spacing: defaultMargin
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: leftButton.left
        anchors.margins: defaultMargin
        Label{
            text: "Servo#"
        }
        InputField{
            width: parent.width
            value: "0"
        }
        Label{
            text: "Angle"
        }
        InputField{
            width: parent.width
            value: "0"
        }
        Button{
            id: setAngleButton
            text: "Set"
            width: parent.width
        }
    }
}
