import QtQuick 2.4
import QtQuick.Controls 2.12


Button {
    id: gameCase
    width: 200
    height: 280
    highlighted: false
    text: ""
    z: 1
    property alias coverPath: coverImage.source
    property alias label: gameCase.text
    property alias caseHeight: gameCase.height
    property alias caseWidth: gameCase.width

    Image {
        id: coverImage
        source: ""
        anchors.topMargin: 2
        anchors.bottomMargin: 2
        anchors.rightMargin: 2
        anchors.leftMargin: 2
        asynchronous: true
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        //fillMode: Image.PreserveAspectFit
        z: 2
    }
}


// This is experimental code to replace the Button.
/*
Rectangle {
    id: gameCase
    width: 200
    height: 280
    color: "dimgrey"
    property alias coverPath: coverImage.source
    property alias label: gameLabel.text
    property alias caseHeight: gameCase.height
    property alias caseWidth: gameCase.width

    Image {
        id: coverImage
        source: ""
        anchors.topMargin: 2
        anchors.bottomMargin: 2
        anchors.rightMargin: 2
        anchors.leftMargin: 2
        asynchronous: true
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        //fillMode: Image.PreserveAspectFit
        z: 2
    }

    Text {
        id: gameLabel
        text: ""
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.bold: true
        fontSizeMode: Text.Fit
        z: 1
    }

    MouseArea {
        anchors.fill: parent
        z: 3
    }
}
*/
