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

void Platform::setPlatId(const int &pid) {
    platId = pid;
}

void Platform::setName(const QString& n) {
    name = n;
}

void Platform::setGeneration(const int& gen) {
    generation = gen;
}

void Platform::setReleaseDate(const QDate& rel) {
    releaseDate = rel;
}

int Platform::getPlatId() const {
    return platId;
}

QString Platform::getName() const {
    return name;
}

int Platform::getGeneration() const {
    return generation;
}

QDate Platform::getReleaseDate() const {
    return releaseDate;
}
