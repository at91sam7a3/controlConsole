import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle{

    property int defaultMargin: Screen.pixelDensity*2

    color: "blue"

    Column{
        id: moveCommands
        spacing: defaultMargin
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: defaultMargin*10
        anchors.margins: defaultMargin
        Label{
            id: label
            text: "Move to coordinates"
        }
        Row{
            Label{
                text: "X Coord,mm"
            }
            InputField{
                value: "0"
            }
        }
        Row{
            Label{
                text: "Y Coord,mm"
            }
            InputField{
                value: "0"
            }
        }
        Button{
            text: "Go"
        }
        Label{

            text: "Turn to angle"
        }
        Row{
            Label{
                text: "Angle,degree"
            }
            InputField{
                value: "0"
            }
        }
        Button{
            text: "Turn"
        }
    }
}
