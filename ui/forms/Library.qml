import QtQuick 2.4
import "../scripts/LibraryLogic.js" as Logic

LibraryForm {
    Component.onCompleted: Logic.refreshLibrary();
}
