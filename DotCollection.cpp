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