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

void AdManager::addCompany(Company company) {
    this->companyAds.push_back(company);
}

void AdManager::am_send_ad_to_serial() {
    // In every serial port name
    for (auto serialName: serialPorts) {
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


void AdManager::am_read_file(const char* text) {
    // read file to stringsteam
    std::stringstream ss, ss2;
    std::ifstream fp (text);
    if (fp.is_open()) {
        ss << fp.rdbuf();
        
    }
    fp.close();
    std::cout << companyAds.size() << "\n";
    string file_contents = ss.str();

    // split to lines
    auto lines = splitString(file_contents, "\n");

    // split to parts
    for (auto ad_text: lines) {
        auto ad_parts = splitString(ad_text, "|");
        string company_name = ad_parts[0];
        string message = ad_parts[1];
        string bid = ad_parts[2];
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

void AdManager::am_save_file(const char* text) {
    for(auto company: companyAds) {
        std::ofstream outputFile;
        outputFile.open(text, std::ios::app);
        if (outputFile.is_open()) {
            std::cout << "OPENED FILE\n";
            outputFile << company.name << "|" << company.message << "|" << company.bid<< "|" << std::endl;
            outputFile.close();
        }
        else {
            std::cerr << "Could not open file to save \n";
        }
    }
}

int AdManager::am_company_size() {
    int total = 0;
    for(auto company: companyAds) {
        total++;
    }
    return total;
}