#ifndef PACKAGE_H
#define PACKAGE_H

#include<iostream>
using namespace std;

class Package {
  public:
    int id;
    string type;          // Domestic or International
    string country;
    string destination;
    double price;
    int duration;
    string tripType;       //Beach/Mountain/Nature/Historic
 
    void display();
  
};
#endif