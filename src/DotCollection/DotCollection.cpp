#include "DotCollection.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>

DotCollection::DotCollection(int numberOfDots) : DotCollection(3, numberOfDots){};
DotCollection::DotCollection(int dimension, int numberOfDots) : dotDimension(dimension), startIndex(0), endIndex(numberOfDots)
{
    this->dots = new Dot[numberOfDots];
    for (int i = 0; i < numberOfDots; i++)
    {
        this->dots[i] = Dot(dimension);
    }
    std::sort(this->dots, this->dots + numberOfDots, Dot::compare);
};

DotCollection::DotCollection(Dot *dotArray, int startIndex, int endIndex) : startIndex(startIndex), endIndex(endIndex)
{
    this->dots = dotArray;
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
    return DotCollection(this->dots, this->startIndex + startIndex, this->startIndex + endIndex);
}

pair<DotCollection, DotCollection> DotCollection::createCollectionWithinMiddle(double delta)
{
    int len = length();
    int middleIdx = len / 2;
    double median = at(middleIdx).getCoordinateAt(0);
    cout << "MEDIAN = " << median << endl;
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
    cout << startIdx << ' ' << endIdx;
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
            Dot first = at(0);
            Dot second = at(1);
            return ClosestPairData(&first, &second, first.getDistance(second));
        }

        ClosestPairData closest(NULL, NULL, INFINITY);
        for (int i = 0; i < 2; i++)
        {
            Dot first = at(i);
            for (int j = i + 1; j < 3; j++)
            {
                Dot second = at(j);
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

    // TODO: get closest around left and right middle

    return closest;
};