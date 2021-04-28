#include "headers/publisher.h"

/*!
 * \brief Creates a publisher object with the provided values.
 * \param pid = The publisher ID in the database
 * \param n = The name of the publisher
 */
Publisher::Publisher(const int &pid, const QString &n) :
    Entry(pid, n)
{
}

/*!
 * \brief The copy constructor for publisher objects.
 * \param otherPub = The publisher object from which the values will be copied
 */
Publisher::Publisher(const Publisher& otherPub) :
    Entry(otherPub.id, otherPub.name)
{
}

/*!
 * \brief The assignment operator for publisher objects.
 * \param otherPub = The publisher object from which the values will be copied
 * \return A pointer to the variable to the left of the operator
 */
Publisher& Publisher::operator=(const Publisher& otherPub) {
    id = otherPub.id;
    name = otherPub.name;

    return *this;
}

/*!
 * \brief Returns the type of entry the calling object is.
 * \return An EntryTypes enum of Publisher
 * \note The returning value will always be the Publisher enum.
 */
EntryTypes Publisher::getEntryType() const {
    return EntryTypes::Publisher;
}
