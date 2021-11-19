#ifndef __MENU_HPP__
#define __MENU_HPP__

#include "company.hpp"

typedef enum main_menu {
	ADD, RUN, DEL, EXT
} main_menu;

Company get_company_input(void);
int men_get_int_input(const char* text);
int men_entry_choice(void);
int men_entry(void);

#endif