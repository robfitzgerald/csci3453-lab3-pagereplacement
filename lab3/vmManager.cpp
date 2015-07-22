

#include "vmManager.h"
#include <iostream>
#include <iomanip>
#include <string>

void vmManager::loadPages(std::vector<int> load) {
    pages = load;
}

void vmManager::run() {
    for (time = 0; time < pages.size(); ++time) {
        access();
        if ((time>0)&&(((time+1)%2000) == 0)) {
            faultRatios.push_back((float) pageFaultCount / (float) time);
        }
    }
}

void vmManager::results() {
    std::string algorithmName;
    switch (algorithm) {
        case 1:
            algorithmName = "Optimal";
            break;
        case 2:
            algorithmName = "LRU";
            break;
    }
    std::cout   << "  " << std::left << std::setprecision(3) << std::fixed
                << std::setw(14) << algorithmName
                << std::setw(14) << pageFaultCount;
    for (int i = 0; i < faultRatios.size(); ++i) {
        std::cout << faultRatios[i] << " ";
    }
    std::cout << std::endl;
}

void vmManager::access() {
    int incomingPageRequest = pages[time];
    bool memoryResident = searchTable(incomingPageRequest);
    if (memoryResident) {
        setLastAccessed(incomingPageRequest);
        //debugTable();
    } else if (pagesTable.size() < numberOfFrames) {
        pagesTable.push_front(incomingPageRequest);
        ++pageFaultCount;
        //debugTable();
    } else {
        // page replacement
        switch(algorithm) {
            case 1: {
                // OPTIMAL
                std::list<int>::iterator longestPage = pagesTable.end();
                int longestDistance = 0;
                bool findingNextOccurence = true;
                bool findingLongestPageDistance = true;
                
                for (std::list<int>::iterator i = pagesTable.begin(); ((findingLongestPageDistance && (i != pagesTable.end()))); ++i) {
                    bool nextOccurenceExists = false;
                    findingNextOccurence = true;
                    
                    for (int j = time; (findingNextOccurence && (j < pages.size())); ++j) {
                        if (*i == pages[j]) {
                            findingNextOccurence = false;
                            nextOccurenceExists = true;
                            int distance = j - time;
                            if (distance > longestDistance) {
                                longestDistance = distance;
                                longestPage = i;
                            }
                        }
                    }
                    if (!nextOccurenceExists) {
                        // didn't find it.  it doesn't occur again, so it can be removed.
                        longestPage = i;
                        findingLongestPageDistance = false;
                    }
                }
                pagesTable.erase(longestPage);
                break;
            }
            case 2: {
                // LRU
                pagesTable.pop_back();
                break;
            }
        }
        pagesTable.push_front(incomingPageRequest);
        ++pageFaultCount;
        //debugTable();
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

void vmManager::debugTable() {
    std::cout << "{ ";
    for (std::list<int>::iterator i = pagesTable.begin(); i != pagesTable.end(); ++i)
        std::cout << *i << " ";
    std::cout << "}\n";
    std::cout << "page faults: " << pageFaultCount << std::endl << std::endl;
}
