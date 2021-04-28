#ifndef SERVICECHANGES_H
#define SERVICECHANGES_H

#include "service.h"
#include "entrychanges.h"

/*!
 * \brief Class used to extract all the differences between two Service objects.
 */
class ServiceChanges : public EntryChanges
{
public:
    ServiceChanges(const int &sid);
    ServiceChanges(Service &serv);
    ServiceChanges(ServiceChanges &otherChanges);
    ServiceChanges& operator=(const ServiceChanges &otherChanges);

    void setNewId(const int &newId);
    void setNewName(const QString& n);

    static ServiceChanges changesFrom(const Service &servA, const Service &servB);

private:
};

#endif // SERVICECHANGES_H
