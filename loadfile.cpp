#include <vector>
#include <iostream>
#include <fstream>



int main() {
    struct double3{
        double x,y,z;
    };
    std::vector<double3> galaxies;
    std::ifstream fin("LNKNLogsVelFortran_01.dat");
    while (!fin.eof()) {
        double3 gal;
        fin >> gal.x >> gal.y >> gal.z;
        if (!fin.eof()) {
            galaxies.push_back(gal);
        }
    }
    fin.close();
    std::cout << "galaxies.size() = " << galaxies.size() << std::endl;
    
}
