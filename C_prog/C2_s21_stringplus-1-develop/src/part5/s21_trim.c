#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = S21_NULL;
  if (src && trim_chars) {
    char *ptr_str = (char *)src;
    char *end_str = (char *)src + s21_strlen(src);
    for (; *ptr_str && s21_strchr(trim_chars, *ptr_str); ptr_str++)
      ;
    for (; s21_strchr(trim_chars, *(end_str - 1)) && ptr_str != end_str;
         end_str--)
      ;
    int len = end_str - ptr_str;
    res = (char *)malloc((end_str - ptr_str + 1) * sizeof(char));
    if (res) {
      s21_strncpy(res, ptr_str, len);
      *(res + len) = '\0';
    }
  }
  return res;
}