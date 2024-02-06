#include "suites.h"

START_TEST(default_input) {
  const char *str1 = "hello";
  const char *str2 = "helLo";
  size_t n = 5;
  int s21 = s21_memcmp(str1, str2, n);
  int actual = memcmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(multichar) {
  const char *str1 = "Хохохоо";
  const char *str2 = "Хехехех";
  size_t n = 5;
  int s21 = s21_memcmp(str1, str2, n);
  int actual = memcmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(empty_str1) {
  const char *str1 = "\0";
  const char *str2 = "hello";
  size_t n = 5;
  int s21 = s21_memcmp(str1, str2, n);
  int actual = memcmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}

START_TEST(empty_str2) {
  const char *str1 = "hello";
  const char *str2 = "\0";
  size_t n = 5;
  int s21 = s21_memcmp(str1, str2, n);
  int actual = memcmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(empty_strings) {
  const char *str1 = {"\0"};
  const char *str2 = {"\0"};
  size_t n = 5;
  int s21 = s21_memcmp(str1, str2, n);
  int actual = memcmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(str1_greater_str2) {
  const char *str1 = "hello!";
  const char *str2 = "hi";
  size_t n = 20;
  int s21 = s21_memcmp(str1, str2, n);
  int actual = memcmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(str2_greater_str1) {
  const char *str1 = "hi";
  const char *str2 = "hello!";
  size_t n = 20;
  int s21 = s21_memcmp(str1, str2, n);
  int actual = memcmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(size_greater) {
  const char *str1 = "hello";
  const char *str2 = "hello";
  size_t n = 10;
  int s21 = s21_memcmp(str1, str2, n);
  int actual = memcmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(size_equal_0) {
  const char *str1 = "hello";
  const char *str2 = "world";
  size_t n = 0;
  int s21 = s21_memcmp(str1, str2, n);
  int actual = memcmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(size_less_0) {
  const char *str1 = "hello";
  const char *str2 = "world";
  size_t n = -10;
  int s21 = s21_memcmp(str1, str2, n);
  int actual = memcmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

Suite *s21_memcmp_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_memcmp");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, default_input);
  tcase_add_test(test_case, multichar);
  tcase_add_test(test_case, empty_str1);
  tcase_add_test(test_case, empty_str2);
  tcase_add_test(test_case, empty_strings);
  tcase_add_test(test_case, str1_greater_str2);
  tcase_add_test(test_case, str2_greater_str1);
  tcase_add_test(test_case, size_greater);
  tcase_add_test(test_case, size_equal_0);
  tcase_add_test(test_case, size_less_0);
  suite_add_tcase(suite, test_case);

  return suite;
}