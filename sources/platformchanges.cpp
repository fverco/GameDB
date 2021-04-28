#include "headers/platformchanges.h"

/*!
 * \brief Create a PlatformChanges object with default values.
 * \param pid = The Platform ID
 */
PlatformChanges::PlatformChanges(const int &pid) :
    EntryChanges(pid)
{
}

/*!
 * \brief Creates a PlatformChanges object from a Platform object.
 * \param plat = The Platform that should be changed
 * \note This is the same as a default constructor, except it uses the ID of the given Platform object.
 */
PlatformChanges::PlatformChanges(Platform &plat) :
    EntryChanges(&plat)
{
}

/*!
 * \brief The copy constructor for PlatformChanges objects.
 * \param otherChanges = The other PlatformChanges object from where the values will be copied.
 */
PlatformChanges::PlatformChanges(PlatformChanges &otherChanges) :
    EntryChanges(&otherChanges)
{
}

/*!
 * \brief The assignment operator for PlatformChanges objects.
 * \param otherChanges = The other PlatformChanges object from where the values will be copied.
 * \return A pointer to the PlatformChanges object on the left of the assignment operator.
 */
PlatformChanges& PlatformChanges::operator=(const PlatformChanges &otherChanges) {
    currentId = otherChanges.currentId;
    iterator = otherChanges.iterator;
    changes = otherChanges.changes;

    return *this;
}

/*!
 * \brief Adds a new platform ID to the list of changes.
 * \param newId = The new platform ID
 */
void PlatformChanges::setNewId(const int &newId) {
    changes[changes.size()] = qMakePair(ChangeTypes::Platform_ID, newId);
}

/*!
 * \brief Adds a new platform name to the list of changes.
 * \param n = The new platform name
 */
void PlatformChanges::setNewName(const QString& n) {
    changes[changes.size()] = qMakePair(ChangeTypes::Name, n);
}

/*!
 * \brief Adds a new console generation to the list of changes.
 * \param gen = The new console generation
 */
void PlatformChanges::setNewGeneration(const int& gen) {
    changes[changes.size()] = qMakePair(ChangeTypes::Generation, gen);
}

/*!
 * \brief Adds a new release date to the list of changes.
 * \param rel = The new release date
 */
void PlatformChanges::setNewReleaseDate(const QDate& rel) {
    changes[changes.size()] = qMakePair(ChangeTypes::Release_Date, rel);
}

/*!
 * \brief Generate a PlatformChanges object from differences between two Platform objects.
 * \param platA = The main platform object
 * \param platB = The second platform object
 * \return A PlatformChanges object with all the changes.
 * \note The first parameter is always regarded as the main object that should be changed.
 */
PlatformChanges PlatformChanges::changesFrom(const Platform &platA, const Platform &platB) {
    PlatformChanges changes(platA.getId());

    if (platA.getId() != platB.getId())
        changes.setNewId(platB.getId());

    if (platA.getName() != platB.getName())
        changes.setNewName(platB.getName());

    if (platA.getGeneration() != platB.getGeneration())
        changes.setNewGeneration(platB.getGeneration());

    if (platA.getReleaseDate() != platB.getReleaseDate())
        changes.setNewReleaseDate(platB.getReleaseDate());

    return changes;
}
