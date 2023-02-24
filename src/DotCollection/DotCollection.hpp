#include <vector>
#include <chrono>
#include "../Dot/Dot.hpp"
#include "../ClosestPairData/ClosestPairData.hpp"

using namespace std;

#ifndef DOT_COLLECTION
#define DOT_COLLECTION
class DotCollection
{
private:
    Dot *dots;
    int startIndex;
    int endIndex;
    int dotDimension;

public:
    /**
     * @brief Construct a new Dot Collection object
     *
     * @param numberOfDots
     */
    DotCollection(int numberOfDots);

    /**
     * @brief Construct a new Dot Collection object
     *
     * @param dotArray
     * @param startIndex
     * @param endIndex
     */
    DotCollection(Dot *dotArray, int startIndex, int endIndex);

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

    /**
     * @brief Delete the array allocated to for the collection
     *
     */
    void clear();

    /**
     * @brief Return the element at the given index. Undefined behaviour when index > endIndex - startIndex
     *
     * @param index
     * @return Dot
     */
    Dot at(int index);

    /**
     * @brief Determine if the index is within the range of the collection or not
     *
     * @param index
     * @return true index is within range
     * @return false index is not within range
     */
    bool inRange(int index);

    ClosestPairData getClosestPair();
};

#endif