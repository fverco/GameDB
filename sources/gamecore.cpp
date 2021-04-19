#include "headers/gamecore.h"

/*!
 * \brief Initializes the member variables.
 * \param gid = The game ID in the database
 * \param plid = The platform ID in the database
 * \param sid = The service ID in the database
 * \param did = The developer ID in the database
 * \param puid = The publisher ID in the database
 * \param cid = The cover ID in the database
 */
GameCore::GameCore(const int &gid,
         const int &plid,
         const int &sid,
         const int &did,
         const int &puid,
         const int &cid) :
    gameId(gid),
    platId(plid),
    servId(sid),
    devId(did),
    pubId(puid),
    coverId(cid)
{
}

/*!
 * \brief Assigns a new game ID.
 * \param gid = The new game ID
 */
void GameCore::setGameId(const int &gid) {
    gameId = gid;
}

/*!
 * \brief Assigns a new platform ID.
 * \param pid = The new platform ID
 */
void GameCore::setPlatId(const int &pid) {
    platId = pid;
}

/*!
 * \brief Assigns a new service ID.
 * \param sid = The new service ID
 */
void GameCore::setServId(const int &sid) {
    servId = sid;
}

/*!
 * \brief Assigns a new developer ID.
 * \param did = The new developer ID
 */
void GameCore::setDevId(const int &did) {
    devId = did;
}

/*!
 * \brief Assigns a new publisher ID.
 * \param puid = The new publisher ID
 */
void GameCore::setPubId(const int &puid) {
    pubId = puid;
}

/*!
 * \brief Assigns a new cover ID.
 * \param cid = The new cover ID
 */
void GameCore::setCoverId(const int &cid) {
    coverId = cid;
}

/*!
 * \brief Assigns a new cover image for the game.
 * \param cover = The new cover image
 */
void GameCore::setCoverImage(const QByteArray &cover) {
    coverImage = cover;
}

/*!
 * \brief Retrieves the game ID.
 * \return The game ID
 */
int GameCore::getGameId() const {
    return gameId;
}

/*!
 * \brief Retrieves the plaform ID.
 * \return The platform ID
 */
int GameCore::getPlatId() const {
    return platId;
}

/*!
 * \brief Retrieves the service ID.
 * \return The service ID
 */
int GameCore::getServId() const {
    return servId;
}

/*!
 * \brief Retrieves the developer ID.
 * \return The developer ID
 */
int GameCore::getDevId() const {
    return devId;
}

/*!
 * \brief Retrieves the publisher ID.
 * \return The publisher ID
 */
int GameCore::getPubId() const {
    return pubId;
}

/*!
 * \brief Retrieves the cover ID.
 * \return The cover ID
 */
int GameCore::getCoverId() const {
    return coverId;
}

/*!
 * \brief Retrieves the cover image.
 * \return The cover image in binary form
 */
QByteArray GameCore::getCoverImage() const {
    return coverImage;
}

