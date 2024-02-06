#include "../../s21_decimal.h"

int s21_get_exp(s21_long_decimal value) {
  unsigned int exp = value.general;
  exp -= s21_get_sign(value) << 31;
  exp >>= 16;
  return exp;
}