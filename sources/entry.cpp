#include "headers/entry.h"

/*!
 * \brief Creates an entry object with the provided values.
 * \param entryId = The entry's ID in the database
 * \param entryName = The name of the entry
 */
Entry::Entry(const int &entryId,
             const QString &entryName) :
    id(entryId),
    name(entryName)
{
}

/*!
 * \brief The entry destructor.
 */
Entry::~Entry() {
}

/*!
 * \brief The copy constructor for entry objects.
 * \param otherEntry = The entry object from which the values will be copied
 */
Entry::Entry(const Entry &otherEntry) :
    id(otherEntry.id),
    name(otherEntry.name)
{
}

/*!
 * \brief The assignment operator for entry objects.
 * \param otherEntry = The entry object from which the values will be copied
 * \return A pointer to the variable to the left of the operator
 */
Entry& Entry::operator=(const Entry &otherEntry) {
    id = otherEntry.id;
    name = otherEntry.name;

    return *this;
}

/*!
 * \brief Assigns a new ID.
 * \param entryId = The new entry ID
 */
void Entry::setId(const int &entryId) {
    id = entryId;
}

/*!
 * \brief Assigns a new name.
 * \param entryName = The new entry name
 */
void Entry::setName(const QString &entryName) {
    name = entryName;
}

/*!
 * \brief Returns the entry ID.
 * \return An integer with the entry ID
 */
int Entry::getId() const {
    return id;
}

/*!
 * \brief Returns the entry's name.
 * \return A QString with the entry name
 */
QString Entry::getName() const {
    return name;
}
