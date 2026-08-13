#include <iostream>
#include "Package.h"
using namespace std;

int main()
{
    Package p1;
    p1.id = 101;
    p1.type = "Domestic";
    p1.country = "Bangladesh";
    p1.destination = "Cox's Bazar";
    p1.price = 25000;
    p1.duration = 3;
    p1.tripType = "Beach";

    p1.display();

    return 0;

}