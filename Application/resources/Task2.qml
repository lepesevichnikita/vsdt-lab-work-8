import QtQuick 2.12
import QtQuick.Controls 2.5

import vsdt.lab.work 1.0

Task2Page {
    id: root
    isInputTextCorrect: task.isInputTextCorrect

    header: Label {
        text: qsTr("Второе задание")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Task2 {
        id: task
        inputText: root.inputText
        isInputTextCorrect: true
    }
}
