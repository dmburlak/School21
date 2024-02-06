#include "../../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  if (!result) {
    flag = 1;
  } else {
    s21_long_decimal tmp = {};
    s21_to_long_decimal(value, &tmp);
    if (s21_get_sign(tmp)) {
      s21_set_sign(&tmp, 0);
    } else {
      s21_set_sign(&tmp, 1);
    }
    flag = s21_long_to_normal(tmp, result);
  }
  return flag != 0;
}