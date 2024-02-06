#include "../../s21_decimal.h"

void s21_same_exp(s21_long_decimal *value_1, s21_long_decimal *value_2) {
  s21_limit_exp(value_1), s21_limit_exp(value_2);
  int diff = s21_get_exp(*value_1) - s21_get_exp(*value_2);
  s21_long_decimal *less = value_2;
  if (diff < 0) {
    diff = -diff;
    less = value_1;
  }
  for (int i = 0; i < diff; i++) {
    s21_mul_ten(less);
  }
  s21_set_exp(less, s21_get_exp(*less) + diff);
}

void s21_limit_exp(s21_long_decimal *value) {
  int diff = s21_get_exp(*value) - 28;
  if (diff > 0) {
    if (diff > 30) {
      s21_long_set_zero(value);
      s21_set_exp(value, 0);
    } else {
      for (int i = 0; i < diff; i++) {
        s21_div_by_ten(value);
      }
      s21_set_exp(value, s21_get_exp(*value) - diff);
    }
  }
}