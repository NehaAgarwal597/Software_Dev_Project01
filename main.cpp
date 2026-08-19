#include <iostream>
#include <fstream>
#include "Package.h"
#include "User.h"

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
                cout << "3. Back to Main Menu" << endl;
                cout << endl;
                cout << "Enter your choice: ";

                int adminChoice;
                cin >> adminChoice;

                switch (adminChoice)
                {
                case 1:
                { // Add Package
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
                }
            }
            else
            {
                cout << "Wrong Password" << endl;
            }
            break;
        }
        case 2:
        { // Register
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
        { // Login
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