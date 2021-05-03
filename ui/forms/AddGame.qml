import QtQuick 2.15
import QtQuick.Controls 2.14

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
                placeholderText: "YYYY"
                onTextChanged: if (length > 4) remove(4, length);
            }

            Label {
                text: " / "
            }

            TextField {
                placeholderText: "MM"
                onTextChanged: if (length > 2) remove(2, length);
            }

            Label {
                text: " / "
            }

            TextField {
                placeholderText: "DD"
                onTextChanged: if (length > 2) remove(2, length);
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
                width: nameLbl.width * 1.8
            }

            Button {
                id: btnImg
                text: "Add Image"
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
}
