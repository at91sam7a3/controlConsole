import QtQuick 2.0
import QtQuick.Window 2.2
Column {
    property int defaultMargin: Screen.pixelDensity*2
    property int defaultWidth: Screen.pixelDensity*40
    width: defaultWidth
    height: Screen.pixelDensity*40
    anchors.leftMargin: defaultMargin
    Repeater{
        model: ["Voltage","Temperature","Altitude" ,"Distance"]
        delegate: Rectangle{
            color:"blue"
            width:defaultWidth
            height: Screen.pixelDensity*10
            Item{
                anchors.leftMargin: defaultMargin
                id: parameter
                height: parent.height
                width:parent.width/2
                Text {
                    id: parameterText
                    text: modelData
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.leftMargin: defaultMargin
                }

            }
            Item{
                id: value
                height: parent.height
                width:parent.width/2
                anchors.right: parent.right
                Text {
                    id: valueText
                    text: "???"
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                }

            }

        }
    }
}
