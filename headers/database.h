#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

/*!
 * \brief The interface class for all database related classes.
 */
class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    virtual ~Database();
    virtual bool createDatabase(const QString& dir) = 0;    ///< Pure virtual function for creating the database.

    QString getDBLocation() const;

protected:
    bool createdDb;     ///< Boolean value that states whether the database has been created.
    QString location;   ///< The full path to where the database is stored.
};

#endif // DATABASE_H
