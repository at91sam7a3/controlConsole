import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle {
    property int value: 0
    property int minValue: -125
    property int maxValue: 125

    color: "grey"
    border.width: 1
    border.color: "lightBlue"
    height:Screen.pixelDensity*5
    Rectangle{
        color: "blue"
        anchors.left: parent.left
        anchors.top:parent.top
        anchors.bottom: parent.bottom
        width: parent.width*((value-minValue)/(maxValue-minValue))
    }
    signal update()
    MouseArea{
        anchors.fill: parent
        onClicked: {
            value=(mouseX/width)*(maxValue-minValue)+minValue
            parent.update()
        }
    }

}

