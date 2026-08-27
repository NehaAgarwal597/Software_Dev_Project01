#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include "Package.h"
#include "User.h"
#include "Booking.h"

using namespace std;

int main()
{
    while (true)
    {
        cout << "  \n=========== TRIPMATE ===========\n  " << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Register (User)" << endl;
        cout << "3. Login (User)" << endl;
        cout << "4. Exit" << endl;
        cout << "\n/Enter Choice: ";

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
                cout << "\nAdmin Login Successfully!" << endl;

                bool adminRunning = true;
                while (adminRunning)
                {
                    cout << " \n----- Admin Menu ----- " << endl; // Admin Menu
                    cout << "1. Add Trip Packages" << endl;
                    cout << "2. View Trip Package" << endl;
                    cout << "3. Search Package" << endl;
                    cout << "4. Update Package" << endl;
                    cout << "5. Delete Package" << endl;
                    cout << "6. Back to Main Menu" << endl;
                    cout << "\nEnter your choice: ";

                    int adminChoice;
                    cin >> adminChoice;

                    switch (adminChoice)
                    {
                    case 1:
                    {
                        // Add Package
                        Package p;
                        cout << " \n------ Add New Package ------ " << endl;

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

                        cout << "Enter Price(Per Person, BDT): ";
                        cin >> p.price;
                        cin.ignore();

                        cout << "Enter Duration(days): ";
                        cin >> p.duration;
                        cin.ignore();

                        cout << "Enter Trip Type(Beach/Mountain/Historical/Nature): ";
                        getline(cin, p.tripType);

                        p.saveToFile();
                        cout << "Package Added Successfully!" << endl;
                        cout << endl;
                        break;
                    }
                    case 2:
                    { // View Trip Packeage
                        cout << " \n------- All Packages -------" << endl;

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
                        string searchName;
                        cout << "Enter Destination Name to search: ";
                        cin.ignore();
                        getline(cin, searchName);

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
                            if (p.destination == searchName)
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

                                cout << "Enter New Price(Per Person, BDT): ";
                                cin >> p.price;
                                cin.ignore();

                                cout << "Enter New Duration(days): ";
                                cin >> p.duration;
                                cin.ignore();

                                cout << "Enter New Trip Type(Beach/Mountain/Historical/Nature...): ";
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
                    case 6: // Back to Main Menu
                        adminRunning = false;
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

            ifstream fin("data/users.txt"); // Check if username already exists
            string line;
            bool usernameExists = false;
            while (getline(fin, line))
            {
                if (line == username)
                {
                    usernameExists = true;
                    break;
                }
            }
            fin.close();

            if (usernameExists)
            {
                cout << "Username already exists! Please choose another name." << endl;
            }
            else
            {
                User u;
                u.username = username;
                u.saveToFile();
                cout << "Registered Successfully!" << endl;
            }
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
                cout << "\nLogin successful!" << endl;

                bool userRunning = true;

                while (userRunning)
                {
                    cout << " \n----- User Menu ----- " << endl; // User Menu
                    cout << "1. Explore Destination" << endl;
                    cout << "2. Plan a trip" << endl;
                    cout << "3. My Trips" << endl;
                    cout << "4. Cancel Booking" << endl;
                    cout << "5. Get Recommendation" << endl;
                    cout << "6. Back to Main Menu" << endl;
                    cout << "\nEnter your choice: ";

                    int userChoice;
                    cin >> userChoice;

                    switch (userChoice)
                    {
                    case 1:
                    {
                        // Explore Destination or view trip package
                        cout << " \n------- View All Packages -------" << endl;

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
                        cin.ignore();
                        string dest;
                        cout << "Enter Destination: ";
                        getline(cin, dest);

                        ifstream fin("data/packages.txt");
                        string line;
                        Package found_p; // Searching destination
                        bool destFound = false;
                        Package p;
                        while (getline(fin, line))
                        {
                            if (line.empty())
                                continue;
                            p.loadFromLine(line);
                            if (p.destination == dest)
                            {
                                found_p = p;
                                destFound = true;
                                break;
                            }
                        }
                        fin.close();

                        if (!destFound)
                        {
                            cout << "Destination not Found!" << endl;
                            break;
                        }
                        int travelers;
                        double budget;
                        cout << "Number of travelers: ";
                        cin >> travelers;
                        cout << "Enter your Budget: ";
                        cin >> budget;

                        double totalCost = found_p.price * travelers;

                        if (totalCost <= budget) // Budget Check
                        {
                            cout << "Package fits your budget!\n Total Cost: " << totalCost << endl;
                            ifstream countFile("data/bookings.txt");
                            string tempLine;
                            int count = 0;
                            while (getline(countFile, tempLine))
                            {
                                if (!tempLine.empty())
                                    count++;
                            }
                            countFile.close();

                            int newBookingId = count + 1;
                            Booking b;
                            b.bookingId = newBookingId;
                            b.username = username;
                            b.packageId = found_p.id;
                            b.numberOfTravelers = travelers;
                            b.totalCost = totalCost;
                            b.bookingStatus = "Confirmed";
                            b.saveToFile();

                            cout << "Booking confirmed!\n Booking ID: " << b.bookingId << endl;
                        }
                        else
                        {
                            cout << "Budget insufficient!\n Estimate Cost: " << totalCost << ", Your Budget: " << budget << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        // My Trips
                        cout << endl;
                        ifstream fin("data/bookings.txt");
                        string line;
                        bool any = false;
                        while (getline(fin, line))
                        {
                            if (line.empty())
                                continue;
                            Booking b;
                            b.loadFromLine(line);
                            if (b.username == username)
                            {
                                b.display();
                                cout << "-------------------------" << endl;
                                any = true;
                            }
                        }
                        fin.close();
                        if (!any)
                            cout << "No bookings found." << endl;
                        break;
                    }
                    case 4:
                    { // Cancel Booking
                        int cancelId;
                        cout << "Enter Booking ID to cancel: ";
                        cin >> cancelId;

                        ifstream fin("data/bookings.txt");
                        ofstream fout("data/temp.txt");
                        string line;
                        bool cancelled = false;
                        while (getline(fin, line))
                        {
                            if (line.empty())
                                continue;
                            Booking b;
                            b.loadFromLine(line);
                            if (b.bookingId == cancelId && b.username == username)
                            {
                                b.bookingStatus = "Cancelled";
                                cancelled = true;
                            }
                            fout << b.bookingId << "," << b.username << "," << b.packageId << "," << b.numberOfTravelers << ","
                                 << b.totalCost << "," << b.bookingStatus << endl;
                        }
                        fin.close();
                        fout.close();

                        remove("data/bookings.txt");
                        rename("data/temp.txt", "data/bookings.txt");

                        if (cancelled)
                        {
                            cout << "Booking Cancelled Successfully." << endl;
                        }
                        else
                        {
                            cout << "Booking ID not found." << endl;
                        }
                        break;
                    }
                    case 5:
                    { // Get Reccomendation
                        double budget;
                        string preferredType;
                        int travelers;

                        cout << "\n====== Smart Tour Recommendation ======\n" << endl;
                        cout << "Your budget: ";
                        cin >> budget;
                        cout << "Preferred trip type: ";
                        cin >> preferredType;
                        cout << "Number of travelers: ";
                        cin >> travelers;

                        vector<Package> allPackages;
                        vector<double> allScores; 
                        vector<double> allBudgetScores;
                        vector<double> allTypeScores;

                        ifstream fin("data/packages.txt");
                        string line;
                        while (getline(fin, line))
                        {
                            if (line.empty())
                                continue;

                            Package p;
                            p.loadFromLine(line);
                            double estimatedCost = p.price * travelers;

                            double budgetScore;
                            if (estimatedCost <= budget)
                            {
                                budgetScore = 100;
                            }
                            else
                            {
                                budgetScore = (budget / estimatedCost) * 100;
                            }
                            double typeScore;
                            if (p.tripType == preferredType)
                            {
                                typeScore = 100;
                            }
                            else
                            {
                                typeScore = 30;
                            }
                            double totalScore = (budgetScore + typeScore) / 2;

                            allPackages.push_back(p);
                            allScores.push_back(totalScore);
                            allBudgetScores.push_back(budgetScore);
                            allTypeScores.push_back(typeScore);
                        }
                        fin.close();

                        if (allPackages.empty())
                        {
                            cout << "No packages available yet." << endl;
                            break;
                        }

                        cout << "\n------- All matches -------\n";
                        for (int i = 0; i < allPackages.size(); i++)
                        {   
                            double estimateCost = allPackages[i].price * travelers;
                            cout << i + 1 << ". " << allPackages[i].destination << " Tour" 
                            << "\n   Estimate Cost: " << estimateCost << " BDT"
                            << "\n   Budget Fit: " << (int)allBudgetScores[i] << "%" 
                             "\n   Trip Type Match: " << (int)allTypeScores[i] << "%" 
                             "\n   Total Match Score: " << (int)allScores[i] << "% \n" << endl;
                        }
                        int best = 0; // find best match
                        for (int i = 1; i < allScores.size(); i++)
                        {
                            if (allScores[i] > allScores[best])
                            {
                                best = i;
                            }
                        }
                        cout << "------------------------------------------\n";
                        cout << "Best Match: " << allPackages[best].destination << " - Score: " << (int)allScores[best] << "%" << endl;
                        cout << "==========================================" << endl;
                        break;
                    }
                    case 6: // Back to Main Menu
                        userRunning = false;
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