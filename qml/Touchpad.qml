import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle {

    property int  xValue: 0;
    property int  yValue: 0;
    property int rangeSize: 50

    color:"gray"
    border.color: "red"
    border.width: 1


    Rectangle{
        id: pointer
        width: Screen.pixelDensity
        height: Screen.pixelDensity
        radius: Screen.pixelDensity/2
        x: parent.width / 2 + xValue*(parent.width / 2)/rangeSize
        y: parent.height / 2 + yValue*(parent.height / 2)/rangeSize
    }

    MouseArea{
        anchors.fill: parent
        onMouseXChanged: {
            xValue = (mouseX - width/2) / (width/2) * rangeSize
            yValue = (mouseY - height/2) / (height/2) * rangeSize
        }
    }
}
