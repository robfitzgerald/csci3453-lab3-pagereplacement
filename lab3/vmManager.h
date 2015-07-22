// vmManager
// class which encapsulates a virtual memory management simulation


#ifndef __lab3__vmManager__
#define __lab3__vmManager__

#include <stdio.h>
#include <vector>
#include <stack>

class vmManager {
private:
    struct frame {
        int pid;
        int lastAccess;
    };
    std::stack<frame> pagesLRU;
    std::vector<frame> pages, pagesOptimal;
    int time;
    int numberOfFrames;
    int algorithm;
    
    void access();
    //void incrementTime() { ++time; }
    
public:
    vmManager(int s, int a): numberOfFrames(s), algorithm(a) { time = 0; }
    void loadPages(std::vector<int>);
    void run();
    void results();
};

#endif /* defined(__lab3__vmManager__) */
