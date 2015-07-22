//
//  readfile.h
//  csci3412_pa1
//
//  Created by Robert Fitzgerald on 2/4/15.
//
//

#ifndef __csci3412_pa1__readfile__
#define __csci3412_pa1__readfile__

#include <vector>
#include <string>

// ƒ read_file(A,p,r)
//
// precondition:  file has one integer per line
// postcondition: returns a vector made of the integers stored in the file
//

std::vector<int> read_file(const char*);
std::vector<int> parse_line(std::string);

#endif /* defined(__csci3412_pa1__readfile__) */
