#ifndef INFODATABASE_H
#define INFODATABASE_H

#include "database.h"
#include "game.h"
#include "platform.h"
#include "service.h"
#include "developer.h"
#include "publisher.h"

#include <QObject>
#include <QGuiApplication>
#include <QSqlDatabase>

namespace GameList {
Q_NAMESPACE
enum Attributes {
    Name,
    Platform,
    Service,
    Developer,
    Publisher,
    Cover,
    Exclusive,
    Expansion,
    Physical,
    Edition,
    Year,
    Month,
    Day
};
Q_ENUM_NS(Attributes)
}

/*!
 * \brief The class for all the game information (strictly text) in the database.
 * \note This class uses SQLite to store its data.
 */
class InfoDatabase : public Database
{
    Q_OBJECT
public:
    explicit InfoDatabase(const QString &conName, QObject *parent = nullptr);
    bool createDatabase(const QString &dir = QGuiApplication::applicationDirPath() + "/info.data");

    QMap<int, QString> getPlatformNames();
    QMap<int, QString> getServiceNames();
    QMap<int, QString> getDeveloperNames();
    QMap<int, QString> getPublisherNames();
    int getGameCopyCount();
    QList< QMap<GameList::Attributes, QPair<int, QString> > > getGameList();

    bool addGame(Game &game);
    bool addPlatform(const Platform &plat);
    bool addService(const Service &serv);
    bool addDeveloper(const Developer &dev);
    bool addPublisher(const Publisher &pub);

signals:

public slots:
    bool resetCoverData();

private:
    QSqlDatabase infoDb;    ///< The database object that contains the SQLite database

    void openDb();
    void closeDb();
};

#endif // INFODATABASE_H
