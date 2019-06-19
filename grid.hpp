#ifndef _GRID_HPP_
#define _GRID_HPP_

class grid{
    protected:
        int4 N;
        double4 L;
        std::vector<double> F;
    
    public:
        grid();
        
        grid(int4 N, double4 L);
        
        void init(int4 N, double4 L);
        
        double get(int i, int j, int k);
        
        int4 getSize();
        
        double4 getDimension();
        
        void rezeroGrid();
};

#endif
