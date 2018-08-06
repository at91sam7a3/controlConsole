import QtQuick 2.0
import QtQuick.Window 2.2
Rectangle{
    property string parameterText: null
    property string valueText: null
    property int defaultMargin: Screen.pixelDensity*2
    property int defaultWidth: Screen.pixelDensity*40
            color:"blue"
            width:defaultWidth
            height: Screen.pixelDensity*10
            Item{
                anchors.leftMargin: defaultMargin
                id: parameter
                height: parent.height
                width:parent.width/2
                Text {
                    text: parameterText
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
                    text: valueText
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter

                }

            }

        }
