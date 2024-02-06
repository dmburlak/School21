#include "../../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  if (!result) {
    flag = 1;
  } else {
    s21_long_decimal tmp = {};
    s21_to_long_decimal(value, &tmp);
    s21_long_truncate(tmp, &tmp);
    flag = s21_long_to_normal(tmp, result);
  }
  return flag != 0;
}

void s21_long_truncate(s21_long_decimal value, s21_long_decimal *result) {
  int exp = s21_get_exp(value), sign = s21_get_sign(value);
  s21_decimal_cpy(result, value);
  while (exp-- > 0) {
    s21_div_by_ten(result);
  }
  s21_set_exp(result, 0);
  s21_set_sign(result, sign);
}