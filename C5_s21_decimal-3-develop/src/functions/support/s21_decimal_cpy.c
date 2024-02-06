#include "../../s21_decimal.h"

void s21_decimal_cpy(s21_long_decimal *value, s21_long_decimal source) {
  s21_long_set_zero(value);
  for (int i = 0; i < 6; i++) {
    value->bits[i] = source.bits[i];
  }
  value->general = source.general;
}