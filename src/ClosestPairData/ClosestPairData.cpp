#include "ClosestPairData.hpp"

ClosestPairData::ClosestPairData(Dot dot1, Dot dot2)
{
    firstDot = dot1;
    secondDot = dot2;
}

ClosestPairData::~ClosestPairData()
{
    firstDot.~Dot();
    secondDot.~Dot();
}

Dot ClosestPairData::getFirstDot()
{
    return firstDot;
}

Dot ClosestPairData::getSecondDot()
{
    return secondDot;
}