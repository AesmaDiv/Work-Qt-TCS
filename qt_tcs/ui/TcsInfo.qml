import QtQuick 2.0
import QtQuick.Controls 1.5
import QtQuick.Controls 2.5

Item {
    property int df_text_width: 290
    property int df_combo_width: 400
    property int text_width: 120
    property int combo_width: 280

    property bool is_adding: false
    property bool is_editable: false
    property bool is_event_enabled: true


    id: root
    width: 420
    height: 420

    signal onEvent(string message)
    signal onComboItemSelected(variant item)

    function sendCurrentItem(item_type, selected_item) {
        if (is_event_enabled) {
            var result = ["TcsInfo", item_type, selected_item[0], selected_item[1]]
            onComboItemSelected(result)
        }
    }
    function setCurrentDateTime() {
        var date = new Date(Date.now())
        var y = date.getFullYear()
        var m = date.getMonth()
        var d = date.getDate()
        var dateString = [y,m,d].join('-')
        dfDateTime.value = dateString
    }


    Rectangle {
        id: rectangle
        anchors.fill: parent
        anchors.margins: 5
        color: "#555555"
        Column {
            id: column
            anchors.topMargin: 5
            anchors.fill: parent
            spacing: 4
            DataField {
                id: dfDateTime
                objectName: "dfDateTime"
                width: df_text_width - 16
                anchors.left: parent.left
                anchors.leftMargin: 0
                widthValue: 155
                header: "Дата/время:"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: false
            }
            DataField {
                id: dfOrderNum
                objectName: "dfOrderNum"
                width: df_text_width - 16
                anchors.left: parent.left
                anchors.leftMargin: 0
                widthValue: 155
                header: "Наряд-заказ:"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: is_editable
            }
            DataField {
                id: dfSerialNum
                objectName: "dfSerialNum"
                width: df_text_width - 16
                anchors.left: parent.left
                anchors.leftMargin: 0
                widthValue: 155
                header: "Заводской №:"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: false
            }
            DataField {
                id: dfCustomer
                objectName: "dfCustomer"
                width: df_combo_width
                anchors.left: parent.left
                anchors.leftMargin: 0
                widthValue: combo_width
                header: "Заказчик:"
                headerAlignment: Text.AlignRight
                isCombo: true
                isEditable: false
                onCurrentIndexChanged: {
                    //sendCurrentItem("Customer", values[currentIndex])
                    currentText = values[currentIndex][1].toString()
                }
            }
            ToolSeparator {
                width: root.width - 20
                height: 13
                anchors.horizontalCenter: parent.horizontalCenter
                orientation: Qt.Horizontal
            }
            DataField {
                id: dfProducer
                objectName: "dfProducer"
                width: df_combo_width
                anchors.left: parent.left
                anchors.leftMargin: 0
                widthValue: combo_width
                header: "Производитель:"
                headerAlignment: Text.AlignRight
                isCombo: true
                isEditable: false
                onCurrentIndexChanged:{
                    sendCurrentItem("Producer", values[currentIndex])
                    currentText = values[currentIndex][1].toString()
                }
            }
            DataField {
                id: dfStationType
                objectName: "dfStationType"
                width: df_combo_width
                anchors.left: parent.left
                anchors.leftMargin: 0
                widthValue: combo_width
                header: "Тип:"
                headerAlignment: Text.AlignRight
                isCombo: true
                isEditable: false
                onCurrentIndexChanged:{
                    sendCurrentItem("StationType", values[currentIndex])
                    currentText = values[currentIndex][1].toString()
                }
            }
            ToolSeparator {
                width: 415
                height: 5
                orientation: Qt.Horizontal
            }
            DataField {
                id: dfInom
                objectName: "dfInom"
                width: df_text_width
                widthValue: text_width
                anchors.right: parent.right
                anchors.rightMargin: 10
                header: "Номинал I,А:"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: is_adding
            }
            DataField {
                id: dfPnom
                objectName: "dfPnom"
                width: df_text_width
                widthValue: text_width
                anchors.right: parent.right
                anchors.rightMargin: 10
                header: "Номинал P,кВт:"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: is_adding
            }
            DataField {
                id: dfImax
                objectName: "dfImax"
                width: df_text_width
                widthValue: text_width
                anchors.right: parent.right
                anchors.rightMargin: 10
                header: "Максимальный I,А:"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: is_adding
            }
            DataField {
                id: dfUsec
                objectName: "dfUsec"
                width: df_text_width
                widthValue: text_width
                anchors.right: parent.right
                anchors.rightMargin: 10
                header: "Втор.обмотка U,В:"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: is_adding
            }
            DataField {
                id: dfMaxRPM
                objectName: "dfMaxRPM"
                width: df_text_width
                widthValue: text_width
                anchors.right: parent.right
                anchors.rightMargin: 10
                header: "Макс.скорость,об/мин:"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: is_adding
            }
            DataField {
                id: dfMinRPM
                objectName: "dfMinRPM"
                width: df_text_width
                widthValue: text_width
                anchors.right: parent.right
                anchors.rightMargin: 10
                header: "Мин.скорость,об/мин:"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: is_adding
            }            
        }
    }



}







/*##^## Designer {
    D{i:2;anchors_width:410}
}
 ##^##*/
