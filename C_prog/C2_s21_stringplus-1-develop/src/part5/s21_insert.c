#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *res = S21_NULL;
  if (src && str && s21_strlen(src) >= start_index) {
    size_t src_len = s21_strlen(src);
    size_t str_len = s21_strlen(str);
    size_t res_len = src_len + str_len + 1;
    res = (char *)malloc(res_len * sizeof(char));
    if (res) {
      s21_strncpy(res, src, start_index);
      s21_strncpy(res + start_index, str, str_len);
      s21_strncpy(res + start_index + str_len, src + start_index,
                  src_len - start_index);
      res[res_len - 1] = '\0';
    }
  }
  return res;
}