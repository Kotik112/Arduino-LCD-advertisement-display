
#ifndef AD_MANAGER 
#define AD_MANAGER

#include <iostream>
#include <vector>
#include "company.hpp"

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

};






#endif