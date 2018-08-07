import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle{
    id: button
    property alias text: label.text
    border.color: "yellow"
    border.width: 2
    width: label.implicitWidth+Screen.pixelDensity *2
    height: Screen.pixelDensity*10
    color: "grey"
    signal click()
    Text{
        id: label
        anchors.centerIn: parent
        font.pixelSize: parent.height/2.5
    }
    MouseArea{
        anchors.fill: parent
        onClicked:{ parent.click() }
        hoverEnabled: true
        onHoveredChanged: {
            button.color= (containsMouse ? "lightgrey": "grey")
        }
    onReleased: {
        button.color = "lightgrey"
    }
    onPressed: {
        button.color = "lightyellow"
    }

    }
}

