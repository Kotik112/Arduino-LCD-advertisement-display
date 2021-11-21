
#ifndef __AD_MANAGER_H__ 
#define __AD_MANAGER_H__

#include <iostream>
#include <vector>
#include "company.hpp"

#define MAX_TIME 60

using std::vector;
using std::string;

class AdManager {
    vector<Company> companyAds;
    vector<string> serialPorts;
    int fullAdTime;
    
    void calculateAdTime();

    public: 
    AdManager(vector<string> serialPorts);

    void addCompany(Company company);
    // void removeCompany(Company company);
    
    void sendAdsToSerial();
    void readFile();
    vector<string> splitString(string text, string delimiter);
    void print_string_vector();
};


#endif