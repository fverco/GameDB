#include "headers/service.h"

/*!
 * \brief Creates a service object with the provided values.
 * \param sid = The service ID in the database
 * \param n = The name of the service
 */
Service::Service(const int &sid, const QString &n) :
    Entry(sid, n)
{
}

/*!
 * \brief The copy constructor for service objects.
 * \param otherServ = The service object from which the values will be copied
 */
Service::Service(const Service& otherServ) :
    Entry(otherServ.id, otherServ.name)
{
}

/*!
 * \brief The assignment operator for service objects.
 * \param otherServ = The service object from which the values will be copied
 * \return A pointer to the variable to the left of the operator
 */
Service& Service::operator=(const Service& otherServ) {
    id = otherServ.id;
    name = otherServ.name;

    return *this;
}

/*!
 * \brief Returns the type of entry the calling object is.
 * \return  An EntryTypes enum of Service
 * \note The returning value will always be the Service enum.
 */
EntryTypes Service::getEntryType() const {
    return EntryTypes::Service;
}
