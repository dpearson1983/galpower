#include <iostream> // In case needed for error reporting, or prompting user
#include <sstream> // In case needed for error reporting, or file name creation
#include <vector>
#include <cmath>
#include <fstream>
// #include "structure.hpp"
/*#include "fft_helpers.hpp"*/ // This would have a function for computing the frequencies on the grid
#include "grid.hpp"


// Initialize filereader 
fileReader::fileReader(){
     init(this -> fType);
}

fileReader::fileReader(fileType fType){
    setFileType(this -> fType);
}

void fileReader::init(fileType fType){
    this->fType = fileType::patchy;
}

void fileReader::setFileType(fileType fType){
    switch (this -> fType)
        case fileType::patchy:
        {
            this->fType = fileType::patchy;
            break;
        }
        case fileType::DR12:
        {
            this->fType = fileType::DR12;
            break;
        }
        case fileType::lognormal:
        {
            this->fType = fileType::lognormal;
            break;
        }
        default:  // is this part needed?
        {
            std::stringstream errMsg;
            errMsg << "Unrecognized or unsupported I/O mode. Defaulting to patchy I/O.\n";
            this->fType = fileType::patchy;
            break;
        }  
}
// NOTE: This should be moved to a file_reader.cpp file which contains the definitions for everything in
// the file_reader.hpp class definition, except the enum class part which doesn't need anything further. That
// function would be called from main.cpp and then the galaxies would be passed to one of the other functions
// here, either one of the constructors that accepts it as an argument, or to binNGP directly.
std::vector<double3> fileReader::loadfile(std::string file) {
    std::vector<double3> gals;
    switch(this->fType){
        case fileType::patchy:
        {
            gals = loadPatchy(file);
            break;
        }
        case fileType::DR12:
        {
            gals = loadDR12(file);
            break;
        }
        case fileType::lognormal:
        {
            gals = loadLognormal(file);
            break;
        }
        default: //is this needed?
        {
            std::stringstream errMsg;
            errMsg << "Invalid type\n";
            throw std::runtime_error(errMsg.str());
        }   
        
    }
    return gals;
}   


//loading Patchy type flie
std::vector<double3> fileReader::loadPatchy(std::string file) {
    std::vector<double3> gals;
    if (std::ifstream (file)){
        std::ifstream fin(file);
//         std::string dummyLine;
//         std::getline(fin, dummyLine);
        while (!fin.eof()) {
            double3 gal;
            fin >> gal.x >> gal.y >> gal.z;
            if (!fin.eof()) {
                gals.push_back(gal);
            }
        }
        fin.close();
    }
    else {
        std::stringstream errMsg;
        errMsg << "Cannot open " << file << "\n";
        errMsg << "Please check that the file exists and is in the appropriate directory.\n";
        throw std::runtime_error(errMsg.str());
    }
    return gals
}   

//loading DR12 type flie
std::vector<double3> fileReader::loadDR12(std::string file) {
    std::vector<double3> gals;
    if (std::ifstream (file)){
        std::ifstream fin(file);
//         std::string dummyLine;
//         std::getline(fin, dummyLine);
        while (!fin.eof()) {
            double3 gal;
            fin >> gal.x >> gal.y >> gal.z;
            if (!fin.eof()) {
                gals.push_back(gal);
            }
        }
        fin.close();
    }
    else {
        std::stringstream errMsg;
        errMsg << "Cannot open " << file << "\n";
        errMsg << "Please check that the file exists and is in the appropriate directory.\n";
        throw std::runtime_error(errMsg.str());
    }
    return gals
}  

//loading lognormal type flie
std::vector<double3> fileReader::loadLognormal(std::string file) {
    std::vector<double3> gals;
    if (std::ifstream (file)){
        std::ifstream fin(file);
//         std::string dummyLine;
//         std::getline(fin, dummyLine);
        while (!fin.eof()) {
            double3 gal;
            fin >> gal.x >> gal.y >> gal.z;
            if (!fin.eof()) {
                gals.push_back(gal);
            }
        }
        fin.close();
    }
    else {
        std::stringstream errMsg;
        errMsg << "Cannot open " << file << "\n";
        errMsg << "Please check that the file exists and is in the appropriate directory.\n";
        throw std::runtime_error(errMsg.str());
    }
    return gals
}  

