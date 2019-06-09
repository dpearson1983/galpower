#include <vector>
#include <iostream>
#include <fstream>
#include "loadfile.hpp"



void Loadfile::loadfile() {
    std::string filename;
    std::cout << "Enter the filename :\n";
    std::cin >> filename;
    std::ifstream fin(filename);
    std::string dummyLine;
    std::getline(fin, dummyLine);
    while (!fin.eof()) {
        double3 gal;
        fin >> gal.x >> gal.y >> gal.z;
        if (!fin.eof()) {
            galaxies.push_back(gal);
        }
    }
    fin.close();
}    
void Loadfile::loadfile(std::string filename) {
    std::ifstream fin(filename);
    std::string dummyLine;
    std::getline(fin, dummyLine);
    while (!fin.eof()) {
        double3 gal;
        fin >> gal.x >> gal.y >> gal.z;
        if (!fin.eof()) {
            galaxies.push_back(gal);
        }
    }
    fin.close();
}

int Loadfile::get_size(){
    return galaxies.size();
}

//void binNGP(std::vector <double3> &galaxies, std::vector )

