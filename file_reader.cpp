#include <iostream> // In case needed for error reporting, or prompting user
#include <sstream> // In case needed for error reporting, or file name creation
#include <vector>
#include <cmath>
#include <fstream>
// #include "structure.hpp"
/*#include "fft_helpers.hpp"*/ // This would have a function for computing the frequencies on the grid
#include "grid.hpp"





// NOTE: This should be moved to a file_reader.cpp file which contains the definitions for everything in
// the file_reader.hpp class definition, except the enum class part which doesn't need anything further. That
// function would be called from main.cpp and then the galaxies would be passed to one of the other functions
// here, either one of the constructors that accepts it as an argument, or to binNGP directly.
std::vector<double3> fileReader::loadfile(std::string filename) {
    std::vector<double3> gals;
    if (std::ifstream (filename)){
        std::ifstream fin(filename);
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
//         binNGP(gals);  NOTE: When moved, you won't call this function here. Instead loadfile will have a
                      // return type of std::vector<double3>, and you will have to add return gals; at the 
                      // end of the function.
    }
    else {
        std::stringstream errMsg;
        errMsg << "Cannot open " << filename << "\n";
        errMsg << "Please check that the file exists and is in the appropriate directory.\n";
        throw std::runtime_error(errMsg.str());
    }
    return gals;
}   
 
