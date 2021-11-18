#include <iostream>
#include <fstream>
#include <string>

#include "serial.h"
#include "ad_manager.hpp"
#include "io_functions.hpp"

using namespace std;


void add_company_name(Company company) {

    cout << "Enter Company name: " << endl;
    cin >> company.name;

    if (std::cin.get() == '\n') {
            std::cout<<"ENTER WAS PRESSED"<<std::endl;
        }
    
}

void add_slogan(Company company) {

    cout << "Enter Slogan: " << endl;
    cin >> company.message;

    if (std::cin.get() == '\n') {
            std::cout<<"ENTER WAS PRESSED"<<std::endl;
        }

}

void add_bid(Company company) {

    cout << "Enter bid: " << endl;
    cin >> company.bid;

    if (std::cin.get() == '\n') {
            std::cout<<"ENTER WAS PRESSED"<<std::endl;
        }
}

void add_prints(Company company) {

for(int i = 0; i > company; i++) {
   cout << company.name << endl;
   cout << company.message << endl;
   cout << company.bid << endl;
}
}

