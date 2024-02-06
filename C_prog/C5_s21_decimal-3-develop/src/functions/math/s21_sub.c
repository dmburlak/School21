#include "../../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_long_decimal val_1 = {}, val_2 = {}, res = {};
  s21_to_long_decimal(value_1, &val_1);
  s21_to_long_decimal(value_2, &val_2);
  s21_sub_long(val_1, val_2, &res);
  return s21_long_to_normal(res, result);
}

void s21_sub_long(s21_long_decimal val_1, s21_long_decimal val_2,
                  s21_long_decimal* res) {
  if (s21_get_sign(val_2) == 1) {
    s21_set_sign(&val_2, 0);
    s21_add_long(val_1, val_2, res);
  } else if (s21_get_sign(val_1) == 1) {
    s21_set_sign(&val_1, 0);
    s21_add_long(val_1, val_2, res);
    s21_set_sign(res, 1);
  } else {
    s21_same_exp(&val_1, &val_2);
    if (s21_greater_long(val_2, val_1)) {
      s21_long_decimal tmp = val_1;
      val_1 = val_2;
      val_2 = tmp;
      s21_set_sign(res, 1);
    }
    long ost = 0, diff = 0;
    for (int i = 0; i < 6; i++) {
      diff = (long)val_1.bits[i] - (long)val_2.bits[i] - ost;
      if (diff < 0) {
        diff += UINT_MAX + 1;
        ost = 1;
      } else {
        ost = 0;
      }
      res->bits[i] = diff;
    }
    s21_set_exp(res, s21_get_exp(val_1));
  }
}