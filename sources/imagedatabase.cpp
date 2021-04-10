#include "headers/imagedatabase.h"

#include <QFile>
#include <QDir>

/*!
 * \brief Instantiates the image database object.
 * \param parent = The QObject to which this database is binded.
 */
ImageDatabase::ImageDatabase(QObject *parent) :
    Database(parent),
    lastCoverId(-1)
{
}

/*!
 * \brief Creates the image database if it doesn't exist yet.
 * \param dir = The full path to where the database should be stored.
 * \return A boolean value that states whether the creation was successful or not.
 */
bool ImageDatabase::createDatabase(const QString &dir) {
    location = dir;

    if (!QDir(location).exists())
        return QDir().mkdir(location);

    return true;
}

/*!
 * \brief Returns the ID of the last cover to be added to the DB.
 * \return An integer with the ID of the last added cover.
 */
int ImageDatabase::getLastCoverId() const {
    return lastCoverId;
}
