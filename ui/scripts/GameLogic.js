// Takes all the provided values and add them as a new game.
function addNewGame() {

    // Get the values.
    let name = nameField.text,
        plat = platBox.currentValue,
        serv = servBox.currentValue,
        dev = devBox.currentValue,
        pub = pubBox.currentValue,
        edition = editionField.text,
        exclusive = (exclusiveCheck.checkState === Qt.Checked) ? true : false,
        expansion = (expansionCheck.checkState === Qt.Checked) ? true : false,
        physical = (physicalCheck.checkState === Qt.Checked) ? true : false,
        year = parseInt(yearField.text),
        month = parseInt(monthField.text),
        day = parseInt(dayField.text),
        coverImg = coverField.text;

    // Verify their validity.
    if (name.length > 0 &&
            plat &&
            serv &&
            dev &&
            pub &&
            edition.length > 0 &&
            yearField.text.length === 4 &&
            month < 13 && month > 0 &&
            day < 32 && day > 0)
    {
        // Add the game and provide a message.
        if (gameInterm.addGame(name, plat, serv, dev, pub, edition, exclusive, expansion, physical, year, month, day, coverImg)) {
            messageDialog.text = "Game successfully added.";
            messageDialog.open();
            messageDialog.closeWindow = true;
        } else {
            messageDialog.text = "Error occurred while adding new game.";
            messageDialog.open();
        }
    } else {
        messageDialog.text = "Please provide valid details for the game.\nA cover image is optional.";
        messageDialog.open();
    }
}

// Populates all the comboboxes in the window.
function poplulateComboBoxes() {
    let emptyLists = "";

    if (!populatePlatforms()) {
        emptyLists += "platform, ";
    }

    if (!populateServices()) {
        emptyLists += "service, ";
    }

    if (!populateDevelopers()) {
        emptyLists += "developer, ";
    }

    if (!populatePublishers()) {
        emptyLists += "publisher, ";
    }

    if (emptyLists.length > 0) {
        emptyLists = emptyLists.slice(0, -2);
        messageDialog.text = "Please add at least one of each of the following:\n" + emptyLists;
        messageDialog.open();
        messageDialog.closeWindow = true;
    }
}

// Populates only the Platforms checkbox.
function populatePlatforms() {
    const platformMap = gameInterm.getPlatformNames();

    for (let plat in platformMap) {
        platBoxModel.append({"name": plat, "id": platformMap[plat]});
    }

    return (platBoxModel.count > 0 ? true : false);
}

// Populates only the Services checkbox.
function populateServices() {
    const serviceMap = gameInterm.getServiceNames();

    for (let serv in serviceMap) {
        servBoxModel.append({"name": serv, "id": serviceMap[serv]});
    }

    return (servBoxModel.count > 0 ? true : false);
}

// Populates only the Developers checkbox.
function populateDevelopers() {
    const developerMap = gameInterm.getDeveloperNames();

    for (let dev in developerMap) {
        devBoxModel.append({"name": dev, "id": developerMap[dev]});
    }

    return (devBoxModel.count > 0 ? true : false);
}

// Populates only the Publishers checkbox.
function populatePublishers() {
    const publisherMap = gameInterm.getPublisherNames();

    for (let pub in publisherMap) {
        pubBoxModel.append({"name": pub, "id": publisherMap[pub]});
    }

    return (pubBoxModel.count > 0 ? true : false);
}

// Used to determine the size of a map.
Object.size = function(obj) {
    let size = 0, key;

    for (key in obj) {
        if (obj.hasOwnProperty(key))
            ++size;
    }

    return size;
};
