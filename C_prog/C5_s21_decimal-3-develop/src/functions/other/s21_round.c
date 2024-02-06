#include "../../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  if (!result) {
    flag = 1;
  } else {
    s21_long_decimal tmp = {}, res = {};
    s21_to_long_decimal(value, &tmp);
    int sign = s21_get_sign(tmp);

    s21_long_decimal one = {{1}, 0}, five = {{5}, 0};
    s21_set_exp(&five, 1);

    s21_long_decimal final = {};
    s21_set_sign(&tmp, 0);
    s21_long_truncate(tmp, &res);
    s21_sub_long(tmp, res, &final);
    s21_set_sign(&final, 0);

    int check = s21_is_greater_or_equal_long(final, five);
    if (check) {
      s21_add_long(res, one, &res);
    }
    s21_set_sign(&res, sign);
    flag = s21_long_to_normal(res, result);
  }

  return flag != 0;
}