#include "../../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_long_decimal val_1 = {}, val_2 = {}, res = {};
  s21_to_long_decimal(value_1, &val_1);
  s21_to_long_decimal(value_2, &val_2);
  int error = 0;
  for (int i = 0; i < 192; i++) {
    if (s21_get_bit(val_2, i)) {
      s21_long_decimal tmp = {};
      s21_decimal_cpy(&tmp, val_1);
      for (int j = 0; j < i; j++) {
        s21_left_shift(&tmp);
      }
      s21_add_long(tmp, res, &res);
    }
  }
  s21_set_exp(&res, s21_get_exp(val_1) + s21_get_exp(val_2));
  s21_set_sign(&res, (s21_get_sign(val_1) + s21_get_sign(val_2)) == 1);
  error = s21_long_to_normal(res, result);
  return error;
}