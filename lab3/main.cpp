

#include <iostream>
#include <vector>
#include "vmManager.h"
#include "testDataUtility.h"

int main(int argc, const char * argv[]) {
//    TEST 1: using Silberschatz Data
//    std::vector<int> refString;
//    int refStringSrc [20] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
//    for (int i = 0; i < 20; ++i) {
//        refString.push_back(refStringSrc[i]);
//    }
//    vmManager vmManager(3, 1);
//    vmManager.loadPages(refString);
    
//    TEST 2: using random generator
    vmManager vmManager(64, 2);
    vmManager.loadPages(generateRandom(10000, 512, true));
    vmManager.run();
    vmManager.results();
    
    return 0;
}
