import QtQuick 2.0

Item {
    id: root
    property alias windowName: windowlabel.text
    default property alias context: stack.children

    Rectangle{
        id: labelBorder
        anchors.horizontalCenter:  parent.horizontalCenter
        anchors.top: parent.top
        width: windowlabel.width+10
        height: windowlabel.height*2
        color: "blue"
        border.color: "green"
        border.width: 2
        z:2
        Label{
            id: windowlabel
            text: "empty text"
            anchors.centerIn: parent
        }
    }

    Rectangle{
        id: windowBorder
        anchors{
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            top: labelBorder.verticalCenter
        }
        anchors.margins: 10
        border.width: 2
        border.color: "Green"
        color: "transparent"
        Item{
            id: stack
            anchors.fill: parent
            anchors.margins: 10
        }
        z:1
    }
}
