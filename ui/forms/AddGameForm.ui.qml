import QtQuick 2.4
import QtQuick.Controls 2.15

Page {
    anchors.fill: parent
    title: "Add Game"

    Row {
        Column {
            Label {
                text: "Name: "
            }
        }
        Column {
            TextField {}
        }
    }
}
