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


int men_entry_choice(void);
int men_entry(void);

#endif