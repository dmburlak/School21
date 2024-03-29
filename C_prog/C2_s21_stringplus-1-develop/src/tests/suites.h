#ifndef SUITE_H
#define SUITE_H

#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite *s21_memchr_suite();
Suite *s21_memcmp_suite();
Suite *s21_memcpy_suite();
Suite *s21_memset_suite();
Suite *s21_strncat_suite();
Suite *s21_strchr_suite();
Suite *s21_strncmp_suite();
Suite *s21_strncpy_suite();
Suite *s21_strcspn_suite();
Suite *s21_strerror_suite();
Suite *s21_strlen_suite();
Suite *s21_strpbrk_suite();
Suite *s21_strrchr_suite();
Suite *s21_strstr_suite();
Suite *s21_strtok_suite();
Suite *s21_sprintf_suite();
Suite *s21_to_lower_suite();
Suite *s21_to_upper_suite();
Suite *s21_trim_suite();
Suite *s21_insert_suite();

#endif