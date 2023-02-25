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
    const int startIndex;
    const int endIndex;
    const int dotDimension;
    const long maxCheckedDots;

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
     * @param parentCollection
     * @param startIndex
     * @param endIndex
     */
    DotCollection(const DotCollection &parentCollection, int startIndex, int endIndex);

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
    Dot &at(int index);

    /**
     * @brief Return the element at the given index. Undefined behaviour when index > endIndex - startIndex
     *
     * @param index
     * @return Dot
     */
    Dot &operator[](int index);

    /**
     * @brief Determine if the index is within the range of the collection or not
     *
     * @param index
     * @return true index is within range
     * @return false index is not within range
     */
    bool inRange(int index);

    /**
     * @brief Return the number of dots in the dot collection
     *
     * @return int
     */
    int length();

    /**
     * @brief Create a sob collection of the dot collection object (startIndex and endIndex is relative from the dotCollection)
     *
     * @param startIndex
     * @param endIndex
     * @return DotCollection&
     */
    DotCollection createSubCollection(int startIndex, int endIndex);

    /**
     * @brief Create two dot collections in range of middle at delta distance (left and right)
     *
     * @param delta sparsity
     * @return pair<DotCollection, DotCollection> left
     */
    pair<DotCollection, DotCollection> createCollectionWithinMiddle(double delta);

    /**
     * @brief Get the middle separator of the collection
     *
     * @return double
     */
    double getMiddleSeparator();

    ClosestPairData getClosestPair();

    ClosestPairData getClosestPairBruteForce();
};

#endif