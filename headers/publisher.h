#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "entry.h"

/*!
 * \brief A class that provides structured storage of publisher entries.
 */
class Publisher : public Entry
{
public:
    Publisher(const int &pid, const QString &n);
    Publisher(const Publisher& otherPub);
    Publisher& operator=(const Publisher& otherPub);

    EntryTypes getEntryType() const;

private:
};

#endif // PUBLISHER_H
