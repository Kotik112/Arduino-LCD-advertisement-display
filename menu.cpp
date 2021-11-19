#include <iostream>
#include <vector>

#include "company.hpp"
#include "serial.h"
#include "ad_manager.hpp"
#include "menu.hpp"


using std::cout;
using std::cin;
using std::endl;
using std::string;


Company get_company_input(void) {
    string name = men_get_string_input("Enter company name: ");
    string message = men_get_string_input("Enter company message: ");
    int bid = men_get_int_input("Enter your bid for the advertisement: ");

    Company new_company = Company(name, message, bid);
    return new_company;
}

string men_get_string_input(const char* text) {

    string io_get_string;
    cout << text << endl;
    cin >> io_get_string;

    if (io_get_string.length() < 1 || io_get_string.length() > 100 ) {
        std::cerr << "Error " << endl;
        return "";
    }
    
    return io_get_string;
}

int men_get_int_input(const char* text) {
    unsigned int io_get_int;

    cout << text << endl;
    cin >> io_get_int;

    if (!cin) {
      cout << "No text allowed." << endl;
      return -1;
    }
    else if(io_get_int < 0) {
      cout << "ERROR" << endl;
      return -1;
    }

    return io_get_int;
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

void men_flush_file(const char* text) {
    std::ofstream ofs;
    ofs.open("ads.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

void men_print_menu(void) {
    cout << "#############################" << endl;
    cout << "####### MAIN MENU ###########" << endl;
    cout << "#                           #" << endl;
    cout << "#    SELECT OPTION BELOW    #" << endl;
    cout << "#   1. Add Adversistment    #" << endl;
    cout << "#   2. Export Ads           #" << endl;
    cout << "#   3. Flush file           #" << endl;
    cout << "#   4. Exit                 #" << endl;
    cout << "#                           #" << endl;
    cout << "#############################" << endl << endl;
}

int men_entry(AdManager am) {

    int ad_count = 0;
    bool stay_in_loop = true;
    
    while(stay_in_loop) {

        

        men_print_menu();
        int choice = men_get_int_input("Enter your choice (1 - 3)");
        if (choice == -1) { std::cerr << "mem_get_int_input() failed!\n"; }
        choice--;
        if (ad_count >= 5) { choice = RUN; }
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
                    am.addCompany(company);
                    ad_count++;
                }
                break;

            case RUN: //Send company vector to Serial COM

                am.sendAdsToSerial();    
                break;

            case DEL:  //Flushes ads.txt

                men_flush_file("ads.txt");
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


