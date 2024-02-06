#include "../../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_long_decimal val_1 = {}, val_2 = {}, res = {};
  s21_to_long_decimal(value_1, &val_1);
  s21_to_long_decimal(value_2, &val_2);
  s21_add_long(val_1, val_2, &res);
  return s21_long_to_normal(res, result);
}

void s21_add_long(s21_long_decimal value_1, s21_long_decimal value_2,
                  s21_long_decimal *res) {
  if (s21_get_sign(value_1) != s21_get_sign(value_2)) {
    if (s21_get_sign(value_2) == 1) {
      s21_set_sign(&value_2, 0);
      s21_sub_long(value_1, value_2, res);
    } else if ((s21_get_sign(value_1) == 1)) {
      s21_set_sign(&value_1, 0);
      s21_sub_long(value_2, value_1, res);
    }
  } else {
    s21_same_exp(&value_1, &value_2);
    long sum = 0, ost = 0, mod = 1l << 32;
    for (int i = 0; i < 6; i++) {
      sum = (long)value_1.bits[i] + (long)value_2.bits[i] + ost;
      ost = sum / mod;
      res->bits[i] = sum % mod;
    }
    s21_set_exp(res, s21_get_exp(value_1));
    s21_set_sign(res, s21_get_sign(value_1));
  }
}