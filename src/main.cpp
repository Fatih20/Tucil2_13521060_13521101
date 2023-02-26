#include "Dot/Dot.hpp"
#include "DotCollection/DotCollection.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    DotCollection dc(3, 4);

    dc.print();

    dc.sort();
    cout << "Result" << endl;
    dc.print();

    // Dot dot1;
    // dot1.swap(dot1);

    return 0;
}