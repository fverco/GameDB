import QtQuick 2.15
import QtQuick.Controls 2.14
import Qt.labs.platform 1.1
import "../scripts/GameLogic.js" as Logic

Window {
    id: gameForm
    width: 400
    height: 600
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    color: "black"
    title: "Add Game"
    Component.onCompleted: Logic.poplulateComboBoxes()

    Column {
        id: column
        anchors.fill: parent
        leftPadding: 10
        topPadding: 10

        // Name row.
        // Note: Every visual value in this nameRow is copied to the other rows.
        Row {
            height: parent.height / 12
            width: parent.width - 10
            spacing: 10
            id: nameRow

            Label {
                width: parent.width / 4
                text: "Name: "
                id: nameLbl
            }

            TextField {
                width: parent.width * 3/4 - 20
                id: nameField
                selectByMouse: true
            }
        }

        // Platform row.
        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Platform: "
            }

            ComboBox {
                id: platBox
                width: nameField.width
                textRole: "name"
                valueRole: "id"
                model: ListModel {
                            id: platBoxModel
                       }
            }
        }

        // Service row.
        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Service: "
            }

            ComboBox {
                id: servBox
                width: nameField.width
                textRole: "name"
                valueRole: "id"
                model: ListModel {
                            id: servBoxModel
                       }
            }
        }

        // Developer row.
        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Developer: "
            }

            ComboBox {
                id: devBox
                width: nameField.width
                textRole: "name"
                valueRole: "id"
                model: ListModel {
                            id: devBoxModel
                       }
            }
        }

        // Publisher row.
        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Publisher: "
            }

            ComboBox {
                id: pubBox
                width: nameField.width
                textRole: "name"
                valueRole: "id"
                model: ListModel {
                            id: pubBoxModel
                       }
            }
        }

        // Edition row.
        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Edition: "
            }

            TextField {
                width: nameField.width
                id: editionField
                selectByMouse: true
            }
        }

        // Exclusive row.
        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Exclusive: "
            }

            CheckBox {
                id: exclusiveCheck
            }
        }

        // Expansion row.
        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Expansion: "
            }

            CheckBox {
                id: expansionCheck
            }
        }

        // Physical copy row.
        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Physical Copy: "
            }

            CheckBox {
                id: physicalCheck
            }
        }

        // Release date row.
        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Release Date: "
            }

            TextField {
                id: yearField
                placeholderText: "YYYY"
                width: 60
                onTextChanged: if (length > 4) remove(4, length);
                selectByMouse: true
                validator: IntValidator {bottom: 1900; top: 2100}
            }

            Label {
                text: " / "
            }

            TextField {
                id: monthField
                placeholderText: "MM"
                width: 50
                onTextChanged: if (length > 2) remove(2, length);
                selectByMouse: true
                validator: IntValidator {bottom: 1; top: 12}
                Keys.onPressed: if (event.key === Qt.Key_Backspace && text.length === 0) {
                                    yearField.focus = true;
                                }
            }

            Label {
                text: " / "
            }

            TextField {
                id: dayField
                placeholderText: "DD"
                width: 50
                onTextChanged: if (length > 2) remove(2, length);
                selectByMouse: true
                validator: IntValidator {bottom: 1; top: 31}
                Keys.onPressed: if (event.key === Qt.Key_Backspace && text.length === 0) {
                                    monthField.focus = true;
                                }
            }
        }

        // Cover image row.
        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                text: "Cover Image: "
            }

            TextField {
                id: coverField
                width: nameLbl.width * 1.8
                selectByMouse: true
                readOnly: true
            }

            Button {
                id: btnImg
                text: "Add Image"
                onClicked: fileDialog.open();
            }
        }

        // Add/cancel row.
        Row {
            height: nameRow.height
            layoutDirection: Qt.RightToLeft
            width: nameRow.width - 10
            spacing: nameRow.spacing

            Button {
                id: btnCancel
                text: "Cancel"
                onClicked: gameForm.close();
            }

            Button {
                id: btnAdd
                text: "Add"
                onClicked: Logic.addNewGame();
            }
        }
    }

    FileDialog {
        id: fileDialog
        folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
        nameFilters: ["Image files (*.jpeg *.jpg *.png *.bmp)"]
        fileMode: FileDialog.OpenFile
        options: FileDialog.ReadOnly
        onAccepted: {
                let filePath = file.toString();
                // remove the prefixed "file:///"
                filePath = filePath.replace(/^(file:\/{3})/,"");
                coverField.text = filePath;
            }
    }

    MessageDialog {
        id: messageDialog
        buttons: MessageDialog.Ok
        text: "NULL"
        onAccepted: if (closeWindow) gameForm.close();

        property bool closeWindow: false;
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
