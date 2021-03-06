import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Lab work")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Task1Page {
        }

        Task2 {
        }

        Task3 {
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        Repeater {
            model: ["Первое задание", "Второе задание", "Третье задание"]
            delegate: TabButton {
                text: qsTr(modelData)
            }
        }
    }
}
