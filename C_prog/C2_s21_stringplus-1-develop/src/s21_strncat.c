#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  for (s21_size_t i = s21_strlen(dest), j = 0; j < n; i++, j++) {
    dest[i] = src[j];
  }
  return dest;
}
