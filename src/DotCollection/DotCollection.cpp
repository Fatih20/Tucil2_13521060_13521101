#include "DotCollection.hpp"
#include <iostream>

DotCollection::DotCollection(int numberOfDots) : DotCollection(3, numberOfDots){};
DotCollection::DotCollection(int dimension, int numberOfDots) : dotDimension(dimension), startIndex(0)
{
    this->dots = new Dot[numberOfDots];
    for (int i = startIndex; i < numberOfDots; i++)
    {
        Dot addedDot(dotDimension);
        bool foundPos = false;
        int j = 0;
        while (j < i && !foundPos)
        {
            foundPos = (addedDot < this->dots[j]);
            j += foundPos ? 0 : 1;
        };
        if (foundPos)
        {
            for (int k = i; k > j; k--)
            {
                this->dots[k] = this->dots[k - 1];
            }
        }
        dots[j] = addedDot;
        endIndex = i;
    }
    std::cout << std::endl;
};

DotCollection::DotCollection(Dot *dotArray, int startIndex, int endIndex) : startIndex(startIndex), endIndex(endIndex)
{
    this->dots = dotArray;
};

DotCollection::~DotCollection(){};

void DotCollection::print()
{
    for (int i = startIndex; i <= endIndex; i++)
    {
        this->dots[i].print();
    }
};

void DotCollection::clear()
{
    for (int i = startIndex; i < endIndex; i++)
    {
        this->dots[i].~Dot();
    }
    delete[] this->dots;
}

Dot DotCollection::at(int index)
{
    return this->dots[startIndex + index];
}

bool DotCollection::inRange(int index)
{
    return index <= endIndex - startIndex && index >= 0;
}

DotCollection *DotCollection::createSubCollection(int startIndex, int endIndex)
{
    DotCollection *subCollection = new DotCollection(this->dots, startIndex, endIndex);
    return subCollection;
}

ClosestPairData DotCollection::getClosestPair()
{
    using namespace chrono;
    time_point<system_clock, duration<int>> startPoint;
    // Function goes here
    time_point<system_clock, duration<int>> endPoint;

    duration<int> processingDuration = endPoint - startPoint;
};