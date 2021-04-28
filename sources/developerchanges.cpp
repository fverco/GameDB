#include "headers/developerchanges.h"

/*!
 * \brief Create a DeveloperChanges object with default values.
 * \param did = The developer ID
 */
DeveloperChanges::DeveloperChanges(const int &did) :
    EntryChanges(did)
{
}

/*!
 * \brief Creates a DeveloperChanges object from a Developer object.
 * \param dev = The developer that should be changed.
 * \note This is the same as a default constructor, except it uses the ID of the given developer object.
 */
DeveloperChanges::DeveloperChanges(Developer &dev) :
    EntryChanges(&dev)
{
}

/*!
 * \brief The copy constructor for DeveloperChanges objects.
 * \param otherChanges = The other DeveloperChanges object from where the values will be copied.
 */
DeveloperChanges::DeveloperChanges(DeveloperChanges &otherChanges) :
    EntryChanges(&otherChanges)
{
}

/*!
 * \brief The assignment operator for DeveloperChanges objects.
 * \param otherChanges = The other DeveloperChanges object from where the values will be copied.
 * \return A pointer to the DeveloperChanges object on the left of the assignment operator.
 */
DeveloperChanges& DeveloperChanges::operator=(const DeveloperChanges &otherChanges) {
    currentId = otherChanges.currentId;
    iterator = otherChanges.iterator;
    changes = otherChanges.changes;

    return *this;
}

/*!
 * \brief Adds a new developer ID to the list of changes.
 * \param newId = The new developer ID
 */
void DeveloperChanges::setNewId(const int &newId) {
    changes[changes.size()] = qMakePair(ChangeTypes::Developer_ID, newId);
}

/*!
 * \brief Adds a new developer name to the list of changes.
 * \param n = The new developer name
 */
void DeveloperChanges::setNewName(const QString& n) {
    changes[changes.size()] = qMakePair(ChangeTypes::Name, n);
}

/*!
 * \brief Generate a DeveloperChanges object from differences between two developer objects.
 * \param devA = The main developer object
 * \param devB = The second developer object
 * \return A DeveloperChanges object with all the changes.
 * \note The first parameter is always regarded as the main object that should be changed.
 */
DeveloperChanges DeveloperChanges::changesFrom(const Developer &devA, const Developer &devB) {
    DeveloperChanges changes(devA.getId());

    if (devA.getId() != devB.getId())
        changes.setNewId(devB.getId());

    if (devA.getName() != devB.getName())
        changes.setNewName(devB.getName());

    return changes;
}
