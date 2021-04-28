#ifndef ENTRYCHANGES_H
#define ENTRYCHANGES_H

#include "entry.h"

#include <QVariant>

/*!
 * \brief Enum for the types of changes that can be made to an entry.
 */
enum class ChangeTypes {
    Game_ID,        ///< 0
    Platform_ID,    ///< 1
    Service_ID,     ///< 2
    Developer_ID,   ///< 3
    Publisher_ID,   ///< 4
    Cover_ID,       ///< 5
    Cover_Image,    ///< 6
    Name,           ///< 7
    Exclusive,      ///< 8
    Expansion,      ///< 9
    Release_Date,   ///< 10
    Physical,       ///< 11
    Edition,        ///< 12
    Date_Added,     ///< 13
    Generation      ///< 14
};

/*!
 * \brief The interface class for all changes based classes.
 */
class EntryChanges
{
public:
    EntryChanges(const int &entryId);
    EntryChanges(Entry *entry);
    EntryChanges(EntryChanges *otherChanges);
    int size() const;
    QPair<ChangeTypes, QVariant> next();
    bool hasNext() const;
    void toStart();

    virtual void setNewId(const int &newId) = 0;

    int getCurrentId() const;
    QHash<int, QPair<ChangeTypes, QVariant> > getAllChanges() const;

protected:
    int currentId;          ///< The ID of the entry to be changed
    int iterator;           ///< Used to iterate through the list of changes
    QHash<int, QPair<ChangeTypes, QVariant> > changes;  ///< A dynamic list of all the changes to the entry
};

#endif // ENTRYCHANGES_H
