// #include <iostream>
// #include <cstdlib>
// #include <vector>
#include "company.hpp"

Company::Company(string name, string message, int bid): 
    name(name), 
    message(message), 
    bid(bid), 
    exposure(0) 
    {} 

string Company::encodeToSerial() {
    int name_len = name.length();
    int message_len = message.length();
    return this->name + "|" + 
        this->message + "|" + 
        std::to_string(this->exposure) + "|";
}

// using std::cerr;
// using std::vector;

// typedef std::vector<company_t> company_list;

// void cmp_add_to_list(company_list& company_list, company_t& company) {
//     company_list.push_back(company);
// }

// void cmp_remove_from_list(vector<company_t>& company_list, const int index) {
//     company_list.erase(company_list.begin()+index);
// }


// void cmp_calculate_display_time(vector<company_t>& company_list) {
//     int total = 0;
//     for (company_list::iterator it = company_list.begin(); it != company_list.end(); ++it) {
//         total += it->bid;
//     }
//     for (company_list::iterator it = company_list.begin(); it != company_list.end(); ++it) {
//         it->exposure = ((float)it->bid / total) * MAX_TIME;
//     }
// } 