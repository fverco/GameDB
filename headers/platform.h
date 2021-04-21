#ifndef PLATFORM_H
#define PLATFORM_H

#include <QDate>

/*!
 * \brief A class that provides structured storage of platform entries.
 */
class Platform
{
public:
    Platform(const int &pid, const QString &n);
    Platform(const Platform& otherPlat);
    Platform& operator=(const Platform& otherPlat);

    void setPlatId(const int &pid);
    void setName(const QString& n);
    void setGeneration(const int& gen);
    void setReleaseDate(const QDate& rel);

    int getPlatId() const;
    QString getName() const;
    int getGeneration() const;
    QDate getReleaseDate() const;

private:
    int platId;         ///< The ID of the platform in the database.
    QString name;       ///< The name of the platform.
    int generation;     ///< The console generation of the platform.
    QDate releaseDate;  ///< The date the platform was released (generally world wide).
};


#endif // PLATFORM_H
