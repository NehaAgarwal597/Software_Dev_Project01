#include "User.h"
#include <fstream>

void User::saveToFile() {
    ofstream fout("data/users.txt" , ios::app);
    fout << username << endl;
    
    fout.close();
}