#include "suites.h"

START_TEST(default_input) {
  const char *str = "Hello, world";
  char *s21 = s21_memchr(str, 'l', s21_strlen(str));
  char *actual = memchr(str, 'l', strlen(str));
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_str) {
  const char str[] = {"\0"};
  char *s21 = s21_memchr(str, 'o', 5);
  char *actual = memchr(str, 'o', 5);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(non_exist) {
  const char *str = "Hello, world";
  char *s21 = s21_memchr(str, 'n', s21_strlen(str));
  char *actual = memchr(str, 'n', strlen(str));
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(without_size) {
  const char *str = "Hello, world";
  char *s21 = s21_memchr(str, 'w', 0);
  char *actual = memchr(str, 'w', 0);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(size_equal_1) {
  const char *str = "Hello";
  char *s21 = s21_memchr(str, 'H', 1);
  char *actual = memchr(str, 'H', 1);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(non_exist_size_greater) {
  const char *str = "Hello, world";
  char *s21 = s21_memchr(str, 'b', 20);
  char *actual = memchr(str, 'b', 20);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(overflow) {
  const char *str = "Hello";
  char *s21 = s21_memchr(str, -33320, 5);
  char *actual = memchr(str, -33320, 5);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(size_greater_str) {
  const char str[4] = "hihi";
  char *s21 = s21_memchr(str, 'h', 5);
  char *actual = memchr(str, 'h', 5);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(size_less_0) {
  const char str[5] = "hello";
  char *s21 = s21_memchr(str, 'o', -10);
  char *actual = s21_memchr(str, 'o', -10);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

Suite *s21_memchr_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_memchr");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, default_input);
  tcase_add_test(test_case, empty_str);
  tcase_add_test(test_case, non_exist);
  tcase_add_test(test_case, without_size);
  tcase_add_test(test_case, size_equal_1);
  tcase_add_test(test_case, non_exist_size_greater);
  tcase_add_test(test_case, overflow);
  tcase_add_test(test_case, size_greater_str);
  tcase_add_test(test_case, size_less_0);
  suite_add_tcase(suite, test_case);

  return suite;
}
