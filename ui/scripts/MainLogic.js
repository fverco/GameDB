const WindowTypes = Object.freeze({
                                      GameWindow: 0,
                                      PlatformWindow: 1,
                                      ServiceWindow: 2,
                                      DeveloperWindow: 3,
                                      PublisherWindow: 4
                                  });

// Opens the type of window that you request.
// Note: It will never allow multiple windows to be open simultaneously.
function openWindow(windowType) {
    if (!detectOpenWindows()) {

        switch(windowType) {

        case WindowTypes.GameWindow:
            var gameFormComponent = Qt.createComponent("../forms/GameForm.qml");
            gameFormInstance = gameFormComponent.createObject(window);
            gameFormInstance.showNormal();
            break;

        case WindowTypes.PlatformWindow:
            var platformFormComponent = Qt.createComponent("../forms/PlatformForm.qml");
            platformFormInstance = platformFormComponent.createObject(window);
            platformFormInstance.showNormal();
            break;

        case WindowTypes.ServiceWindow:
            var serviceFormComponent = Qt.createComponent("../forms/SimpleEntryForm.qml");
            simpleEntryFormInstance = serviceFormComponent.createObject(window);
            simpleEntryFormInstance.entryType = "Service";
            simpleEntryFormInstance.showNormal();
            break;

        case WindowTypes.DeveloperWindow:
            var developerFormComponent = Qt.createComponent("../forms/SimpleEntryForm.qml");
            simpleEntryFormInstance = developerFormComponent.createObject(window);
            simpleEntryFormInstance.entryType = "Developer";
            simpleEntryFormInstance.showNormal();
            break;

        case WindowTypes.PublisherWindow:
            var publisherFormComponent = Qt.createComponent("../forms/SimpleEntryForm.qml");
            simpleEntryFormInstance = publisherFormComponent.createObject(window);
            simpleEntryFormInstance.entryType = "Publisher";
            simpleEntryFormInstance.showNormal();
            break;

        default:

        }
    }
}

// Checks if any window instance is open.
// Returns true if it does find one and make it active.
function detectOpenWindows() {
    if (gameFormInstance && gameFormInstance.visible) {
        gameFormInstance.requestActivate();
        return true;
    }

    if (platformFormInstance && platformFormInstance.visible) {
        platformFormInstance.requestActivate();
        return true;
    }

    if (simpleEntryFormInstance && simpleEntryFormInstance.visible) {
        simpleEntryFormInstance.requestActivate();
        return true;
    }

    return false;
}
