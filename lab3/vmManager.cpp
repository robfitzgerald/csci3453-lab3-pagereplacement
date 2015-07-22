//
//  vmManager.cpp
//  lab3
//
//  Created by Robert Fitzgerald on 7/21/15.
//  Copyright (c) 2015 Rob Fitzgerald. All rights reserved.
//

#include "vmManager.h"

void vmManager::run() {
    for (time = 0; time < pages.size(); ++time) {
        access();
    }
}

void vmManager::access() {
    bool pageReplacement = false;
    frame incomingPageRequest = pages[time];
    
    // if incoming is already in there
    
    if (pageReplacement) {
        switch(algorithm) {
            case 1:
                // do optimal stuff
                break;
            case 2:
                // do LRU stuff
                break;
        }
    }
}

