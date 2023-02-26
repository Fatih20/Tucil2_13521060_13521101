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
    // std::sort(this->dots, this->dots + numberOfDots, Dot::compare);
    // sort();
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

void DotCollection::sort()
{
    cout << length() << endl;
    int length = this->length();
    print();
    if (length <= 1)
    {
        return;
    }

    switch (length)
    {
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
        int rightPointer = endIndex;
        int leftPointer = startIndex;
        Dot pivot = at(startIndex);

        while (leftPointer < rightPointer && leftPointer < endIndex && rightPointer >= startIndex)
        {
            cout << leftPointer << endl;
            cout << rightPointer << endl;

            do
            {
                leftPointer++;
            } while (at(leftPointer) < pivot && leftPointer < endIndex - 1);

            do
            {
                rightPointer--;
            } while (at(rightPointer) > pivot && rightPointer > startIndex);

            at(leftPointer).swap(at(rightPointer));
        }

        cout << "Exited the loop" << endl;
        at(leftPointer).swap(at(rightPointer));
        at(rightPointer).swap(at(startIndex));

        DotCollection dcLeft = createSubCollection(startIndex, rightPointer);
        DotCollection dcRight = createSubCollection(rightPointer + 1, endIndex);
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

ClosestPairData DotCollection::getClosestPair()
{
    int len = length();
    if (len <= 3)
    {
        return getClosestPairBruteForce();
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
            Dot &right = aroundMiddle.second[i];
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

        Dot &first = at(0);
        Dot &second = at(1);
        return ClosestPairData(&first, &second, first.getDistance(second));
    }
    break;
    default:
    {
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