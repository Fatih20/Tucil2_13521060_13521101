#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

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
    Dot(int);

    /**
     * @brief Construct a new Dot object from the givenCoordinate
     *
     * @param givenCoordinate
     */
    Dot(vector<double>);

    /**
     * @brief Construct a new Dot object using the assignment operator
     *
     * @param givenCoordinate
     */
    Dot &operator=(const Dot &);

    /**
     * @brief Determine if this dot is the same as another dot
     *
     * @param givenDot
     */
    bool operator==(const Dot &);

    /**
     * @brief Get the square of the distance of this dot to the targetDot. It's assumed the target dot has the same dimension.
     *
     * @param targetDot
     * @return double
     */

    double getSquaredDistance(Dot);
    /**
     * @brief Get the distance of this dot to the targetDot. It's assumed the target dot has the same dimension.
     *
     * @param targetDot
     * @return double
     */
    double getDistance(Dot);
    double getCoordinateAt(int);
};