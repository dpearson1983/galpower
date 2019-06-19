#ifndef _FILE_READER_HPP_
#define _FILE_READER_HPP_

#include <string>
#include <vector>
#include "structure.hpp"

enum class fileType{
    patchy,
    DR12,
    lognormal
};

class fileReader {
    fileType fType;
    
    std::vector<double3> loadPatchy(std::string file);
    
    std::vector<double3> loadDR12(std::string file);
    
    std::vector<double3> loadLognormal(std::string file);
    
    public:
        fileReader();
        
        fileReader(fileType fType);
        
        void init(fileType fType);
        
        void setFileType(fileType fType);
        
        std::vector<double3> loadfile(std::string file);
        
};
