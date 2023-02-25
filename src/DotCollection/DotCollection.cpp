#include "DotCollection.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>

DotCollection::DotCollection(int numberOfDots) : DotCollection(3, numberOfDots){};
DotCollection::DotCollection(int dimension, int numberOfDots) : dotDimension(dimension), startIndex(0), endIndex(numberOfDots), maxCheckedDots(2 * pow(3, dimension))
{
    this->dots = new Dot[numberOfDots];
    for (int i = 0; i < numberOfDots; i++)
    {
        this->dots[i] = Dot(dimension);
    }
    std::sort(this->dots, this->dots + numberOfDots, Dot::compare);
};

DotCollection::DotCollection(const DotCollection &parentCollection, int startIndex, int endIndex) : startIndex(startIndex), endIndex(endIndex), dotDimension(parentCollection.dotDimension), maxCheckedDots(parentCollection.maxCheckedDots)
{
    this->dots = parentCollection.dots;
};

DotCollection::~DotCollection(){};

void DotCollection::print()
{
    for (int i = 0; i < length(); i++)
    {
        at(i).print();
    }
};

void DotCollection::clear()
{
    delete[] this->dots;
}

Dot &DotCollection::at(int index)
{
    return this->dots[startIndex + index];
}

Dot &DotCollection::operator[](int index)
{
    return this->dots[startIndex + index];
}

bool DotCollection::inRange(int index)
{
    return index < length() && index >= 0;
}

int DotCollection::length()
{
    return endIndex - startIndex;
}

DotCollection DotCollection::createSubCollection(int startIndex, int endIndex)
{
    return DotCollection(*this, this->startIndex + startIndex, this->startIndex + endIndex);
}

pair<DotCollection, DotCollection> DotCollection::createCollectionWithinMiddle(double delta)
{
    int len = length();
    int middleIdx = len / 2;
    double median = at(middleIdx).getCoordinateAt(0);
    int startIdx = middleIdx;
    for (int i = 0; i < middleIdx; i++)
    {
        if (median - at(i)[0] <= delta)
        {
            startIdx = i;
            break;
        }
    }

    int endIdx;
    for (endIdx = middleIdx + 1; endIdx < len; endIdx++)
    {
        if (at(endIdx)[0] - median > delta)
        {
            break;
        }
    }
    return pair<DotCollection, DotCollection>(createSubCollection(startIdx, middleIdx), createSubCollection(middleIdx, endIdx));
}

double DotCollection::getMiddleSeparator()
{
    return (at(endIndex).getCoordinateAt(1) - at(startIndex).getCoordinateAt(1)) / 2;
}

ClosestPairData DotCollection::getClosestPair()
{
    int len = length();
    if (len <= 3)
    {
        if (len == 1)
        {
            throw "Cant calculate distance of 1 dot";
        }
        if (len == 2)
        {
            Dot &first = at(0);
            Dot &second = at(1);
            return ClosestPairData(&first, &second, first.getDistance(second));
        }

        ClosestPairData closest(NULL, NULL, INFINITY);
        for (int i = 0; i < 2; i++)
        {
            Dot &first = at(i);
            for (int j = i + 1; j < 3; j++)
            {
                Dot &second = at(j);
                double distance = first.getDistance(second);
                if (closest.getDistance() > distance)
                    closest = ClosestPairData(&first, &second, distance);
            }
        }
        return closest;
    }

    int middleIdx = len / 2;
    ClosestPairData closeLeft = createSubCollection(0, middleIdx).getClosestPair();
    ClosestPairData closeRight = createSubCollection(middleIdx, len).getClosestPair();
    ClosestPairData &closest = closeLeft.getDistance() < closeRight.getDistance() ? closeLeft : closeRight;
    double delta = closest.getDistance();

    pair<DotCollection, DotCollection> aroundMiddle = createCollectionWithinMiddle(delta);

    for (int i = 0; i < aroundMiddle.first.length(); i++)
    {
        long count = 0;
        Dot &left = aroundMiddle.first[i];
        for (int j = 0; j < aroundMiddle.second.length(); j++)
        {
            bool needToCheck = true;
            Dot &right = aroundMiddle.second[i];
            for (int k = 0; k < dotDimension; k++)
            {
                if (abs(left[k] - right[k]) > delta)
                {
                    needToCheck = false;
                    break;
                };
            }
            if (needToCheck)
            {
                double distance = left.getDistance(right);
                if (distance < delta)
                {
                    delta = distance;
                    closest = ClosestPairData(&left, &right, distance);
                    count++;
                    if (count == maxCheckedDots)
                        break;
                }
            }
        }
    }

    return closest;
};

ClosestPairData DotCollection::getClosestPairBruteForce()
{
    int len = length();

    if (len == 1)
    {
        throw "Cant calculate distance of 1 dot";
    }

    ClosestPairData closest(NULL, NULL, INFINITY);
    for (int i = 0; i < len - 1; i++)
    {
        Dot &first = at(i);
        for (int j = i + 1; j < len; j++)
        {
            Dot &second = at(j);
            double distance = first.getDistance(second);
            if (closest.getDistance() > distance)
                closest = ClosestPairData(&first, &second, distance);
        }
    }
    return closest;
}