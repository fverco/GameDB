import QtQuick 2.15
import QtQuick.Controls 2.15
import "./forms"
import "./components"

ApplicationWindow {
    id: window
    width: 800
    height: 600
    minimumWidth: 800
    minimumHeight: 600
    visible: true
    title: qsTr("GameDB")

    property AddGame addGameInstance

    function openAddGameWindow() {
        if (!addGameInstance) {
            var addGameComponent = Qt.createComponent("./forms/AddGame.qml");
            addGameInstance = addGameComponent.createObject(window);
            addGameInstance.showNormal();
        } else {
            if (addGameInstance.visibility === 3 || addGameInstance.visibility === 0) {
                addGameInstance.showNormal();
            }
            addGameInstance.requestActivate();
        }
    }

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
//                    stackView.push("./forms/AddGameForm.ui.qml") // Trying something else.
                    drawer.close();
                    openAddGameWindow();
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
