#include "Dot/Dot.hpp"
#include "DotCollection/DotCollection.hpp"

int main()
{
    DotCollection dc(2, 10);
    dc.print();
    dc.getMiddleSeparator();
    // DotCollection dc2 = *(dc.createSubCollection(5, 90));
    // dc.at(0).print();
    // dc.at(5).print();
    // dc2.at(0).print();

    // dc.clear();
}
