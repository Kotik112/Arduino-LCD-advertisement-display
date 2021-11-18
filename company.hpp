#ifndef __COMPANY_H__
#define __COMPANY_H__

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

struct Company {
    string name;
    string message;
    int bid;
    float exposure;

    //Constructor
    Company(string name, string message, int bid);

    //Encodes a 'Company' object to a string
    string encodeToSerial();
};

#endif
