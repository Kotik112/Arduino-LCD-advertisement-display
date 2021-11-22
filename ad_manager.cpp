#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include "serial.h"
#include "company.hpp"
#include "ad_manager.hpp"

using namespace std;

AdManager::AdManager(vector<std::string> serialPorts): 
fullAdTime(MAX_TIME), 
serialPorts(serialPorts)
{}

void AdManager::calculateAdTime() {
    // Add up up all bids to a total
    int total_bids = 0;
    std::cout << "Calculating total time!\n";
    for (auto company: this->companyAds) {
        total_bids += company.bid;
        std::cout << "Current total: " << total_bids << std::endl;
    }
    std::cout << "Sum total bids: " << total_bids << std::endl;
    // Set exposure to be total secs * bid fraction
    float total = 0;
    for (auto company: this->companyAds) {
        std::cout << "Full ad time: " << fullAdTime << std::endl;
        std::cout << "Company bid: " << company.bid << ". Total bids: " << total_bids <<
        ". Turns into exposure of: " << ((float)company.bid / (float)total_bids) * (float)fullAdTime << std::endl;
        company.exposure = ((float)company.bid / (float)total_bids) * (float)fullAdTime;
        std::cout << "Company exposure: " << company.exposure << std::endl;
        total += company.exposure; 
    }
    std::cout << "Sum total expsure: " << total << std::endl;
}

void AdManager::addCompany(Company company) {
    this->companyAds.push_back(company);
    std::cout << "Added company to vector. \n";
}


void AdManager::sendAdsToSerial() {
    // Calculate time
    this->calculateAdTime();

    // In every serial port name
    for (auto serialName: this->serialPorts) {
        // Init the port
        auto port = SerialInit((char*)serialName.c_str());
        // Check if it's connected
        if(SerialIsConnected(port)) {
            std::cout << "Connected!\n";
            // Shuffle the ads
            //std::shuffle(companyAds.begin(), companyAds.end());

            // Write ad info to to port
            for (auto company: companyAds) {
                string message = company.encodeToSerial();
                std::cout << "Company exposure (inside sendToSerial): " << company.exposure << std::endl;
                std::cout << message << std::endl;
                SerialWritePort(port, (char*) message.c_str(), message.length());
            }
            SerialClose(port);
        }
        else {
            std::cerr << "Not connected.\n";
        }
    }


}

void AdManager::readFile() {
    // read file to stringsteam
    std::stringstream ss, ss2;
    std::ifstream fp ("ads.txt");
    if (fp.is_open()) {
        ss << fp.rdbuf();
        
    }
    fp.close();
    std::cout << this->companyAds.size() << "\n";
    string file_contents = ss.str();

    // split to lines
    auto lines = this->splitString(file_contents, "\n");

    // split to parts
    for (auto ad_text: lines) {
        auto ad_parts = splitString(ad_text, "|");
        string company_name = ad_parts[0];
        string message = ad_parts[1];
        //Allt detta för att få en sträng till int. Funkar ej.
        ss2 << ad_parts[2];
        string bid_string;
        ss2 >> bid_string;
        int bid = atoi(bid_string.c_str());
        auto new_company = Company(company_name, message, bid);
        addCompany(new_company);
    }

}


vector<string> AdManager::splitString(string text, string delimiter) {
    vector<string> parts;
    size_t start = 0;
    size_t end = 0;
    //std::cout << "looking for:" << delimiter << " in:" << text << std::endl;
    //std::cout << "Text is " << text.length()  << " long and delimiter is: " << delimiter.length() << " long." << std::endl;
    while((end = text.find(delimiter, start)) != std::string::npos) {
        //std::cout << "Positions are start: " << start << " end: "<< end << std::endl;
        //std::cout << "Found pos:" << end << std::endl;
        size_t length = end - start;
        parts.push_back(text.substr(start, length));
        start = end + delimiter.length();
        //std::cout << "Next start pos is: " << start << std::endl;
    }
    start = end + delimiter.length();
    size_t length = text.length() - start;
    parts.push_back(text.substr(start, length));

    return parts;
}

int AdManager::am_company_size() {
    int total = 0;
    for(auto company: companyAds) {
        total++;
    }
    return total;
}