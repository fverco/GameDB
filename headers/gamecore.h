#ifndef GAMECORE_H
#define GAMECORE_H

#include <QDate>

/*!
 * \brief The core class for the Game and GameChanges classes.
 * \note This is an abstract class and cannot be instantiated.
 */
class GameCore
{
public:
    GameCore(const int &gid,
             const int &plid,
             const int &sid,
             const int &did,
             const int &puid,
             const int &cid = -1);

    void setGameId(const int &gid);
    void setPlatId(const int &pid);
    void setServId(const int &sid);
    void setDevId(const int &did);
    void setPubId(const int &puid);
    void setCoverId(const int &cid);
    void setCoverImage(const QByteArray &cover);

    virtual void setName(const QString &n) = 0;
    virtual void setExclusive(const bool &excl) = 0;
    virtual void setExpansion(const bool &exp) = 0;
    virtual void setReleaseDate(const QDate &rel) = 0;
    virtual void setPhysical(const bool &phys) = 0;
    virtual void setEdition(const QString &ed) = 0;
    virtual void setDateAdded(const QDate &added) = 0;
    virtual void setPlatName(const QString &pName) = 0;
    virtual void setServName(const QString &sName) = 0;
    virtual void setDevName(const QString &dev) = 0;
    virtual void setPubName(const QString &pub) = 0;

    int getGameId() const;
    int getPlatId() const;
    int getServId() const;
    int getDevId() const;
    int getPubId() const;
    int getCoverId() const;
    QByteArray getCoverImage() const;

protected:
    int gameId;         ///< The game ID
    int platId;         ///< The platform ID
    int servId;         ///< The service ID
    int devId;          ///< The developer ID
    int pubId;          ///< The publisher ID
    int coverId;        ///< The cover ID
    QByteArray coverImage;
};

#endif // GAMECORE_H
