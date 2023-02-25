#include "../Dot/Dot.hpp"

#ifndef CLOSEST_PAIR_DATA
#define CLOSEST_PAIR_DATA

class ClosestPairData
{
private:
    Dot *firstDot;
    Dot *secondDot;
    double distance;

public:
    /**
     * @brief Construct a new Closest Pair Data object
     *
     */
    ClosestPairData(Dot *firstDot, Dot *secondDot, double distance);
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
    Dot &getFirstDot() const;

    /**
     * @brief Get the second dot object
     *
     * @return Dot
     */
    Dot &getSecondDot() const;

    /**
     * @brief Get the distance between dots
     *
     * @return distance
     */
    double getDistance() const;
};

#endif