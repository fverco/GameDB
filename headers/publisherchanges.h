#ifndef PUBLISHERCHANGES_H
#define PUBLISHERCHANGES_H

#include "publisher.h"
#include "entrychanges.h"

/*!
 * \brief Class used to extract all the differences between two Developer objects.
 */
class PublisherChanges : public EntryChanges
{
public:
    PublisherChanges(const int &pid);
    PublisherChanges(Publisher &pub);
    PublisherChanges(PublisherChanges &otherChanges);
    PublisherChanges& operator=(const PublisherChanges &otherChanges);

    void setNewId(const int &newId);
    void setNewName(const QString& n);

    static PublisherChanges changesFrom(const Publisher &pubA, const Publisher &pubB);

private:
};

#endif // PUBLISHERCHANGES_H
