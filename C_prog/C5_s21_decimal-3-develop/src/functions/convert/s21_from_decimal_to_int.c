#include "../../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  s21_long_decimal value = {};
  s21_to_long_decimal(src, &value);
  int exp = s21_get_exp(value), flag = 0;
  double num = 0;
  for (int i = 0; i < 192; i++) {
    num += s21_get_bit(value, i) * pow(2, i);
  }
  num /= pow(10, exp);
  if (num > INT_MAX) {
    flag = 1;
  } else {
    if (s21_get_sign(value)) {
      num = -num;
    }
    *dst = num;
  }
  return flag;
}