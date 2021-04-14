/*! \mainpage Welcome
 *
 *  \section build-info Build Information
 *
 *  This application uses Qt 6.0.3 and uses Qt Quick.\n
 *  Compiled with MinGW 64-bit and uses SQLite as its database.\n
 *  Documentation is done with a combination of Doxygen and Graphviz.\n
 *
 */

/*! \page ERD Entity Relationship Diagram
 *  \image html "GameDB ERD.png"
 */

#include "headers/gameinterm.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

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

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/ui/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    GameInterm gameInterm;
    engine.rootContext()->setContextProperty(QStringLiteral("gameInterm"), &gameInterm);

    return app.exec();
}
