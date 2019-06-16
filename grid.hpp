#ifndef _GRID_HPP_
#define _GRID_HPP_

#include <vector>
#include <string>
#include "structure.hpp"
// #include "fft_helpers.hpp"

class grid{
    int4 N; // Stores grid dimensions and total number of grid points
    double4 L; // Stores physical dimensions and volume
    double3 Delta_r, r_min; // Delta_r stores grid spacing, r_min stores the minimum position allowed (0,0,0) by 
                            // default
    std::vector<double3> gals;                        
    std::vector<double> k_x, k_y, k_z; // Storage for the frequecies
    std::vector<double> F; // The grid itself
    
    // We'll want to add storage for a fftw plan here at some point as well.
    
    public:
        grid(); // Basic constructor
        
        // Several different constructors for flexibility for the user
        grid(int4 N, double4 L, double3 r_min = {0.0, 0.0, 0.0});
        
        grid(int4 N, double4 L, std::vector<double3> &gals, double3 r_min = {0.0, 0.0, 0.0});
        
        grid(int3 N, double3 L, double3 r_min = {0.0, 0.0, 0.0});
        
        grid(int3 N, double3 L, std::vector<double3> &gals, double3 r_min = {0.0, 0.0, 0.0});
        
        void init(int4 N, double4 L, double3 r_min = {0.0, 0.0, 0.0});
        
        void init(int4 N, double4 L, std::vector<double3> &gals, double3 r_min = {0.0, 0.0, 0.0});
        
        void init(int3 N, double3 L, double3 r_min = {0.0, 0.0, 0.0});
        
        void init(int3 N, double3 L, std::vector<double3> &gals, double3 r_min = {0.0, 0.0, 0.0});
        
        void binNGP(std::vector<double3> &gals);
        
        // This could load the data from the file and then call the bin function, or we could leave this
        // out and have a separate simple header file that loads the file, then we pass the galaxies to
        // the class constructor or simply the binNGP function depending on the constructor we call
        void load(std::string file);
        void load();
        int get_size();
        
};

#endif
