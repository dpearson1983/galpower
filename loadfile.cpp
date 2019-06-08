#include <vector>
#include <iostream>
#include <fstream>

struct double3{
    double x,y,z;
};

std::vector<double3> loadfile(std::string filename) {

    std::vector<double3> galaxies;
    //std::cout << "Enter the filename : \n";
    //std::cin >> filename;
    
    //std::ifstream fin("LNKNLogsVelFortran_01.dat");
    std::ifstream fin(filename);
    std::string dummyLine;
    std::getline(fin, dummyLine);
    while (!fin.eof()) {
        double3 gal;
        fin >> gal.x >> gal.y >> gal.z;
        if (!fin.eof()) {
            galaxies.push_back(gal);
        }
    }
    fin.close();
    //std::cout << "galaxies.size() = " << galaxies.size() << std::endl;
    
    return galaxies;
}

//void binNGP(std::vector <double3> &galaxies, std::vector )

