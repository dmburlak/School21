#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *string = S21_NULL;
  for (s21_size_t i = 0; str1[i] != '\0' && string == S21_NULL; i++) {
    for (s21_size_t j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        string = i + (char *)str1;
        break;
      }
    }
  }
  return string;
}