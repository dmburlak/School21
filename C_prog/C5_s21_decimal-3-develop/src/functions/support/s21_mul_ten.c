#include "../../s21_decimal.h"

void s21_mul_ten(s21_long_decimal *value) {
  s21_long_decimal res_1 = {}, res_2 = {};
  s21_decimal_cpy(&res_1, *value);
  s21_decimal_cpy(&res_2, *value);
  s21_left_shift(&res_1);
  s21_left_shift(&res_1);
  s21_add_long(res_1, res_2, value);
  s21_left_shift(value);
}
