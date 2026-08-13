#include <iostream>
#include <fstream>
#include "Package.h"
#include "User.h"

using namespace std;

int main()
{
   while(true){
    cout << "   =========== TRIPMATE ===========  " << endl;
    cout << "1. Admin Login" << endl;
    cout << "2. Register (User)" << endl;
    cout << "3. Login (User)" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter Choice: ";

    int choice;
    cin >> choice;

  switch(choice) {
    case 1: {          //  Admin Login
     string password;
     cout << "Enter Admin Password: ";
     cin >> password;
     if(password == "admin789") {
        cout << "Admin Login Successfully" << endl;
     } else {
        cout << "Wrong Password" << endl;
     }
       break;
    }
    case 2: {            // Register
        string username;
        cout << "Enter Username: ";
        cin >> username;

        User u;
        u.username = username;
        u.saveToFile();
        cout << "Registered Successfully!" << endl;

        break;
    }
    case 3: {                // Login
         string username;
        cout << "Enter Username: ";
        cin >> username;

        ifstream fin("data/users.txt");
        string line;
        bool found = false;
        while(getline(fin,line)) {
            if(line == username) {
                found = true;
            }
        }
        fin.close();

        if(found == true){
            cout << "Login successful" << endl;
        } else {
            cout << "User not found, please register first" << endl;
        }
        break;
    }
    case 4:                           // Exit
        cout << "Exiting..." << endl;
        return 0;
    default:
        cout << "Invalid choice" << endl;


  }


 }

    return 0;

}