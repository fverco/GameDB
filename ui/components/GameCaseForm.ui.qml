import QtQuick 2.4
import QtQuick.Controls 2.12

Button {
    id: btn
    width: 200
    height: 300
    highlighted: false
    property alias imgSource: img.source
    property alias btnHeight: btn.height
    property alias btnWidth: btn.width

    Image {
        id: img
        source: "NULL"
        anchors.topMargin: 2
        anchors.bottomMargin: 2
        anchors.rightMargin: 2
        anchors.leftMargin: 2
        asynchronous: true
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
    }
}
