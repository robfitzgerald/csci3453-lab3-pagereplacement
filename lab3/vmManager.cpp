

#include "vmManager.h"
#include <iostream>

void vmManager::loadPages(std::vector<int> load) {
    pages = load;
}

void vmManager::run() {
    for (time = 0; time < pages.size(); ++time) {
        access();
    }
}

void vmManager::results() {
    std::cout << "page faults: " << pageFaultCount << std::endl;
}

void vmManager::access() {
    int incomingPageRequest = pages[time];
    
    bool memoryResident = searchTable(incomingPageRequest);
    if (memoryResident) {
        setLastAccessed(incomingPageRequest);
    } else if (pagesTable.size() < numberOfFrames) {
        pagesTable.push_front(incomingPageRequest);
        ++pageFaultCount;
    } else {
        std::cout << "page replacement: \n";
        for (std::list<int>::iterator i = pagesTable.begin(); i != pagesTable.end(); ++i)
            std::cout << *i << " ";
        std::cout << "\n~~at time: " << time << std::endl;
        // page replacement
        switch(algorithm) {
            case 1:
                // optimal
                // for (std::list<int>::iterator i = pagesTable.begin(); i != pagesTable.end(); ++i)
                //   for (int j = time; j < pages.size(); ++j)
                //     if (pages[j] == *i)
                //
                break;
            case 2:
                // LRU
                pagesTable.pop_back();
                pagesTable.push_front(incomingPageRequest);
                ++pageFaultCount;
                break;
        }
    }
}

bool vmManager::searchTable(int page) {
    for (std::list<int>::iterator i = pagesTable.begin(); i != pagesTable.end(); ++i)
        if (*i==page)
            return true;
    return false;
}

void vmManager::setLastAccessed(int page) {
    if (algorithm==2) {
        pagesTable.remove(page);
        pagesTable.push_front(page);
    }
}

