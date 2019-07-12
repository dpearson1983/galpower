#include <iostream>
#include <cmath>
#include "../include/cosmology.hpp"
#include "../include/galaxy.hpp"

galaxy::galaxy() {
    this->ra = 0.0;
    this->dec = 0.0;
    this->red = 0.0;
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
    this->nbar = 0.0;
    this->w = 0.0;
    this->bias = 0.0;
}

galaxy::galaxy(double ra, double dec, double red, cosmology &cosmo, double nbar, double w, double bias) {
    galaxy::init(ra, dec, red, cosmo, nbar, w, bias);
}

galaxy::galaxy(double x, double y, double z, double nbar, double w, double bias) {
    galaxy::init(x, y, z, nbar, w, bias);
}

void galaxy::init(double ra, double dec, double red, cosmology &cosmo, double nbar, double w, double bias) {
    this->ra = ra;
    this->dec = dec;
    this->red = red;
    this->nbar = nbar;
    this->w = w;
    this->bias = bias;
    
    double D = cosmo.comoving_distance(red);
    this->x = D*std::cos(dec*M_PI/180.0)*std::cos(ra*M_PI/180.0);
    this->y = D*std::cos(dec*M_PI/180.0)*std::sin(ra*M_PI/180.0);
    this->z = D*std::sin(dec*M_PI/180.0);
}

void galaxy::init(double x, double y, double z, double nbar, double w, double bias) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->nbar = nbar;
    this->w = w;
    this->bias = bias;
}
