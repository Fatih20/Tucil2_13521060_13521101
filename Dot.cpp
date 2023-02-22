#include "Dot.hpp"

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
    return (pow(getSquaredDistance(targetDot), 1 / coordinates.size()));
}

double Dot::getCoordinateAt(int dimension)
{
    return coordinates.at(dimension - 1);
}

bool Dot::operator==(const Dot &givenDot)
{
    return coordinates == givenDot.coordinates;
};
