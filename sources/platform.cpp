#include "headers/platform.h"

/*!
 * \brief Creates a platform object with default values.
 * \param pid = The platform ID in the database
 * \param n = The name of the platform
 */
Platform::Platform(const int &pid,
                   const QString &n) :
    Entry(pid, n),
    generation(-1),
    releaseDate(QDate(2000, 1, 1))
{
}

/*!
 * \brief Creates a platform object with the provided values.
 * \param pid = The platform ID in the database
 * \param n = The name of the platform
 * \param gen = The console generation of the platform
 * \param relDate = The release date of the platform
 */
Platform::Platform(const int &pid,
                   const QString &n,
                   const int &gen,
                   const QDate &relDate) :
    Entry(pid, n),
    generation(gen),
    releaseDate(relDate)
{
}

/*!
 * \brief The copy constructor for Platform objects.
 * \param otherPlat = The platform object from which the values will be copied
 */
Platform::Platform(const Platform& otherPlat) :
    Entry(otherPlat.id, otherPlat.name),
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
    id = otherPlat.id;
    name = otherPlat.name;
    generation = otherPlat.generation;
    releaseDate = otherPlat.releaseDate;

    return *this;
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

/*!
 * \brief Returns the type of entry the calling object is.
 * \return  An EntryTypes enum of Platform
 * \note The returning value will always be the Platform enum.
 */
EntryTypes Platform::getEntryType() const {
    return EntryTypes::Platform;
}
