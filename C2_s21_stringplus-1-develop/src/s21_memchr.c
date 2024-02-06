#include "s21_string.h"

void *s21_memchr(const void *string, int symbol, s21_size_t length) {
  unsigned char *l = S21_NULL;
  unsigned char *str = (unsigned char *)string;
  for (s21_size_t i = 0; i < length; i++) {
    if (str[i] == symbol) {
      l = &str[i];
      break;
    }
  }
  return l;
}