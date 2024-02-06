#include "../../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  s21_long_decimal dst_1 = {};

  int flag = 0, sign = 0;

  if (src < 0.0) {
    sign = 1;
    src *= -1;
  }

  if ((isnan(src)) || (isinf(src)) || (src >= D_MAX) || (src < D_MIN)) {
    flag = 1;
    if (src < D_MIN)
      for (int i = 0; i < 4; i++) dst->bits[i] = 0;
  } else {
    char string[100];
    sprintf(string, "%e", src);

    for (int j = 0; j < 8; j++) {
      if (string[j] != '.') {
        s21_mul_ten(&dst_1);
        s21_long_decimal adddition = {{string[j] - '0'}, 0};
        s21_add_long(dst_1, adddition, &dst_1);
      }
    }

    int exp = get_string_exp(string), normal_exp = 6;

    normal_exp -= exp;

    if (normal_exp < 0) {
      normal_exp *= -1;
      for (int i = 0; i < normal_exp; i++) {
        s21_mul_ten(&dst_1);
      }
      normal_exp = 0;
    }

    s21_set_sign(&dst_1, sign);
    s21_set_exp(&dst_1, normal_exp);
    flag = s21_long_to_normal(dst_1, dst);
  }
  return flag;
}

int get_string_exp(char *str) {
  int result = 0, sign = 0, idx = 0;
  while (str[idx] != 'e') idx++;
  idx++;
  if (str[idx] == '-') sign = 1;
  result = (str[idx + 1] - '0') * 10 + (str[idx + 2] - '0');
  if (sign == 1) result *= -1;
  return result;
}

// int s21_from_float_to_decimal(float src, s21_decimal *dst) {
//   s21_long_decimal value = {};
//   int count = 0, flag = 0;
//   if (src < 0.0) {
//     s21_set_sign(&value, 1);
//     src *= -1;
//   }
//   if (isnan(src) || isinf(src) || !dst) {
//     flag = 1;
//   } else {
//     while ((long)src != src && count < 28) {
//       src *= 10;
//       count++;
//     }
//     value.bits[0] = round(src);
//     s21_set_exp(&value, count);
//     s21_long_to_normal(value, dst);
//   }
//   return flag;
// }