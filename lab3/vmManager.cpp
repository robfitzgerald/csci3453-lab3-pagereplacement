

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
    std::cout << "time " << time << std::endl;
    std::cout << "incoming " << incomingPageRequest << std::endl;
    bool memoryResident = searchTable(incomingPageRequest);
    if (memoryResident) {
        std::cout << "memory resident\n";
        setLastAccessed(incomingPageRequest);
        debugTable();
    } else if (pagesTable.size() < numberOfFrames) {
        std::cout << "page fault without replacement\n";
        pagesTable.push_front(incomingPageRequest);
        ++pageFaultCount;
        debugTable();
    } else {

        std::cout << "page replacement: \n";

        // page replacement
        switch(algorithm) {
            case 1: {
                std::list<int>::iterator longestPage = pagesTable.end();
                int longestDistance = 0;
                bool findingNextOccurence = true;
                bool findingLongestPageDistance = true;
                for (std::list<int>::iterator i = pagesTable.begin(); ((findingLongestPageDistance && (i != pagesTable.end()))); ++i) {
                    bool nextOccurenceExists = false;
                    findingNextOccurence = true;
                    for (int j = time; (findingNextOccurence && (j < pages.size())); ++j) {
                        std::cout << "checking for " << *i << " at pages[" << j << "] and found " << pages[j] << std::endl;
                        if (*i == pages[j]) {
                            findingNextOccurence = false;
                            nextOccurenceExists = true;
                            int distance = j - time;
                            if (distance > longestDistance) {
                                longestDistance = distance;
                                longestPage = i;
                                std::cout << pages[j] << "==" << *i << ", distance > longestDistance " << distance << " > " << longestDistance << std::endl;
                            }
                        }
                    }
                    if (!nextOccurenceExists) {
                        // didn't find it.  it doesn't occur again, so it
                        // can be removed.  longestDistance comparison is irrelevant.
                        // therefore the first page to have no reoccurence is removed.2
                        // short circuit the list.foreach() process
                        longestPage = i;
                        //i = pagesTable.end();
                        std::cout << *i << " not found." << std::endl;
                        findingLongestPageDistance = false;
                    }
                }
                
                // optimal
//                std::list<int>::iterator longestPage = pagesTable.end();
//                int longestDistance = 0;
//                for (std::list<int>::iterator i = pagesTable.begin(); i != pagesTable.end(); ++i) {
//                    bool pageIsRequestedAgain = false;
//                    for (int j = time; j < pages.size(); ++j) {
//                       if (pages[j] == *i) {
//                           if ((j - time) > longestDistance) {
//                               std::cout << pages[j] << "==" << *i << ", (j-time) > longestDistance " << (j - time) << " > " << longestDistance << std::endl;
//                               std::cout << "j is " << j << " and time is " << time << std::endl;
//                               longestPage = i;
//                               longestDistance = j - time;
//                               pageIsRequestedAgain = true;
//                           }
//                           j = (int) pages.size();  // basically, 'continue;' out of for(j) loop
//                        }
//                    }
//                    // if it doesn't get requested again, make it the longest.  tie is broken
//                    // by page being the first not requested page in the ref string
//                    if (!pageIsRequestedAgain && (longestDistance < (int) pages.size())) {
//                        std::cout << *i << " is not referenced again" << std::endl;
//                        longestPage = i;
//                        longestDistance = (int) pages.size();
//                    }
//                    
//                }
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
        debugTable();
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
