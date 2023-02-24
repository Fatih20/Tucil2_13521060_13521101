#include "DotCollection.hpp"

DotCollection::DotCollection(int numberOfDots) : DotCollection(3, numberOfDots){};
DotCollection::DotCollection(int dimension, int numberOfDots) : dotDimension(dimension), startIndex(0), endIndex(numberOfDots - 1)
{
    this->dots = new Dot[numberOfDots];
    for (int i = 0; i < numberOfDots; i++)
    {
        Dot addedDot(dotDimension);
        dots[i] = addedDot;
    }
};

DotCollection::DotCollection(Dot *dotArray, int startIndex, int endIndex) : startIndex(startIndex), endIndex(endIndex)
{
    this->dots = dotArray;
};

DotCollection::~DotCollection(){};

void DotCollection::print()
{
    for (int i = startIndex; i < endIndex; i++)
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

ClosestPairData DotCollection::getClosestPair()
{
    using namespace chrono;
    time_point<system_clock, duration<int>> startPoint;
    // Function goes here
    time_point<system_clock, duration<int>> endPoint;

    duration<int> processingDuration = endPoint - startPoint;
};