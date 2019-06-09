#include <vector>


struct double3 {
    double x,y,z;
};



class Loadfile {
    std::vector<double3> galaxies;
    public:
        void loadfile();
        void loadfile(std::string filename);
        int get_size();
        //void max_x
        //void max_y
        //void max_z
        
};
