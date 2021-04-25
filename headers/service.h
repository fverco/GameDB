#ifndef SERVICE_H
#define SERVICE_H

#include <QString>

/*!
 * \brief A class that provides structured storage of service entries.
 */
class Service
{
public:
    Service(const int &sid, const QString &n);
    Service(const Service& otherServ);
    Service& operator=(const Service& otherServ);

    void setServId(const int &sid);
    void setName(const QString &n);

    int getServId() const;
    QString getName() const;

private:
    int servId;     ///< The ID of the service in the database.
    QString name;   ///< The name of the service.
};


#endif // SERVICE_H
