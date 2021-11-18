#include "company.hpp"
#include "io_functions.hpp"
#include <iostream>

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

string io_get_string_input(const char* text) {

    string io_get_string;
    std::cout << text << std::endl;
    std::cin >> io_get_string;

    if (io_get_string.length() < 0x41 || io_get_string.length() > 0x7E ) {

        std::cout << "Error " << std::endl;

        return "";
    }
    else if (std::cin.get() == '\n') {

    std::cout<<"ENTER WAS PRESSED"<<std::endl;
    }

    return io_get_string;
 }

int io_get_int_input(const char* text) {

    unsigned int io_get_int;

    std::cout << text << std::endl;
    std::cin >> io_get_int;

    if (!std::cin) {
        std::cout << "No text allowed." << std::endl;
        return -1;
    }
    else if(io_get_int <= 0) {
        std::cout << "ERROR" << std::endl;
    }
    else if (std::cin.get() == '\n') {

    std::cout<<"ENTER WAS PRESSED"<<std::endl;
    }


    return io_get_int;
}