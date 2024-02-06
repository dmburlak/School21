#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int count = 0;
  s21_size_t len = correct_length(str1, str2, n);
  for (s21_size_t i = 0; i < len; i++) {
    if (((char *)str1)[i] == ((char *)str2)[i]) {
      continue;
    } else {
      count = ((char *)str1)[i] - ((char *)str2)[i];
      break;
    }
  }
  return count;
}