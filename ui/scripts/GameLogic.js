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
