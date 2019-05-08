import QtQuick 2.12
import QtQuick.Controls 2.5

import vsdt.lab.work 1.0

Task3Form {
    id: root
    header: Label {
        text: qsTr("Третье задание")
        font.pointSize: Qt.application.font.pointSize * 2
        padding: 10
    }

    lastWord: task.lastWord

    Task3 {
        id: task
        inputText: root.inputText
    }
}
