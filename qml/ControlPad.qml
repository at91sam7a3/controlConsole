import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle{
    width: Screen.width/4
    height: Screen.height*0.75
    property int defaultMargin: Screen.pixelDensity*2
    border.width: 2
    border.color: "yellow"
    color: "blue"
    visible: client.connected

    InputField{
        id: stepsCount
        anchors.right: parent.right
        anchors.verticalCenter: backButton.verticalCenter
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
        onClick: {
            client.stepForward(stepsCount.value);
        }
    }

    Button{
        id: leftButton
        anchors.top: forwardButton.bottom
        anchors.right: forwardButton.left
        anchors.topMargin: defaultMargin
        text: "Left"
        onClick: {
            client.stepLeft(stepsCount.value);
        }
    }

    Button{
        id: rightButton
        anchors.top: forwardButton.bottom
        anchors.left: forwardButton.right
        anchors.topMargin: defaultMargin
        text: "Right"
        onClick: {
            client.stepRight(stepsCount.value);
        }
    }
    Button{
        id: backButton
        anchors.top: rightButton.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: defaultMargin
        text: "Back"

        onClick: {
            client.stepBackward(stepsCount.value);
        }
    }

    Column{
        id: servoBlock
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
            id: servoIdString
            width: parent.width
            value: "0"
        }
        Label{
            text: "Angle"
        }
        InputField{
            id: servoAngleLString
            width: parent.width
            value: "0"
        }
        Button{
            id: setAngleButton
            text: "Set"
            width: parent.width
            onClick: {
               client.setAngle(servoIdString.value,servoAngleLString.value)
            }
        }
    }

    property int selectedLeg: 0
    Touchpad{
        id: touchpad
        anchors.left: parent.left
        anchors.leftMargin: defaultMargin
        anchors.bottomMargin: defaultMargin
        anchors.bottom: heightControl.top
        width: Screen.pixelDensity*50
        height: Screen.pixelDensity*50
        onXValueChanged: {
            client.setXY(selectedLeg,xValue,yValue)
        }
        onYValueChanged: {
            client.setXY(selectedLeg,xValue,yValue)
        }
    }

    Column{
        anchors.left: touchpad.right
        anchors.top: touchpad.top
        anchors.right: parent.right
        anchors.leftMargin: defaultMargin
        anchors.rightMargin: defaultMargin
        spacing: defaultMargin

        Label{
            text: "Leg XY"
        }
        InputField{
            value: selectedLeg
            onValueChanged: selectedLeg=value
        }
        Label{
            text: "x = "+touchpad.xValue
        }
        Label{
            text: "y = "+touchpad.yValue
        }
        Button{
        id: buttonCenter
        text:" XY-Center"
        onClick: {
            touchpad.xValue=0
            touchpad.yValue=0
        }
        }
    }

    Rectangle{
        id: heightControl
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.leftMargin: defaultMargin
        anchors.rightMargin: defaultMargin
        anchors.bottomMargin: defaultMargin
        height:  Screen.pixelDensity*20
        color: "lightblue"
        border.color: "yellow"
        border.width: 1
        Label{
            id: distanceLabel
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: defaultMargin
            anchors.rightMargin: defaultMargin
            anchors.bottomMargin: defaultMargin
            anchors.topMargin: defaultMargin
            text: "From body to ground: " + heightSlider.value
        }
        HorizontalSlider{
            id: heightSlider
            minValue: 40
            maxValue: 250
            value: 80
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.leftMargin: defaultMargin
            anchors.rightMargin: defaultMargin
            anchors.bottomMargin: defaultMargin
            onValueChanged: {
                client.setBodyHeight(value)
            }
        }
    }
}
