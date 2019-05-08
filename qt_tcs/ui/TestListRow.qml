import QtQuick 2.0

Item {
    objectName: "row_"+index
    width: 330
    height: 26

    property color txt_color: mouseArea.containsMouse ? "black" : "white"

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: onItemClicked(parent.objectName)
    }
    Rectangle {
        anchors.fill: parent
        anchors.margins: 2
        color: "#AAAAAA"
        opacity: mouseArea.containsMouse ? 0.8 : 0
        radius: 3
    }
    Row {
        anchors.leftMargin: 5
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        spacing: 2
        Text {
            id: txtId
            width: 40
            objectName: "txtId"
            color: txt_color
            text: model.modelData.record
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 8
            font.family: "Verdana"
        }
        Text {
            id: txtDateTime
            width: 100
            objectName: "txtDateTime"
            color: txt_color
            text: model.modelData.dateTime
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 8
            font.family: "Verdana"
        }
        Text {
            id: txtOrder
            width: 80
            objectName: "txtOrder"
            color: txt_color
            text: model.modelData.order
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 8
            font.family: "Verdana"
        }
        Text {
            id: txtSerial
            width: 100
            objectName: "txtSerial"
            color: txt_color
            text: model.modelData.serial
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 8
            font.family: "Verdana"
        }
    }
}
