#include "company.hpp"
#include <iostream>

//Constructor
Company::Company(string name, string message, string bid):
    name(name), 
    message(message), 
    bid(bid)
    {} 


// Encodes the struct variables with '|' delimiter.
string Company::encodeToSerial() {
    return name + "|" + message + "|" + bid + "|";
}


bool Company::writeToFile()
  {
    std::ofstream outputFile;
    outputFile.open("ads.txt", std::ios::app);
    if (outputFile.is_open()) {
      std::cout << "OPENED FILE\n";
      outputFile << name << "|" << message << "|" << bid<< "|" << std::endl;
      outputFile.close();
      return true;
    }
    else {
      std::cerr << "Could not open file to save \n";
      return false;
    }
  }

  void Company::printCompany() {
      std::cout << "Name: " << name << std::endl;
      std::cout << "Msg: " << message << std::endl;
      std::cout << "Bid: " << bid << std::endl;
  }
