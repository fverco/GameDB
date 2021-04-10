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

signals:

private:
    InfoDatabase infoDatabase;      ///< The Info Database for all the text based information.
    ImageDatabase imageDatabase;    ///< The Image Database for all the images.
};

#endif // GAMEINTERM_H
