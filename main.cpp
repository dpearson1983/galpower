#include <iostream>
#include <vector>
#include "loadfile.hpp"

int main(){
    std::string filename = "LNKNLogsVelFortran_01.dat";
    Loadfile newfile;
    
    newfile.loadfile(filename);
    
    std::cout << "size = "<< newfile.get_size()<<" " << std::endl;
}


