#include "Package.h"
#include <fstream>
#include <sstream>

void Package::display(){
    cout << "Package ID: " << id << endl;
        cout << "Type: " << type << endl;  // Domestic/International
        cout << "Country: " << country << endl;
        cout << "Destination: " << destination << endl;
        cout << "Price(Per Person, BDT): " << price << endl;
        cout << "Duration(days): " << duration << endl;
        cout << "Trip Type: " << tripType << endl;    // Beach/Mountain/Historical/Nature....
}

void Package::saveToFile() {
    ofstream fout("data/packages.txt", ios::app);
    fout << id << "," << type << "," << country << ","
         << destination << "," << price << ","
         << duration << "," << tripType << endl;
    fout.close();
}

void Package::loadFromLine(string line) {
    stringstream ss(line);
    string idStr, priceStr, durationStr;

    getline(ss, idStr, ',');
    getline(ss, type, ',');
    getline(ss, country, ',');
    getline(ss, destination, ',');
    getline(ss, priceStr, ',');
    getline(ss, durationStr, ',');
    getline(ss, tripType, ',');

    id = stoi(idStr);
    price = stod(priceStr);
    duration = stoi(durationStr);
}