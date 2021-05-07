import QtQuick 2.15
import QtQuick.Controls 2.15
import "./forms"
import "./components"
import "./scripts/MainLogic.js" as Logic

ApplicationWindow {
    id: window
    width: 800
    height: 600
    minimumWidth: 800
    minimumHeight: 600
    visible: true
    title: qsTr("GameDB")

    property GameForm gameFormInstance
    property PlatformForm platformFormInstance
    property SimpleEntryForm simpleEntryFormInstance

    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
                    stackView.pop()
                } else {
                    drawer.open()
                }
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.10
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Add Game")
                width: parent.width
                onClicked: {
                    drawer.close();
                    Logic.openWindow(Logic.WindowTypes.GameWindow);
                }
            }

            ItemDelegate {
                text: qsTr("Add Platform")
                width: parent.width
                onClicked: {
                    drawer.close();
                    Logic.openWindow(Logic.WindowTypes.PlatformWindow);
                }
            }

            ItemDelegate {
                text: qsTr("Add Service")
                width: parent.width
                onClicked: {
                    drawer.close();
                    Logic.openWindow(Logic.WindowTypes.ServiceWindow);
                }
            }

            ItemDelegate {
                text: qsTr("Add Developer")
                width: parent.width
                onClicked: {
                    drawer.close();
                    Logic.openWindow(Logic.WindowTypes.DeveloperWindow);
                }
            }

            ItemDelegate {
                text: qsTr("Add Publisher")
                width: parent.width
                onClicked: {
                    drawer.close();
                    Logic.openWindow(Logic.WindowTypes.PublisherWindow);
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "./forms/LibraryForm.ui.qml"
        anchors.fill: parent
    }
}
