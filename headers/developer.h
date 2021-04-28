#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "entry.h"

/*!
 * \brief A class that provides structured storage of developer entries.
 */
class Developer : public Entry
{
public:
    Developer(const int &did, const QString &n);
    Developer(const Developer& otherDev);
    Developer& operator=(const Developer& otherDev);

    EntryTypes getEntryType() const;

private:
};

#endif // DEVELOPER_H
