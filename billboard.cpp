#include "billboard.hpp"
#include <iostream>
#include <stdlib.h>

void pkt_create(char *package, package_t *cmp) {
 int p_idx = 0, c_idx= 0;
 char num[MAX_CMP_NUM];
 
 while (package[p_idx] != '|') {
    cmp->cname[p_idx] = package[p_idx];
    p_idx++;
    c_idx++;
  } p_idx++, c_idx++;
  cmp->cname[c_idx - 1] = '\0';
  cmp->name_size = c_idx;
  
  c_idx = 0;

  while (package[p_idx] != '|') {
    cmp->cmess[c_idx] = package[p_idx];
    p_idx++;
    c_idx++;
  } p_idx++, c_idx++;
  cmp->cmess[c_idx - 1] = '\0';
  cmp->mess_size = c_idx;
  
  c_idx = 0;

  while (package[p_idx] != '|') {
    num[c_idx] = package[p_idx];
    p_idx++;
    c_idx++;
  } p_idx++, c_idx++;
  
  num[c_idx - 1] = '\0';
  cmp->exposure = atoi(num);
  cmp->exposure * 100;
  num[MAX_CMP_NUM];
}
