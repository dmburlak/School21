#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *string = S21_NULL;
  if (c == '\0') {
    string = "";
  } else {
    for (s21_size_t i = 0; str[i] != '\0'; i++) {
      if (str[i] == c) {
        string = (char *)(str + i);
        break;
      }
    }
  }
  return string;
}