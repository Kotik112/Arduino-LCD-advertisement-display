#ifndef __MENU_HPP__
#define __MENU_HPP__

#include "company.hpp"
#include "ad_manager.hpp"

typedef enum main_menu {
	ADD, RUN, DEL, EXT
} main_menu;

Company get_company_input(void);
std::string men_get_string_input(const char* text);
int men_get_int_input(const char* text);
void men_flush_file(const char* text);
void men_print_menu(void);
int men_entry_choice(const char* text);
int men_entry(AdManager am);

#endif
