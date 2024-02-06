#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *buff = calloc(len, sizeof(*buff));
  if (buff) {
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 97 && str[i] <= 122) {
        buff[i] = str[i] - 32;
        continue;
      }
      buff[i] = str[i];
    }
  } else {
    buff = S21_NULL;
  }
  return (void *)buff;
}