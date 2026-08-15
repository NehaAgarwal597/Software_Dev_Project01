#include "Package.h"
#include <fstream>

void Package::display(){
    cout << "Package ID: " << id << endl;
        cout << "Type: " << type << endl;
        cout << "Country: " << country << endl;
        cout << "Destination: " << destination << endl;
        cout << "Price: " << price << endl;
        cout << "Duration: " << duration << endl;
        cout << "Trip Type: " << tripType << endl;
}

void Package::saveToFile() {
    ofstream fout("data/packages.txt", ios::app);
    fout << id << "," << type << "," << country << ","
         << destination << "," << price << ","
         << duration << "," << tripType << endl;
    fout.close();
}