#include "suites.h"

START_TEST(full_filling) {
  char str[10] = "hello";
  int n = 10;
  char *s21 = s21_memset(str, 'v', n);
  char *actual = memset(str, 'v', n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(half_filling) {
  char str[5] = "hello";
  int n = 2;
  char *s21 = s21_memset(str, 'v', n);
  char *actual = memset(str, 'v', n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(pointer_filling) {
  int n = 10;
  char *str = malloc(n * sizeof(char));
  char *s21 = s21_memset(str, 0, n);
  char *actual = memset(str, 0, n);
  ck_assert_pstr_eq(actual, s21);
  free(str);
}
END_TEST

START_TEST(filling_zero) {
  char str[10] = "hello";
  int n = 10;
  char *s21 = s21_memset(str, 0, n);
  char *actual = memset(str, 0, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(filling_less_zero) {
  char str[10] = "hello";
  int n = 10;
  char *s21 = s21_memset(str, -1, n);
  char *actual = memset(str, -1, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

Suite *s21_memset_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_memset");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, full_filling);
  tcase_add_test(test_case, half_filling);
  tcase_add_test(test_case, pointer_filling);
  tcase_add_test(test_case, filling_zero);
  tcase_add_test(test_case, filling_less_zero);
  suite_add_tcase(suite, test_case);

  return suite;
}