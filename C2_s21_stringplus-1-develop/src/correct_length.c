#include "s21_string.h"

s21_size_t correct_length(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t len =
      s21_strlen(str1) > s21_strlen(str2) ? s21_strlen(str1) : s21_strlen(str2);
  if (n < len) {
    len = n;
  }
  return len;
}