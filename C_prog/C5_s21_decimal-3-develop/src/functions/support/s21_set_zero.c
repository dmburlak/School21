#include "../../s21_decimal.h"

void s21_set_zero(s21_decimal *value) {
  for (int i = 0; i < 4; i++) {
    value->bits[i] = 0;
  }
}

void s21_long_set_zero(s21_long_decimal *value) {
  value->general = 0;
  for (int i = 0; i < 6; i++) {
    value->bits[i] = 0;
  }
}