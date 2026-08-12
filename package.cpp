#include "Package.h"

void Package::display(){
    cout << "TRIP ID: " << id << endl;
        cout << "Type: " << type << endl;
        cout << "Country: " << country << endl;
        cout << "Destination: " << destination << endl;
        cout << "Price: " << price << endl;
        cout << "Duration: " << duration << endl;
        cout << "Trip Type: " << tripType << endl;
}