#ifndef _OVERDEN_HPP_
#define _OVERDEN_HPP_

#include <fftw3.h>
#include "grid.hpp"
#include "numden.hpp"

class overden : public grid{
    std::vector<double> kx, ky, kz;
    fftw_plan dr2dk;
    double alpha, shotNoise, norm;
    
    std::vector<double> getFrequencies(int n, double l);
    
    public:
        // Override the definition from parent class due to different size needed for the in-place FFT
        overden(int4 N, double4 L);
        
        overden(int4 N, double4 L, numden &n_g, numden &n_r);
        
        void init(int4 N, double4 L);
        
        void init(int4 N, double4 L, numden &n_g, numdem &n_r);
        
        void transform();
        
};
