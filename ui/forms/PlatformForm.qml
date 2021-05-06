import QtQuick 2.15
import QtQuick.Controls 2.14

ApplicationWindow {
    width: 450
    height: 200
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    title: "Add Platform"
    id: addPlatformWindow

    Column {
        id: column
        anchors.fill: parent
        leftPadding: 10
        topPadding: 10

        // Name row.
        // Note: Every visual value in this nameRow is copied to the other rows.
        Row {
            height: parent.height / 4
            width: 490
            spacing: 10
            id: nameRow

            Label {
                width: parent.width / 3.5
                text: "Name: "
                id: nameLbl
            }

            TextField {
                width: parent.width * 5.7/10
                id: nameField
                selectByMouse: true
            }
        }

        // Console Generation row.
        Row {
            height: nameRow.height
            width: nameRow.width
            spacing: nameRow.spacing

            Label {
                width: nameLbl.width
                text: "Console Generation: "
            }

            SpinBox {
                value: 0
            }

            Label {
                text: "Leave 0 if not a console"
                font.italic: true
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

        // Add/cancel button row.
        Row {
            height: nameRow.height
            layoutDirection: Qt.RightToLeft
            width: nameRow.width * 0.88
            spacing: nameRow.spacing

            Button {
                id: btnCancel
                text: "Cancel"
                onClicked: addPlatformWindow.close();
            }

            Button {
                id: btnAdd
                text: "Add"
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
