import QtQuick 2.12
import QtQuick.Controls 2.12
//import QtQuick.Controls.Styles 1.4

Row {
    property bool isCombo: true
    property bool isEditable: true

    property int headerAlignment: Text.AlignLeft
    property int valueAlignment: Text.AlignLeft

    property int width_value: 210
    property int width_popup: width_value

    property string header: "Заголовок"
    property string value: "значение"
    property alias current_index: cmbValues.currentIndex
    property alias current_text: cmbValues.displayText
    property variant values: []

    function reload() {
        var index = cmbValues.currentIndex
        var str = ""
        var width = 0
        var model = []
        values.forEach(function (item, i, values) {
            str = values[i].toString();
            width = str.length * 8;
            if (width > width_popup) width_popup = width;
            model.push({ display_text: values[i] });
        })
        cmbValues.model = model
        cmbValues.currentIndex = index
    }

    onValuesChanged: reload()

    id: root
    width: 415
    height: 24
    spacing: 5
    Text {
        id: txtHeader
        text: qsTr(header)
        horizontalAlignment: headerAlignment
        anchors.right: rectValue.left
        anchors.rightMargin: 10
        anchors.left: root.left
        anchors.leftMargin: 5
        anchors.verticalCenter: root.verticalCenter
        font.pixelSize: 12
    }
    Rectangle {
        id: rectValue
        width: width_value
        height: 24
        anchors.right: root.right
        anchors.rightMargin: 0
        clip: true
        color: isEditable ? "#777777" : "#333333"
        radius: 3
        TextInput {
            id: txtValue
            text: qsTr(value)
            leftPadding: 5
            topPadding: 4
            anchors.verticalCenter: parent.verticalCenter
            anchors.fill: parent
            selectionColor: "#000000"
            selectByMouse: true
            font.pixelSize: 12
            horizontalAlignment: valueAlignment
            visible: !isCombo
            enabled: isEditable
            color: "white"
        }
        ComboBox {
            id: cmbValues
            objectName: "cmbValues"
            height: 24
            wheelEnabled: true
            visible: isCombo
            anchors.fill: rectValue
            editable: isEditable
            textRole: "display_text"
            delegate: ItemDelegate {
                width: width_popup - 2
                height: 24
                highlighted: cmbValues.highlightedIndex === index
                background: Rectangle {
                    color: highlighted ? "#AAAAAA" : "444444"
                }
                contentItem: Text {
                    leftPadding: -7
                    text: model.modelData.display_text
                    color: highlighted ? "black" : "white"
                    verticalAlignment: Text.AlignVCenter
                }
            }
            popup: Popup {
                id: pop
                y: cmbValues.height - 1
                width: width_popup
                implicitHeight: contentItem.implicitHeight
                padding: 1
                background: Rectangle {
                    color: "#444444"
                    border.color: "white"
                    border.width: 1
                    radius: 2
                    width: width_popup
                    height: pop.height + 2
                }
                contentItem: ListView {
                    implicitHeight: contentHeight
                    model: cmbValues.popup.visible ? cmbValues.delegateModel : null
                    currentIndex: cmbValues.highlightedIndex
                }
            }
            indicator: Canvas {
                id: canvas
                x: cmbValues.width - 17
                y: cmbValues.height / 2 - 4
                width: 16
                height: 8
                contextType: "2d"
                Connections {
                    target: cmbValues
                    onPressedChanged: canvas.requestPaint()
                }
                onPaint: {
                    context.reset();
                    context.moveTo(width / 3, 0);
                    context.lineTo(2 * width / 3, 0);
                    context.lineTo(width / 2, height);
                    context.closePath();
                    context.fillStyle = "#333333";
                    context.fill();
                }
            }
            contentItem: Text {
                leftPadding: 5
                text: cmbValues.displayText
                font: cmbValues.font
                color: cmbValues.pressed ? "blue" : "black"
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }
//            onCurrentTextChanged:
        }
    }
}

