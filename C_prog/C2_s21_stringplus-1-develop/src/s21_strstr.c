#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t len = s21_strlen(needle);
  char *string = S21_NULL;
  if (haystack[0] == '\0' && needle[0] == '\0') {
    string = "";
  } else {
    for (s21_size_t i = 0; haystack[i] != '\0'; i++) {
      s21_size_t j;
      for (j = 0; j < len; j++) {
        if (haystack[i + j] != needle[j]) break;
      }
      if (j == len) {
        string = (char *)haystack + i;
        break;
      }
    }
  }
  return string;
}