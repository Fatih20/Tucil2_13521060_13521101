#include <vector>
#include <chrono>
#include "Dot.hpp"
#include "../ClosestPairData/ClosestPairData.hpp"

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

    /**
     * @brief Destroy the Dot Collection object
     *
     */
    ~DotCollection();

    /**
     * @brief Print the dots
     *
     */
    void print();

    ClosestPairData getClosestPair()
    {
        using namespace chrono;
        time_point<system_clock, duration<int>> startPoint;
        // Function goes here
        time_point<system_clock, duration<int>> endPoint;

        duration<int> processingDuration = endPoint - startPoint;
    };
};