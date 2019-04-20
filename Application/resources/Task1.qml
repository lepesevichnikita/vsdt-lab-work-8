import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Page {
    id: root
    title: qsTr("Первое задание")

    header: RowLayout {
        Label {
            text: title
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.pointSize: 20
        }
        Button {
            id: saveButton
            Layout.margins: 20
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            text: qsTr("Сохранить")
        }
    }

    GridLayout {
        id: taskForm
        anchors.fill: parent
        anchors.margins: 20
        columns: 1

        Label {
            font.pointSize: 11
            text: qsTr("Исходный текст")
        }
        TextField {
            Layout.fillWidth: true
            placeholderText: qsTr("Введите исходный текст")
        }
        Label {
            font.pointSize: 11
            text: qsTr("Результат")
        }
        TextField {
            Layout.fillWidth: true
            placeholderText: qsTr("Результат")
            readOnly: true
            selectByMouse: true
        }
    }
}
