import QtQuick 2.15
import QtQuick.Controls 2.14
import Qt.labs.platform 1.1
import "../scripts/SimpleEntryLogic.js" as Logic
import "../scripts/WindowTypes.js" as Types

Window {
    width: 450
    height: 100
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    color: "black"
    title: if (entryType > -1 && entryType < Types.count()) {
                "Add " + Types.getType(entryType);
           } else {
                "Add Entry";
           }

    id: simpleEntryForm

    property int entryType;

    Column {
        id: column
        anchors.fill: parent
        leftPadding: 10
        topPadding: 10

        // Name row.
        // Note: Every visual value in this nameRow is copied to the other rows.
        Row {
            height: parent.height / 2
            width: parent.width / 2
            spacing: 10
            id: nameRow

            Label {
                width: parent.width / 2.8
                text: "Name: "
                id: nameLbl
            }

            TextField {
                width: parent.width * 1.5
                id: nameField
                selectByMouse: true
            }
        }

        // Add/cancel button row.
        Row {
            height: nameRow.height
            layoutDirection: Qt.RightToLeft
            width: nameRow.width * 1.9
            spacing: nameRow.spacing

            Button {
                id: btnCancel
                text: "Cancel"
                onClicked: simpleEntryForm.close();
            }

            Button {
                id: btnAdd
                text: "Add"
                onClicked: Logic.addNewEntry();
            }
        }
    }

    MessageDialog {
        id: messageDialog
        buttons: MessageDialog.Ok
        text: "NULL"
        onAccepted: if (closeWindow) simpleEntryForm.close();

        property bool closeWindow: false;
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
