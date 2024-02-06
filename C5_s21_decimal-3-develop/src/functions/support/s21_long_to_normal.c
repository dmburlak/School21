#include "../../s21_decimal.h"

int s21_long_to_normal(s21_long_decimal value_1, s21_decimal* res) {
  int exp = s21_get_exp(value_1), sign = s21_get_sign(value_1), error = 0;
  if (s21_get_upper_bits_sum(value_1) == 0) {
    for (int i = 0; i < 3; i++) res->bits[i] = value_1.bits[i];
    s21_set_exp(&value_1, exp);
    res->bits[3] = value_1.general;
  } else {
    error = 1 + sign;
    s21_set_zero(res);
  }
  return error;
}

long s21_get_upper_bits_sum(s21_long_decimal value) {
  long sum = 0;
  for (int i = 3; i < 6; i++) {
    sum += value.bits[i];
  }
  return sum;
}
