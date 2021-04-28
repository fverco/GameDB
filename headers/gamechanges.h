#ifndef GAMECHANGES_H
#define GAMECHANGES_H

#include "game.h"
#include "entrychanges.h"

/*!
 * \brief Class used to extract all the differences between two Game objects.
 */
class GameChanges : public EntryChanges
{
public:
    GameChanges(const int &gid,
                const int &plid,
                const int &sid,
                const int &did,
                const int &puid,
                const int &cid);
    GameChanges(Game &game);
    GameChanges(GameChanges &otherChanges);
    GameChanges& operator=(const GameChanges &otherChanges);

    void setNewId(const int &newId);
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

    int getCurrentPlatId() const;
    int getCurrentServId() const;
    int getCurrentDevId() const;
    int getCurrentPubId() const;
    int getCurrentCoverId() const;

    static GameChanges changesFrom(const Game &beforeChanges, const Game &afterChanges);

private:
    int platId;                 ///< The platform ID
    int servId;                 ///< The service ID
    int devId;                  ///< The developer ID
    int pubId;                  ///< The publisher ID
    int coverId;                ///< The cover ID
};

#endif // GAMECHANGES_H
