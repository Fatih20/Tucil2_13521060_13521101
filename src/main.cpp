#include "Dot/Dot.hpp"
#include "DotCollection/DotCollection.hpp"
#include "Visualizer/visualizer.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int dimension;
    cout << "Enter the dimension of the space : ";
    cin >> dimension;
    int pointCount;
    cout << "Enter the number of points : ";
    cin >> pointCount;
    cout << endl;
    DotCollection dc(dimension, pointCount);

    using namespace chrono;
    auto start = high_resolution_clock::now();
    ClosestPairData closest = dc.getClosestPair();
    auto end = high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Devide et Impera\n";
    cout << (double)duration.count() / 1e6 << " seconds" << endl;
    cout << "Number of Distance Calculation : " << Dot::getTotalEuclidean() << endl;

    closest.getFirstDot().print();
    closest.getSecondDot().print();
    cout << closest.getDistance() << endl;

    Dot::resetTotalEuclidean();

    start = high_resolution_clock::now();
    ClosestPairData closestBrute = dc.getClosestPairBruteForce();
    end = high_resolution_clock::now();
    cout << endl;
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Smol brain O(n^2)\n";
    cout << (double)duration.count() / 1e6 << " seconds" << endl;
    cout << "Number of Distance Calculation : " << Dot::getTotalEuclidean() << endl;

    closest.getFirstDot().print();
    closest.getSecondDot().print();
    cout << closest.getDistance() << endl;

    if (dimension == 3)
    {
        visualizeDots(dc, closest);
    }
    return 0;
}
