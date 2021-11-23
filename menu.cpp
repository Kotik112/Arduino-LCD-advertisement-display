#include <iostream>
#include <vector>
#include <sstream>
#include <ios> 
#include <limits>

#include "company.hpp"
#include "serial.h"
#include "ad_manager.hpp"
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

static bool inp_check(char ch) {
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
	return (ch >= 0x20 && ch <= 0x7a || ch == 0x0 || ch == 0x4);
}

static bool int_check(char ch) {
	return ch >= '0' && ch <= '9';
}

static string cmp_add_name(void) {

    string name;
	cout << "add company name: ";
    cin >> name;
	for (int i = 0; i < name.length(); i++) {
		if(!inp_check(name) {
			cout << "you've entered an invalid character. try again" << endl;
			return cmp_add_name();
		} else if (name.length() > MAX_CMP_NAME){
			cout << "max 20 characters. try again" << endl;
			return cmp_add_name();
		}
	}
}

static string cmp_add_message(void) {

    string message;
	cout << "add company message: ";
    cin >> message;
	for (int i = 0; i < message.length(); i++) {
		if(!inp_check(message) {
			cout << "you've entered an invalid character. try again" << endl;
			return cmp_add_message();
		} else if (message.length() > MAX_CMP_NAME){
			cout << "max 100 characters. try again" << endl;
			return cmp_add_message();
		}
	}
    return message
}

static string cmp_add_bid(void) {
    string bid;
	cout << "add a bid: ";
    cin >> bid;
	for (int i = 0; i < bid.length(); i++) {
		if (!int_check(bid)) {
			cout << "not an integer, try again. try again" << endl;
			return cmp_add_name();
		} else if (bid.length() > MAX_CMP_NAME){
			cout << "number to large. try again" << endl;
			return cmp_add_name();
		}
	}
    return bid;
}

Company get_company_input(void) {
 
    string name = cmp_add_name();
    string message = cmp_add_message();
    string bid = cmp_add_bid();

    Company new_company = Company(name, message, bid);
    return new_company;
}

int men_entry_choice(const char* text) {

	int choice, temp;
	cout << text;
	cin >> temp;

    //adjust the -1 offset from enum.
    temp--; 

	if (temp < ADD || temp > EXT) {
		cout << "not an option. try again." << endl;
		return -1;
	}
    else {
        choice = temp;
        return choice;
    }
	return -1;
}

void men_flush_file() {
    std::ofstream ofs;
    ofs.open("ads.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

void men_print_menu(void) {
    cout << "#############################" << endl;
    cout << "######### MAIN MENU #########" << endl;
    cout << "#                           #" << endl;
    cout << "#    SELECT OPTION BELOW    #" << endl;
    cout << "#   1. Add Adversistment    #" << endl;
    cout << "#   2. Export Ads to Ardu   #" << endl;
    cout << "#   3. Flush file           #" << endl;
    cout << "#   4. Exit                 #" << endl;
    cout << "#                           #" << endl;
    cout << "#############################" << endl << endl;
}

int men_entry(AdManager am) {

    

    int choice = -1; //-1 så att den inte hoppar in i switchen.

    if (choice == -1) { std::cerr << "mem_get_int_input() failed!\n"; }

    int ad_count = 0;
    bool stay_in_loop = true;
    

    while(stay_in_loop) {

        if (ad_count >= 5) { choice = RUN; }

        men_print_menu();
        choice = men_get_int_input("Enter your choice (1 - 3)");
        choice--;

        switch(choice) 
        {
            case ADD:   //Add new company to the company vector.
                
                if (ad_count >= 5) {
                    std::cout << "Maximum 5 number of Ads per 60 sec slot.\n";
                    break;
                }

                else {

                    auto company = get_company_input();
                    company.printCompany(); //Kommentera bort det här sen.
                    company.writeToFile();
                    am.am_add_company(company);
                    ad_count++;
                }
                break;

            case RUN: //Send company vector to Serial COM

                am.sendAdsToSerial();    
                break;

            case DEL:  //Flushes ads.txt
                read_file();
                //men_flush_file();
                break;

            case EXT:  //Exit program.

                std::cout << "Good Bye" << endl;
                stay_in_loop = false;
                return 0;

            default:
                std::cout << "Try again." << endl;                   
        }
    }
    return 0;


}