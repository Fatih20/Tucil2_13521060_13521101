#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

#ifndef DOT
#define DOT

class Dot
{
private:
    vector<double> coordinates;

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
     * @brief Construct a new Dot object from the givenCoordinate
     *
     * @param givenCoordinate
     */
    Dot(vector<double> givenCoordinate);

    /**
     * @brief Destroy the Dot object
     *
     */
    ~Dot();

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
     * @brief Get the square of the distance of this dot to the targetDot. It's assumed the target dot has the same dimension.
     *
     * @param targetDot
     * @return double
     */

    double getSquaredDistance(Dot targetDot);
    /**
     * @brief Get the distance of this dot to the targetDot. It's assumed the target dot has the same dimension.
     *
     * @param targetDot
     * @return double
     */
    double getDistance(Dot targetDot);
    /**
     * @brief Get the coordinate at nthDimension
     * @param nthDimension the desired dimension of coordinate to be fetched
     * @return double
     */
    double getCoordinateAt(int nthDimentsion);

    /**
     * @brief Get the coordinate at nthDimension
     * @param nthDimension the desired dimension of coordinate to be fetched
     * @return double
     */
    double operator[](int nthDimentsion);

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
};

#endif