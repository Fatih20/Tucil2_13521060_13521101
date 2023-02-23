#include "DotCollection.hpp"

DotCollection::DotCollection() : dotDimension(3)
{
    dots = vector<Dot>(0);
}

DotCollection::DotCollection(int numberOfDots) : dotDimension(3)
{
    dots = vector<Dot>(0);
    for (int i = 0; i < numberOfDots; i++)
    {
        Dot addedDot(dotDimension);
        dots.push_back(addedDot);
    }
}

DotCollection::DotCollection(int dimension, int numberOfDots)
{
    dots = vector<Dot>(0);
    for (int i = 0; i < numberOfDots; i++)
    {
        Dot addedDot(dimension);
        dots.push_back(addedDot);
    }
}

DotCollection::~DotCollection()
{
    for (int i = 0; i < dots.size(); i++)
    {
        dots.at(i).~Dot();
    }
    dots.clear();
}

void DotCollection::print()
{
    for (int i = 0; i < dots.size(); i++)
    {
        dots.at(i).print();
    }
};

ClosestPairData DotCollection::getClosestPair()
{
    using namespace chrono;
    time_point<system_clock, duration<int>> startPoint;
    // Function goes here
    time_point<system_clock, duration<int>> endPoint;

    duration<int> processingDuration = endPoint - startPoint;
};