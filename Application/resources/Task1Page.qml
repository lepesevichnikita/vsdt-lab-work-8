import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import Qt.labs.platform 1.1

import vsdt.lab.work 1.0

Page {
    id: root
    title: "Первое задание"

    Task1 {
        id: task1
        outputFilePath: saveFileDialog.currentFile
    }

    FileDialog {
        id: saveFileDialog
        title: qsTr("Сохранить файл")
        acceptLabel: qsTr("Сохранить")
        defaultSuffix: ".txt"
        fileMode: FileDialog.SaveFile
        onAccepted: {
            task1.writeResultToFile()
        }
    }

    header: RowLayout {
        anchors.margins: 20
        Label {
            text: title
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.pointSize: 20
        }
        RowLayout {
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Button {
                id: saveButton
                text: qsTr("Сохранить")
                onClicked: {
                    saveFileDialog.open()
                }
            }
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
            text: task1.sourceText
            placeholderText: qsTr("Введите исходный текст")
            onEditingFinished: task1.sourceText = text
        }
        Label {
            font.pointSize: 11
            text: qsTr("Результат")
        }
        TextField {
            Layout.fillWidth: true
            placeholderText: qsTr("Результат")
            text: task1.resultText
            readOnly: true
            selectByMouse: true
        }
    }
}




/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
