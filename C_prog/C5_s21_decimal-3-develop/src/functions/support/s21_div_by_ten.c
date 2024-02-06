#include "../../s21_decimal.h"

int s21_div_by_ten(s21_long_decimal* value) {
  s21_long_decimal res = {};
  unsigned int tmp = 0;
  for (int i = 191; i >= 0; i--) {
    tmp <<= 1;
    tmp += s21_get_bit(*value, i);
    s21_left_shift(&res);
    if (tmp >= 10) {
      tmp -= 10;
      res.bits[0] += 1;
    }
  }
  s21_decimal_cpy(value, res);
  return tmp;
}