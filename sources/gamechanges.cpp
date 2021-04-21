#include "headers/gamechanges.h"

/*!
 * \brief Create a GameChanges object with default values.
 * \param gId = The Game ID
 * \param plId = The Platform ID
 * \param sId = The Service ID
 * \param dId = The Developer ID
 * \param puId = The Publisher ID
 * \param cId = The Cover ID
 * \note The IDs used here are IDs belonging to the Game entry, in the database, to which this GameChanges object is referring to.
 */
GameChanges::GameChanges(
        const int &gId,
        const int &plId,
        const int &sId,
        const int &dId,
        const int &puId,
        const int &cId) :
    GameCore(gId,
             plId,
             sId,
             dId,
             puId,
             cId,
             ""),
    iterator(0),
    coverImageChanged(false),
    coverIdChanged(false)
{
}

/*!
 * \brief The copy constructor for GameChanges objects.
 * \param otherChanges = The other GameChanges object from where the values will be copied.
 */
GameChanges::GameChanges(const GameChanges &otherChanges) :
    GameCore(otherChanges.gameId,
             otherChanges.platId,
             otherChanges.servId,
             otherChanges.devId,
             otherChanges.pubId,
             otherChanges.coverId,
             otherChanges.coverImage),
    iterator(otherChanges.iterator),
    coverImageChanged(otherChanges.coverImageChanged),
    coverIdChanged(otherChanges.coverIdChanged),
    changes(otherChanges.changes)
{
}

/*!
 * \brief The assignment operator for GameChanges objects.
 * \param otherChanges = The other GameChanges object from where the values will be copied.
 * \return A pointer to the GameChanges object on the left of the assignment operator.
 */
GameChanges& GameChanges::operator=(const GameChanges &otherChanges) {
    gameId = otherChanges.gameId;
    platId = otherChanges.platId;
    servId = otherChanges.servId;
    devId = otherChanges.devId;
    pubId = otherChanges.pubId;
    coverId = otherChanges.coverId;
    coverImage = otherChanges.coverImage;
    iterator = otherChanges.iterator;
    coverImageChanged = otherChanges.coverImageChanged;
    coverIdChanged = otherChanges.coverIdChanged;
    changes = otherChanges.changes;

    return *this;
}

/*!
 * \brief Returns the amount of changes to the Game.
 * \return An integer with the size of the changes data structure.
 */
int GameChanges::size() const {
    return changes.size();
}

/*!
 * \brief Returns the change currently pointed to, then moves up by one spot.
 * \return A QPair in the form of <(Value type changed), (New Value)>.
 */
QPair<QString, QVariant> GameChanges::next() {
    return changes.value(iterator++);
}

/*!
 * \brief Are there more changes left in the list?
 * \return A boolean value.
 */
bool GameChanges::hasNext() const {
    return (iterator < size() ? true:false);
}

/*!
 * \brief Has the cover ID been changed?
 * \return A boolean value.
 */
bool GameChanges::coverIdIsChanged() const {
    return coverIdChanged;
}

/*!
 * \brief Has the cover image been changed?
 * \return A boolean value.
 */
bool GameChanges::coverImageIsChanged() const {
    return coverImageChanged;
}

/*!
 * \brief Moves the iterator back to the start.
 */
void GameChanges::toStart() {
    iterator = 0;
}

/*!
 * \brief Adds a new Game ID to the list of changes.
 * \param gid = The new Game ID
 * \note The previous Game ID is still kept for reference.
 */
void GameChanges::setNewGameId(const int& gid) {
    changes[changes.size()] = qMakePair(QString("Game ID"), gid);
}

/*!
 * \brief Adds a new Platform ID to the list of changes.
 * \param plid = The new Platform ID
 * \note The previous Platform ID is still kept for reference.
 */
void GameChanges::setNewPlatId(const int& plid) {
    changes[changes.size()] = qMakePair(QString("Plat ID"), plid);
}

/*!
 * \brief Adds a new Service ID to the list of changes.
 * \param sid = The new Service ID
 * \note The previous Service ID is still kept for reference.
 */
void GameChanges::setNewServId(const int& sid) {
    changes[changes.size()] = qMakePair(QString("Serv ID"), sid);
}

/*!
 * \brief Adds a new Developer ID to the list of changes.
 * \param did = The new Developer ID
 * \note The previous Developer ID is still kept for reference.
 */
void GameChanges::setNewDevId(const int& did) {
    changes[changes.size()] = qMakePair(QString("Dev ID"), did);
}

/*!
 * \brief Adds a new Publisher ID to the list of changes.
 * \param puid = The new Publisher ID
 * \note The previous Publisher ID is still kept for reference.
 */
void GameChanges::setNewPubId(const int& puid) {
    changes[changes.size()] = qMakePair(QString("Pub ID"), puid);
}

/*!
 * \brief Adds a new Cover ID to the list of changes.
 * \param cid = The new Cover ID
 * \note The previous Cover ID is still kept for reference.
 */
void GameChanges::setNewCoverId(const int& cid) {
    changes[changes.size()] = qMakePair(QString("Cover ID"), cid);
    coverIdChanged = true;
}

/*!
 * \brief Adds a new Cover Image to the list of changes.
 * \param cover = The new Cover Image
 * \note The previous Cover Image is still kept for history.
 */
void GameChanges::setNewCoverImage(const QByteArray &cover) {
    changes[changes.size()] = qMakePair(QString("Cover Image"), cover);
    coverImageChanged = true;
}

/*!
 * \brief Adds a new name to the list of changes.
 * \param n = The new name
 */
void GameChanges::setName(const QString& n) {
    changes[changes.size()] = qMakePair(QString("Name"), n);
}

/*!
 * \brief Adds a new exclusive status to the list of changes.
 * \param excl = The new exclusive status
 */
void GameChanges::setExclusive(const bool& excl) {
    changes[changes.size()] = qMakePair(QString("Exclusive"), excl);
}

/*!
 * \brief Adds a new expansion status to the list of changes.
 * \param exp = The new expansion status
 */
void GameChanges::setExpansion(const bool& exp) {
    changes[changes.size()] = qMakePair(QString("Expansion"), exp);
}

/*!
 * \brief Adds a new release date to the list of changes.
 * \param rel = The new release date
 */
void GameChanges::setReleaseDate(const QDate& rel) {
    changes[changes.size()] = qMakePair(QString("Release Date"), rel);
}

/*!
 * \brief Adds a new physical status to the list of changes.
 * \param phys = The new physical status
 */
void GameChanges::setPhysical(const bool& phys) {
    changes[changes.size()] = qMakePair(QString("Physical"), phys);
}

/*!
 * \brief Adds a new edition to the list of changes.
 * \param exp = The new edition
 */
void GameChanges::setEdition(const QString& ed) {
    changes[changes.size()] = qMakePair(QString("Edition"), ed);
}

/*!
 * \brief Adds a new date added to the list of changes.
 * \param exp = The new date added
 */
void GameChanges::setDateAdded(const QDate &added) {
    changes[changes.size()] = qMakePair(QString("Date Added"), added);
}

/*!
 * \brief Changes the platform name for the platform ID this object stores.
 * \param pName = The new platform name
 * \note This does not add a new platform name to the list of changes, because that name is only used for quick access.
 */
void GameChanges::setPlatName(const QString &pName) {
    changes[changes.size()] = qMakePair(QString("Plat Name"), pName);
}

/*!
 * \brief Changes the service name for the service ID this object stores.
 * \param sName = The new service name
 * \note This does not add a new service name to the list of changes, because that name is only used for quick access.
 */
void GameChanges::setServName(const QString &sName) {
    changes[changes.size()] = qMakePair(QString("Serv Name"), sName);
}

/*!
 * \brief Changes the developer name for the developer ID this object stores.
 * \param dev = The new developer name
 * \note This does not add a new developer name to the list of changes, because that name is only used for quick access.
 */
void GameChanges::setDevName(const QString &dev) {
    changes[changes.size()] = qMakePair(QString("Dev Name"), dev);
}

/*!
 * \brief Changes the publisher name for the publisher ID this object stores.
 * \param pub = The new publisher name
 * \note This does not add a new publisher name to the list of changes, because that name is only used for quick access.
 */
void GameChanges::setPubName(const QString &pub) {
    changes[changes.size()] = qMakePair(QString("Pub Name"), pub);
}

/*!
 * \brief Returns a data structure with all game changes.
 * \return A QHash with the form of <(Change ID), <(Change type, Change value)> >
 */
QHash<int, QPair<QString, QVariant> > GameChanges::getAllChanges() const {
    return changes;
}

/*!
 * \brief Generate a GameChanges object from differences between two Game objects.
 * \param gameA = The main game object
 * \param gameB = The second game object
 * \return A GameChanges object with all the changes.
 */
GameChanges GameChanges::changesFrom(const Game &gameA, const Game &gameB) {
    GameChanges changes(gameA.getGameId(),
                        gameA.getPlatId(),
                        gameA.getServId(),
                        gameA.getDevId(),
                        gameA.getPubId(),
                        gameA.getCoverId());

    if (gameA.getGameId() != gameB.getGameId())
        changes.setNewGameId(gameB.getGameId());

    if (gameA.getPlatId() != gameB.getPlatId())
        changes.setNewPlatId(gameB.getPlatId());

    if (gameA.getServId() != gameB.getServId())
        changes.setNewServId(gameB.getServId());

    if (gameA.getDevId() != gameB.getDevId())
        changes.setNewDevId(gameB.getDevId());

    if (gameA.getPubId() != gameB.getPubId())
        changes.setNewPubId(gameB.getPubId());

    if (gameA.getCoverId() != gameB.getCoverId()) {
        changes.setNewCoverId(gameB.getCoverId());
        changes.coverIdChanged = true;
    }

    if (gameA.getCoverImage() != gameB.getCoverImage()) {
        changes.setNewCoverImage(gameB.getCoverImage());
        changes.coverImageChanged = true;
    }

    if (gameA.getName() != gameB.getName())
        changes.setName(gameB.getName());

    if (gameA.getExclusive() != gameB.getExclusive())
        changes.setExclusive(gameB.getExclusive());

    if (gameA.getExpansion() != gameB.getExpansion())
        changes.setExpansion(gameB.getExpansion());

    if (gameA.getReleaseDate() != gameB.getReleaseDate())
        changes.setReleaseDate(gameB.getReleaseDate());

    if (gameA.getPhysical() != gameB.getPhysical())
        changes.setPhysical(gameB.getPhysical());

    if (gameA.getEdition() != gameB.getEdition())
        changes.setEdition(gameB.getEdition());

    if (gameA.getDateAdded() != gameB.getDateAdded())
        changes.setDateAdded(gameB.getDateAdded());

    return changes;
}
