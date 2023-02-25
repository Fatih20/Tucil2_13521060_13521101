#include "ClosestPairData.hpp"

ClosestPairData::ClosestPairData(Dot dot1, Dot dot2, double distance)
{
    firstDot = dot1;
    secondDot = dot2;
    this->distance = distance;
}

ClosestPairData::~ClosestPairData()
{
}

Dot ClosestPairData::getFirstDot() const
{
    return firstDot;
}

Dot ClosestPairData::getSecondDot() const
{
    return secondDot;
}

double ClosestPairData::getDistance() const
{
    return distance;
}