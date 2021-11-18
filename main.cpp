#include <iostream>
#include <string>
#include <vector>
#include <stdbool.h> // Behövs detta i c++ ens?
#include "ad_manager.hpp"

#include "serial.h"

using namespace std;

Company get_company_input(void) {
    string name = io_get_string_input("Enter company name: ");
    string message = io_get_string_input("Enter company message: ");
    int bid = io_get_int_input("Enter your bid for the advertisement: ");

    Company new_company = Company(name, message, bid);
    return new_company;
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
    /* for (auto port: ports){
        cout << port << endl;
    } */

    // Create ad manager and send in ports
    auto am = AdManager(ports);

    // Read file
    am.readFile();
    am.print_string_vector(); //Funkar ej
    
    //Company company = get_company_input();
    //company.printCompany();
    
    const char* my_string = "1234\0";

    SERIALPORT port = SerialInit((char *) ports[0].c_str());
    if (SerialIsConnected(port)) {
        cout << "Connected.\n";
        SerialWritePort(port, (char*) my_string, sizeof(char)*5);
        SerialClose(port);
    }
    else {
        cerr << "Not connected.\n";
    }

    
    return 0;
}


