

#include <iostream>
#include <vector>
#include "vmManager.h"
#include "testDataUtility.h"
#include "readfile.h"

int main(int argc, const char * argv[]) {
//    TEST 1: using Silberschatz Data
//    std::vector<int> refString;
//    int refStringSrc [20] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
//    for (int i = 0; i < 20; ++i) {
//        refString.push_back(refStringSrc[i]);
//    }
//    vmManager vmManager(3, 1);
//    vmManager.loadPages(refString);
//    vmManager.run();
//    vmManager.results();
    
//    TEST 2: using random generator
//    lru.loadPages(generateRandom(10000, 512, true));
//    lru.run();
//    lru.results();
//    optimal.loadPages(generateRandom(10000, 512, true));
//    optimal.run();
//    optimal.results();
    
    std::vector<int> data = read_file("testData.txt");
    
    int frames = 64;
    std::cout   << "==============================================================\n"
                << "  Page Replacement Algorithm Simulation (num frames = " << frames << ")\n"
                << "==============================================================\n"
                << "                                    Page fault ratio          \n"
                << "  Algorithm Total page faults 2000  4000  6000  8000  10000   \n"
                << "--------------------------------------------------------------\n";
    vmManager lru(frames, 2), optimal(frames, 1);
    lru.loadPages(data);
    lru.run();
    lru.results();
    optimal.loadPages(data);
    optimal.run();
    optimal.results();
    
    return 0;
}
