#include "../../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_long_decimal l_dec_1 = {}, l_dec_2 = {};
  s21_to_long_decimal(value_1, &l_dec_1);
  s21_to_long_decimal(value_2, &l_dec_2);
  return s21_equality(l_dec_1, l_dec_2);
}

bool s21_equality(s21_long_decimal value_1, s21_long_decimal value_2) {
  bool flag = true;
  s21_same_exp(&value_1, &value_2);
  for (int i = 5; i >= 0; i--) {
    if (value_1.bits[i] != value_2.bits[i]) {
      flag = false;
    }
  }
  return flag;
}