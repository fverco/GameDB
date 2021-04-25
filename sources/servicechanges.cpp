#include "headers/servicechanges.h"

/*!
 * \brief Create a ServiceChanges objest with default values.
 * \param sid = The service ID
 */
ServiceChanges::ServiceChanges(const int &sid) :
    servId(sid),
    iterator(0)
{
}

/*!
 * \brief Creates a ServiceChanges object from a Service object.
 * \param serv = The service that should be changed.
 * \note This is the same as a default constructor, except it uses the ID of the given service object.
 */
ServiceChanges::ServiceChanges(const Service &serv) :
    servId(serv.getServId()),
    iterator(0)
{
}

/*!
 * \brief The copy constructor for ServiceChanges objects.
 * \param otherChanges = The other ServiceChanges object from where the values will be copied.
 */
ServiceChanges::ServiceChanges(const ServiceChanges &otherChanges) :
    servId(otherChanges.servId),
    iterator(otherChanges.iterator),
    changes(otherChanges.changes)
{
}

/*!
 * \brief The assignment operator for ServiceChanges objects.
 * \param otherChanges = The other ServiceChanges object from where the values will be copied.
 * \return A pointer to the ServiceChanges object on the left of the assignment operator.
 */
ServiceChanges& ServiceChanges::operator=(const ServiceChanges &otherChanges) {
    servId = otherChanges.servId;
    iterator = otherChanges.iterator;
    changes = otherChanges.changes;

    return *this;
}

/*!
 * \brief Returns the amount of changes to the service.
 * \return An integer with the size of the changes data structure.
 */
int ServiceChanges::size() const {
    return changes.size();
}

/*!
 * \brief Returns the change currently pointed to, then moves up by one spot.
 * \return A QPair in the form of <(Value type changed), (New Value)>.
 */
QPair<QString, QVariant> ServiceChanges::next() {
    return changes.value(iterator++);
}

/*!
 * \brief Are there more changes left in the list?
 * \return A boolean value.
 */
bool ServiceChanges::hasNext() const {
    return (iterator < size() ? true:false);
}

/*!
 * \brief Moves the iterator back to the start.
 */
void ServiceChanges::toStart() {
    iterator = 0;
}

/*!
 * \brief Adds a new service ID to the list of changes.
 * \param sid = The new service ID
 */
void ServiceChanges::setNewServId(const int &sid) {
    changes[changes.size()] = qMakePair(QString("Service ID"), sid);
}

/*!
 * \brief Adds a new service name to the list of changes.
 * \param n = The new service name
 */
void ServiceChanges::setNewName(const QString& n) {
    changes[changes.size()] = qMakePair(QString("Name"), n);
}

/*!
 * \brief Returns the current service ID.
 * \return An integer of the ID.
 * \note This is the service ID to which this Changes object refers to, to be changed.
 */
int ServiceChanges::getCurrentServId() const {
    return servId;
}

/*!
 * \brief Returns a data structure with all service changes.
 * \return A QHash with the form of <(Change ID), <(Change type, Change value)> >
 * \note A case where only the name of the service was changed: <0, <"Name", "Steam">>
 */
QHash<int, QPair<QString, QVariant> > ServiceChanges::getAllChanges() const {
    return changes;
}

/*!
 * \brief Generate a ServiceChanges object from differences between two service objects.
 * \param servA = The main service object
 * \param servB = The second service object
 * \return A ServiceChanges object with all the changes.
 * \note The first parameter is always regarded as the main object that should be changed.
 */
ServiceChanges ServiceChanges::changesFrom(const Service &servA, const Service &servB) {
    ServiceChanges changes(servA.getServId());

    if (servA.getServId() != servB.getServId())
        changes.setNewServId(servB.getServId());

    if (servA.getName() != servB.getName())
        changes.setNewName(servB.getName());

    return changes;
}
