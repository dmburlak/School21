#include "../../s21_decimal.h"

void s21_to_long_decimal(s21_decimal value, s21_long_decimal *res) {
  s21_long_set_zero(res);
  res->general = value.bits[3];
  for (int i = 0; i < 3; i++) {
    res->bits[i] = value.bits[i];
  }
}