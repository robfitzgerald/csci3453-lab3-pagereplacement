//
//  readfile.cpp
//  csci3412_pa1
//
//  Created by Robert Fitzgerald on 2/4/15.
//
//

#include "readfile.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> read_file(const char* fileName)
{
    std::vector<int> result;
    std::ifstream file;
    file.open(fileName);
    
    // return empty array if file is bad
    if (!file.good())
        return result;
    
    std::string line;
    
    // get data
    while (getline(file,line))
    {
        std::vector<int> p = parse_line(line);
        result.push_back(p[0]);
        line.clear();
    }
    
    return result;
}

std::vector<int> parse_line(std::string line) {
    std::stringstream stream(line);
    std::vector<int> result;
    int n;
    while(stream >> n) {
        result.push_back(n);
    }
    return result;
}

