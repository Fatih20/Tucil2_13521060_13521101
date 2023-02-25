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
    using namespace chrono;
    time_point<system_clock, duration<int>> startPoint;
    // Function goes here
    time_point<system_clock, duration<int>> endPoint;

    duration<int> processingDuration = endPoint - startPoint;
};