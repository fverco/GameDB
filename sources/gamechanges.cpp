#include "headers/gamechanges.h"

/*!
 * \brief Create a GameChanges object with default values.
 * \param gid = The Game ID
 * \param plid = The Platform ID
 * \param sid = The Service ID
 * \param did = The Developer ID
 * \param puid = The Publisher ID
 * \param cid = The Cover ID
 * \note The IDs used here are IDs belonging to the Game entry, in the database, to which this GameChanges object is referring to.
 */
GameChanges::GameChanges(
        const int &gid,
        const int &plid,
        const int &sid,
        const int &did,
        const int &puid,
        const int &cid) :
    EntryChanges(gid),
    platId(plid),
    servId(sid),
    devId(did),
    pubId(puid),
    coverId(cid)
{
}

/*!
 * \brief Create a GameChanges object from a Game object.
 * \param game = The Game object that should be changed
 * \note This is the same as a default constructor, except it uses the IDs from the given Game object.
 */
GameChanges::GameChanges(Game &game) :
    EntryChanges(&game),
    platId(game.getPlatId()),
    servId(game.getServId()),
    devId(game.getDevId()),
    pubId(game.getPubId()),
    coverId(game.getCoverId())
{
}

/*!
 * \brief The copy constructor for GameChanges objects.
 * \param otherChanges = The other GameChanges object from where the values will be copied.
 */
GameChanges::GameChanges(GameChanges &otherChanges) :
    EntryChanges(&otherChanges),
    platId(otherChanges.platId),
    servId(otherChanges.servId),
    devId(otherChanges.devId),
    pubId(otherChanges.pubId),
    coverId(otherChanges.coverId)
{
}

/*!
 * \brief The assignment operator for GameChanges objects.
 * \param otherChanges = The other GameChanges object from where the values will be copied.
 * \return A pointer to the GameChanges object on the left of the assignment operator.
 */
GameChanges& GameChanges::operator=(const GameChanges &otherChanges) {
    currentId = otherChanges.currentId;
    platId = otherChanges.platId;
    servId = otherChanges.servId;
    devId = otherChanges.devId;
    pubId = otherChanges.pubId;
    coverId = otherChanges.coverId;
    iterator = otherChanges.iterator;
    changes = otherChanges.changes;

    return *this;
}

/*!
 * \brief Adds a new Game ID to the list of changes.
 * \param newId = The new Game ID
 * \note The previous Game ID is still kept for reference.
 */
void GameChanges::setNewId(const int& newId) {
    changes[changes.size()] = qMakePair(ChangeTypes::Game_ID, newId);
}

/*!
 * \brief Adds a new Platform ID to the list of changes.
 * \param plid = The new Platform ID
 * \note The previous Platform ID is still kept for reference.
 */
void GameChanges::setNewPlatId(const int& plid) {
    changes[changes.size()] = qMakePair(ChangeTypes::Platform_ID, plid);
}

/*!
 * \brief Adds a new Service ID to the list of changes.
 * \param sid = The new Service ID
 * \note The previous Service ID is still kept for reference.
 */
void GameChanges::setNewServId(const int& sid) {
    changes[changes.size()] = qMakePair(ChangeTypes::Service_ID, sid);
}

/*!
 * \brief Adds a new Developer ID to the list of changes.
 * \param did = The new Developer ID
 * \note The previous Developer ID is still kept for reference.
 */
void GameChanges::setNewDevId(const int& did) {
    changes[changes.size()] = qMakePair(ChangeTypes::Developer_ID, did);
}

/*!
 * \brief Adds a new Publisher ID to the list of changes.
 * \param puid = The new Publisher ID
 * \note The previous Publisher ID is still kept for reference.
 */
void GameChanges::setNewPubId(const int& puid) {
    changes[changes.size()] = qMakePair(ChangeTypes::Publisher_ID, puid);
}

/*!
 * \brief Adds a new Cover ID to the list of changes.
 * \param cid = The new Cover ID
 * \note The previous Cover ID is still kept for reference.
 */
void GameChanges::setNewCoverId(const int& cid) {
    changes[changes.size()] = qMakePair(ChangeTypes::Cover_ID, cid);
}

/*!
 * \brief Adds a new Cover Image to the list of changes.
 * \param cover = The new Cover Image
 * \note This does not change the cover ID. You must remember to change it yourself if necessary.
 */
void GameChanges::setNewCoverImage(const QByteArray &cover) {
    changes[changes.size()] = qMakePair(ChangeTypes::Cover_Image, cover);
}

/*!
 * \brief Adds a new name to the list of changes.
 * \param n = The new name
 */
void GameChanges::setNewName(const QString& n) {
    changes[changes.size()] = qMakePair(ChangeTypes::Name, n);
}

/*!
 * \brief Adds a new exclusive status to the list of changes.
 * \param excl = The new exclusive status
 */
void GameChanges::setNewExclusive(const bool& excl) {
    changes[changes.size()] = qMakePair(ChangeTypes::Exclusive, excl);
}

/*!
 * \brief Adds a new expansion status to the list of changes.
 * \param exp = The new expansion status
 */
void GameChanges::setNewExpansion(const bool& exp) {
    changes[changes.size()] = qMakePair(ChangeTypes::Expansion, exp);
}

/*!
 * \brief Adds a new release date to the list of changes.
 * \param rel = The new release date
 */
void GameChanges::setNewReleaseDate(const QDate& rel) {
    changes[changes.size()] = qMakePair(ChangeTypes::Release_Date, rel);
}

/*!
 * \brief Adds a new physical status to the list of changes.
 * \param phys = The new physical status
 */
void GameChanges::setNewPhysical(const bool& phys) {
    changes[changes.size()] = qMakePair(ChangeTypes::Physical, phys);
}

/*!
 * \brief Adds a new edition to the list of changes.
 * \param ed = The new edition
 */
void GameChanges::setNewEdition(const QString& ed) {
    changes[changes.size()] = qMakePair(ChangeTypes::Edition, ed);
}

/*!
 * \brief Adds a new date added to the list of changes.
 * \param added = The new date added
 */
void GameChanges::setNewDateAdded(const QDate &added) {
    changes[changes.size()] = qMakePair(ChangeTypes::Date_Added, added);
}

/*!
 * \brief Returns the current Platform ID.
 * \return An integer of the Platform ID.
 * \note This is the Platform ID associated with the Game object to be changed.
 */
int GameChanges::getCurrentPlatId() const {
    return platId;
}

/*!
 * \brief Returns the current Service ID.
 * \return An integer of the Service ID.
 * \note This is the Service ID associated with the Game object to be changed.
 */
int GameChanges::getCurrentServId() const {
    return servId;
}

/*!
 * \brief Returns the current Developer ID.
 * \return An integer of the Developer ID.
 * \note This is the Developer ID associated with the Game object to be changed.
 */
int GameChanges::getCurrentDevId() const {
    return devId;
}

/*!
 * \brief Returns the current Publisher ID.
 * \return An integer of the Publisher ID.
 * \note This is the Publisher ID associated with the Game object to be changed.
 */
int GameChanges::getCurrentPubId() const {
    return pubId;
}

/*!
 * \brief Returns the current Cover ID.
 * \return An integer of the Cover ID.
 * \note This is the Cover ID associated with the Game object to be changed.
 */
int GameChanges::getCurrentCoverId() const {
    return coverId;
}

/*!
 * \brief Generate a GameChanges object from differences between two Game objects.
 * \param gameA = The main game object
 * \param gameB = The second game object
 * \return A GameChanges object with all the changes.
 * \note The first parameter is always regarded as the main object that should be changed.
 */
GameChanges GameChanges::changesFrom(const Game &gameA, const Game &gameB) {
    GameChanges changes(gameA.getId(),
                        gameA.getPlatId(),
                        gameA.getServId(),
                        gameA.getDevId(),
                        gameA.getPubId(),
                        gameA.getCoverId());

    if (gameA.getId() != gameB.getId())
        changes.setNewId(gameB.getId());

    if (gameA.getPlatId() != gameB.getPlatId())
        changes.setNewPlatId(gameB.getPlatId());

    if (gameA.getServId() != gameB.getServId())
        changes.setNewServId(gameB.getServId());

    if (gameA.getDevId() != gameB.getDevId())
        changes.setNewDevId(gameB.getDevId());

    if (gameA.getPubId() != gameB.getPubId())
        changes.setNewPubId(gameB.getPubId());

    if (gameA.getCoverId() != gameB.getCoverId())
        changes.setNewCoverId(gameB.getCoverId());

    if (gameA.getCoverImage() != gameB.getCoverImage())
        changes.setNewCoverImage(gameB.getCoverImage());

    if (gameA.getName() != gameB.getName())
        changes.setNewName(gameB.getName());

    if (gameA.getExclusive() != gameB.getExclusive())
        changes.setNewExclusive(gameB.getExclusive());

    if (gameA.getExpansion() != gameB.getExpansion())
        changes.setNewExpansion(gameB.getExpansion());

    if (gameA.getReleaseDate() != gameB.getReleaseDate())
        changes.setNewReleaseDate(gameB.getReleaseDate());

    if (gameA.getPhysical() != gameB.getPhysical())
        changes.setNewPhysical(gameB.getPhysical());

    if (gameA.getEdition() != gameB.getEdition())
        changes.setNewEdition(gameB.getEdition());

    if (gameA.getDateAdded() != gameB.getDateAdded())
        changes.setNewDateAdded(gameB.getDateAdded());

    return changes;
}
