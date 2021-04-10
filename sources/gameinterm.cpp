#include "headers/gameinterm.h"

/*!
 * \brief Instantiates the GameInterm object and instantiates the databases.
 * \param parent = The QObject to which this object is binded.
 * \note If it fails to create/read the databases, it will force close the application.
 */
GameInterm::GameInterm(QObject *parent) :
    QObject(parent),
    infoDatabase(this),
    imageDatabase(this)
{
    if (!infoDatabase.createDatabase())
        QGuiApplication::quit();

    if (!imageDatabase.createDatabase())
        QGuiApplication::quit();
}
