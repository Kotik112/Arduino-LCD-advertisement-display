#ifndef BILLBOARD_H
#define BILLBOARD_H
#include "arduino.h"

#define MAX_CMP_NAME 20
#define MAX_CMP_MESS 100
#define MAX_CMP_NUM 2

typedef struct package_t {
  unsigned int name_size;
  unsigned int mess_size;
  char cname[MAX_CMP_NAME];
  char cmess[MAX_CMP_MESS];
  int exposure;
} package_t;

void pkt_create(char *package, package_t *cmp);

#endif