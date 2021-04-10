#include "headers/database.h"

/*!
 * \brief Instantiates the basic database object.
 * \param parent = The QObject to which this database is binded.
 */
Database::Database(QObject *parent) :
    QObject(parent),
    createdDb(false),
    location("")
{
}

/*!
 * \brief The Database destructor.
 */
Database::~Database() {
}

/*!
 * \brief Returns the full path to where the database is stored.
 * \return A QString with the directory of the database.
 */
QString Database::getDBLocation() const {
    return location;
}
