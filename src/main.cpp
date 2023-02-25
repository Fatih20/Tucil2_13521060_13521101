#include "Dot/Dot.hpp"
#include "DotCollection/DotCollection.hpp"
#include <iostream>

int main()
{
    const int dimension = 5;
    const int pointCount = 10000;
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
    cout << "TOTAL COMPARISON: " << Dot::getTotalEuclidean() << endl;

    closest.getFirstDot().print();
    closest.getSecondDot().print();
    cout << closest.getDistance() << endl;
    Dot::resetTotalEuclidean();
    start = high_resolution_clock::now();
    ClosestPairData closestBrute = dc.getClosestPairBruteForce();
    end = high_resolution_clock::now();
    // cout << "TOTAL COMPARISON :" << DotCollection::

    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "BRUTE FORCE\n";
    cout << (double)duration.count() / 1e6 << " seconds" << endl;
    cout << "TOTAL COMPARISON: " << Dot::getTotalEuclidean() << endl;

    closest.getFirstDot().print();
    closest.getSecondDot().print();
    cout << closest.getDistance() << endl;
    return 0;
}
