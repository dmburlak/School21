#include "../../s21_decimal.h"

void s21_set_exp(s21_long_decimal* value, unsigned int exp) {
  exp <<= 16;
  value->general = (s21_get_sign(*value) << 31) + exp;
}