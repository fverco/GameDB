#ifndef GAMELISTMODEL_H
#define GAMELISTMODEL_H

#include "infodatabase.h"
#include "imagedatabase.h"

#include <QAbstractListModel>

class GameListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit GameListModel(QObject *parent = nullptr);

    enum {
        DoneRole = Qt::UserRole,
        GameNameRole,
        GameCoverRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    virtual QHash<int, QByteArray> roleNames() const override;

public slots:
    void refreshGameListCache();

private:
    QList< QMap<GameList::Attributes, QPair<int, QString> > > gameListCache;

    InfoDatabase infoDatabase;      ///< The Info Database where all text data is stored.
    ImageDatabase imageDatabase;    ///< The Image Database where all cover images are stored.
};

#endif // GAMELISTMODEL_H
