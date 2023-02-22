#include "../Dot/Dot.hpp"

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