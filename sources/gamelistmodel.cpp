#include "headers/gamelistmodel.h"

GameListModel::GameListModel(QObject *parent) :
    QAbstractListModel(parent),
    gameListCache(),
    infoDatabase("GameListModelInfoCon", this),
    imageDatabase("GameListModelImageCon", this)
{
    if (infoDatabase.createDatabase()) {
        if (imageDatabase.createDatabase()) {
            refreshGameListCache();
        }
    }
}

int GameListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return gameListCache.size();
}

QVariant GameListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role) {

    case DoneRole:
        return QVariant(false);

    case GameNameRole:
        return QVariant(gameListCache.at(index.row()).value(GameList::Attributes::Name).second);

    case GameCoverRole:
        QString cover(gameListCache.at(index.row()).value(GameList::Attributes::Cover).second);
        return QVariant((cover.length() > 0) ? ("file:\\" + cover) : (cover));
    }

    return QVariant();
}

Qt::ItemFlags GameListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

bool GameListModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();

    return false;
}

QHash<int, QByteArray> GameListModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[DoneRole] = "done";
    names[GameNameRole] = "gameName";
    names[GameCoverRole] = "gameCover";
    return names;
}

void GameListModel::refreshGameListCache()
{
    gameListCache.clear();
    gameListCache = infoDatabase.getGameList(); // Add a list of all games in the InfoDatabase to the gameListCache.

    // Retrieve the full path to the covers of all games and add them to the gameListCache.
    for (int i(0); i < gameListCache.size(); ++i) {
        gameListCache[i][GameList::Attributes::Cover].second = imageDatabase.getCoverPath(
                    gameListCache.at(i).value(GameList::Attributes::Cover).first
                    );
    }
}
