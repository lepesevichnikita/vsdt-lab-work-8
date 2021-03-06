import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3

Page {
    title: qsTr("Второе задание")
    width: 640
    height: 480

    property string inputText: ""
    property bool isInputTextCorrect: true

    header: headerItem

    GridLayout {
        anchors.fill: parent
        anchors.margins: 20
        rows: 2

        Label {
            font.pointSize: 11
            text: qsTr("Текст")
        }
        TextField {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: inputText
            placeholderText: qsTr("Введите текст для проверки")
            onEditingFinished: inputText = text
        }
    }
    MessageDialog {
        id: mistakesWindow
        visible: false
        standardButtons: StandardButton.Ok
        informativeText: qsTr("В тексте содержатся ошибки")
        detailedText: qsTr("ЧА/ЩА пиши с буквой А")
        onAccepted: visible = false
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
