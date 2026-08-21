#include "Booking.h"
#include <fstream>
#include <sstream>

void Booking::display(){
    cout << "Booking ID: " << bookingId << endl;
        cout << "User Name: " << username << endl;
        cout << "Package ID: " << packageId << endl;
        cout << "Number of Travelers: " << numberOfTravelers << endl;
        cout << "Total Cost: " << totalCost << endl;
        cout << "Booking Status: " << bookingStatus << endl;
}       
    
void Booking::saveToFile() {
    ofstream fout("data/bookings.txt", ios::app);
    fout << bookingId << "," << username << "," << packageId << ","
         << numberOfTravelers << "," << totalCost << ","
         << bookingStatus << endl;
    fout.close();
}

void Booking::loadFromLine(string line) {
    stringstream ss(line);
    string bookingIdStr, packageIdStr, travelersStr, costStr;

    getline(ss, bookingIdStr, ',');
    getline(ss, username, ',');
    getline(ss, packageIdStr, ',');
    getline(ss, travelersStr, ',');
    getline(ss,  costStr, ',');
    getline(ss, bookingStatus, ',');
    

    bookingId = stoi(bookingIdStr);
    packageId = stoi(packageIdStr);
    numberOfTravelers = stoi(travelersStr);
    totalCost = stod(costStr);
}

