#include "../../s21_decimal.h"

void s21_set_sign(s21_long_decimal *value, bool sign) {
  if (sign) {
    value->general |= (1u << 31);
  }
  if (!sign) {
    value->general &= ~(1u << 31);
  }
}