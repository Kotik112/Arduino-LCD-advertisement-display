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
    Company(string name, string message, int bid, string exposure);

    void set_exposure(float exposure);
    //Encodes a 'Company' object to a string
    string encodeToSerial();
    bool writeToFile();
    void printCompany();

};

string io_get_string_input(const char* text);
int io_get_int_input(const char* text);
Company get_company_input(void);


#endif
