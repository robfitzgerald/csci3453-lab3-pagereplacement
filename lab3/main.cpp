

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include "vmManager.h"
#include "testDataUtility.h"
#include "readfile.h"


int main(int argc, const char * argv[]) {
    if (argc < 3) {
        std::cout << "usage: % lab3 num_frames input_file output_file\n";
        return 1;
    }
    
    std::vector<int> data = read_file(argv[2]);
    std::ofstream outFile;
    outFile.open(argv[3], std::ofstream::out | std::ofstream::app);
    
    int frames = atoi(argv[1]);
    
    outFile   << "==============================================================\n"
                << "  Page Replacement Algorithm Simulation (num frames = " << frames << ")\n"
                << "==============================================================\n"
                << "                                    Page fault ratio          \n"
                << "  Algorithm Total page faults 2000  4000  6000  8000  10000   \n"
                << "--------------------------------------------------------------\n";
    
    vmManager lru(frames, 2), optimal(frames, 1);
    lru.loadPages(data);
    lru.run();
    outFile << lru.results();
    optimal.loadPages(data);
    optimal.run();
    outFile << optimal.results();
    outFile.close();
    
    return 0;
}
