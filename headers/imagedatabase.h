#ifndef IMAGEDATABASE_H
#define IMAGEDATABASE_H

#include "database.h"
#include "game.h"

#include <QObject>
#include <QGuiApplication>
#include <QSqlDatabase>

/*!
 * \brief The class for images in the database.
 * \note This class stores its images in the file system, but stores information about the images in an SQLite database.
 */
class ImageDatabase : public Database
{
    Q_OBJECT
public:
    explicit ImageDatabase(const QString &conName, QObject *parent = nullptr);
    bool createDatabase(const QString &imgDir = QGuiApplication::applicationDirPath() + "/images");

    bool addCover(const QString &filePath);
    bool addCover(const QPixmap &img, const QString &suffix);
    bool addCover(const QByteArray &img, const QString &suffix);
    bool addCover(const Game &game, const QString &suffix);

    int getLastCoverId() const;
    QString getCoverPath(const int &coverId);
    QString getCoverSuffix(const int &coverId);

    static QString getFileSuffix(const QString &filePath);
    static QString removeFileSuffix(QString fileName);

    const static QList<QString> supportedSuffixes;  ///< List of supported image file suffixes. The entire ImageDatabase gets its suffix information from this list.

signals:
    void imageDatabaseReset();  ///< Emitted when the CoverDB is cleared. For informing other classes that the old cover IDs no longer exist.

public slots:

private:
    QSqlDatabase coverDataDb;   ///< Database used to store information about the covers.
    QString coverDataLocation;  ///< The file path to the coverDataDB.
    int lastCoverId;            ///< The ID of the last cover in the database.

    void openDb();
    void closeDb();
    bool createCoverDataDB();
    bool readImagesToCoverDataDB();
    int addCoverData(const QString &fileSuffix);
};

#endif // IMAGEDATABASE_H
