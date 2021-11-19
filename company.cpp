#include "company.hpp"
#include <iostream>

using std::cout;
using std::cin;

//Constructor
Company::Company(string name, string message, int bid): 
    name(name), 
    message(message), 
    bid(bid), 
    exposure(0) {} 

string Company::encodeToSerial() {
/*     int name_len = name.length();
    int message_len = message.length(); */
    return this->name + "|" + this->message + "|" + std::to_string(this->exposure) + "|";
}

bool Company::writeToFile() {
    std::ofstream outputFile;
    outputFile.open("ads.txt", std::ios::app);
    if (outputFile.is_open()) {
      cout << "OPENED FILE\n";
      outputFile << this->name << "|" << this->message << "|" << this->bid<< "|" << std::endl;
      outputFile.close();
      return true;
    }
    else {
      std::cerr << "Could not open file to save \n";
      return false;
    }
  }

  void Company::printCompany() {
      cout << "Name: " << this->name << std::endl;
      cout << "Message: " << this->message << std::endl;
      cout << "Bid: " << this->bid << std::endl;
  }

