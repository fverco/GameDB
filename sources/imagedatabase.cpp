#include "headers/imagedatabase.h"

#include <QFile>
#include <QDir>
#include <QPixmap>
#include <QSqlQuery>
#include <QSqlError>

/*!
 * \brief Instantiates the image database object.
 * \param parent = The QObject to which this database is binded.
 */
ImageDatabase::ImageDatabase(QObject *parent) :
    Database(parent),
    coverDataDb(QSqlDatabase::addDatabase("QSQLITE", "imageId")),
    coverDataLocation(QGuiApplication::applicationDirPath() + "/image.data"),
    lastCoverId(-1)
{
}

/*!
 * \brief Creates the image database if it doesn't exist yet.
 * \param imgDir = The full path to where the database should be stored.
 * \return A boolean value that states whether the creation was successful or not.
 * \note This creates the images directory and the image.data database file if they don't already exist.
 */
bool ImageDatabase::createDatabase(const QString &imgDir) {
    location = imgDir;

    if (!QDir(location).exists()) {
        if (QDir().mkdir(location)) {
            if (!createCoverDataDB())
                return false;
        } else
            return false;
    }

    if (!QFile::exists(coverDataLocation)) {
        if (!createCoverDataDB())
            return false;

        QDir directory(location);
        QStringList images(directory.entryList(QStringList() << "*.jpg"
                                                            << "*.JPG"
                                                            << "*.jpeg"
                                                            << "*.JPEG"
                                                            << "*.png"
                                                            << "*.PNG"
                                                            << "*.bmp"
                                                            << "*.BMP" ,QDir::Files, QDir::Name));
        QString lastImage(images.at(images.length()-1));
        QString lastImageName("");

        for (int i(0); i < lastImage.length(); ++i) {
            if (lastImage.at(i) != '.') {
                lastImageName += lastImage.at(i);
            } else
                break;
        }

        lastCoverId = lastImageName.toInt();
        setLastCoverDB(lastImageName.toInt());
    }

    return getLastCoverDB();
}

/*!
 * \brief Adds a new cover image to the database by loading it from a given file path.
 * \param filePath = The path to the image file
 * \return A boolean value that states whether the operation was successful or not.
 * \note To obtain the new cover's ID, call the getLastCoverId() function.
 * \see getLastCoverId()
 */
bool ImageDatabase::addCover(const QString &filePath) {
    QPixmap pixImg(filePath);
    QString format(getFileSuffix(filePath));
    bool success(false);

    success = pixImg.save(getDBLocation() + "/" + QString::number(++lastCoverId) + "." + format, format.toStdString().c_str());

    if (success) {
        setLastCoverDB(lastCoverId);
        return true;
    }

    return false;
}

/*!
 * \brief Adds a new cover image to the database.
 * \param img = The image
 * \param imgFormat = The file format of the image
 * \return A boolean value that states whether the operation was successful or not.
 * \note To obtain the new cover's ID, call the getLastCoverId() function.
 * \see getLastCoverId()
 */
bool ImageDatabase::addCover(const QByteArray &img, const ImageFormats &imgFormat) {
    QPixmap pixImg;
    pixImg.loadFromData(img);
    bool success(false);

    const char* format("");

    switch (imgFormat) {
        case ImageFormats::JPG: format = "jpg";
                                break;
        case ImageFormats::PNG: format = "png";
                                break;
        case ImageFormats::BMP: format = "bmp";
                                break;
        default: format = "jpg";
    }

    success = pixImg.save(getDBLocation() + "/" + QString::number(++lastCoverId), format);

    if (success) {
        setLastCoverDB(lastCoverId);
        return true;
    }

    return false;
}

/*!
 * \brief Adds a new cover image to the database.
 * \param game = A game object with a cover image
 * \param imgFormat = The file format of the image
 * \return A boolean value that states whether the operation was successful or not.
 * \note This function is exactly the same as addCover(const QByteArray &img, const ImageFormats &imgFormat).
 * \note To obtain the new cover's ID, call the getLastCoverId() function.
 * \see getLastCoverId()
 */
bool ImageDatabase::addCover(const Game &game, const ImageFormats &imgFormat) {
    return addCover(game.getCoverImage(), imgFormat);
}

/*!
 * \brief Returns the ID of the last cover to be added to the DB.
 * \return An integer with the ID of the last added cover.
 * \note This is not the same as getLastCoverDB(). Unlike getLastCoverDB() this call does not make any database queries.
 */
int ImageDatabase::getLastCoverId() const {
    return lastCoverId;
}

/*!
 * \brief Detects the suffix of a provided file.
 * \param filePath = The path to the file
 * \return A QString with the suffix (excluding the dot).
 */
QString ImageDatabase::getFileSuffix(const QString &filePath) {
    QString format("");

    // Find the file suffix backwards.
    for (int i(filePath.length() - 1); filePath.at(i) != '.'; --i)
        format += filePath.at(i);

    // Reverse the suffix to normal direction.
    std::reverse(format.begin(), format.end());

    return format;
}

/*!
 * \brief Opens a connection to the database file, if it's not open already.
 */
void ImageDatabase::openDb() {
    if (!coverDataDb.isOpen()) {
        coverDataDb.setDatabaseName(coverDataLocation);
        coverDataDb.open();
    }
}

/*!
 * \brief Closes the connection to the database file, if it is open.
 */
void ImageDatabase::closeDb() {
    if (coverDataDb.isOpen())
        coverDataDb.close();
}

/*!
 * \brief Creates the cover data database used to store information about the cover images.
 * \return A boolean value that states whether the operation was successful or not.
 */
bool ImageDatabase::createCoverDataDB() {
    coverDataDb.setDatabaseName(coverDataLocation);

    if (coverDataDb.open()) {
        QSqlQuery imageQry(coverDataDb);

        imageQry.prepare("CREATE TABLE CoverData ("
                         "last_cover_id INTEGER UNIQUE NOT NULL PRIMARY KEY);");

        if (!imageQry.exec()) {
            closeDb();
            return false;
        }

        imageQry.prepare("INSERT INTO CoverData (last_cover_id) "
                         "VALUES (-1);");

        if (!imageQry.exec()) {
            closeDb();
            return false;
        }

        closeDb();
    }

    return true;
}

/*!
 * \brief Updates the last cover ID in the database to the provided ID.
 * \param id = The new last cover ID
 * \return A boolean value that states whether the operation was successful or not.
 * \note This function must be called every time the lastCoverId is changed to ensure it persists each time the application is closed.
 */
bool ImageDatabase::setLastCoverDB(const int &id) {
    openDb();

    QSqlQuery imageQry(coverDataDb);

    imageQry.clear();
    imageQry.prepare("UPDATE CoverData SET last_cover_id = :id");
    imageQry.bindValue(":id", id);

    if (!imageQry.exec()) {
        closeDb();
        return false;
    }

    closeDb();
    return true;
}

/*!
 * \brief Retrieves the last cover ID stored in the database and applies it to lastCoverId.
 * \return A boolean value that states whether the operation was successful or not.
 * \note This function is not the same as getLastCoverId(). This function must ONLY be called if absolutely necessary, such as during boot up of the application.\n If you simply need to get the last cover ID, call getLastCoverId() instead.
 * \see getLastCoverId()
 */
bool ImageDatabase::getLastCoverDB() {
    openDb();

    QSqlQuery imageQry(coverDataDb);

    imageQry.prepare("SELECT last_cover_id FROM CoverData");
    if (imageQry.exec()) {
        if(imageQry.next())
            lastCoverId = imageQry.value(0).toInt();
        else {
            closeDb();
            return false;
        }
    } else {
        closeDb();
        return false;
    }

    closeDb();
    return true;
}
