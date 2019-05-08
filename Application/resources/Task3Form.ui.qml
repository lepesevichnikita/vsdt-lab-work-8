import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3

Page {
    width: 400
    height: 400
    property string inputText: ""
    property string lastWord: ""

    GridLayout {
        anchors.fill: parent
        anchors.margins: 20
        rows: 2

        Label {
            font.pointSize: 11
            text: qsTr("Текст")
        }
        TextField {
            Layout.fillHeight: true
            Layout.fillWidth: true
            placeholderText: qsTr("Введите текст")
            onEditingFinished: inputText = text
        }
    }
    MessageDialog {
        id: lastWordDialog
        visible: false
        standardButtons: StandardButton.Ok
        informativeText: qsTr("Последнее слово найдено")
        detailedText: lastWord
    }

    states: [
        State {
            name: "hasLastWord"
            when: lastWord.length > 0
            PropertyChanges {
                target: lastWordDialog
                visible: true
            }
        }
    ]
}
