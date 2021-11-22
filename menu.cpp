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
    cin >> io_get_string >> endl;
    

    if (io_get_string.length() < 1 || io_get_string.length() > 100 ) {
        std::cerr << "Error " << endl;
        return "";
    }
    
    return io_get_string;
    return 0;
}

int men_get_input(const char* text) {
    
    string io_get_int;
     
    cout << text << endl;
    cin >> io_get_int;
    if(io_get_int[0] == '-') {
            std::cerr << "Invalid number entered." << endl;
            return -1;
        }
    else {
        int the_int = stoi(io_get_int);
        return the_int;
    }
    return 0;
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
    cout << "####### MAIN MENU ###########" << endl;
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
                    am.addCompany(company);
                    ad_count++;
                }
                break;

            case RUN: //Send company vector to Serial COM

                am.sendAdsToSerial();    
                break;

            case DEL:  //Flushes ads.txt

                men_flush_file();
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


