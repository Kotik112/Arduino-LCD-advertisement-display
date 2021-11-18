#include "company.hpp"

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
