/*

IMPORTANT:
This script requires the WindowTypes.js script to be loaded as "Types".

*/

// Opens the type of window that you request.
// Note: It will never allow multiple windows to be open simultaneously.
function openWindow(windowType) {

    if (!detectOpenWindows()) {

        switch(windowType) {

        case Types.WindowTypes.GameWindow.value:
            var gameFormComponent = Qt.createComponent("../forms/GameForm.qml");
            gameFormInstance = gameFormComponent.createObject(window);
            gameFormInstance.showNormal();
            break;

        case Types.WindowTypes.PlatformWindow.value:
            var platformFormComponent = Qt.createComponent("../forms/PlatformForm.qml");
            platformFormInstance = platformFormComponent.createObject(window);
            platformFormInstance.showNormal();
            break;

        case Types.WindowTypes.ServiceWindow.value:
            var serviceFormComponent = Qt.createComponent("../forms/SimpleEntryForm.qml");
            simpleEntryFormInstance = serviceFormComponent.createObject(window);
            simpleEntryFormInstance.entryType = Types.WindowTypes.ServiceWindow.value;
            simpleEntryFormInstance.showNormal();
            break;

        case Types.WindowTypes.DeveloperWindow.value:
            var developerFormComponent = Qt.createComponent("../forms/SimpleEntryForm.qml");
            simpleEntryFormInstance = developerFormComponent.createObject(window);
            simpleEntryFormInstance.entryType = Types.WindowTypes.DeveloperWindow.value;
            simpleEntryFormInstance.showNormal();
            break;

        case Types.WindowTypes.PublisherWindow.value:
            var publisherFormComponent = Qt.createComponent("../forms/SimpleEntryForm.qml");
            simpleEntryFormInstance = publisherFormComponent.createObject(window);
            simpleEntryFormInstance.entryType = Types.WindowTypes.PublisherWindow.value;
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
