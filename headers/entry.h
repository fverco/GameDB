#ifndef ENTRY_H
#define ENTRY_H

#include <QString>

/*!
 * \brief Enum for entry types used in the database.
 */
enum class EntryTypes {
    Game,       ///< 0
    Platform,   ///< 1
    Service,    ///< 2
    Developer,  ///< 3
    Publisher   ///< 4
};

/*!
 * \brief The interface class for all entry classes used in the database.
 */
class Entry
{
public:
    Entry(const int &entryId, const QString &entryName);
    virtual ~Entry();
    Entry(const Entry &otherEntry);
    Entry& operator=(const Entry &otherEntry);

    void setId(const int &entryId);
    void setName(const QString &entryName);

    int getId() const;
    QString getName() const;
    virtual EntryTypes getEntryType() const = 0;

protected:
    int id;         ///< The ID of the entry in the database.
    QString name;   ///< The name of the entry.
};

#endif // ENTRY_H
