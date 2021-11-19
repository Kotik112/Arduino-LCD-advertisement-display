#include <iostream>
#include <vector>

#include "company.hpp"
#include "serial.h"
#include "ad_manager.hpp"
#include "menu.hpp"


using namespace std;


int men_entry_choice(void) {

	int choice;
	std::cout << "Choose entry: ";
	std::cin >> choice;
	if (choice < SET || choice > EXT) {
		std::cout << "not an option. try again." << endl;
		return men_entry();
	}
	return choice;
}

int men_entry(void){

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
                    get_company_input();
                    Company addCompany();
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


