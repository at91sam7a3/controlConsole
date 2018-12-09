import QtQuick 2.0
import QtQuick.Window 2.2


Rectangle{
    id: button
    property alias icon: image.source
    property alias iconRotation: image.rotation
    property alias iconMirror: image.mirror
    border.color: "yellow"
    border.width: 2
    width: Screen.pixelDensity*10
    height: Screen.pixelDensity*10
    color: "grey"
    signal click()
    Image {
        anchors.fill: parent
        anchors.topMargin: 5
        anchors.bottomMargin: 5
        anchors.leftMargin: 5
        anchors.rightMargin: 5
        id: image
        source: "qrc:/qml/svg/screenshot.svg"
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

