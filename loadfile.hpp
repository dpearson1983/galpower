#include <vector>
#include "structure.hpp"




class Loadfile {
    std::vector<double3> galaxies;
    public:
        void loadfile();
        void loadfile(std::string filename);
        int get_size();
        void binNGP(std::vector<double3> &galaxies, std::vector<double> &dr, int4 N = {512, 512, 512, 0}, double3 L = {1024.0, 1024.0, 1024.0});
        //void max_x
        //void max_y
        //void max_z
        
};
