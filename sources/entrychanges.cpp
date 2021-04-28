#include "headers/entrychanges.h"

/*!
 * \brief Create an EntryChanges object with default values.
 * \param entryId = The entry ID
 */
EntryChanges::EntryChanges(const int &entryId) :
    currentId(entryId),
    iterator(0)
{
}

/*!
 * \brief Creates an EntryChanges object from any Entry object.
 * \param entry = The entry that should be changed
 */
EntryChanges::EntryChanges(Entry *entry) :
    currentId(entry->getId()),
    iterator(0)
{
}

/*!
 * \brief The copy constructor for EntryChanges objects.
 * \param otherChanges = The other EntryChanges object from where the values will be copied.
 */
EntryChanges::EntryChanges(EntryChanges *otherChanges) :
    currentId(otherChanges->currentId),
    iterator(otherChanges->iterator),
    changes(otherChanges->changes)
{
}

/*!
 * \brief Returns the amount of changes to the entry.
 * \return An integer with the size of the changes data stucture.
 */
int EntryChanges::size() const {
    return changes.size();
}

/*!
 * \brief Returns the change currently pointed to, then moves up by one spot.
 * \return A QPair in the form of <(Value type changed), (New Value)>.
 */
QPair<ChangeTypes, QVariant> EntryChanges::next() {
    return changes.value(iterator++);
}

/*!
 * \brief Are there more changes left in the list?
 * \return A boolean value.
 */
bool EntryChanges::hasNext() const {
    return (iterator < size() ? true:false);
}

/*!
 * \brief Moves the iterator back to the start.
 */
void EntryChanges::toStart() {
    iterator = 0;
}

/*!
 * \brief Returns the current entry ID.
 * \return An integer of the ID.
 * \note This is the entry ID to which this Changes object refers to, to be changed.
 */
int EntryChanges::getCurrentId() const {
    return currentId;
}

/*!
 * \brief Returns a data structure with all entry changes.
 * \return  A QHash with the form of <(Change ID), <(Change type, Change value)> >
 */
QHash<int, QPair<ChangeTypes, QVariant> > EntryChanges::getAllChanges() const {
    return changes;
}
