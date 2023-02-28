#include "Dot.hpp"
#include <iostream>
#include <random>

long Dot::totalEuclidean = 0;

Dot::Dot() : Dot(3)
{
}

Dot::Dot(int dimension)
{

    // Create random floating point number generator with the range of -1000 to 1000
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> distribution(-1000, 1000);

    // Initialize array of coordinate value
    coordinates = new double[dimension];
    this->dimension = dimension;

    // Fill the array with randomized alue

    for (int i = 0; i < dimension; i++)
    {
        coordinates[i] = distribution(generator);
    }
}

Dot::Dot(const Dot &givenDot)
{
    // Make an array with the exact same content as the givenDot
    this->dimension = givenDot.dimension;
    this->coordinates = new double[dimension];
    for (int i = 0; i < dimension; i++)
    {
        coordinates[i] = givenDot[i];
    }
}

Dot::~Dot()
{
    // Deallocate the coordinate array created with new
    delete[] coordinates;
}

Dot &Dot::operator=(const Dot &givenDot)
{
    // Copy the content of the givenDot
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
    // Increment the number of euclidean calculation counter
    Dot::totalEuclidean++;
    // Sum the square of the difference for all coordinate
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
    // Compare each of the coordinate
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
    // Swap the content of two dot
    int tempDimension = givenDot.dimension;
    double *tempCoordinates = givenDot.coordinates;

    givenDot.dimension = dimension;
    dimension = tempDimension;
    givenDot.coordinates = this->coordinates;
    this->coordinates = tempCoordinates;
}

void Dot::print()
{
    // Print the dot with the format '(x1, x2, x3, ..., xn)'
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
    // Compare the difference of each coordinate with the delta
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