#ifndef PLATFORMCHANGES_H
#define PLATFORMCHANGES_H

#include "platform.h"
#include "entrychanges.h"

/*!
 * \brief Class used to extract all the differences between two Platform objects.
 */
class PlatformChanges : public EntryChanges
{
public:
    PlatformChanges(const int &pid);
    PlatformChanges(Platform &plat);
    PlatformChanges(PlatformChanges &otherChanges);
    PlatformChanges& operator=(const PlatformChanges &otherChanges);

    void setNewId(const int &newId);
    void setNewName(const QString &n);
    void setNewGeneration(const int &gen);
    void setNewReleaseDate(const QDate &rel);

    static PlatformChanges changesFrom(const Platform &platA, const Platform &platB);

private:
};

#endif // PLATFORMCHANGES_H
