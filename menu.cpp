#include <iostream>
#include <vector>

#include "company.hpp"
#include "serial.h"
#include "ad_manager.hpp"
#include "menu.hpp"


using namespace std;

Company get_company_input(void) {
    string name = io_get_string_input("Enter company name: ");
    string message = io_get_string_input("Enter company message: ");
    int bid = io_get_int_input("Enter your bid for the advertisement: ");

    Company new_company = Company(name, message, bid);
    return new_company;
}

string io_get_string_input(const char* text) {

    string io_get_string;
    cout << text << std::endl;
    cin >> io_get_string;

    if (io_get_string.length() < 1 || io_get_string.length() > 100 ) {
      cout << "Error " << std::endl;
      return "";
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

    return io_get_int;
}

int men_entry_choice(void) {

	int choice;
	std::cout << "\nchoose entry: ";
	std::cin >> choice;
	if (choice < SET || choice > EXT) {
		std::cout << "not an option. try again." << endl;
		return men_entry();
	}
	return choice;
}

int men_entry(AdManager am){

std::cout << "#############################" << endl;
std::cout << "####### MAIN MENU ###########" << endl;
std::cout << "#     SELECT OPTION BELOW   #" << endl;
std::cout << "#     1. ADD                #" << endl;
std::cout << "#     2. RUN ADS            #" << endl;
std::cout << "#     3. EXIT               #" << endl;
std::cout << "#############################" << endl;
    int staged = 0;
    while(1) {
        int choice = men_entry();
        switch(choice) {
            case SET:
                if (staged == 1) {
                    // ropar på company_input() func och tar emot den i company var.
                    auto company = get_company_input();
                    //ropar på addCompany metoden för att push_back company i vector<company>.
                    am.addCompany(company);
                    company.printCompany();
                    staged = 1;
                } else {
                    std::cout << "You've staged all companies" << endl;
                }
                break;
            case RUN:
                if (staged == 2) {
                    cout << "This is where we put function to run the shit" << endl;
                    std::cout << "RUNNING THE SHOW" << endl;
                    return 0;            
                } else {
                    std::cout << "Please declare messages and companies first" << endl;
                    break;                
                }
            case EXT:
                std::cout << "Good Bye" << endl;
                exit(0);
                return 0;
            default:
                std::cout << "Try again." << endl;                   
        }
    }
    return 0;


}


