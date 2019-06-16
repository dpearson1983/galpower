#include <iostream> // In case needed for error reporting, or prompting user
#include <sstream> // In case needed for error reporting, or file name creation
#include <vector>
#include <cmath>
#include <fstream>
// #include "structure.hpp"
/*#include "fft_helpers.hpp"*/ // This would have a function for computing the frequencies on the grid
#include "grid.hpp"

// For this basic constructor, just do something trivial. Setting the N data member to all zeros then 
// also gives a way of checking that the user has later called one of the init functions before trying
// to do something like call binNGP
grid::grid() {
    this->N = {0, 0, 0, 0}; // Use this-> to point to the data members of the class
}

// One of the overloaded constructors. We don't need to set the default value for r_min here since it's
// in the forward declaration in the header file. Since we need separate init functions in case the
// user calls the basic constructor, this constructor can just call the appropriate init function so we
// don't have to write the code twice.
grid::grid(int4 N, double4 L, double3 r_min) {
    grid::init(N, L, r_min); // Use grid:: to point to class functions
}

// This will initialize all the data members with the input provided by the user.
void grid::init(int4 N, double4 L, double3 r_min) {
    // Copy the provided data to the appropriate member.
    this->N = N;
    this->L = L;
    this->r_min = r_min;
    
    // Delta_r has to be computed from the provided information. Note that in cases where the user
    // may have only provided int3 and double3, we would use a similar way of initialing N and L, where
    // we would then compute the last element ourselves, e.g.
    //     this->N = {N.x, N.y, N.z, N.x*N.y*N.z};
    this->Delta_r = {L.x/N.x, L.y/N.y, L.z/N.z};
    
    // The fftFrequencies would be a function defined in fft_helpers.hpp (which we should create) that
    // returns a std::vector<double> which we then store in our data members.
//     this->k_x = fftFrequencies(N.x, L.x);
//     this->k_y = fftFrequencies(N.y, L.y);
//     this->k_z = fftFrequencies(N.z, L.z);
    
    // This line just calls the constructor for the vector, creating an empty vector and copying to
    // our data member.
    this->F = std::vector<double>(N.w);
}

// All other functions would need to be defined below here.



void grid::load() {
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
                gals.push_back(gal);
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
void grid::load(std::string filename) {
    if (std::ifstream (filename)){
        std::ifstream fin(filename);
        std::string dummyLine;
        std::getline(fin, dummyLine);
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
        errMsg << "Cannot open " << filename << "\n";
        errMsg << "Please check that the file exists and is in the appropriate directory.\n";
        throw std::runtime_error(errMsg.str());
    }
}   

int grid::get_size(){
    return gals.size();
}


void grid::binNGP(std::vector<double3> &gals) {
    N.w = N.x*N.y*N.z;
    for (size_t tid = 0; tid < gals.size(); ++tid) {
        int i = gals[tid].x/Delta_r.x;
        int j = gals[tid].y/Delta_r.y;
        int k = gals[tid].z/Delta_r.z;
        
        int index = k + N.z*(j + N.y*i);
        if (index < N.w) {
            F[index] += 1.0;
        }
    }
    std::cout << std::endl;
}
