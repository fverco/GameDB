#include "headers/gameinterm.h"
#include "headers/service.h"
#include "headers/developer.h"
#include "headers/publisher.h"

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

/*!
 * \brief Requests the Infodatabase to add the given Service.
 * \param name = The name of the service
 * \return A bool value that's true if the request was successful.
 */
bool GameInterm::addService(QString name) {
    Service newServ(-1, name);
    return infoDatabase.addService(newServ);
}

/*!
 * \brief Requests the Infodatabase to add the given Developer.
 * \param name = The name of the developer
 * \return A bool value that's true if the request was successful.
 */
bool GameInterm::addDeveloper(QString name) {
    Developer newDev(-1, name);
    return infoDatabase.addDeveloper(newDev);
}

/*!
 * \brief Requests the Infodatabase to add the given Publisher.
 * \param name = The name of the publisher
 * \return A bool value that's true if the request was successful.
 */
bool GameInterm::addPublisher(QString name) {
    Publisher newPub(-1, name);
    return infoDatabase.addPublisher(newPub);
}
