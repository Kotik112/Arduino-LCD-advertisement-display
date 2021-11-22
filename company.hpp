#ifndef __COMPANY_H__
#define __COMPANY_H__


#include <string>
#include <fstream>


using std::string;

struct Company {
    string name;
    string message;
    int bid;
    string exposure;

    //Constructor
    Company(string name, string message, int bid);

    void set_exposure(string exposure);
    //Encodes a 'Company' object to a string
    string encodeToSerial();
    bool writeToFile();
    void printCompany();

};

#endif
