#ifndef _GALAXY_HPP_
#define _GALAXY_HPP_

#include "cosmology.hpp"

class galaxy{
    public:
        double ra, dec, red, x, y, z, nbar, w, bias;
    
        galaxy();
        
        galaxy(double ra, double dec, double red, cosmology &cosmo, double nbar = 1.0, double w = 1.0, 
               double bias = 1.0);
        
        galaxy(double x, double y, double z, double nbar = 1.0, double w = 1.0, double bias = 1.0);
        
        void init(double ra, double dec, double red, cosmology &cosmo, double nbar = 1.0, double w = 1.0, 
                  double bias = 1.0);
        
        void init(double x, double y, double z, double nbar = 1.0, double w = 1.0, double bias = 1.0);
};

#endif
