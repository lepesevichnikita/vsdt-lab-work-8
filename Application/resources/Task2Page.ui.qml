import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3

Page {
    title: qsTr("Второе задание")
    width: 640
    height: 480

    property var headerItem: Label {
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    property string inputText: ""
    property bool isInputTextCorrect: true

    header: headerItem

    GridLayout {
        anchors.fill: parent
        anchors.margins: 20
        columns: 2

        Label {
            text: qsTr("Исходный текст")
        }
        TextField {
            Layout.fillWidth: true
            text: inputText
            placeholderText: qsTr("Введите текст для проверки")
            onEditingFinished: inputText = text
        }
    }
    Dialog {
        id: mistakesWindow
        visible: false
        modality: Qt.WindowModal
        standardButtons: StandardButton.Ok
        title: qsTr("В тексте содержатся ошибки")
        contentItem: Rectangle {
            Label {
                Layout.fillWidth: true
                text: qsTr("ЧА/ЩА пиши с буквой А")
            }
        }
    }
    states: [
        State {
            name: "hasMistakes"
            when: !isInputTextCorrect
            PropertyChanges {
                target: mistakesWindow
                visible: true
            }
        }
    ]
}
