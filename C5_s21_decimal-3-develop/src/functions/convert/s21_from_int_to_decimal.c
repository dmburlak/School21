#include "../../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int flag = 0;
  if (!dst) {
    flag = 1;
  } else {
    s21_long_decimal value = {};
    if (src < 0) {
      src = -src;
      s21_set_sign(&value, 1);
    }
    value.bits[0] = src;
    flag = s21_long_to_normal(value, dst);
  }
  return flag;
}