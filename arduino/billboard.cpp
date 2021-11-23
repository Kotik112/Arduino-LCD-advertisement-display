#include "billboard.h"

static int pipe_parse(char *buff_package, int buff_length) {
/*returns amount of pipes - delimiter "|" - in current package.*/
  int pipes = 0;
  for (int i = 0; i < buff_length; i++) {
    if (buff_package[i] == '|') {
      pipes++;
    }
  }
  return pipes;
}

static int cnum_parse(char *buff_package, int buff_length) {
/*calculates number of companies in current package by dividing
 *the frequence of '|'-chars (3 for each company) with 3.
 */
  int pipes = pipe_parse(buff_package, buff_length);
  return pipes / 3;
}

int count_cmp(char *buff_package, int buff_length) {
/*returns number of companies in package.*/
  int cnum = cnum_parse(buff_package, buff_length);
  return cnum;
}

int parse_cmp(char *buff_package, package_t *cmp) {
/*allright, this is bloody. but it is what it is. sorting chars
 *out from an array and assign them to various struct-members.
 */
  int pipe_count = 0, mem_idx = 0;
  char tmp_bid[MAX_NUMB] = { '\0' };
  
  while (buff_package[pkg_idx] != '|') {
    cmp->name[mem_idx] = buff_package[pkg_idx];
    pkg_idx++;
    mem_idx++;
  } pkg_idx++, mem_idx++;
  
  cmp->name[mem_idx - 1] = '\0';
  cmp->name_size = mem_idx;
    
  mem_idx = 0;
  
  while (buff_package[pkg_idx] != '|') {
    cmp->mess[mem_idx] = buff_package[pkg_idx];
    pkg_idx++;
    mem_idx++;
  } pkg_idx++, mem_idx++;
    
  cmp->mess[mem_idx - 1] = '\0';
  cmp->mess_size = mem_idx;
    
  mem_idx = 0;
  
  while (buff_package[pkg_idx] != '|') {
    tmp_bid[mem_idx] = buff_package[pkg_idx];
    pkg_idx++;
    mem_idx++;
  } pkg_idx++, mem_idx++;

  tmp_bid[mem_idx - 1] = '\0';
  
  cmp->bid = atof(tmp_bid);
  return cmp->bid;
}
