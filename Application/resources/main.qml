import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tab")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Task1 {
        }

        Task2  {
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
