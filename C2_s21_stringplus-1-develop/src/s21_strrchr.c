#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *string = S21_NULL;
  if (c == '\0') {
    string = "";
  } else {
    for (int i = s21_strlen(str) - 1; i >= 0; i--) {
      if (str[i] == c) {
        string = (char *)str + i;
        break;
      }
    }
  }
  return string;
}