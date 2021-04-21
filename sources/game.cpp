#include "headers/game.h"

/*!
 * \brief Creates a game object with default values.
 * \param gid = The game ID in the database
 * \param plid = The platform ID in the database
 * \param sid = The service ID in the database
 * \param did = The developer ID in the database
 * \param puid = The publisher ID in the database
 * \param n = The name of the game
 * \param cid = The cover ID in the database
 * \note Any id that is not provided must be -1.
 */
Game::Game(
     const int &gid,
     const int &plid,
     const int &sid,
     const int &did,
     const int &puid,
     const int &cid,
     const QString &n) :
    GameCore(gid,
             plid,
             sid,
             did,
             puid,
             cid,
             ""),
    name(n),
    exclusive(false),
    expansion(false),
    releaseDate(QDate(2000,1,1)),
    physical(false),
    edition("Standard Edition"),
    dateAdded(QDate(2000,1,1)),
    platName(""),
    servName(""),
    devName(""),
    pubName("")
{
}

/*!
 * \brief The copy constructor for Game objects.
 * \param otherGame = The game object from which the values will be copied
 */
Game::Game(const Game &otherGame) :
    GameCore(otherGame.gameId,
             otherGame.platId,
             otherGame.servId,
             otherGame.devId,
             otherGame.pubId,
             otherGame.coverId,
             otherGame.coverImage),
    name(otherGame.name),
    exclusive(otherGame.exclusive),
    expansion(otherGame.expansion),
    releaseDate(otherGame.releaseDate),
    physical(otherGame.physical),
    edition(otherGame.edition),
    dateAdded(otherGame.dateAdded),
    platName(otherGame.platName),
    servName(otherGame.servName),
    devName(otherGame.devName),
    pubName(otherGame.pubName)
{
}

/*!
 * \brief The assignment operator for Game objects.
 * \param otherGame = The game object from which the values will be copied
 * \return A pointer to the variable to the left of the operator
 */
Game& Game::operator=(const Game& otherGame) {
    gameId = otherGame.gameId;
    platId = otherGame.platId;
    servId = otherGame.servId;
    devId = otherGame.devId;
    pubId = otherGame.pubId;
    coverId = otherGame.coverId;
    coverImage = otherGame.coverImage;
    name = otherGame.name;
    exclusive = otherGame.exclusive;
    expansion = otherGame.expansion;
    releaseDate = otherGame.releaseDate;
    physical = otherGame.physical;
    edition = otherGame.edition;
    dateAdded = otherGame.dateAdded;
    platName = otherGame.platName;
    servName = otherGame.servName;
    devName = otherGame.devName;
    pubName = otherGame.pubName;

    return *this;
}

/*!
 * \brief Assigns a new name for the game.
 * \param n = The new game name
 */
void Game::setName(const QString &n) {
    name = n;
}

/*!
 * \brief Assigns a new value to the exclusive property.
 * \param excl = The new value
 */
void Game::setExclusive(const bool &excl) {
    exclusive = excl;
}

/*!
 * \brief Assigns a new value to the expansion property.
 * \param exp = The new value
 */
void Game::setExpansion(const bool &exp) {
    expansion = exp;
}

/*!
 * \brief Assigns a new release date for the game.
 * \param rel = The new release date
 */
void Game::setReleaseDate(const QDate &rel) {
    releaseDate = rel;
}

/*!
 * \brief Assigns a new value to the physical property.
 * \param phys = The new value
 */
void Game::setPhysical(const bool &phys) {
    physical = phys;
}

/*!
 * \brief Assigns a new edition name for the game.
 * \param ed = The new edition name
 */
void Game::setEdition(const QString &ed) {
    edition = ed;
}

/*!
 * \brief Assigns a new date added for the game.
 * \param added = The new date added
 */
void Game::setDateAdded(const QDate &added) {
    dateAdded = added;
}

/*!
 * \brief Assigns a new platform name for the game.
 * \param pName = The new platform name
 */
void Game::setPlatName(const QString &pName) {
    platName = pName;
}

/*!
 * \brief Assigns a new service name for the game.
 * \param sName = The new service name
 */
void Game::setServName(const QString &sName) {
    servName = sName;
}

/*!
 * \brief Assigns a new developer name for the game.
 * \param dev = The new developer name
 */
void Game::setDevName(const QString &dev) {
    devName = dev;
}

/*!
 * \brief Assigns a new publisher name for the game.
 * \param pub = The new publisher name
 */
void Game::setPubName(const QString &pub) {
    pubName = pub;
}

/*!
 * \brief Retrieves the game name.
 * \return The game name
 */
QString Game::getName() const {
    return name;
}

/*!
 * \brief Retrieves the game's exclusivity status.
 * \return A true/false value
 */
bool Game::getExclusive() const {
    return exclusive;
}

/*!
 * \brief Retrieves the game's expansion status.
 * \return A true/false value
 */
bool Game::getExpansion() const {
    return expansion;
}

/*!
 * \brief Retrieves the game's release date.
 * \return The release date
 */
QDate Game::getReleaseDate() const {
    return releaseDate;
}

/*!
 * \brief Retrieves the game copy's physical status.
 * \return A true/false value
 */
bool Game::getPhysical() const {
    return physical;
}

/*!
 * \brief Retrieves the game copy's edition.
 * \return The edition
 */
QString Game::getEdition() const {
    return edition;
}

/*!
 * \brief Retrieves the date added to the database for the game.
 * \return The date added
 */
QDate Game::getDateAdded() const {
    return dateAdded;
}

/*!
 * \brief Retrieves the platform name.
 * \return The platform name
 */
QString Game::getPlatName() const {
    return platName;
}

/*!
 * \brief Retrieves the service name.
 * \return The service name
 */
QString Game::getServName() const {
    return servName;
}

/*!
 * \brief Retrieves the developer name.
 * \return The developer name
 */
QString Game::getDevName() const {
    return devName;
}

/*!
 * \brief Retrieves the publisher name.
 * \return The publisher name
 */
QString Game::getPubName() const {
    return pubName;
}
