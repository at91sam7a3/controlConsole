import QtQuick 2.0
import QtQuick.Window 2.2

Item {
    property int defaultMargin: Screen.pixelDensity * 2
    property int menuWidth: Screen.pixelDensity * 45
    property int menuHeight: Screen.pixelDensity * 20
    GridView {
        width: parent.width
        height: parent.height
        cellHeight: menuHeight + 5
        cellWidth: menuWidth + 5
        model: teleCon
        delegate: Rectangle {
            height: menuHeight
            width: menuWidth
            color: model.color
            Label {
                text: model.name
                anchors.horizontalCenter: parent.Center
                anchors.top: parent.top
                anchors.topMargin: defaultMargin
            }
            Text {
                id: value
                text: model.value
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                height: parent.height / 3
                font.pixelSize: height
            }
            Label {
                id: units
                text: model.units
                anchors.bottom: value.bottom
                anchors.left: value.right
                width: undefined
                height: parent.height / 4
            }
        }
    }
}
