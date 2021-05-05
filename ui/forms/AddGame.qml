import QtQuick 2.15
import QtQuick.Controls 2.14
import Qt.labs.platform 1.1

ApplicationWindow {
    width: 400
    height: 600
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    title: "Add Game"
    id: addGameWindow

    Column {
        id: column
        anchors.fill: parent
        leftPadding: 10
        topPadding: 10

        // Every visual value in this nameRow is copied to the other rows.
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

        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Platform: "
            }

            ComboBox {
                width: nameField.width
                id: platBox
            }
        }

        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Service: "
            }

            ComboBox {
                width: nameField.width
                id: servBox
            }
        }

        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Developer: "
            }

            ComboBox {
                width: nameField.width
                id: devBox
            }
        }

        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Publisher: "
            }

            ComboBox {
                width: nameField.width
                id: pubBox
            }
        }

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

        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
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

        Row {
            height: nameRow.height
            layoutDirection: Qt.RightToLeft
            width: nameRow.width - 10
            spacing: nameRow.spacing

            Button {
                id: btnCancel
                text: "Cancel"
                onClicked: addGameWindow.close();
            }

            Button {
                id: btnAdd
                text: "Add"
            }
        }
    }

    FileDialog {
        id: fileDialog
        folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
        nameFilters: ["Image files (*.jpeg *.jpg *.png *.gif *.bmp)"]
        fileMode: FileDialog.OpenFile
        options: FileDialog.ReadOnly
        onAccepted: coverField.text = file;
    }
}
