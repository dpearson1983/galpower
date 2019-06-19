#ifndef _NUMDEN_HPP_
#define _NUMDEM_HPP_

#include "grid.hpp"

class numden : public grid{
    double3 wnb; // x -> sum of weights, y -> sum of weights squared, z -> sum of weights squared times nbar
    double3 r_min, Delta_r;
    
    public:
        numden(int4 N, double4 L, double3 r_min = {0.0, 0.0, 0.0});
        
        numden(int4 N, double4 L, std::vector<double3> &gals, double3 r_min = {0.0, 0.0, 0.0});
        
        numden(int3 N, double3 L, double3 r_min = {0.0, 0.0, 0.0});
        
        numden(int3 N, double3 L, std::vector<double3> &gals, double3 r_min = {0.0, 0.0, 0.0});
        
        void init(int4 N, double4 L, double3 r_min = {0.0, 0.0, 0.0});
        
        void init(int4 N, double4 L, std::vector<double3> &gals, double3 r_min = {0.0, 0.0, 0.0});
        
        void init(int3 N, double3 L, double3 r_min = {0.0, 0.0, 0.0});
        
        void init(int3 N, double3 L, std::vector<double3> &gals, double3 r_min = {0.0, 0.0, 0.0});
        
        void binNGP(std::vector<double3> &gals);
        
};
    
