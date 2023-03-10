#include "DotCollection.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>

DotCollection::DotCollection(int numberOfDots) : DotCollection(3, numberOfDots){};
DotCollection::DotCollection(int dimension, int numberOfDots) : dotDimension(dimension), startIndex(0), endIndex(numberOfDots), maxCheckedDots(2 * pow(3, dimension))
{
    // Fill the collection with dots
    this->dots = new Dot[numberOfDots];
    for (int i = 0; i < numberOfDots; i++)
    {
        this->dots[i] = Dot(dimension);
    }
    // Sort the created dot in the collection
    sort();
};

DotCollection::DotCollection(const DotCollection &parentCollection, int startIndex, int endIndex) : startIndex(startIndex), endIndex(endIndex), dotDimension(parentCollection.dotDimension), maxCheckedDots(parentCollection.maxCheckedDots)
{
    // Assign the same array pointer as the parent collection
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
    // Deallocate the array of dot created with new
    delete[] this->dots;
}

Dot &DotCollection::at(int index)
{
    // Return nth index relative to start
    return this->dots[startIndex + index];
}

Dot &DotCollection::operator[](int index)
{
    // Return nth index relative to start
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

void DotCollection::sort()
{
    int length = this->length();
    // Stopped sorting if there's already one or less element
    if (length <= 1)
    {
        return;
    }

    switch (length)
    {
        // Sort the collection trivially when there's only 2 dots
    case 2:
    {
        if (at(1) < at(0))
        {
            at(1).swap(at(0));
        }
    }
    break;
    default:
    {
        // Sort the collection recursively using quicksort
        int rightPointer = length;
        int leftPointer = 0;
        Dot pivot = at(0);

        while (leftPointer < rightPointer && leftPointer < length && rightPointer >= 0)
        {
            do
            {
                leftPointer++;
            } while (at(leftPointer) < pivot && leftPointer < length - 1);

            do
            {
                rightPointer--;
            } while (at(rightPointer) > pivot && rightPointer > 0);

            at(leftPointer).swap(at(rightPointer));
        }

        at(leftPointer).swap(at(rightPointer));
        at(rightPointer).swap(at(0));

        // Call sort on the subproblem
        DotCollection dcLeft = createSubCollection(0, rightPointer);
        DotCollection dcRight = createSubCollection(rightPointer + 1, length);
        dcLeft.sort();
        dcRight.sort();
    }
    break;
    }
}

DotCollection DotCollection::createSubCollection(int startIndex, int endIndex)
{
    return DotCollection(*this, this->startIndex + startIndex, this->startIndex + endIndex);
}

pair<DotCollection, DotCollection> DotCollection::createCollectionWithinMiddle(double delta)
{
    // Find the median dot in respect to the x-axis
    int len = length();
    int middleIdx = len / 2;
    double median = at(middleIdx).getCoordinateAt(0);
    int startIdx = middleIdx;
    // Find the bottom-bound of the index of the dot that starts to be within delta of the median
    for (int i = 0; i < middleIdx; i++)
    {
        if (median - at(i)[0] <= delta)
        {
            startIdx = i;
            break;
        }
    }

    // Find the upper-bound of the index of the dot that starts to be within delta of the median
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

ClosestPairData DotCollection::getClosestPair()
{
    int len = length();
    // Basis when there are 3 dots or less
    if (len <= 3)
    {
        return getClosestPairBruteForce();
    }

    // Get the closest distance between left and right subcollection
    int middleIdx = len / 2;
    ClosestPairData closeLeft = createSubCollection(0, middleIdx).getClosestPair();
    ClosestPairData closeRight = createSubCollection(middleIdx, len).getClosestPair();
    ClosestPairData &closest = closeLeft.getDistance() < closeRight.getDistance() ? closeLeft : closeRight;
    double delta = closest.getDistance();

    pair<DotCollection, DotCollection> aroundMiddle = createCollectionWithinMiddle(delta);

    // Check each of the dots left of the middle against the dots right of the middle up to the max chacked dots
    for (int i = 0; i < aroundMiddle.first.length(); i++)
    {
        long count = 0;
        Dot &left = aroundMiddle.first[i];
        for (int j = 0; j < aroundMiddle.second.length(); j++)
        {
            Dot &right = aroundMiddle.second[i];
            // Ensure checking isn't done if difference in distance at any one axis is already more than delta
            if (!left.bottomBoundDistance(delta, right))
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

    switch (len)
    {
    case 1:
    {
        throw "Can't calculate distance of 1 dot.";
    }
    break;
    case 2:
    {
        // Calculate the closest distance trivially
        Dot &first = at(0);
        Dot &second = at(1);
        return ClosestPairData(&first, &second, first.getDistance(second));
    }
    break;
    default:
    {
        // Check each dot against every other dot that haven't been checked
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
    break;
    }
}