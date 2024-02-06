#include "../../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_long_decimal l_dec_1 = {}, l_dec_2 = {};
  s21_to_long_decimal(value_1, &l_dec_1);
  s21_to_long_decimal(value_2, &l_dec_2);
  return s21_less_long(l_dec_1, l_dec_2);
}

bool s21_less_long(s21_long_decimal value_1, s21_long_decimal value_2) {
  bool res = false;
  s21_same_exp(&value_1, &value_2);
  int sign_1 = s21_get_sign(value_1), sign_2 = s21_get_sign(value_2);
  if (sign_1 != sign_2 && !(s21_is_zero(value_1) && s21_is_zero(value_2))) {
    res = sign_1;
  } else {
    int i = 5;
    while (i >= 0 && value_1.bits[i] == value_2.bits[i]) {
      i--;
    }
    if (i >= 0) {
      res = value_1.bits[i] < value_2.bits[i];
      if (sign_1 && sign_2) {
        res = 1 - res;
      }
    }
  }
  return res;
}
