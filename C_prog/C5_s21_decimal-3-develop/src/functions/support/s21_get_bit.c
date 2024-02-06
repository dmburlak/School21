#include "../../s21_decimal.h"

int s21_get_bit(s21_long_decimal value, unsigned char index) {
  int rank = 0, position = 0, res = 0;
  rank = index / 32;
  position = index % 32;
  res = (value.bits[rank] & (1 << position)) != 0 ? 1 : 0;
  return res;
}