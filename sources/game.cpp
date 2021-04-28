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
    Entry(gid, n),
    platId(plid),
    servId(sid),
    devId(did),
    pubId(puid),
    coverId(cid),
    coverImage(""),
    exclusive(false),
    expansion(false),
    releaseDate(QDate(2000,1,1)),
    physical(false),
    edition("Standard Edition"),
    dateAdded(QDate(2000,1,1))
{
}

/*!
 * \brief The copy constructor for Game objects.
 * \param otherGame = The game object from which the values will be copied
 */
Game::Game(const Game &otherGame) :
    Entry(otherGame.id, otherGame.name),
    platId(otherGame.platId),
    servId(otherGame.servId),
    devId(otherGame.devId),
    pubId(otherGame.pubId),
    coverId(otherGame.coverId),
    coverImage(otherGame.coverImage),
    exclusive(otherGame.exclusive),
    expansion(otherGame.expansion),
    releaseDate(otherGame.releaseDate),
    physical(otherGame.physical),
    edition(otherGame.edition),
    dateAdded(otherGame.dateAdded)
{
}

/*!
 * \brief The assignment operator for Game objects.
 * \param otherGame = The game object from which the values will be copied
 * \return A pointer to the variable to the left of the operator
 */
Game& Game::operator=(const Game& otherGame) {
    id = otherGame.id;
    name = otherGame.name;
    platId = otherGame.platId;
    servId = otherGame.servId;
    devId = otherGame.devId;
    pubId = otherGame.pubId;
    coverId = otherGame.coverId;
    coverImage = otherGame.coverImage;
    exclusive = otherGame.exclusive;
    expansion = otherGame.expansion;
    releaseDate = otherGame.releaseDate;
    physical = otherGame.physical;
    edition = otherGame.edition;
    dateAdded = otherGame.dateAdded;

    return *this;
}

/*!
 * \brief Assigns a new platform ID.
 * \param pid = The new platform ID
 */
void Game::setPlatId(const int &pid) {
    platId = pid;
}

/*!
 * \brief Assigns a new service ID.
 * \param sid = The new service ID
 */
void Game::setServId(const int &sid) {
    servId = sid;
}

/*!
 * \brief Assigns a new developer ID.
 * \param did = The new developer ID
 */
void Game::setDevId(const int &did) {
    devId = did;
}

/*!
 * \brief Assigns a new publisher ID.
 * \param puid = The new publisher ID
 */
void Game::setPubId(const int &puid) {
    pubId = puid;
}

/*!
 * \brief Assigns a new cover ID.
 * \param cid = The new cover ID
 */
void Game::setCoverId(const int &cid) {
    coverId = cid;
}

/*!
 * \brief Assigns a new cover image for the game.
 * \param cover = The new cover image
 */
void Game::setCoverImage(const QByteArray &cover) {
    coverImage = cover;
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
 * \brief Retrieves the plaform ID.
 * \return The platform ID
 */
int Game::getPlatId() const {
    return platId;
}

/*!
 * \brief Retrieves the service ID.
 * \return The service ID
 */
int Game::getServId() const {
    return servId;
}

/*!
 * \brief Retrieves the developer ID.
 * \return The developer ID
 */
int Game::getDevId() const {
    return devId;
}

/*!
 * \brief Retrieves the publisher ID.
 * \return The publisher ID
 */
int Game::getPubId() const {
    return pubId;
}

/*!
 * \brief Retrieves the cover ID.
 * \return The cover ID
 */
int Game::getCoverId() const {
    return coverId;
}

/*!
 * \brief Retrieves the cover image.
 * \return The cover image in binary form
 */
QByteArray Game::getCoverImage() const {
    return coverImage;
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
 * \brief Returns the type of entry the calling object is.
 * \return  An EntryTypes enum of Game
 * \note The returning value will always be the Game enum.
 */
EntryTypes Game::getEntryType() const {
    return EntryTypes::Game;
}
