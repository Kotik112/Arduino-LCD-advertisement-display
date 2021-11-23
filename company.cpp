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

void Company::printCompany() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Msg: " << message << std::endl;
    std::cout << "Bid: " << bid << std::endl;
}
