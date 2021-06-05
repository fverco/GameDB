/*! \mainpage Welcome
 *
 *  \section build-info Build Information
 *
 *  This application uses Qt 6.1.0 and uses Qt Quick 2.0.\n
 *  Compiled with MinGW 64-bit and uses SQLite as its database.\n
 *  Documentation is done with a combination of Doxygen and Graphviz.\n
 *
 */

/*! \page ERD Entity Relationship Diagram
 *  \image html "GameDB ERD.png"
 */

#include "headers/gameinterm.h"
#include "headers/gamelistmodel.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtDebug>

void initializeGameComponents(QQmlApplicationEngine &engine, GameInterm &gameInterm, GameListModel &gameListModel) {
    engine.rootContext()->setContextProperty(QStringLiteral("gameInterm"), &gameInterm);
    engine.rootContext()->setContextProperty(QStringLiteral("gameListModel"), &gameListModel);
}

/*!
 * \brief Start the application.
 * \param argc The amount of arguments passed to the application at start.
 * \param argv A list of all arguments passed to the application at start.
 * \return An integer that shows whether the application was successfull or failed.
 */
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);

    qmlRegisterUncreatableMetaObject(GameList::staticMetaObject, "gamelist.attributes", 1, 0, "GameListAttributes", "Not creatable. This is an enum type.");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/ui/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    GameInterm gameInterm;
    GameListModel gameListModel;
    initializeGameComponents(engine, gameInterm, gameListModel);

    engine.load(url);

    return app.exec();
}
