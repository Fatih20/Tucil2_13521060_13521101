#include "Dot/Dot.hpp"
#include "DotCollection/DotCollection.hpp"
// #include "Visualizer/visualizer.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Ask the dimension of and number of points from user
    int dimension;
    cout << "Enter the dimension of the space : ";
    cin >> dimension;
    int pointCount;
    cout << "Enter the number of points : ";
    cin >> pointCount;
    cout << endl;

    // Initialize dot collection according to the given parameters
    DotCollection dc(dimension, pointCount);

    using namespace chrono;

    // Do the calculation with the DnC algorithm and measure the time
    auto start = high_resolution_clock::now();
    ClosestPairData closest = dc.getClosestPair();
    auto end = high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // Print out the result
    cout << "Devide et Impera" << endl;
    cout << (double)duration.count() / 1e6 << " seconds" << endl;
    cout << "Number of Distance Calculation : " << Dot::getTotalEuclidean() << endl;

    cout << dc.getTotalDotInTheMiddle() << endl;
    cout << dc.getTotalSubProblemJoin() << endl;
    cout << dc.getAverageDotInTheMiddle() << endl;
    cout << dc.getMaxDotInTheMiddle() << endl;
    cout << dc.getAvgTopPercentileOfDotsInTheMiddle() << endl;

    /*
    cout << "First Dot" << endl;
    closest.getFirstDot().print();
    cout << "Second Dot" << endl;
    closest.getSecondDot().print();
    cout << "Distance" << endl;
    cout << closest.getDistance() << endl;
    */

    cout << endl
         << endl;

    /*
    // Reset the euclidean distance counter
    Dot::resetTotalEuclidean();

    // Do the calculation with the brute force algorithm and measure the time
    start = high_resolution_clock::now();
    ClosestPairData closestBrute = dc.getClosestPairBruteForce();
    end = high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // Print out the result
    cout << "Smol brain O(n^2)\n";
    cout << (double)duration.count() / 1e6 << " seconds" << endl;
    cout << "Number of Distance Calculation : " << Dot::getTotalEuclidean() << endl;

    cout << "First Dot" << endl;
    closest.getFirstDot().print();
    cout << "Second Dot" << endl;
    closest.getSecondDot().print();
    cout << "Distance" << endl;
    cout << closest.getDistance() << endl;

    */

    // Visualize the result if it's in 3D
    // if (dimension == 3)
    // {
    //     visualizeDots(dc, closest);
    // }
    return 0;
}
