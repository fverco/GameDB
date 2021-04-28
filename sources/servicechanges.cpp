#include "headers/servicechanges.h"

/*!
 * \brief Create a ServiceChanges objest with default values.
 * \param sid = The service ID
 */
ServiceChanges::ServiceChanges(const int &sid) :
    EntryChanges(sid)
{
}

/*!
 * \brief Creates a ServiceChanges object from a Service object.
 * \param serv = The service that should be changed.
 * \note This is the same as a default constructor, except it uses the ID of the given service object.
 */
ServiceChanges::ServiceChanges(Service &serv) :
    EntryChanges(&serv)
{
}

/*!
 * \brief The copy constructor for ServiceChanges objects.
 * \param otherChanges = The other ServiceChanges object from where the values will be copied.
 */
ServiceChanges::ServiceChanges(ServiceChanges &otherChanges) :
    EntryChanges(&otherChanges)
{
}

/*!
 * \brief The assignment operator for ServiceChanges objects.
 * \param otherChanges = The other ServiceChanges object from where the values will be copied.
 * \return A pointer to the ServiceChanges object on the left of the assignment operator.
 */
ServiceChanges& ServiceChanges::operator=(const ServiceChanges &otherChanges) {
    currentId = otherChanges.currentId;
    iterator = otherChanges.iterator;
    changes = otherChanges.changes;

    return *this;
}

/*!
 * \brief Adds a new service ID to the list of changes.
 * \param newId = The new service ID
 */
void ServiceChanges::setNewId(const int &newId) {
    changes[changes.size()] = qMakePair(ChangeTypes::Service_ID, newId);
}

/*!
 * \brief Adds a new service name to the list of changes.
 * \param n = The new service name
 */
void ServiceChanges::setNewName(const QString& n) {
    changes[changes.size()] = qMakePair(ChangeTypes::Name, n);
}

/*!
 * \brief Generate a ServiceChanges object from differences between two service objects.
 * \param servA = The main service object
 * \param servB = The second service object
 * \return A ServiceChanges object with all the changes.
 * \note The first parameter is always regarded as the main object that should be changed.
 */
ServiceChanges ServiceChanges::changesFrom(const Service &servA, const Service &servB) {
    ServiceChanges changes(servA.getId());

    if (servA.getId() != servB.getId())
        changes.setNewId(servB.getId());

    if (servA.getName() != servB.getName())
        changes.setNewName(servB.getName());

    return changes;
}
