#include "../../s21_decimal.h"

void s21_left_shift(s21_long_decimal *value) {
  for (int i = 5; i > 0; i--) {
    value->bits[i] <<= 1;
    value->bits[i] += (value->bits[i - 1] >= (1u << 31));
  }
  value->bits[0] <<= 1;
}