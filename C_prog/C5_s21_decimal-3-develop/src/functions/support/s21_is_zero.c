#include "../../s21_decimal.h"

bool s21_is_zero(s21_long_decimal value) {
  bool res = true;
  for (int i = 0; i < 6; i++) {
    if (value.bits[i] != 0) {
      res = false;
    }
  }
  return res;
}