#include "headers/platformchanges.h"

/*!
 * \brief Create a PlatformChanges object with default values.
 * \param pid = The Platform ID
 */
PlatformChanges::PlatformChanges(const int &pid) :
    platId(pid),
    iterator(0)
{
}

/*!
 * \brief The copy constructor for PlatformChanges objects.
 * \param otherChanges = The other PlatformChanges object from where the values will be copied.
 */
PlatformChanges::PlatformChanges(const PlatformChanges &otherChanges) :
    platId(otherChanges.platId),
    iterator(otherChanges.iterator),
    changes(otherChanges.changes)
{
}

/*!
 * \brief The assignment operator for PlatformChanges objects.
 * \param otherChanges = The other PlatformChanges object from where the values will be copied.
 * \return A pointer to the PlatformChanges object on the left of the assignment operator.
 */
PlatformChanges& PlatformChanges::operator=(const PlatformChanges &otherChanges) {
    platId = otherChanges.platId;
    iterator = otherChanges.iterator;
    changes = otherChanges.changes;

    return *this;
}

/*!
 * \brief Returns the amount of changes to the Platform.
 * \return An integer with the size of the changes data stucture.
 */
int PlatformChanges::size() const {
    return changes.size();
}

/*!
 * \brief Returns the change currently pointed to, then moves up by one spot.
 * \return A QPair in the form of <(Value type changed), (New Value)>.
 */
QPair<QString, QVariant> PlatformChanges::next() {
    return changes.value(iterator++);
}

/*!
 * \brief Are there more changes left in the list?
 * \return A boolean value.
 */
bool PlatformChanges::hasNext() const {
    return (iterator < size() ? true:false);
}

/*!
 * \brief Moves the iterator back to the start.
 */
void PlatformChanges::toStart() {
    iterator = 0;
}

/*!
 * \brief Adds a new platform ID to the list of changes.
 * \param pid = The new platform ID
 */
void PlatformChanges::setNewPlatId(const int &pid) {
    changes[changes.size()] = qMakePair(QString("ID"), pid);
}

/*!
 * \brief Adds a new platform name to the list of changes.
 * \param n = The new platform name
 */
void PlatformChanges::setNewName(const QString& n) {
    changes[changes.size()] = qMakePair(QString("Name"), n);
}

/*!
 * \brief Adds a new console generation to the list of changes.
 * \param gen = The new console generation
 */
void PlatformChanges::setNewGeneration(const int& gen) {
    changes[changes.size()] = qMakePair(QString("Generation"), gen);
}

/*!
 * \brief Adds a new release date to the list of changes.
 * \param rel = The new release date
 */
void PlatformChanges::setNewReleaseDate(const QDate& rel) {
    changes[changes.size()] = qMakePair(QString("Release Date"), rel);
}

/*!
 * \brief Returns the current platform ID.
 * \return An integer of the ID.
 * \note This is the platform ID to which this Changes object refers to, to be changed.
 */
int PlatformChanges::getCurrentPlatId() const {
    return platId;
}

/*!
 * \brief Returns a data structure with all platform changes.
 * \return  A QHash with the form of <(Change ID), <(Change type, Change value)> >
 * \example A case where only the name of the platform was changed: <0, <"Name", "Playstation 3">>
 */
QHash<int, QPair<QString, QVariant> > PlatformChanges::getAllChanges() const {
    return changes;
}

/*!
 * \brief Generate a PlatformChanges object from differences between two Platform objects.
 * \param platA = The main platform object
 * \param platB = The second platform object
 * \return A PlatformChanges object with all the changes.
 * \note The first parameter is always regarded as the main object that should be changed.
 */
PlatformChanges PlatformChanges::changesFrom(const Platform &platA, const Platform &platB) {
    PlatformChanges changes(platA.getPlatId());

    if (platA.getPlatId() != platB.getPlatId())
        changes.setNewPlatId(platB.getPlatId());

    if (platA.getName() != platB.getName())
        changes.setNewName(platB.getName());

    if (platA.getGeneration() != platB.getGeneration())
        changes.setNewGeneration(platB.getGeneration());

    if (platA.getReleaseDate() != platB.getReleaseDate())
        changes.setNewReleaseDate(platB.getReleaseDate());

    return changes;
}
