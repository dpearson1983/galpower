#include <iostream>
#include <vector>
#include "grid.hpp"

int main(){
    std::string filename = "LNKNLogsVelFortran_01.dat";
    grid newfile;
    
    newfile.load(filename);
    
//     std::cout << "size = "<< newfile.get_size()<<" " << std::endl;
   
}


