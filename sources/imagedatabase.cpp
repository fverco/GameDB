#include "headers/imagedatabase.h"

#include <QFile>
#include <QDir>
#include <QPixmap>
#include <QSqlQuery>
#include <QSqlError>

const QList<QString> ImageDatabase::supportedSuffixes({"jpg", "jpeg", "png", "bmp"});

/*!
 * \brief Instantiates the image database object.
 * \param conName = The name of the connection (Must be unique)
 * \param parent = The QObject to which this database is binded
 * \note By default it specifies the CoverDataDB as a file named "image.data" in the application root, but doesn't create it yet.
 */
ImageDatabase::ImageDatabase(const QString &conName, QObject *parent) :
    Database(parent),
    coverDataDb(QSqlDatabase::addDatabase("QSQLITE", conName)),
    coverDataLocation(QGuiApplication::applicationDirPath() + "/image.data"),
    lastCoverId(-1)
{
}

/*!
 * \brief Creates the image database if it doesn't exist yet.
 * \param imgDir = The full path to where the images should be stored.
 * \return A boolean value that states whether the creation was successful or not.
 * \note This creates the images directory and the CoverDataDB, specified by the constructor, if they don't already exist.
 * If the images directory doesn't exist then it will create it, reset the CoverDataDB and emit the signal imageDatabaseReset().
 * If only the CoverDataDB file is not found, then it will create it and detect all the images already in the images directory.
 */
bool ImageDatabase::createDatabase(const QString &imgDir) {
    location = imgDir;

    if (!QDir(location).exists()) {
        if (QDir().mkdir(location)) {
            if (QFile::remove(coverDataLocation)) {
                if (createCoverDataDB())
                    emit imageDatabaseReset();
                else
                    return false;
            } else
                return false;
        } else
            return false;
    }

    if (!QFile::exists(coverDataLocation)) {
        if (createCoverDataDB())
            return readImagesToCoverDataDB();
        else
            return false;
    }

    return true;
}

/*!
 * \brief Adds a new cover image to the database by loading it from a given file path.
 * \param filePath = The path to the image file
 * \return A boolean value that states whether the operation was successful or not.
 * \note This is an overloaded function.
 * \note To obtain the new cover's ID, call the getLastCoverId() function.
 * \see getLastCoverId()
 */
bool ImageDatabase::addCover(const QString &filePath) {
    QPixmap pixImg(filePath);
    QString suffix(getFileSuffix(filePath));

    return addCover(pixImg, suffix);
}

/*!
 * \brief Adds a new cover image to the database by loading it from a QPixmap.
 * \param img = The QPixmap image
 * \param suffix = The file suffix
 * \return A boolean value that states whether the operation was successful or not.
 * \note To obtain the new cover's ID, call the getLastCoverId() function.
 * \see getLastCoverId()
 */
bool ImageDatabase::addCover(const QPixmap &img, const QString &suffix)
{
    bool success(false);
    int coverId(addCoverData(suffix));

    if (coverId > -1) {
        success = img.save(getDBLocation() + "/" + QString::number(coverId) + "." + suffix.toLower(), suffix.toStdString().c_str());
        lastCoverId = coverId;
        return success;
    }

    return false;
}

/*!
 * \brief Adds a new cover image to the database by loading it from a QByteArray.
 * \param img = The QByteArray image
 * \param suffix = The file suffix
 * \return A boolean value that states whether the operation was successful or not.
 * \note This is an overloaded function.
 * \note To obtain the new cover's ID, call the getLastCoverId() function.
 * \see getLastCoverId()
 */
bool ImageDatabase::addCover(const QByteArray &img, const QString &suffix) {
    QPixmap pixImg;
    pixImg.loadFromData(img);

    return addCover(pixImg, suffix);
}

/*!
 * \brief Adds a new cover image to the database by loading the QByteArray from a Game object.
 * \param game = A game object with a cover image
 * \param suffix = The file suffix
 * \return A boolean value that states whether the operation was successful or not.
 * \note This is an overloaded function.
 * \note To obtain the new cover's ID, call the getLastCoverId() function.
 * \see getLastCoverId()
 */
bool ImageDatabase::addCover(const Game &game, const QString &suffix) {
    return addCover(game.getCoverImage(), suffix);
}

/*!
 * \brief Retrieves the ID of the last cover image added to the database.
 * \return An Integer with the cover ID. Returns -1 if no cover image has ever been added.
 */
int ImageDatabase::getLastCoverId() const {
    return lastCoverId;
}

/*!
 * \brief Retrieves the full file path to a cover image.
 * \param coverId = The ID of the cover image in the database
 * \return A QString with the full file path. Returns an empty QString if that cover isn't found or an error has occurred.
 * \note This function uses SQL queries.
 */
QString ImageDatabase::getCoverPath(const int &coverId)
{
    QString coverPath("");
    QString coverSuffix(getCoverSuffix(coverId));

    coverPath = location + "/" + QString::number(coverId) + "." + coverSuffix;

    if(!QFile::exists(coverPath))
        coverPath = "";

    return coverPath;
}

/*!
 * \brief Retrieves the suffix/image format of the cover in the database.
 * \param coverId = The ID of the cover image in the database
 * \return QString with the suffix/image format. Returns an empty QString if that cover isn't found or an error has occurred.
 */
QString ImageDatabase::getCoverSuffix(const int &coverId)
{
    openDb();

    QString coverSuffix("");
    QSqlQuery imageQry(coverDataDb);

    imageQry.prepare("SELECT suffix "
                     "FROM CoverData "
                     "WHERE cover_id = ?;");
    imageQry.addBindValue(coverId);

    if (imageQry.exec()) {
        if (imageQry.next()) {
            coverSuffix = imageQry.value(0).toString();

            closeDb();
            return coverSuffix;
        }
    }

    closeDb();
    return coverSuffix;
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
 * \brief Returns a file name without the file suffix.
 * \param fileName = The full path to the file or just the file name.
 * \return QString of the file name with the file suffix removed.
 */
QString ImageDatabase::removeFileSuffix(QString fileName)
{
    // Move nameSize to the last letter in fileName.
    int nameSize(fileName.length() - 1);

    // Count down until you reach the dot seperator.
    for (; fileName.at(nameSize) != '.'; --nameSize) {}

    // Find the suffix size by subtracting fileName size with the name size,
    // then remove that amount of letters from the end.
    fileName.chop(fileName.size() - nameSize);

    return fileName;
}

/*!
 * \brief Opens a connection to the CoverData database file, if it's not open already.
 */
void ImageDatabase::openDb() {
    if (!coverDataDb.isOpen()) {
        coverDataDb.setDatabaseName(coverDataLocation);
        coverDataDb.open();
    }
}

/*!
 * \brief Closes the connection to the CoverData database file, if it is open.
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
                         "cover_id INTEGER UNIQUE NOT NULL PRIMARY KEY AUTOINCREMENT,"
                         "suffix TEXT NOT NULL);");

        if (!imageQry.exec()) {
            qDebug() << "(ImageDB) Cover data DB creation error: " << imageQry.lastError().text() << Qt::endl;
            closeDb();
            return false;
        }

        closeDb();
    } else
        return false;

    return true;
}

/*!
 * \brief Detects all the image files in the images directory and records their data to the CoverData database.
 * \return A boolean value that states whether the operation was successful or not.
 * \note This ONLY detects image files correctly named from the number 1 and up.
 */
bool ImageDatabase::readImagesToCoverDataDB()
{
    QDir directory(location);

    // Create a filter list of all supported image files.
    QStringList fileFilterList;
    for (int i(0); i < supportedSuffixes.size(); ++i) {
        fileFilterList << "*." + supportedSuffixes.at(i);
        fileFilterList << "*." + supportedSuffixes.at(i).toUpper();
    }

    // Get a list of all image files in the existing images directory.
    QStringList images(directory.entryList(fileFilterList, QDir::Files, QDir::Name));

    int fileNameId(0);
    QString fileSuffix("");
    QVariantList idList,  suffixList;   // Lists of all recorded files to be added in bulk to the database.

    // Obtain the names and suffixes of all image files and add them to the lists.
    // NOTE: This will only record the files correctly named from 1 and up.
    for (int i(0); i < images.size(); ++i) {

        fileNameId = removeFileSuffix(images.at(i)).toInt();
        fileSuffix = getFileSuffix(images.at(i));

        if (fileNameId == i + 1) {
            idList << fileNameId;
            suffixList << fileSuffix;
        }
    }

    openDb();

    QSqlQuery imageQry(coverDataDb);

    imageQry.prepare("INSERT INTO CoverData (cover_id, suffix) "
                     "VALUES (?, ?);");

    imageQry.addBindValue(idList);
    imageQry.addBindValue(suffixList);

    if (!imageQry.execBatch()) {
        qDebug() << "(ImageDB) Cover data DB error detecting images: " << imageQry.lastError().text() << Qt::endl;
        closeDb();
        return false;
    }

    closeDb();
    return true;
}

/*!
 * \brief Creates a new cover ID in the database and adds the given suffix to it.
 * \param fileSuffix = The file suffix of the new cover image
 * \return An integer with the new cover ID. Returns -1 if an error occurs.
 */
int ImageDatabase::addCoverData(const QString &fileSuffix)
{
    if (supportedSuffixes.contains(fileSuffix.toLower())) {

        openDb();

        QSqlQuery imageQry(coverDataDb);

        imageQry.prepare("INSERT INTO CoverData (suffix) "
                         "VALUES (?);");
        imageQry.addBindValue(fileSuffix);

        if (imageQry.exec()) {
            int lastId(imageQry.lastInsertId().toInt());
            closeDb();
            return lastId;
        }

        closeDb();
    }

    return -1;
}
