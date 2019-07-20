#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cmath>
#include<fftw3.h>
#include<complex>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

overden::overden(int4 N,double4 L) {
	overden::init(N,L);
}

void overden::init(int4 N,double4 L) {

	this->N = N;
	this->L = L;

}

overden::overden(int4 N,double4 L,numden &n_g, numden &n_r) {
	overden::init(N,L,n_g,n_r);
}

void overden::init(int4 N,double4 L,numden &n_g, numden &n_r) {

	this->N = N;
	this->L = L;

	overden::numden(n_g);
	overden::numden(n_r);

}

void overden::transform() {

	N.w=N.x*N.y*N.z;
	int dk_size= N.x * N.y * (N.z/2+1);

	std::vector<double> data(N.w)= n_g - (alpha * n_r) ;
	std::vector<fftw_complex> dk(dk_size);

	dr2dk=fftw_plan_dft_r2c_3d(N.x,N.y,N.z,data.data(),dk.data(),FFTW_MEASURE);

}

double getFrequencies(int n, double l) {
    
//Generate the frequencies(or wavenumbers) of a real FFT along any dimension given the window length(n) and sample spacing(l) 
    
    double val=1/(n*l);
    int N = n/2 + 1;
    std::vector<double> freq;
    
    for(int i=0; i < N;i++)
            freq[i]= i/val;
    
}












