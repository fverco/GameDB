#ifndef GAME_H
#define GAME_H

#include "entry.h"

#include <QDate>

/*!
 * \brief A class that provides structured storage of game entries.
 * \note This class is a mix up of the Copy and Game tables in the database.
 */
class Game : public Entry
{
public:
    Game(const int &gid,
         const int &plid,
         const int &sid,
         const int &did,
         const int &puid,
         const int &cid,
         const QString &n);
    Game(const int &gid,
         const int &plid,
         const int &sid,
         const int &did,
         const int &puid,
         const QString &n,
         const QString &ed,
         const bool &excl,
         const bool &exp,
         const bool &phys,
         const QDate &rel,
         const int &cid);
    Game(const Game &otherGame);
    Game& operator=(const Game& otherGame);

    void setPlatId(const int &pid);
    void setServId(const int &sid);
    void setDevId(const int &did);
    void setPubId(const int &puid);
    void setCoverId(const int &cid);
    void setCoverImage(const QByteArray &cover);
    void setCoverImage(const QString &filePath);
    void setExclusive(const bool &excl);
    void setExpansion(const bool &exp);
    void setReleaseDate(const QDate &rel);
    void setPhysical(const bool &phys);
    void setEdition(const QString &ed);
    void setDateAdded(const QDate &added);

    int getPlatId() const;
    int getServId() const;
    int getDevId() const;
    int getPubId() const;
    int getCoverId() const;
    QByteArray getCoverImage() const;
    bool getExclusive() const;
    bool getExpansion() const;
    QDate getReleaseDate() const;
    bool getPhysical() const;
    QString getEdition() const;
    QDate getDateAdded() const;
    EntryTypes getEntryType() const;

    static QByteArray imageFromFile(const QString &filePath);

private:
    int platId;             ///< The platform ID
    int servId;             ///< The service ID
    int devId;              ///< The developer ID
    int pubId;              ///< The publisher ID
    int coverId;            ///< The cover ID
    QByteArray coverImage;  ///< The cover image
    bool exclusive;         ///< Is this game a platform exclusive?
    bool expansion;         ///< Is this game an expansion/DLC of an existing game?
    QDate releaseDate;      ///< The date of release for this game (usually world wide)
    bool physical;          ///< Is this game a physical copy game?
    QString edition;        ///< The edition of the game. For example, standard edition, collectors edition etc
    QDate dateAdded;        ///< The date this game copy was added to the system
};

#endif // GAME_H
