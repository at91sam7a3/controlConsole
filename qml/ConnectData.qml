import QtQuick 2.0
import QtQuick.Window 2.2


Rectangle {
    property int defaultMargin: Screen.pixelDensity*2
    property int defaultWidth: Screen.pixelDensity*80
    width: defaultWidth
    height: Screen.pixelDensity*20
    color: "blue"
    border.color: "yellow"
    border.width: 2
    Label{
        anchors.topMargin: defaultMargin
        anchors.top:parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        text:"Enter Robot`s IP"
    }
    InputField{
        id:inputIpField
        anchors.bottomMargin: defaultMargin
        anchors.leftMargin: defaultMargin
        width:defaultMargin*24
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        value: "192.168.0.129"
    }
    Button{
        anchors.bottomMargin: defaultMargin
        anchors.rightMargin: defaultMargin
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        text: "Connect"
        onClick: {
            sData.connect("tcp://"+inputIpField.value+":5555")
        }
    }



}

