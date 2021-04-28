#ifndef SERVICE_H
#define SERVICE_H

#include "entry.h"

/*!
 * \brief A class that provides structured storage of service entries.
 */
class Service : public Entry
{
public:
    Service(const int &sid, const QString &n);
    Service(const Service& otherServ);
    Service& operator=(const Service& otherServ);

    EntryTypes getEntryType() const;

private:
};


#endif // SERVICE_H
