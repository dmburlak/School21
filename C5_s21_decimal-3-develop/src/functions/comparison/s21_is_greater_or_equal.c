#include "../../s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_long_decimal l_dec_1 = {}, l_dec_2 = {};
  s21_to_long_decimal(value_1, &l_dec_1);
  s21_to_long_decimal(value_2, &l_dec_2);
  return s21_equality(l_dec_1, l_dec_2) || !s21_less_long(l_dec_1, l_dec_2);
}

int s21_is_greater_or_equal_long(s21_long_decimal value_1,
                                 s21_long_decimal value_2) {
  return s21_equality(value_1, value_2) || !s21_less_long(value_1, value_2);
}