#ifndef PLATFORM_H
#define PLATFORM_H

#include "entry.h"

#include <QDate>

/*!
 * \brief A class that provides structured storage of platform entries.
 */
class Platform : public Entry
{
public:
    Platform(const int &pid, const QString &n);
    Platform(const Platform &otherPlat);
    Platform& operator=(const Platform &otherPlat);

    void setGeneration(const int &gen);
    void setReleaseDate(const QDate &rel);

    int getGeneration() const;
    QDate getReleaseDate() const;
    EntryTypes getEntryType() const;

private:
    int generation;     ///< The console generation of the platform.
    QDate releaseDate;  ///< The date the platform was released (generally world wide).
};


#endif // PLATFORM_H
