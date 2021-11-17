#include <iostream>
#include <string>
#include <vector>
#include <stdbool.h> // Behövs detta i c++ ens?
#include "ad_manager.hpp"

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Error. You must specify the port number." << endl;
        return -1;
    }

    // Split args and stick them in a vector
    vector<string> ports;

    for (int i = 1; i < argc; i++) {
        // check argv[i]
        std::string portName(argv[i]);

        // Test each arg to ensure it matches "COM*"
        if (portName == "COM1" || portName == "COM2" || portName == "COM3" || portName == "COM4" || portName == "COM5") {
            ports.push_back("\\\\.\\" + portName);
        }
        else {
            cerr << "Error. Your options are 'COM1', 'COM2', 'COM3', 'COM4' or 'COM5' (Case sensitive): '" << portName << "'" << endl;
            return -1;
        }
    }

    // Create ad manager and send in ports
    auto am = AdManager(ports);

    // Read file
    am.readFile();
    
    return 0;
}

/*
    förslag på jumplist som läser "huvudfunktioner" efter inmatning.

    typedef enum main_menu {        // ska ligga i en header
        SET, GET, DEL, RUN, EXT
    } main_menu;

    <skapa en hel vectorstruct>

    int choice = input_func();

    while(1) {
        switch(choice)
        case: SET
            //  set_vector(<vectorstruct>, filename)
                //  for (name, slogan, bid) "ish"...
                    //  vetor->add_name
                    //  vetor->add_slogan
                    //  vetor->add_bid
                //  calculate_exposure(<vectorstruct>)
            //  write_to_file(<vectorstruct>, filename)
                //  for (name, slogan, bid) "ish"...
                    //  append_to_file(<vectorstruct>)
                        //  FILE * out ...osv(skriv till fil)
        case: GET
            //  read_file(<vectorstruct>, filename)... osv (läs från fil/granska)
                //  print_en_massa_data(<vectorstruct>, filename)
                //  
        case: DEL
            //  read_file(<vectorstruct>, filename)... osv (del i fil)
                //  del_entries_through_file(<vectorstruct>)
                //  del_stuff() "ish"
                //  sortering av nått slag för att rewrite file() "ish"
            //  write_file(<vectorstruct>, filename)
        case: RUN
            //  run_vector(<vectorstruct>)... osv (skicka till arduino)
                //  read_file(vectorstruct)... osv (läs från fil)
                //  choose_companies(<vectorstruct>)
                    send_stuff_arduino(<vectorstruct>)      
        case: EXT
            // cout "hejdå"
                //break
        default:
            cout "du har valt nått galet, testa igen"
    }
*/
