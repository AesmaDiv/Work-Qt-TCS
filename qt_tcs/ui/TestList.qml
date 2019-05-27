import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Controls 2.5

Rectangle {
    signal onEvent(string message)

//    property ListModel testListModel: ListModel{}

    id: root
    width: 340
    height: 510
    color: "#555555"

    TextField {
        id: txtFilter
        objectName: "txtFilter"
        height: 24
        text: qsTr("Input filter")
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.right: btnFilter.left
        anchors.rightMargin: 8
        padding: 0
        selectByMouse: true
    }
    Button {
        id: btnFilter
        objectName: "btnFilter"
        x: 258
        width: 24
        height: 24
        text: qsTr("")
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
        rightPadding: 0
        leftPadding: 0
        padding: 3
        icon.name: "filter"
        icon.source: "qrc:/images/magnifier.png"
        display: AbstractButton.IconOnly

        onClicked: onEvent("TestList:Filter:" + txtFilter.text)
    }

    ListView {
        id: testListView
        objectName: "testListView"
        anchors.margins: 5
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: btnNewRecord.top
        anchors.top: txtFilter.bottom
        model: testListModel
        delegate: TestListRow {
            MouseArea {
                anchors.fill: parent
                onDoubleClicked: onEvent("TestList:ItemSelected:" + modelData.record)
            }
        }
    }

    Button {
        id: btnNewRecord
        height: 24
        text: "новая запись"
        display: AbstractButton.TextOnly
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5

        onClicked: {
            onEvent("TestList:NewTest:")
            tcsInfo.setCurrentDateTime()
        }
    }
}





/*##^## Designer {
    D{i:3;anchors_height:440;anchors_width:330;anchors_x:5;anchors_y:38}D{i:6;anchors_width:330}
}
 ##^##*/
