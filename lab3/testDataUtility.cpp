//
//  testDataUtility.cpp
//  lab3
//
//  Created by Robert Fitzgerald on 7/22/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

#include "testDataUtility.h"
#include <cmath>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <stdio.h>

std::vector<int> generateRandom(int pages, int range, bool trueRandom) {
    std::vector<int> pageList;
    if (trueRandom) {
        srand((unsigned int) time(NULL));
    } else {
        srand(1);
    }
    for (int i = 0; i < pages; ++i) {
        int page = (rand() % range);
        pageList.push_back(page);
    }
    
    return pageList;
}

std::string formattedGenerator(int p, int r, bool t) {
    std::string output;
    std::vector<int> pages = generateRandom(p, r, t);
    for (int i = 0; i < pages.size(); ++i) {
        char line [20];
        sprintf(line, "%d\n", pages[i]);
        output += line;
    }
    
    return output;
}