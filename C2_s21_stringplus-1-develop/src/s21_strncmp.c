#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int count = 0;
  s21_size_t len = correct_length(str1, str2, n);
  for (s21_size_t i = 0; i < len; i++) {
    if (str1[i] == str2[i]) {
      continue;
    } else {
      count = str1[i] - str2[i];
      break;
    }
  }
  return count;
}