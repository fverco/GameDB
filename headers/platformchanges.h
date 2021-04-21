#ifndef PLATFORMCHANGES_H
#define PLATFORMCHANGES_H

#include "platform.h"

#include <QDate>

/*!
 * \brief Class used to extract all the differences between two Platform objects.
 */
class PlatformChanges
{
public:
    PlatformChanges(const int &pid);
    PlatformChanges(const Platform &plat);
    PlatformChanges(const PlatformChanges &otherChanges);
    PlatformChanges& operator=(const PlatformChanges &otherChanges);
    int size() const;
    QPair<QString, QVariant> next();
    bool hasNext() const;
    void toStart();

    void setNewPlatId(const int &pid);
    void setNewName(const QString &n);
    void setNewGeneration(const int &gen);
    void setNewReleaseDate(const QDate &rel);

    int getCurrentPlatId() const;
    QHash<int, QPair<QString, QVariant> > getAllChanges() const;

    static PlatformChanges changesFrom(const Platform &platA, const Platform &platB);

private:
    int platId;         ///< The ID of the platform entry to be changed
    int iterator;       ///< Used to iterate through the list of changes
    QHash<int, QPair<QString, QVariant> > changes;  ///< A dynamic list of all the changes to the platform
};

#endif // PLATFORMCHANGES_H
