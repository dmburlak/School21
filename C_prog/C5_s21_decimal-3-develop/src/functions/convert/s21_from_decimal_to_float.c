#include "../../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  s21_long_decimal value = {};
  s21_to_long_decimal(src, &value);
  int exp = s21_get_exp(value);
  double num = 0;
  for (int i = 0; i < 192; i++) {
    num += s21_get_bit(value, i) * pow(2, i);
  }
  num /= pow(10, exp);
  if (s21_get_sign(value)) {
    num = -num;
  }
  *dst = num;
  return 0;
}