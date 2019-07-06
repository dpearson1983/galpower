#include <iostream> // In case needed for error reporting, or prompting user
#include <sstream> // In case needed for error reporting, or file name creation
#include <vector>
#include <cmath>
#include <fstream>
/*#include "fft_helpers.hpp"*/ // This would have a function for computing the frequencies on the grid
#include "grid.hpp"

// For this basic constructor, just do something trivial. Setting the N data member to all zeros then 
// also gives a way of checking that the user has later called one of the init functions before trying
// to do something like call binNGP
grid::grid() {
    this->N = {0, 0, 0, 0}; // Use this-> to point to the data members of the class
}

grid::grid(int4 N, double4 L) {
    grid::init(N, L); // Use grid:: to point to class functions
}

// This will initialize all the data members with the input provided by the user.
void grid::init(int4 N, double4 L) {
    // Copy the provided data to the appropriate member.
    this->N = N;
    this->L = L;
    this->Delta_r = {L.x/N.x, L.y/N.y, L.z/N.z};
    // This line just calls the constructor for the vector, creating an empty vector and copying to
    // our data member.
    this->F = std::vector<double>(N.w);
}

double grid::get(int i, int j, int k){
    
}

int4 grid::getsize(){
    return N.size()
}

double4 grid::getDimention(){
    return L.size()
}
    
