#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "grid.hpp"



void Load::load() {
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
void Load::load(std::string filename) {
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

int Load::get_size(){
    return galaxies.size();
}


void Load::binNGP(std::vector<double3> &galaxies, std::vector<double> &dr, int4 N , double3 L) {
    N.w = N.x*N.y*N.z;
    double3 Delta_r = {L.x/N.x, L.y/N.y, L.z/N.z};
    for (size_t tid = 0; tid < galaxies.size(); ++tid) {
        int i = galaxies[tid].x/Delta_r.x;
        int j = galaxies[tid].y/Delta_r.y;
        int k = galaxies[tid].z/Delta_r.z;
        
        int index = k + N.z*(j + N.y*i);
        if (index < N.w) {
            dr[index] += 1.0;
        }
    }
    std::cout << std::endl;
}



