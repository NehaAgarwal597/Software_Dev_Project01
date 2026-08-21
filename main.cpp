#include <iostream>
#include <fstream>
#include <cstdio>
#include "Package.h"
#include "User.h"
#include "Booking.h"

using namespace std;

int main()
{
    while (true)
    {
        cout << "   =========== TRIPMATE ===========  " << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Register (User)" << endl;
        cout << "3. Login (User)" << endl;
        cout << "4. Exit" << endl;
        cout << endl;
        cout << "/Enter Choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        { //  Admin Login
            string password;
            cout << "Enter Admin Password: ";
            cin >> password;
            if (password == "admin789")
            {
                cout << "Admin Login Successfully" << endl;
                cout << endl;
                cout << " ----- Admin Menu ----- " << endl; // Admin Menu
                cout << "1. Add Trip Packages" << endl;
                cout << "2. View Trip Package" << endl;
                cout << "3. Search Package" << endl;
                cout << "4. Update Package" << endl;
                cout << "5. Delete Package" << endl;
                cout << "6. Back to Main Menu" << endl;
                cout << endl;
                cout << "Enter your choice: ";

                int adminChoice;
                cin >> adminChoice;

                switch (adminChoice)
                {
                case 1:
                {
                    // Add Package
                    Package p;
                    cout << endl;
                    cout << " ------ Add New Package ------ " << endl;

                    cout << "Enter Package ID: ";
                    cin >> p.id;
                    cin.ignore(); // Clear leftover newline
                    // ID Check
                    ifstream checkFile("data/packages.txt");
                    string line;
                    bool idExists = false;
                    while (getline(checkFile, line))
                    {
                        if (line.empty())
                            continue;

                        Package temp;
                        temp.loadFromLine(line);
                        if (temp.id == p.id)
                        {
                            idExists = true;
                            break;
                        }
                    }
                    checkFile.close();

                    if (idExists)
                    {
                        cout << "Package ID already exists! Use a different ID." << endl;
                        break;
                    }

                    cout << "Enter Type (Domestic/International): ";
                    cin >> p.type;
                    cin.ignore();

                    cout << "Enter Country: ";
                    getline(cin, p.country); // takes full line including space

                    cout << "Enter Destination: ";
                    getline(cin, p.destination);

                    cout << "Enter Price: ";
                    cin >> p.price;
                    cin.ignore();

                    cout << "Enter Duration(days): ";
                    cin >> p.duration;
                    cin.ignore();

                    cout << "Enter Trip Type: ";
                    getline(cin, p.tripType);

                    p.saveToFile();
                    cout << "Package Added Successfully!" << endl;
                    cout << endl;
                    break;
                }
                case 2:
                { // View Trip Packeage
                    cout << endl;
                    cout << " ------- All Packages -------" << endl;

                    ifstream fin("data/packages.txt");
                    string line;
                    while (getline(fin, line))
                    {
                        if (line.empty())
                            continue;
                        Package p;
                        p.loadFromLine(line);
                        p.display();
                        cout << "-----------------------" << endl;
                    }
                    fin.close();
                    break;
                }
                case 3:
                { // Search Package
                    int searchName;
                    cout << "Enter Destination Name to search: ";
                    cin >> searchName;
                    cout << endl;
                    ifstream fin("data/packages.txt");
                    string line;
                    bool found = false;
                    while (getline(fin, line))
                    {
                        if (line.empty())
                            continue;

                        Package p;
                        p.loadFromLine(line);
                        if (p.id == searchName)
                        {
                            p.display();
                            found = true;
                            break;
                        }
                    }
                    fin.close();

                    if (!found)
                    {
                        cout << "Package not found." << endl;
                    }
                    break;
                }
                case 4:
                { // Update Package
                    int updateId;
                    cout << "Enter Package ID to update: ";
                    cin >> updateId;

                    ifstream fin("data/packages.txt");
                    string line;

                    ofstream fout("data/temp.txt");

                    bool updated = false;
                    while (getline(fin, line))
                    {
                        if (line.empty())
                            continue;

                        Package p;
                        p.loadFromLine(line);
                        if (p.id == updateId)
                        {
                            cout << "Enter New Type (Domestic/International): ";
                            cin >> p.type;
                            cin.ignore();

                            cout << "Enter New Country: ";
                            getline(cin, p.country); // takes full line including space

                            cout << "Enter New Destination: ";
                            getline(cin, p.destination);

                            cout << "Enter New Price: ";
                            cin >> p.price;
                            cin.ignore();

                            cout << "Enter New Duration(days): ";
                            cin >> p.duration;
                            cin.ignore();

                            cout << "Enter New Trip Type: ";
                            getline(cin, p.tripType);

                            updated = true;
                        }
                        fout << p.id << "," << p.type << "," << p.country << ","
                             << p.destination << "," << p.price << ","
                             << p.duration << "," << p.tripType << endl;
                    }
                    fin.close();
                    fout.close();

                    remove("data/packages.txt");
                    rename("data/temp.txt", "data/packages.txt");

                    if (updated)
                    {
                        cout << "Package Updated Successfully!" << endl;
                    }
                    else
                    {
                        cout << "Package ID not found!" << endl;
                    }
                    break;
                }
                case 5:
                {
                    // Delete Package
                    int deleteId;
                    cout << "Enter Package ID to delete: ";
                    cin >> deleteId;

                    ifstream fin("data/packages.txt");
                    string line;

                    ofstream fout("data/temp.txt");

                    bool deleted = false;
                    while (getline(fin, line))
                    {
                        if (line.empty())
                            continue;

                        Package p;
                        p.loadFromLine(line);
                        if (p.id == deleteId)
                        {
                            deleted = true;
                            continue;
                        }
                        fout << p.id << "," << p.type << "," << p.country << ","
                             << p.destination << "," << p.price << ","
                             << p.duration << "," << p.tripType << endl;
                    }
                    fin.close();
                    fout.close();

                    remove("data/packages.txt");
                    rename("data/temp.txt", "data/packages.txt");

                    if (deleted)
                    {
                        cout << "Package Deleted Successfully!" << endl;
                    }
                    else
                    {
                        cout << "Package ID not found!" << endl;
                    }
                    break;
                }
                }
            }
            else
            {
                cout << "Wrong Password" << endl;
            }
            break;
        }
        case 2:
        { // User Register
            string username;
            cout << "Enter Username: ";
            cin >> username;

            User u;
            u.username = username;
            u.saveToFile();
            cout << "Registered Successfully!" << endl;

            break;
        }
        case 3:
        { // User Login
            string username;
            cout << "Enter Username: ";
            cin >> username;

            ifstream fin("data/users.txt");
            string line;
            bool found = false;
            while (getline(fin, line))
            {
                if (line == username)
                {
                    found = true;
                }
            }
            fin.close();

            if (found == true)
            {
                cout << "Login successful" << endl;
                cout << endl;
                cout << " ----- User Menu ----- " << endl; // User Menu
                cout << "1. Explore Destination" << endl;
                cout << "2. Plan a trip" << endl;
                cout << "3. My Trips" << endl;
                cout << "4. Back to Main Menu" << endl;
                cout << endl;
                cout << "Enter your choice: ";

                int userChoice;
                cin >> userChoice;

                switch (userChoice)
                {
                case 1:
                {
                    // Explore Destination or view trip package
                    cout << endl;
                    cout << " ------- View All Packages -------" << endl;

                    ifstream fin("data/packages.txt");
                    string line;
                    while (getline(fin, line))
                    {
                        if (line.empty())
                            continue;
                        Package p;
                        p.loadFromLine(line);
                        p.display();
                        cout << "-----------------------" << endl;
                    }
                    fin.close();
                    break;
                }
                case 2:
                {
                    // Plan a trip
                    int pkgId, travelers;
                    cout << "Enter Package ID to book: ";
                    cin >> pkgId;
                    cout << "Enter Number of Travelers: ";
                    cin >> travelers;

                    ifstream fin("data/packages.txt");
                    string line;
                    bool pkgFound = false;
                    Package p;
                    while (getline(fin, line))
                    {
                        if (line.empty())
                            continue;
                        p.loadFromLine(line);
                        if (p.id == pkgId)
                        {
                            pkgFound = true;
                            break;
                        }
                    }
                    fin.close();

                    if (!pkgFound)
                    {
                        cout << "Package not Found!" << endl;
                        break;
                    }
                    Booking b;
                    b.bookingId = pkgId * 1000 + travelers;
                    b.username = username;
                    b.packageId = pkgId;
                    b.numberOfTravelers = travelers;
                    b.totalCost = p.price * travelers;
                    b.bookingStatus = "Confirmed";
                    b.saveToFile();

                    cout << "Booking confirmed!\n Total Cost: " << b.totalCost << endl;

                    break;
                }
                case 3:
                {
                    // My Trip
                    cout << endl;
                    ifstream fin("data/bookings.txt");
                    string line;
                    while (getline(fin, line))
                    {
                        if (line.empty())
                            continue;
                        Booking b;
                        b.loadFromLine(line);
                        if (b.username == username)
                        {
                            b.display();
                            cout << "-----------------------" << endl;
                        }
                    }
                    fin.close();
                    break;
                }
                }
            }
            else
            {
                cout << "User not found, please register first" << endl;
            }
            break;
        }
        case 4: // Exit
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}