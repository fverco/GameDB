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

    property GameForm gameFormInstance
    property PlatformForm platformFormInstance

    function openGameFormWindow() {
        if (!gameFormInstance) {
            var gameFormComponent = Qt.createComponent("./forms/GameForm.qml");
            gameFormInstance = gameFormComponent.createObject(window);
            gameFormInstance.showNormal();
        } else {
            if (gameFormInstance.visibility === 3 || gameFormInstance.visibility === 0) {
                gameFormInstance.showNormal();
            }
            gameFormInstance.requestActivate();
        }
    }

    function openPlatformFormWindow() {
        if (!platformFormInstance) {
            var platformFormComponent = Qt.createComponent("./forms/PlatformForm.qml");
            platformFormInstance = platformFormComponent.createObject(window);
            platformFormInstance.showNormal();
        } else {
            if (platformFormInstance.visibility === 3 || platformFormInstance.visibility === 0) {
                platformFormInstance.showNormal();
            }
            platformFormInstance.requestActivate();
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
                    drawer.close();
                    openGameFormWindow();
                }
            }

            ItemDelegate {
                text: qsTr("Add Platform")
                width: parent.width
                onClicked: {
                    drawer.close();
                    openPlatformFormWindow();
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
