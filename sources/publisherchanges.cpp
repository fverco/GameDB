#include "headers/publisherchanges.h"

/*!
 * \brief Create a PublisherChanges object with default values.
 * \param pid = The publisher ID
 */
PublisherChanges::PublisherChanges(const int &pid) :
    EntryChanges(pid)
{
}

/*!
 * \brief Creates a PublisherChanges object from a Publisher object.
 * \param pub = The publisher that should be changed.
 * \note This is the same as a default constructor, except it uses the ID of the given publisher object.
 */
PublisherChanges::PublisherChanges(Publisher &pub) :
    EntryChanges(&pub)
{
}

/*!
 * \brief The copy constructor for PublisherChanges objects.
 * \param otherChanges = The other PublisherChanges object from where the values will be copied.
 */
PublisherChanges::PublisherChanges(PublisherChanges &otherChanges) :
    EntryChanges(&otherChanges)
{
}

/*!
 * \brief The assignment operator for PublisherChanges objects.
 * \param otherChanges = The other PublisherChanges object from where the values will be copied.
 * \return A pointer to the PublisherChanges object on the left of the assignment operator.
 */
PublisherChanges& PublisherChanges::operator=(const PublisherChanges &otherChanges) {
    currentId = otherChanges.currentId;
    iterator = otherChanges.iterator;
    changes = otherChanges.changes;

    return *this;
}

/*!
 * \brief Adds a new publisher ID to the list of changes.
 * \param newId = The new publisher ID
 */
void PublisherChanges::setNewId(const int &newId) {
    changes[changes.size()] = qMakePair(ChangeTypes::Publisher_ID, newId);
}

/*!
 * \brief Adds a new publisher name to the list of changes.
 * \param n = The new publisher name
 */
void PublisherChanges::setNewName(const QString& n) {
    changes[changes.size()] = qMakePair(ChangeTypes::Name, n);
}

/*!
 * \brief Generate a PublisherChanges object from differences between two publisher objects.
 * \param pubA = The main publisher object
 * \param pubB = The second publisher object
 * \return A PublisherChanges object with all the changes.
 * \note The first parameter is always regarded as the main object that should be changed.
 */
PublisherChanges PublisherChanges::changesFrom(const Publisher &pubA, const Publisher &pubB) {
    PublisherChanges changes(pubA.getId());

    if (pubA.getId() != pubB.getId())
        changes.setNewId(pubB.getId());

    if (pubA.getName() != pubB.getName())
        changes.setNewName(pubB.getName());

    return changes;
}
