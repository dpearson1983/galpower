#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "loadfile.hpp"



void Loadfile::loadfile() {
    std::string filename;
    std::cout << "Enter the filename :\n";
    std::cin >> filename;
    
    
    if (std::ifstream(filename)){
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
    else {
        std::stringstream errMsg;
        errMsg << "Cannot open " << filename << "\n";
        errMsg << "Please check that the file exists and is in the appropriate directory.\n";
        throw std::runtime_error(errMsg.str());
    }
}    
void Loadfile::loadfile(std::string filename) {
    if (std::ifstream (filename)){
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
    else {
        std::stringstream errMsg;
        errMsg << "Cannot open " << filename << "\n";
        errMsg << "Please check that the file exists and is in the appropriate directory.\n";
        throw std::runtime_error(errMsg.str());
    }
}   

int Loadfile::get_size(){
    return galaxies.size();
}



//void binNGP(std::vector <double3> &galaxies, std::vector )

