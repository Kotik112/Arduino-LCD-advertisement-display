/* TODO:
    - Lägg till main menu.
    - Swap på arduinon. (VG)
    - Save to file i AdManager.
    - Exposed blir sträng
    - Readme.txt

    - BETA TESTA KODEN O FIXA
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "ad_manager.hpp"
#include "serial.h"

using namespace std;

static bool inp_check(char ch) {
	return ((ch >= 0x20 && ch <= 0x7a) || ch == 0x0 || ch == 0x4);
}
static bool int_check(char ch) {
	return ch >= '0' && ch <= '9';
}
static string cmp_add_name(void) {
    string name;
	std::cout << "add company name: ";
    std::cin >> name;
	for (unsigned int i = 0; i < name.length(); i++) {
        char ch = name[i];
		if(!inp_check(ch)) {
			cout << "you've entered an invalid character. try again" << endl;
			return cmp_add_name();
		} else if (name.length() > MAX_CMP_NAME){
			cout << "max 20 characters. try again" << endl;
			return cmp_add_name();
		}
	}
    return name;
}

static string cmp_add_message(void) {
    string message;
	std::cout << "add message: ";
    std::cin >> message;
	for (unsigned int i = 0; i < message.length(); i++) {
        char ch = message[i];
		if(!inp_check(ch)) {
			cout << "you've entered an invalid character. try again" << endl;
			return cmp_add_message();
		} else if (message.length() > MAX_CMP_MESS) {
			cout << "max 20 characters. try again" << endl;
			return cmp_add_message();
		}
	}
    return message;
}

static string cmp_add_bid(void) {
    string bid;
	std::cout << "add a bid: ";
    std::cin >> bid;
	for (unsigned int i = 0; i < bid.length(); i++) {
        char ch = bid[i];
		if(!int_check(ch)) {
			cout << "you've not entered a digit. try again." << endl;
			return cmp_add_bid();
		} else if (bid.length() > MAX_CMP_BID){
			cout << "to large number, try again" << endl;
			return cmp_add_bid();
		}
	}
    return bid;
}

static int menu_choice(void) {
    int choice;
	std::cout << "Enter menu choice (1-6): ";
    std::cin >> choice;
    string choice_str = std::to_string(choice);
	for (unsigned int i = 0; i < choice_str.length(); i++) {
        char ch = choice_str[i];
		if(!int_check(ch)) {
			cout << "you've not entered a digit. try again." << endl;
			return menu_choice();
		} else if (choice_str.length() > 1){
			cout << "to large number, try again" << endl;
			return menu_choice();
		}
	}
    choice = atoi( choice_str.c_str() );
    choice--;  //To adjust for the enum offset.
    return choice;
}

void flush_file(const char* text) {
    std::ofstream ofs;
    ofs.open(text, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

void print_menu(void) {
    cout << "#############################" << endl;
    cout << "####### MAIN MENU ###########" << endl;
    cout << "#                           #" << endl;
    cout << "#    SELECT OPTION BELOW    #" << endl;
    cout << "#   1. Add Adversistment    #" << endl;
    cout << "#   2. Export Ads to Ardu   #" << endl;
    cout << "#   3. Save to file         #" << endl;
    cout << "#   4. Read from file       #" << endl;
    cout << "#   5. Flush file           #" << endl;
    cout << "#   6. Exit                 #" << endl;
    cout << "#                           #" << endl;
    cout << "#############################" << endl << endl;
}

void create_company(AdManager& am) {
    string company = cmp_add_name();
    string message = cmp_add_message();
    string bid = cmp_add_bid();
    
    auto new_company = Company(company, message, bid);
    am.addCompany(new_company);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Error. You must specify the port number." << endl;
        return -1;
    }

    // Split args and stick them in a vector
    vector<string> ports;

    for (int i = 1; i < argc; i++) {
        // check argv[i]
        string portName(argv[i]);

        // Test each arg to ensure it matches "COM*"
        if (portName == "COM1" || portName == "COM2" || portName == "COM3" || portName == "COM4" || portName == "COM5") {
            ports.push_back("\\\\.\\" + portName);
        }
        else {
            cerr << "Error. Your options are 'COM1', 'COM2', 'COM3', 'COM4' or 'COM5' (Case sensitive): '" << portName << "'" << endl;
            return -1;
        }
    }
    auto am = AdManager(ports);
    int choice;
    while(1){
        print_menu();
        choice = menu_choice();
        switch (choice)
        {
        /* Add a new company to vector. */
        case ADD:
            if(am.am_company_size() > 5) {
                cerr << "Max 5 entries." << endl;
                choice = ARDU; //Funkar?
            }
            create_company(am);
            break;

        /* Send encoded struct to serial. */
        case ARDU:
            am.am_send_ad_to_serial();
            break;
        /* Save to file. */
        case SAVE:
            am.am_save_file("ads.txt");
            break;

        /* Read from file. */
        case READ:
            am.am_read_file("ads.txt");
            break;

        /* Flush file. */
        case FLSH:
            flush_file("ads.txt");
            am.am_flush_cmp_vector();
            break;

        /* Exit out of program. */
        case EXIT:
            exit(0);
            break;
        
        default:
            cerr << "Choices are 1-6." << endl;
            break;
        }
    }
}
    

