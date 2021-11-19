#include "company.hpp"
#include <iostream>

using std::cout;
using std::cin;

//Constructor
Company::Company(string name, string message, int bid): 
    name(name), 
    message(message), 
    bid(bid), 
    exposure(0) 
    {} 

string Company::encodeToSerial() {
    int name_len = name.length();
    int message_len = message.length();
    return this->name + "|" + this->message + "|" + std::to_string(this->exposure) + "|";
}

bool Company::writeToFile()
  {
    std::ofstream outputFile;
    outputFile.open("ads.txt", std::ios::app);
    if (outputFile.is_open()) {
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
      cout << "Msg: " << this->message << std::endl;
      cout << "Bid: " << this->bid << std::endl;
  }

string io_get_string_input(const char* text) {

    string io_get_string;
    cout << text << std::endl;
    cin >> io_get_string;

    if (io_get_string.length() < 60 || io_get_string.length() > 126 ) {
      cout << "Error " << std::endl;
      return "";
    }

    else if (cin.get() == '\n') {
      cout<<"ENTER WAS PRESSED"<<std::endl;
    }
    
    return io_get_string;
}

int io_get_int_input(const char* text) {
    unsigned int io_get_int;

    cout << text << std::endl;
    cin >> io_get_int;

    if (!cin) {
      cout << "No text allowed." << std::endl;
      return -1;
    }
    else if(io_get_int <= 0) {
      cout << "ERROR" << std::endl;
    }
    else if (cin.get() == '\n') {
      cout << "ENTER WAS PRESSED" << std::endl;
    }
    return io_get_int;
}