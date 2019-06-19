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
        overden(numden &n_g, numden &n_r);
        
        void init(numden &n_g, numdem &n_r);
        
        void transform();
        
};
