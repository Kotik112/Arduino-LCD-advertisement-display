#ifndef __COMPANY_H__
#define __COMPANY_H__


#include <string>
#include <fstream>


using std::string;

struct Company {
    string name;
    string message;
    string bid;

    //Constructor
    Company(string name, string message, string bid);

    //Encodes a 'Company' struct to a string
    string encodeToSerial();
    bool writeToFile();
    void printCompany();
};

#endif
