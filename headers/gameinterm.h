#ifndef GAMEINTERM_H
#define GAMEINTERM_H

#include "infodatabase.h"
#include "imagedatabase.h"

#include <QObject>

/*!
 * \brief The intermediary class that communicates between the C++ database classes and QML code.
 */
class GameInterm : public QObject
{
    Q_OBJECT
public:
    explicit GameInterm(QObject *parent = nullptr);

    Q_INVOKABLE QVariantMap getPlatformNames();
    Q_INVOKABLE QVariantMap getServiceNames();
    Q_INVOKABLE QVariantMap getDeveloperNames();
    Q_INVOKABLE QVariantMap getPublisherNames();

    Q_INVOKABLE bool addGame(QString name,
                             int platId,
                             int servId,
                             int devId,
                             int pubId,
                             QString edition,
                             bool excl,
                             bool exp,
                             bool phys,
                             int year,
                             int month,
                             int day,
                             QString coverImg);
    Q_INVOKABLE bool addPlatform(QString name,
                                 int gen,
                                 int year,
                                 int month,
                                 int day);
    Q_INVOKABLE bool addService(QString name);
    Q_INVOKABLE bool addDeveloper(QString name);
    Q_INVOKABLE bool addPublisher(QString name);

signals:

private:
    InfoDatabase infoDatabase;      ///< The Info Database for all the text based information.
    ImageDatabase imageDatabase;    ///< The Image Database for all the images.
};

#endif // GAMEINTERM_H
