#include <iostream>
#include <vector>
#include "company.hpp"
#include "serial.h"
#include "ad_manager.hpp"

using namespace std;

#ifndef MENU_HPP
#define MENU_HPP


typedef enum main_menu {
	SET, RUN, EXT
} main_menu;

Company get_company_input(void);
string io_get_string_input(const char* text);
int io_get_int_input(const char* text);
int men_entry_choice(void);
int men_entry(void);

#endif