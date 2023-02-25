#include "Dot/Dot.hpp"
#include "DotCollection/DotCollection.hpp"
#include <iostream>

int main()
{
    int dimension;
    cout << "Enter the dimension of the space : ";
    cin >> dimension;
    int pointCount;
    cout << "Enter the number of points : ";
    cin >> pointCount;
    srand(time(NULL));
    DotCollection dc(dimension, pointCount);

    cout << "TOTAL POINTS: " << dc.length() << endl;
    cout << "DIMENSION: " << dimension << endl;
    using namespace chrono;
    auto start = high_resolution_clock::now();
    ClosestPairData closest = dc.getClosestPair();
    auto end = high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "DIVIDE AND CONQUER\n";
    cout << (double)duration.count() / 1e6 << " seconds" << endl;
    cout << "TOTAL DISTANCE CALCULATION : " << Dot::getTotalEuclidean() << endl;

    closest.getFirstDot().print();
    closest.getSecondDot().print();
    cout << closest.getDistance() << endl;
    Dot::resetTotalEuclidean();
    start = high_resolution_clock::now();
    ClosestPairData closestBrute = dc.getClosestPairBruteForce();
    end = high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "BRUTE FORCE\n";
    cout << (double)duration.count() / 1e6 << " seconds" << endl;
    cout << "TOTAL DISTANCE CALCULATION : " << Dot::getTotalEuclidean() << endl;

    closest.getFirstDot().print();
    closest.getSecondDot().print();
    cout << closest.getDistance() << endl;
    return 0;
}
