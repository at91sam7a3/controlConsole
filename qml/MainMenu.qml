import QtQuick 2.0
import QtQuick.Window 2.2
Rectangle {
    property int defaultMargin: Screen.pixelDensity*2
    property int defaultWidth: Screen.pixelDensity*80
    width: defaultWidth
    height: Screen.pixelDensity*15
    color: "blue"

    border.color: "yellow"
    border.width: 2

    Row{
        id: buttonsRow
        anchors.fill: parent
        spacing: defaultMargin
        anchors.bottomMargin: defaultMargin
        anchors.topMargin: defaultMargin
        anchors.leftMargin: defaultMargin
    Button{
        text: "Direct control"
    }
    Button{
        text: "Program"
    }
    Button{
        text: "Video"
        onClick: {
            client.runVideo()
        }
    }


}
}
