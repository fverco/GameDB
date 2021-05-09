#include "headers/gameinterm.h"
#include "headers/platform.h"
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
 * \brief Returns a list of all platforms' names together with their IDs.
 * \return A QVariantMap (synonymous with QMap<QString, QVariant>) of the form <Name: QString, ID: int>.\n Returns an empty list if there are no entries.
 */
QVariantMap GameInterm::getPlatformNames() {
    QMap<int, QString> dbPlatNames(infoDatabase.getPlatformNames());
    QMap<QString, QVariant> qmlPlatNames;

    for (QMap<int, QString>::const_iterator it(dbPlatNames.cbegin()), end = dbPlatNames.cend(); it != end; ++it)
        qmlPlatNames.insert(it.value(), it.key());

    return qmlPlatNames;
}

/*!
 * \brief Returns a list of all services' names together with their IDs.
 * \return A QVariantMap (synonymous with QMap<QString, QVariant>) of the form <Name: QString, ID: int>.\n Returns an empty list if there are no entries.
 */
QVariantMap GameInterm::getServiceNames() {
    QMap<int, QString> dbServNames(infoDatabase.getServiceNames());
    QMap<QString, QVariant> qmlServNames;

    for (QMap<int, QString>::const_iterator it(dbServNames.cbegin()), end = dbServNames.cend(); it != end; ++it)
        qmlServNames.insert(it.value(), it.key());

    return qmlServNames;
}

/*!
 * \brief Returns a list of all developers' names together with their IDs.
 * \return A QVariantMap (synonymous with QMap<QString, QVariant>) of the form <Name: QString, ID: int>.\n Returns an empty list if there are no entries.
 */
QVariantMap GameInterm::getDeveloperNames() {
    QMap<int, QString> dbDevNames(infoDatabase.getDeveloperNames());
    QMap<QString, QVariant> qmlDevNames;

    for (QMap<int, QString>::const_iterator it(dbDevNames.cbegin()), end = dbDevNames.cend(); it != end; ++it)
        qmlDevNames.insert(it.value(), it.key());

    return qmlDevNames;
}

/*!
 * \brief Returns a list of all publishers' names together with their IDs.
 * \return A QVariantMap (synonymous with QMap<QString, QVariant>) of the form <Name: QString, ID: int>.\n Returns an empty list if there are no entries.
 */
QVariantMap GameInterm::getPublisherNames() {
    QMap<int, QString> dbPubNames(infoDatabase.getPublisherNames());
    QMap<QString, QVariant> qmlPubNames;

    for (QMap<int, QString>::const_iterator it(dbPubNames.cbegin()), end = dbPubNames.cend(); it != end; ++it)
        qmlPubNames.insert(it.value(), it.key());

    return qmlPubNames;
}

/*!
 * \brief Requests the Infodatabase to add the given Platform.
 * \param name = The name of the platform
 * \param gen = The console generation of the platform
 * \param year = The release year of the platform
 * \param month = The release month of the platform
 * \param day = The release day of the platform
 * \return A bool value that's true if the request was successful.
 */
bool GameInterm::addPlatform(QString name, int gen, int year, int month, int day) {
    Platform newPlat(-1, name, gen, QDate(year, month, day));
    return infoDatabase.addPlatform(newPlat);
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
