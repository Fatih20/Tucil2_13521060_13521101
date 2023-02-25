#include "Dot/Dot.hpp"
#include "DotCollection/DotCollection.hpp"
#include "matplotlibcpp.h"
#include <iostream>
#include <vector>
using namespace std;

namespace plt = matplotlibcpp;

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
        auto fig = plt::figure();
        vector<vector<double>> x, y, z;
        vector<double> x_row, y_row, z_row;
        for (int i = 0; i < pointCount; i++)
        {
            Dot &dot = dc[i];
            if (&dot != &closest.getFirstDot() && &dot != &closest.getSecondDot())
            {
                x_row.push_back(dot[0]);
                y_row.push_back(dot[1]);
                z_row.push_back(dot[2]);
            }
            else
            {
                vector<double> x_row, y_row, z_row;
                x_row.push_back(dot[0]);
                y_row.push_back(dot[1]);
                z_row.push_back(dot[2]);
                plt::scatter(x_row, y_row, z_row, 1.0, {{"color", "red"}}, fig);
            }
        }
        plt::scatter(x_row, y_row, z_row, 1.0, {{"color", "blue"}}, fig);
        plt::title("This is title");
        plt::show();
    }
    return 0;
}
