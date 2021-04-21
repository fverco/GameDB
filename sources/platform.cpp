#include "headers/platform.h"

/*!
 * \brief Creates a platform object with default values.
 * \param pid = The platform ID in the database
 * \param n = The name of the platform
 */
Platform::Platform(const int &pid,
                   const QString &n) :
    platId(pid),
    name(n),
    generation(-1),
    releaseDate(QDate(2000, 1, 1))
{
}

/*!
 * \brief The copy constructor for Platform objects.
 * \param otherPlat = The platform object from which the values will be copied
 */
Platform::Platform(const Platform& otherPlat) :
    platId(otherPlat.platId),
    name(otherPlat.name),
    generation(otherPlat.generation),
    releaseDate(otherPlat.releaseDate)
{
}

/*!
 * \brief The assignment operator for Platform objects.
 * \param otherPlat = The platform object from which the values will be copied
 * \return A pointer to the variable to the left of the operator
 */
Platform& Platform::operator=(const Platform& otherPlat) {
    platId = otherPlat.platId;
    name = otherPlat.name;
    generation = otherPlat.generation;
    releaseDate = otherPlat.releaseDate;

    return *this;
}

/*!
 * \brief Assigns a new platform ID.
 * \param pid = The new platform ID
 */
void Platform::setPlatId(const int &pid) {
    platId = pid;
}

/*!
 * \brief Assigns a new platform name.
 * \param n = The new platform name
 */
void Platform::setName(const QString& n) {
    name = n;
}

/*!
 * \brief Assigns a new console generation number.
 * \param gen = The new console generation
 */
void Platform::setGeneration(const int& gen) {
    generation = gen;
}

/*!
 * \brief Assigns a new release date of the platform.
 * \param rel = The new release date
 */
void Platform::setReleaseDate(const QDate& rel) {
    releaseDate = rel;
}

/*!
 * \brief Returns the platform ID.
 * \return An integer with the platform ID
 */
int Platform::getPlatId() const {
    return platId;
}

/*!
 * \brief Returns the platform name.
 * \return A QString with the platform name
 */
QString Platform::getName() const {
    return name;
}

/*!
 * \brief Returns the platform's console generation.
 * \return An integer with the console generation number
 */
int Platform::getGeneration() const {
    return generation;
}

/*!
 * \brief Returns the platform's release date.
 * \return A QDate with the release date
 */
QDate Platform::getReleaseDate() const {
    return releaseDate;
}
