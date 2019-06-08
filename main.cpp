#include <iostream>
#include <vector>
#include "loadfile.hpp"


int main(){
    std::string filename;
    std::vector<double3> galaxies;
    filename = "LNKNLogsVelFortran_01.dat";
    galaxies = loadfile(filename);
    std::cout << "size = "<< galaxies.size()<<" " << galaxies[0].y << std::endl;
}
