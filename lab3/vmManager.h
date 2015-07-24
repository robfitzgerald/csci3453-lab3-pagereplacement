// vmManager
// class which encapsulates a virtual memory management simulation.
// one replacement algorithm, a simulated page table with a user-specified number of frames,
// and a given set of page requests are the test data.

// public
/*
 
 constructor vmManager::vmManager(int s, int a)
    instantiates a vmManager object with a given number of frames (s) and using an algorithm (a)
    where
        a=1 => run with Optimal Page Replacement Algorithm
        a=2 => run with LRU Page Replacement Algorithm
 
 ƒ void loadPages(vector<int>)
    post: pages as a vector of ints are copied from the function argument to the class property pages
 
 ƒ void run()
    pre:  vmManager is instantiated, pages are loaded
    post: entire simulation has run
 
 ƒ string results()
    pre:  vmManager is instantiated
    post: vmManager metadata and results, if any, are returned as a string
 
 */

#ifndef __lab3__vmManager__
#define __lab3__vmManager__

#include <stdio.h>
#include <vector>
#include <stack>
#include <deque>
#include <list>
#include <string>

class vmManager {
private:
    std::list<int> pagesTable;
    std::vector<int> pages;
    int time;
    int numberOfFrames;
    int algorithm;
    
    void access();
    bool searchTable(int);
    void setLastAccessed(int);

    int pageFaultCount;
    std::vector<float> faultRatios;
    
    void debugTable();
public:
    vmManager(int s, int a): numberOfFrames(s), algorithm(a) { time = 0; pageFaultCount = 0; }
    void loadPages(std::vector<int>);
    void run();
    std::string results();
    
};

#endif /* defined(__lab3__vmManager__) */
