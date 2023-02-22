#include "../Dot/Dot.hpp"

#ifndef CLOSEST_PAIR_DATA
#define CLOSEST_PAIR_DATA

class ClosestPairData
{
private:
    Dot firstDot;
    Dot secondDot;

public:
    /**
     * @brief Construct a new Closest Pair Data object
     *
     */
    ClosestPairData(Dot firstDot, Dot secondDot);
    /**
     * @brief Destroy the Closest Pair Data object
     *
     */
    ~ClosestPairData();

    /**
     * @brief Get the first dot object
     *
     * @return Dot
     */
    Dot getFirstDot();

    /**
     * @brief Get the second dot object
     *
     * @return Dot
     */
    Dot getSecondDot();
};

#endif