#ifndef BILLBOARD_H
#define BILLBOARD_H
#include "arduino.h"

#define SEC 1000
#define MAX_TIME 60
#define MAX_BUFFER 612
#define MAX_COMP 5      
#define MAX_NAME 20
#define MAX_MESS 100
#define MAX_NUMB 10

extern char buff_package[MAX_BUFFER];
extern int buff_length;
extern int cmp_num;
extern int pkg_idx;

typedef struct package_t {
  float bid;
  float exposure;
  int name_size;
  int mess_size;
  char name[MAX_NAME];
  char mess[MAX_MESS];
} package_t;
/*struct for storing data in current package.*/

int count_cmp(char *buff_package, int buff_length);
int parse_cmp(char *buff_package, package_t *cmp);
/*functions for parsing current package.*/

#endif
