#ifndef GAMECHANGES_H
#define GAMECHANGES_H

#include "game.h"

#include <QDate>

/*!
 * \brief Class used to extract all the differences between two Game object.
 */
class GameChanges : public GameCore
{
public:
    GameChanges(const int &gId,
                const int &plId,
                const int &sId,
                const int &dId,
                const int &puId,
                const int &cId);
    GameChanges(const GameChanges &otherChanges);
    GameChanges& operator=(const GameChanges &otherChanges);
    int size() const;
    QPair<QString, QVariant> next();
    bool hasNext() const;
    bool coverIdIsChanged() const;
    bool coverImageIsChanged() const;
    void toStart();

    void setNewGameId(const int &gid);
    void setNewPlatId(const int &plid);
    void setNewServId(const int &sid);
    void setNewDevId(const int &did);
    void setNewPubId(const int &puid);
    void setNewCoverId(const int &cid);
    void setNewCoverImage(const QByteArray &cover);

    void setName(const QString &n);
    void setExclusive(const bool &excl);
    void setExpansion(const bool &exp);
    void setReleaseDate(const QDate &rel);
    void setPhysical(const bool &phys);
    void setEdition(const QString &ed);
    void setDateAdded(const QDate &added);
    void setPlatName(const QString &pName);
    void setServName(const QString &sName);
    void setDevName(const QString &dev);
    void setPubName(const QString &pub);

    QHash<int, QPair<QString, QVariant> > getAllChanges() const;

    static GameChanges changesFrom(const Game &beforeChanges, const Game &afterChanges);

private:
    int iterator;            ///< Used to iterate through the list of changes
    bool coverImageChanged;  ///< Has the cover image been changed?
    bool coverIdChanged;     ///< Has the cover ID been changed?
    QHash<int, QPair<QString, QVariant> > changes;  ///< A dynamic list of all remaining changes to the game

    // These functions are meant to minimize repetitive code used in the copy constructor and assignment operator.
    void assignGameCore(const GameChanges &otherChanges);
    void assignGameChanges(const GameChanges &otherChanges);
};

#endif // GAMECHANGES_H
