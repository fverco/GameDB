#ifndef DEVELOPERCHANGES_H
#define DEVELOPERCHANGES_H

#include "developer.h"
#include "entrychanges.h"

/*!
 * \brief Class used to extract all the differences between two Developer objects.
 */
class DeveloperChanges : public EntryChanges
{
public:
    DeveloperChanges(const int &did);
    DeveloperChanges(Developer &dev);
    DeveloperChanges(DeveloperChanges &otherChanges);
    DeveloperChanges& operator=(const DeveloperChanges &otherChanges);

    void setNewId(const int &newId);
    void setNewName(const QString& n);

    static DeveloperChanges changesFrom(const Developer &devA, const Developer &devB);

private:
};

#endif // DEVELOPERCHANGES_H
