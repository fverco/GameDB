#include "headers/developer.h"

/*!
 * \brief Creates a developer object with the provided values.
 * \param did = The developer ID in the database
 * \param n = The name of the developer
 */
Developer::Developer(const int &did, const QString &n) :
    Entry(did, n)
{
}

/*!
 * \brief The copy constructor for developer objects.
 * \param otherDev = The developer object from which the values will be copied
 */
Developer::Developer(const Developer& otherDev) :
    Entry(otherDev.id, otherDev.name)
{
}

/*!
 * \brief The assignment operator for developer objects.
 * \param otherDev = The developer object from which the values will be copied
 * \return A pointer to the variable to the left of the operator
 */
Developer& Developer::operator=(const Developer& otherDev) {
    id = otherDev.id;
    name = otherDev.name;

    return *this;
}

/*!
 * \brief Returns the type of entry the calling object is.
 * \return An EntryTypes enum of Developer
 * \note The returning value will always be the Developer enum.
 */
EntryTypes Developer::getEntryType() const {
    return EntryTypes::Developer;
}
