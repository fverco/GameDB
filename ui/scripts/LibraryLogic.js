.import gamelist.attributes 1.0 as GLA

function refreshLibrary() {
    console.log("Testing the gamelist.attributes enum: " + GLA.GameListAttributes.Physical);
}

function createGameCase(id) {
    var component = Qt.createComponent("../components/GameCase.qml");
    var button = component.createObject(gameGrid,{gameId: id});

    if (button === null) {
        messageDialog.text = "Error refreshing the game library.";
        messageDialog.open();
        messageDialog.closeWindow = true;
    } else {
        ++gameGrid.gameCount;
    }
}
