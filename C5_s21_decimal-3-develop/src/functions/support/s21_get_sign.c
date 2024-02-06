#include "../../s21_decimal.h"

bool s21_get_sign(s21_long_decimal value) { return value.general >> 31; }