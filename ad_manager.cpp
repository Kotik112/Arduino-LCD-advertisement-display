
#include <algorithm>
#include <fstream>
#include <sstream>
#include "serial.h"
#include "ad_manager.hpp"

AdManager::AdManager(vector<std::string> serialPorts): 
fullAdTime(MAX_TIME), 
serialPorts(serialPorts)
{}

void AdManager::calculateAdTime() {
    // Add up up all bids to a total
    float totalTime = 0;

    for (auto company: this->companyAds) {
        totalTime += company.bid;
    }

    // Set exposure to be total secs * bid fraction
    for (auto company: this->companyAds) {
        company.exposure = (company.bid / totalTime) * fullAdTime;
    }
}

void AdManager::addCompany(Company company) {
    this->companyAds.push_back(company);
}

// void AdManager::removeCompany(Company company) {
//     auto index = std::find(this->companyAds.begin(), this->companyAds.end(), company);
//     if (index != this->companyAds.end()) {
//         this->companyAds.erase(index);
//     }
// }

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
            //std::random_shuffle(this->companyAds.begin(), this->companyAds.end());

            // Write ad info to to port
            for (auto company: this->companyAds) {
                string message = company.encodeToSerial();
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
    std::stringstream ss;
    std::ifstream fp ("ads.txt");
    if (fp.is_open()) {
        ss << fp.rdbuf();
    }
    fp.close();
    string file_contents = ss.str();

    // split to lines
    auto lines = this->splitString(file_contents, "\n");

    // split to parts
    for (auto ad_text: lines) {
        auto ad_parts = this->splitString(ad_text, "|");
    }
}

vector<string> AdManager::splitString(string text, string delimiter) {
    vector<string> parts;
    size_t start = 0;
    size_t end = 0;
    // std::cout << "looking for:" << delimiter << " in:" << text << std::endl;
    //std::cout << "Text is " << text.length()  << " long and delimiter is: " << delimiter.length() << " long." << std::endl;
    while((end = text.find(delimiter, start)) != std::string::npos) {
        //std::cout << "Positions are start: " << start << " end: "<< end << std::endl;
        // std::cout << "Found pos:" << end << std::endl;
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

void AdManager::print_string_vector() {
    for (auto company: this->companyAds) {
        std::cout << "TEST1\n";
        company.printCompany();
    }
}
