#include "billboard.h"
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char buff_package[MAX_BUFFER] = { '\0' };
int buff_length = 0;
int cmp_num = 0;
int pkg_idx = 0;
int bid_total = 0;
/*global variables*/

static void roll_ad(long run_time, int str_size) {
/*runs ad by counting down its runtime while scrolling the prints in a for-loop*/
  while (run_time > 0) {
    for (int positionCounter = 0; positionCounter < str_size; positionCounter++) {
      lcd.scrollDisplayLeft();
      delay(150);
      run_time -= 150;
    }
  }
}

static void show_ad(package_t *cmp) {
/*fetches name/mess-sizes and run_time from members in the struct*/
  int str_size = cmp->name_size + cmp->mess_size;
  long run_time = (long)cmp->exposure * SEC;
  lcd.clear();
  lcd.print(cmp->name);
  lcd.print(" | ");
  lcd.print(cmp->mess);
  delay(500);
  run_time -= 500;
  roll_ad(run_time, str_size);
}

static void stage_ads(package_t *cmp) {
/*throws every cmp in front of the spotlight*/
  for (int i = 0; i < cmp_num; i++) {
    show_ad(&cmp[i]);
  }
}

static void run_show(int mode) {
  if (mode == 1) {
    lcd.clear();
    lcd.print("initializing...");
    delay(2000);
  } else {
    lcd.clear();
    lcd.print("show's over :(");
    delay(2000);
  }
}

static void calc_exp(int bid_total, package_t *cmp) {
  cmp->exposure = (cmp->bid / bid_total) * MAX_TIME;
}

void setup() {
/*imports entire array to "package", Serial.available() doesent play along for some
 *reason. stores array-length in package_length and copies "package" over to a
 *plain char-array before recieving number of companies in the count_cmp-function.
 */
  lcd.begin(16, 2);
  Serial.begin(9600);
  String package = Serial.readString();
  
  for (int i = 0; package[i] != '\0'; i++) {
    buff_length++;
  }
  for (int i = 0; i < buff_length; i++) {
    buff_package[i] = package[i];
  }
  cmp_num = count_cmp(buff_package, buff_length);
}

void loop() {
/*various loops has being dealt with in the static funtions prior why this part is
 *used more or less as a "main" where the show starts and ends with arduino's exit-call
 *after cmp-instanses being created, assignned, calculated and shown in stage_ads.
 */
  run_show(1);
  package_t cmp[cmp_num];
  for (int i = 0; i < cmp_num; i++) {
    bid_total += parse_cmp(buff_package, &cmp[i]);
  }
  for (int i = 0; i < cmp_num; i++) {
    calc_exp(bid_total, &cmp[i]);
  }
  stage_ads(cmp);
  run_show(0);
  exit(0);
}