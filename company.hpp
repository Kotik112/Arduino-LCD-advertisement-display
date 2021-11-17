#ifndef __COMPANY_H__
#define __COMPANY_H__

#include <iostream>
#include <vector>
#include <string>

// #define MAX_COMPANY_NAME 20
// #define MAX_MESSAGE_LEN 100
// #define MAX_TIME 60
// #define MAX_PACKAGE_SIZE = MAX_COMPANY_NAME * MAX_MESSAGE_LEN


using std::vector;
using std::string;

struct Company {
    string name;
    string message;
    int bid;
    float exposure;

    Company(string name, string message, int bid);

    string encodeToSerial();
};

#endif

// typedef struct company{
//     char name[MAX_COMPANY_NAME];
//     char message[MAX_MESSAGE_LEN];
//     int bid;
//     float exposure;
// } company_t;

// std::vector<company_t> company_list;  //ta bort sen

// /* Adds a company to the company_list vector. */
// void cmp_add_to_list(vector<company_t>& company_list, company_t& company);

// /* Removes the index number from the vector. */
// void cmp_remove_from_list(vector<company_t>& company_list, int index);

// /* Calculates the amount of time the message is advertised. */
// void cmp_calculate_display_time(vector<company_t>& company_list);