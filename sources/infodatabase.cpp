#include "headers/infodatabase.h"

#include <QFile>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QSqlRecord>

/*!
 * \brief Instantiates the info database object.
 * \param parent = The QObject to which this database is binded.
 */
InfoDatabase::InfoDatabase(QObject *parent) :
    Database(parent),
    infoDb(QSqlDatabase::addDatabase("QSQLITE", "info"))
{
}

/*!
 * \brief Creates the info database file if it doesn't exist yet.
 * \param dir = The full path to where the database should be stored.
 * \return A boolean value that states whether the creation was successful or not.
 */
bool InfoDatabase::createDatabase(const QString &dir) {
    if (!QFile::exists(dir)) {
        infoDb.setDatabaseName(dir);

        if (infoDb.open()) {
            location = dir;
            QSqlQuery infoQry(infoDb);

            infoQry.prepare("CREATE TABLE Game ("
                            "game_id INTEGER UNIQUE NOT NULL PRIMARY KEY AUTOINCREMENT,"
                            "name TEXT NOT NULL,"
                            "exclusive INTEGER,"
                            "expansion INTEGER,"
                            "release_date INTEGER);");

            if (!infoQry.exec()) {
                //QMessageBox::critical(this, "Error 001", "Problem setting up database.");
                closeDb();
                return false;
            }

            infoQry.prepare("CREATE TABLE Platform ("
                            "plat_id INTEGER UNIQUE NOT NULL PRIMARY KEY AUTOINCREMENT,"
                            "name TEXT NOT NULL,"
                            "generation INTEGER,"
                            "release_date INTEGER);");

            if (!infoQry.exec()) {
                //QMessageBox::critical(this, "Error 002", "Problem setting up database.");
                closeDb();
                return false;
            }

            infoQry.prepare("CREATE TABLE Service ("
                            "serv_id INTEGER UNIQUE NOT NULL PRIMARY KEY AUTOINCREMENT,"
                            "name TEXT NOT NULL);");

            if (!infoQry.exec()) {
                //QMessageBox::critical(this, "Error 003", "Problem setting up database.");
                closeDb();
                return false;
            }

            infoQry.prepare("CREATE TABLE Developer ("
                            "dev_id INTEGER UNIQUE NOT NULL PRIMARY KEY AUTOINCREMENT,"
                            "name TEXT NOT NULL);");

            if (!infoQry.exec()) {
                //QMessageBox::critical(this, "Error 004", "Problem setting up database.");
                closeDb();
                return false;
            }

            infoQry.prepare("CREATE TABLE Publisher ("
                            "pub_id INTEGER UNIQUE NOT NULL PRIMARY KEY AUTOINCREMENT,"
                            "name TEXT NOT NULL);");

            if (!infoQry.exec()) {
                //QMessageBox::critical(this, "Error 005", "Problem setting up database.");
                closeDb();
                return false;
            }

            infoQry.prepare("CREATE TABLE Copy ("
                            "game_id INTEGER NOT NULL,"
                            "plat_id INTEGER NOT NULL,"
                            "serv_id INTEGER NOT NULL,"
                            "dev_id INTEGER NOT NULL,"
                            "pub_id INTEGER NOT NULL,"
                            "cover_id INTEGER,"
                            "physical INTEGER,"
                            "edition TEXT,"
                            "date_added INTEGER,"
                            "PRIMARY KEY (game_id, plat_id, serv_id),"
                            "FOREIGN KEY (game_id) REFERENCES Game (game_id),"
                            "FOREIGN KEY (plat_id) REFERENCES Platform (plat_id),"
                            "FOREIGN KEY (serv_id) REFERENCES Service (serv_id),"
                            "FOREIGN KEY (dev_id) REFERENCES Developer (dev_id),"
                            "FOREIGN KEY (pub_id) REFERENCES Publisher (pub_id),"
                            "FOREIGN KEY (cover_id) REFERENCES Cover (cover_id));");

            if (infoQry.exec()) {
                createdDb = true;
                return true;
            }
            else {
                closeDb();
                return false;
            }
        } else
            return false;
    } else {
        infoDb.setDatabaseName(dir);

        if (infoDb.open()) {
            location = dir;
            infoDb.close();
        } else
            return false;

        createdDb = true;
        return true;
    }
}

/*!
 * \brief Adds a new service entry to the database.
 * \param serv = The new service entry
 * \return A bool value that's true if it was successful.
 */
bool InfoDatabase::addService(const Service &serv) {
    openDb();
    QSqlQuery qryInfo(infoDb);

    qryInfo.prepare("INSERT INTO Service (Name)"
                    "VALUES (?)");
    qryInfo.addBindValue(serv.getName());

    if (qryInfo.exec()) {
        closeDb();
        return true;
    } else {
        closeDb();
        return false;
    }
}

/*!
 * \brief Adds a new developer entry to the database.
 * \param dev = The new developer entry
 * \return A bool value that's true if it was successful.
 */
bool InfoDatabase::addDeveloper(const Developer &dev) {
    openDb();
    QSqlQuery qryInfo(infoDb);

    qryInfo.prepare("INSERT INTO Developer (Name)"
                    "VALUES (?)");
    qryInfo.addBindValue(dev.getName());

    if (qryInfo.exec()) {
        closeDb();
        return true;
    } else {
        closeDb();
        return false;
    }
}

/*!
 * \brief Adds a new publisher entry to the database.
 * \param pub = The new publisher entry
 * \return A bool value that's true if it was successful.
 */
bool InfoDatabase::addPublisher(const Publisher &pub) {
    openDb();
    QSqlQuery qryInfo(infoDb);

    qryInfo.prepare("INSERT INTO Publisher (Name)"
                    "VALUES (?)");
    qryInfo.addBindValue(pub.getName());

    if (qryInfo.exec()) {
        closeDb();
        return true;
    } else {
        closeDb();
        return false;
    }
}

/*!
 * \brief Opens a connection to the database file, if it's not open already.
 */
void InfoDatabase::openDb() {
    if (!infoDb.isOpen()) {
        infoDb.setDatabaseName(location);
        infoDb.open();
    }
}

/*!
 * \brief Closes the connection to the database file, if it is open.
 */
void InfoDatabase::closeDb() {
    if (infoDb.isOpen())
        infoDb.close();
}
