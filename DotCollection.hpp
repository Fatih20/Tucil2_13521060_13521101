#include <vector>
#include "Dot.hpp"

using namespace std;
class DotCollection
{
private:
    vector<Dot> dots;
    int dotDimension;

public:
    /**
     * @brief Construct a new Dot Collection object
     *
     */
    DotCollection();

    /**
     * @brief Construct a new Dot Collection object
     *
     * @param numberOfDots
     */
    DotCollection(int numberOfDots);

    /**
     * @brief Construct a new Dot Collection object
     *
     * @param dimension
     * @param numberOfDots
     */
    DotCollection(int dimension, int numberOfDots);
};