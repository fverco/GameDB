// Adds the provided details as a new Platform entry.
function addNewPlatform() {

    // Get the values.
    let name = nameField.text,
        gen = genSpin.value,
        year = parseInt(yearField.text),
        month = parseInt(monthField.text),
        day = parseInt(dayField.text);

    // Verify their validity.
    if (name.length > 0 &&
            yearField.text.length === 4 &&
            month < 13 && month > 0 &&
            day < 32 && day > 0)
    {
        // Add the platform and provide a message.
        if (gameInterm.addPlatform(name, gen, year, month, day)) {
            messageDialog.text = "Platform successfully added.";
            messageDialog.open();
            messageDialog.closeWindow = true;
        } else {
            messageDialog.text = "Error occurred while adding new platform.";
            messageDialog.open();
        }

    } else {
        messageDialog.text = "Please provide a valid name and release date.";
        messageDialog.open();
    }
}
