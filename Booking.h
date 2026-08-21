#ifndef BOOKING_H
#define BOOKING_H

#include<iostream>
using namespace std;

class Booking {
  public:
    int bookingId;
    string username;       
    int packageId;
    int numberOfTravelers;
    double totalCost;
    string bookingStatus;       // Confirmed or Cancelled
 
    void display();
    void saveToFile();
    void loadFromLine(string Line);
};
#endif