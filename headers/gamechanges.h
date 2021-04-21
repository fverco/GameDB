#ifndef GAMECHANGES_H
#define GAMECHANGES_H

#include "game.h"

#include <QDate>

/*!
 * \brief Class used to extract all the differences between two Game objects.
 */
class GameChanges
{
public:
    GameChanges(const int &gid,
                const int &plid,
                const int &sid,
                const int &did,
                const int &puid,
                const int &cid);
    GameChanges(const Game &game);
    GameChanges(const GameChanges &otherChanges);
    GameChanges& operator=(const GameChanges &otherChanges);
    int size() const;
    QPair<QString, QVariant> next();
    bool hasNext() const;
    void toStart();

    void setNewGameId(const int &gid);
    void setNewPlatId(const int &plid);
    void setNewServId(const int &sid);
    void setNewDevId(const int &did);
    void setNewPubId(const int &puid);
    void setNewCoverId(const int &cid);
    void setNewCoverImage(const QByteArray &cover);
    void setNewName(const QString &n);
    void setNewExclusive(const bool &excl);
    void setNewExpansion(const bool &exp);
    void setNewReleaseDate(const QDate &rel);
    void setNewPhysical(const bool &phys);
    void setNewEdition(const QString &ed);
    void setNewDateAdded(const QDate &added);
    void setNewPlatName(const QString &pName);
    void setNewServName(const QString &sName);
    void setNewDevName(const QString &dev);
    void setNewPubName(const QString &pub);

    int getCurrentGameId() const;
    int getCurrentPlatId() const;
    int getCurrentServId() const;
    int getCurrentDevId() const;
    int getCurrentPubId() const;
    int getCurrentCoverId() const;

    QHash<int, QPair<QString, QVariant> > getAllChanges() const;

    static GameChanges changesFrom(const Game &beforeChanges, const Game &afterChanges);

private:
    int gameId;                 ///< The game ID
    int platId;                 ///< The platform ID
    int servId;                 ///< The service ID
    int devId;                  ///< The developer ID
    int pubId;                  ///< The publisher ID
    int coverId;                ///< The cover ID
    int iterator;               ///< Used to iterate through the list of changes
    QHash<int, QPair<QString, QVariant> > changes;  ///< A dynamic list of all remaining changes to the game
};

#endif // GAMECHANGES_H
