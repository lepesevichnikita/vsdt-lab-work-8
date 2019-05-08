import QtQuick 2.12
import QtQuick.Controls 2.5

import vsdt.lab.work 1.0

Task2Page {
    id: root
    isInputTextCorrect: task.isInputTextCorrect

    Task2 {
        id: task
        inputText: root.inputText
        onIsInputTextCorrectChanged: print(isInputTextCorrect)
        isInputTextCorrect: true
    }
}
