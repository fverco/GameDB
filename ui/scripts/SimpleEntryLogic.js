// Adds the name field's value as a new entry.
function addNewEntry() {

    // Is the name field not empty?
    if (nameField.text.length > 0) {

        let successful;

        // Determine the type of entry to be added and then add it.
        switch(entryType) {

        case Types.WindowTypes.ServiceWindow.value:
            successful = gameInterm.addService(nameField.text);
            break;

        case Types.WindowTypes.DeveloperWindow.value:
            successful = gameInterm.addDeveloper(nameField.text);
            break;

        case Types.WindowTypes.PublisherWindow.value:
            successful = gameInterm.addPublisher(nameField.text);
            break;

        default:
            successful = false;
        }

        // Show a message based on the result of the transaction.
        if (successful) {
            messageDialog.text = "Entry successfully added.";
            messageDialog.open();
            messageDialog.closeWindow = true;
        } else {
            messageDialog.text = "Error occurred while adding new entry.";
            messageDialog.open();
        }
    } else {
        messageDialog.text = "The service name is too short.";
        messageDialog.open();
    }
}
