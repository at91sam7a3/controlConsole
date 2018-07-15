import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle {
    property int value: 0
    property int minValue: -125
    property int maxValue: 125

    color: "grey"
    border.width: 1
    border.color: "lightBlue"
    height:Screen.pixelDensity*10
    Rectangle{
        color: "blue"
        anchors.left: parent.left
        anchors.top:parent.top
        anchors.bottom: parent.bottom
        width: parent.width*((value+125)/250)
    }
    signal update()
    MouseArea{
        anchors.fill: parent
        onClicked: {
            value=(mouseX/width-0.5)*250
            parent.update()
            console.log("width ",width, " mouseX ",mouseX," value ",value)
        }
    }

}

