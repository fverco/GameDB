#ifndef INFODATABASE_H
#define INFODATABASE_H

#include "database.h"

#include <QObject>
#include <QGuiApplication>
#include <QSqlDatabase>

/*!
 * \brief The class for all the game information (strictly text) in the database.
 * \note This class uses SQLite to store its data.
 */
class InfoDatabase : public Database
{
    Q_OBJECT
public:
    explicit InfoDatabase(QObject *parent = nullptr);
    bool createDatabase(const QString& dir = QGuiApplication::applicationDirPath() + "/info.data");
signals:

public slots:

private:
    QSqlDatabase infoDb;    ///< The database object that contains the SQLite database

    void openDb();
    void closeDb();
};

#endif // INFODATABASE_H