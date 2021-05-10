#ifndef IMAGEDATABASE_H
#define IMAGEDATABASE_H

#include "database.h"
#include "game.h"

#include <QObject>
#include <QGuiApplication>
#include <QSqlDatabase>

/*!
 * \brief Enum for all the supported image formats by the application.
 */
enum class ImageFormats {
    JPG,    ///< 0
    PNG,    ///< 1
    BMP     ///< 2
};

/*!
 * \brief The class for images in the database.
 * \note This class stores its images in the file system, but stores information about the images in an SQLite database.
 */
class ImageDatabase : public Database
{
    Q_OBJECT
public:
    explicit ImageDatabase(QObject *parent = nullptr);
    bool createDatabase(const QString &imgDir = QGuiApplication::applicationDirPath() + "/images");

    bool addCover(const QString &filePath);
    bool addCover(const QByteArray &img, const ImageFormats &imgFormat);
    bool addCover(const Game &game, const ImageFormats &imgFormat);

    int getLastCoverId() const;

    static QString getFileSuffix(const QString &filePath);

signals:

public slots:

private:
    QSqlDatabase coverDataDb;   ///< Database used to store information about the covers.
    QString coverDataLocation;  ///< The file path to the coverDataDb
    int lastCoverId;            ///< ID of the last cover image to be added to the DB

    void openDb();
    void closeDb();
    bool createCoverDataDB();
    bool setLastCoverDB(const int &id);
    bool getLastCoverDB();
};

#endif // IMAGEDATABASE_H
