#include "FileHandler.h"
#include <fstream>

vector<Package> loadAllPackages()
{
    vector<Package> list;     //empty list

    ifstream fin("data/packages.txt");
    string line;
    while (getline(fin,line))
    {
        if(line.empty())
        continue;

        Package p;
        p.loadFromLine(line);
        list.push_back(p);
    }
    fin.close();

    return list;
}