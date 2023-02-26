#include "Dot.hpp"
#include <iostream>
#include <random>

long Dot::totalEuclidean = 0;

Dot::Dot() : Dot(3)
{
}

Dot::Dot(int dimension)
{

    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> distribution(-1000, 1000);

    coordinates = new double[dimension];
    this->dimension = dimension;

    for (int i = 0; i < dimension; i++)
    {
        coordinates[i] = distribution(generator);
    }
}

Dot::Dot(const Dot &givenDot)
{
    this->dimension = givenDot.dimension;
    this->coordinates = new double[dimension];
    for (int i = 0; i < dimension; i++)
    {
        coordinates[i] = givenDot[i];
    }
}

Dot::~Dot()
{
    delete[] coordinates;
}

Dot &Dot::operator=(const Dot &givenDot)
{
    this->dimension = givenDot.dimension;
    this->coordinates = new double[dimension];
    for (int i = 0; i < dimension; i++)
    {
        coordinates[i] = givenDot[i];
    }
    return *this;
}

double Dot::getSquaredDistance(Dot &targetDot)
{
    Dot::totalEuclidean++;
    double sum = 0;
    for (int i = 0; i < dimension; i++)
    {
        sum += pow(getCoordinateAt(i) - targetDot.getCoordinateAt(i), 2);
    }
    return sum;
};

double Dot::getDistance(Dot &targetDot)
{
    return sqrt(getSquaredDistance(targetDot));
}

double Dot::getCoordinateAt(int dimension) const
{
    return coordinates[dimension];
}

double Dot::operator[](int nthDimension) const
{
    return coordinates[nthDimension];
}

bool Dot::operator==(const Dot &givenDot)
{
    bool same = dimension == givenDot.dimension;
    int i = 0;
    while (same && i < dimension)
    {
        same = givenDot[i] == getCoordinateAt(i);
        i += same;
    }
    return same;
};

bool Dot::operator<(const Dot &givenDot)
{
    return getCoordinateAt(0) < givenDot[0];
};

bool Dot::operator>(const Dot &givenDot)
{
    return getCoordinateAt(0) > givenDot[0];
};

bool Dot::operator<=(const Dot &givenDot)
{
    return *this < givenDot || *this == givenDot;
};

bool Dot::operator>=(const Dot &givenDot)
{
    return *this > givenDot || *this == givenDot;
};

void Dot::swap(Dot &givenDot)
{
    int tempDimension = givenDot.dimension;
    double *tempCoordinates = givenDot.coordinates;

    givenDot.dimension = dimension;
    dimension = tempDimension;
    givenDot.coordinates = this->coordinates;
    this->coordinates = tempCoordinates;
}

void Dot::print()
{
    cout << "(";
    cout << getCoordinateAt(0);
    for (int i = 1; i < dimension; i++)
    {
        cout << ", " << getCoordinateAt(i);
    }
    cout << ")" << endl;
}

bool Dot::compare(Dot &dot1, Dot &dot2)
{
    return dot1 < dot2;
}

int Dot::getTotalEuclidean()
{
    return Dot::totalEuclidean;
}

void Dot::resetTotalEuclidean()
{
    Dot::totalEuclidean = 0;
}

bool Dot::bottomBoundDistance(double delta, Dot &givenDot)
{
    bool moreThan = false;
    for (int i = 0; i < dimension; i++)
    {
        moreThan = (abs(getCoordinateAt(i) - givenDot[i]) > delta);
        if (moreThan)
        {
            break;
        }
    }
    return moreThan;
}