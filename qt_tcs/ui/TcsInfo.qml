import QtQuick 2.0
import QtQuick.Controls 1.5
import QtQuick.Controls 2.5

Item {
    property int df_text_width: 290
    property int df_combo_width: 400
    property int text_width: 120
    property int combo_width: 280

    property bool is_adding: false

    id: root
    width: 420
    height: 420

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
                width_value: 155
                header: "Дата/время:"
                value: "1979.09.14 01:00"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: false
            }
            DataField {
                id: dfOrder
                objectName: "dfOrder"
                width: df_text_width - 16
                anchors.left: parent.left
                anchors.leftMargin: 0
                width_value: 155
                header: "Наряд-заказ:"
                value: "1122334455"
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
                width_value: combo_width
                header: "Заказчик:"
                value: "Лукойл ЗС"
                headerAlignment: Text.AlignRight
                isCombo: true
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
                width_value: combo_width
                header: "Производитель:"
                value: "ООО \"ИРЗ\""
                headerAlignment: Text.AlignRight
                isCombo: true
                isEditable: false
            }
            DataField {
                id: dfStationType
                objectName: "dfStationType"
                width: df_combo_width
                anchors.left: parent.left
                anchors.leftMargin: 0
                width_value: combo_width
                header: "Тип:"
                value: "ИРЗ-500-12-БП"
                headerAlignment: Text.AlignRight
                isCombo: true
                isEditable: false
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
                width_value: text_width
                anchors.right: parent.right
                anchors.rightMargin: 10
                header: "Номинал I,А:"
                value: "150"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: is_adding
            }
            DataField {
                id: dfPnom
                objectName: "dfPnom"
                width: df_text_width
                width_value: text_width
                anchors.right: parent.right
                anchors.rightMargin: 10
                header: "Номинал P,кВт:"
                value: "420"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: is_adding
            }
            DataField {
                id: dfImax
                objectName: "dfImax"
                width: df_text_width
                width_value: text_width
                anchors.right: parent.right
                anchors.rightMargin: 10
                header: "Максимальный I,А:"
                value: "150"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: is_adding
            }
            DataField {
                id: dfUsec
                objectName: "dfUsec"
                width: df_text_width
                width_value: text_width
                anchors.right: parent.right
                anchors.rightMargin: 10
                header: "Втор.обмотка U,В:"
                value: "950"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: is_adding
            }
            DataField {
                id: dfMaxRPM
                objectName: "dfMaxRPM"
                width: df_text_width
                width_value: text_width
                anchors.right: parent.right
                anchors.rightMargin: 10
                header: "Макс.скорость,об/мин:"
                value: "500"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: is_adding
            }
            DataField {
                id: dfMinRPM
                objectName: "dfMinRPM"
                width: df_text_width
                width_value: text_width
                anchors.right: parent.right
                anchors.rightMargin: 10
                header: "Мин.скорость,об/мин:"
                value: "3000"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: is_adding
            }
            Button {
                width: text_width
                height: 24
                text: "добавить тип"
                anchors.right: parent.right
                anchors.rightMargin: 10

                onClicked: is_adding = !is_adding
            }
        }
    }



}







/*##^## Designer {
    D{i:2;anchors_width:410}
}
 ##^##*/
