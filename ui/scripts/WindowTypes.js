.pragma library

const WindowTypes = Object.freeze({
                                      GameWindow: {value: 0, type: "Game"},
                                      PlatformWindow: {value: 1, type: "Platform"},
                                      ServiceWindow: {value: 2, type: "Service"},
                                      DeveloperWindow: {value: 3, type: "Developer"},
                                      PublisherWindow: {value: 4, type: "Publisher"}
                                  });

// Counts the amount of values in the WindowTypes enum.
function count() {
    let size = 0;

    for (let type in WindowTypes) {
        size++;
    }

    return size;
}

// Returns the coresponding window type of the provided integer value.
function getType(val) {
    switch(val) {

    case WindowTypes.GameWindow.value:
        return WindowTypes.GameWindow.type;

    case WindowTypes.PlatformWindow.value:
        return WindowTypes.PlatformWindow.type;

    case WindowTypes.ServiceWindow.value:
        return WindowTypes.ServiceWindow.type;

    case WindowTypes.DeveloperWindow.value:
        return WindowTypes.DeveloperWindow.type;

    case WindowTypes.PublisherWindow.value:
        return WindowTypes.PublisherWindow.type;

    default:
        return "NULL";
    }
}
