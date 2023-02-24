#include "Dot.hpp"
#include <iostream>

Dot::Dot() : Dot(3)
{
}

Dot::Dot(int dimension)
{
    coordinates = {};
    for (int i = 0; i < dimension; i++)
    {
        double randomCoordinate = rand();
        double sign = rand() % 2 == 0 ? -1 : 1;
        coordinates.push_back(sign * randomCoordinate);
    }
}

Dot::Dot(vector<double> givenCoordinate)
{
    coordinates = givenCoordinate;
};

Dot::~Dot()
{
    coordinates.clear();
}

Dot &Dot::operator=(const Dot &givenDot)
{
    coordinates = givenDot.coordinates;
    return *this;
}

double Dot::getSquaredDistance(Dot targetDot)
{
    double sum = 0;
    for (int i = 0; i < coordinates.size(); i++)
    {
        sum += pow(getCoordinateAt(i) - targetDot.getCoordinateAt(i), 2);
    }
    return sum;
};

double Dot::getDistance(Dot targetDot)
{
    return (pow(getSquaredDistance(targetDot), 1 / 2));
}

double Dot::getCoordinateAt(int dimension)
{
    return coordinates.at(dimension - 1);
}

bool Dot::operator==(const Dot &givenDot)
{
    return coordinates == givenDot.coordinates;
};

void Dot::print()
{
    cout << "(";
    cout << coordinates.at(0);
    for (int i = 1; i < coordinates.size(); i++)
    {
        cout << ", " << coordinates.at(i);
    }
    cout << ")" << endl;
}