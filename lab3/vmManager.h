// vmManager
// class which encapsulates a virtual memory management simulation


#ifndef __lab3__vmManager__
#define __lab3__vmManager__

#include <stdio.h>
#include <vector>
#include <stack>
#include <deque>
#include <list>

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
    
    void debugTable();
public:
    vmManager(int s, int a): numberOfFrames(s), algorithm(a) { time = 0; pageFaultCount = 0; }
    void loadPages(std::vector<int>);
    void run();
    void results();
    
};

#endif /* defined(__lab3__vmManager__) */
