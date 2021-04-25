#ifndef SERVICECHANGES_H
#define SERVICECHANGES_H

#include "service.h"

#include <QVariant>

/*!
 * \brief Class used to extract all the differences between two Service objects.
 */
class ServiceChanges
{
public:
    ServiceChanges(const int &sid);
    ServiceChanges(const Service &serv);
    ServiceChanges(const ServiceChanges &otherChanges);
    ServiceChanges& operator=(const ServiceChanges &otherChanges);
    int size() const;
    QPair<QString, QVariant> next();
    bool hasNext() const;
    void toStart();

    void setNewServId(const int &sid);
    void setNewName(const QString& n);

    int getCurrentServId() const;
    QHash<int, QPair<QString, QVariant> > getAllChanges() const;

    static ServiceChanges changesFrom(const Service &servA, const Service &servB);

private:
    int servId;         ///< The ID of the service entry to be changed
    int iterator;       ///< Used to iterate through the list of changes
    QHash<int, QPair<QString, QVariant> > changes;  ///< A dynamic list of all the changes to the service
};

#endif // SERVICECHANGES_H
