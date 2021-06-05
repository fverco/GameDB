import QtQuick 2.15
import QtQuick.Controls 2.15
import Qt.labs.platform 1.1
import "../components"

Page {
    id: libraryPage
    title: qsTr("Library")

    property alias gameGrid: gameGrid
    property alias messageDialog: messageDialog

    GridView {
        id: gameGrid
        implicitWidth: parent.width
        implicitHeight: parent.height
        //clip: true

        cellWidth: 220
        cellHeight: 300

        model: gameListModel
        delegate: GameCase {
            label: model.gameName
            coverPath: model.gameCover
        }

        topMargin: 20
        bottomMargin: topMargin
        leftMargin: topMargin
        rightMargin: topMargin
    }

    MessageDialog {
        id: messageDialog
        buttons: MessageDialog.Ok
        text: "NULL"
        onAccepted: if (closeWindow) Qt.quit;

        property bool closeWindow: false;
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
