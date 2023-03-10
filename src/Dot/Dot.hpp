#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

#ifndef DOT
#define DOT

class Dot
{
private:
    double *coordinates;
    int dimension;
    static long totalEuclidean;

public:
    /**
     * @brief Construct a new Dot object with default dimension of 3
     *
     */
    Dot();

    /**
     * @brief Construct a new Dot object with the given dimension
     *
     * @param dimension
     */
    Dot(int dimension);

    /**
     * @brief Destroy the Dot object
     *
     */
    ~Dot();

    /**
     * @brief Copy constructor for Dot
     *
     * @param givenCoordinate
     * @return Dot&
     */
    Dot(const Dot &givenDot);

    /**
     * @brief Construct a new Dot object using the assignment operator
     *
     * @param givenCoordinate
     */
    Dot &operator=(const Dot &givenCoordinate);

    /**
     * @brief Determine if this dot is the same as another dot
     *
     * @param givenDot
     */
    bool operator==(const Dot &);

    /**
     * @brief Determine if a dot is on the left of another dot on the x-axis
     *
     * @return true the dot on the left of the operator is on the left of the other dot
     * @return false the dot on the left of the operator is on the right of the other dot
     */
    bool operator<(const Dot &);

    /**
     * @brief Determine if a dot is on the right of another dot on the x-axis
     *
     * @return true the dot on the left of the operator is on the right of the other dot
     * @return false the dot on the left of the operator is on the left of the other dot
     */
    bool operator>(const Dot &);

    /**
     * @brief Determine if a dot is on the left or same as of another dot on the x-axis
     *
     * @return true the dot on the left of the operator is on the left of the other dot
     * @return false the dot on the left of the operator is on the right of the other dot
     */
    bool operator<=(const Dot &);

    /**
     * @brief Determine if a dot is on the right of another dot on the x-axis
     *
     * @return true the dot on the right of the operator is on the right of the other dot
     * @return false the dot on the right of the operator is on the left of the other dot
     */
    bool operator>=(const Dot &);

    /**
     * @brief Get the square of the distance of this dot to the targetDot. It's assumed the target dot has the same dimension.
     *
     * @param targetDot
     * @return double
     */

    double getSquaredDistance(Dot &targetDot);
    /**
     * @brief Get the distance of this dot to the targetDot. It's assumed the target dot has the same dimension.
     *
     * @param targetDot
     * @return double
     */
    double getDistance(Dot &targetDot);
    /**
     * @brief Get the coordinate at nthDimension
     * @param nthDimension the desired dimension of coordinate to be fetched
     * @return double
     */
    double getCoordinateAt(int nthDimentsion) const;

    /**
     * @brief Get the coordinate at nthDimension
     * @param nthDimension the desired dimension of coordinate to be fetched
     * @return double
     */
    double operator[](int nthDimentsion) const;

    /**
     * @brief Print the dot coordinates
     *
     */
    void print();

    /**
     * @brief Compare two dots (for sorting)
     *
     */
    static bool compare(Dot &dot1, Dot &dot2);

    /**
     * @brief Get the total euclidean variable
     *
     * @return int
     */
    static int getTotalEuclidean();

    /**
     * @brief Reset the total euclidean calculation to zero
     *
     * @return int
     */
    static void resetTotalEuclidean();

    /**
     * @brief Swap this dot and the givenDot
     *
     * @param givenDot
     */
    void swap(Dot &givenDot);

    /**
     * @brief Return whether this dot is at least delta distance from givenDot
     *
     * @param givenDot compared dot
     * @param delta
     * @return true the distance between the two point is at least delta
     * @return false the distance between the two point could be more than delta
     */
    bool bottomBoundDistance(double delta, Dot &givenDot);
};

#endif