#ifndef __COMPANY_H__
#define __COMPANY_H__


#include <string>
#include <fstream>


using std::string;

struct Company {
    string name;
    string message;
    int bid;
    int exposure;

    //Constructor
    Company(string name, string message, int bid);
    Company(const Company& other);
    ~Company();
    void set_exposure(int exposure);
    //Encodes a 'Company' object to a string
    string encodeToSerial();
    bool writeToFile();
    void printCompany();

};

#endif
