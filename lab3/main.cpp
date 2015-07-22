

#include <iostream>
#include <vector>
#include "vmManager.h"

int main(int argc, const char * argv[]) {
    std::vector<int> refString;
    int refStringSrc [22] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    for (int i = 0; i < 22; ++i) {
        refString.push_back(refStringSrc[i]);
    }
    vmManager vmManager(3, 1);
    vmManager.loadPages(refString);
    vmManager.run();
    vmManager.results();
    
    return 0;
}
