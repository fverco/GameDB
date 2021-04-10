#ifndef IMAGEDATABASE_H
#define IMAGEDATABASE_H

#include "database.h"

#include <QObject>
#include <QGuiApplication>

/*!
 * \brief The class for images in the database.
 * \note This class does not actually use a DBMS like SQLite, instead it stores its images in the file system.
 */
class ImageDatabase : public Database
{
    Q_OBJECT
public:
    explicit ImageDatabase(QObject *parent = nullptr);
    bool createDatabase(const QString& dir = QGuiApplication::applicationDirPath() + "/images");

    int getLastCoverId() const;

signals:

public slots:

private:
    int lastCoverId;    ///< ID of the last cover image to be added to the DB
};

#endif // IMAGEDATABASE_H
