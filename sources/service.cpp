#include "headers/service.h"

/*!
 * \brief Creates a service object with the provided values.
 * \param sid = The service ID in the database
 * \param n = The name of the service
 */
Service::Service(const int &sid, const QString &n) :
    servId(sid),
    name(n)
{
}

/*!
 * \brief The copy constructor for service objects.
 * \param otherServ = The service object from which the values will be copied
 */
Service::Service(const Service& otherServ) :
    servId(otherServ.servId),
    name(otherServ.name)
{
}

/*!
 * \brief The assignment operator for service objects.
 * \param otherServ = The service object from which the values will be copied
 * \return A pointer to the variable to the left of the operator
 */
Service& Service::operator=(const Service& otherServ) {
    servId = otherServ.servId;
    name = otherServ.name;

    return *this;
}

/*!
 * \brief Assigns a new service ID.
 * \param sid = The new service ID
 */
void Service::setServId(const int &sid) {
    servId = sid;
}

/*!
 * \brief Assigns a new service name.
 * \param n = The new service name
 */
void Service::setName(const QString &n) {
    name = n;
}

/*!
 * \brief Returns the service ID.
 * \return An integer with the service ID
 */
int Service::getServId() const {
    return servId;
}

/*!
 * \brief Returns the service name.
 * \return A QString with the service name
 */
QString Service::getName() const {
    return name;
}
