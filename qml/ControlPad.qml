import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle{

    property int defaultMargin: Screen.pixelDensity*2

    color: "blue"

    Column{
        id: moveCommands
        spacing: defaultMargin
        anchors.left: parent.horizontalCenter
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: defaultMargin*10
        anchors.margins: defaultMargin
        Label{
            id: label
            text: "Move control"
        }
        ButtonWithIcon{
            id: forwardButton
            icon: "qrc:/qml/svg/arrow-up.svg"
            onClick: {
                client.stepForward(stepsCount.value);
            }
        }
        Row{
            spacing: defaultMargin
            ButtonWithIcon{
                id: leftButton
                icon: "qrc:/qml/svg/rot-left.svg"
                onClick: {
                    client.stepLeft(stepsCount.value);
                }
            }

            ButtonWithIcon{
                id: rightButton
                icon: "qrc:/qml/svg/rot-left.svg"
                iconMirror: true
                onClick: {
                    client.stepRight(stepsCount.value);
                }
            }
        }
        ButtonWithIcon{
            id: backButton
            icon: "qrc:/qml/svg/arrow-up.svg"
            iconRotation: 180

            onClick: {
                client.stepBackward(stepsCount.value);
            }
        }
        InputField{
            id: stepsCount
            value: "1"
        }
    }




    Column{
        id: servoBlock
        spacing: defaultMargin
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: defaultMargin*10
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
/*
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
    */
/*
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
    }*/
}
