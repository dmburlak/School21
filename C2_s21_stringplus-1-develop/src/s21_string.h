#ifndef S21_STRING_H
#define S21_STRING_H

#define S21_NULL ((void *)0)
#define BUFF_SIZE 12000

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef long unsigned s21_size_t;

typedef struct {
  bool minus;
  bool plus;
  bool space;
  bool def;
  s21_size_t precision;
  s21_size_t width;
  int count_length;
  char length;
  char value[12000];
} flags;

s21_size_t correct_length(const char *str1, const char *str2, s21_size_t n);
void *s21_memchr(const void *string, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

void s21_sprintf(char *str, const char *format, ...);

void findFlags(const char *format, flags *flag, s21_size_t *i);
void findWidth(const char *format, s21_size_t *width, s21_size_t *i);
void findPrecision(const char *format, flags *flag, s21_size_t *i);
void findLength(const char *format, flags *flag, s21_size_t *i);
void findSpecifier(char curr_ch, flags *flag, va_list args);

void lengthDecimal(long long *num, va_list args, flags flag);
void spaceFill(char *str, int *k, s21_size_t *j, int diff);
void bufferFill(long long num, flags *flag);
void lengthUnsigned(long long *num, va_list args, flags flag);
void integerChanger(long long num, char *buff);
void precisionCorrect(flags *flag);
void unsignedChanger(unsigned long long num, char *buff);
void reverseArr(char *buff);
void floatChanger(double f_num, flags *flag);
void fillStr(flags flag, char *str, s21_size_t *j);
double wholeDetect(double f_num, flags *flag, s21_size_t *start,
                   s21_size_t *point);
void strFilling(flags *flag, char *str);
void pointApprove(s21_size_t point, flags *flag);
s21_size_t countLen(unsigned long long num);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif