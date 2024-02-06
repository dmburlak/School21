#include "suites.h"

START_TEST(default_input) {
  char *str1 = "Hello, world";
  char *str2 = "e";
  char *s21 = s21_strpbrk(str1, str2);
  char *actual = strpbrk(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(multichar) {
  char *str1 = "привет, мир";
  char *str2 = "вет";
  char *s21 = s21_strpbrk(str1, str2);
  char *actual = strpbrk(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(double_char) {
  char *str1 = "Hello, world";
  char *str2 = "l";
  char *s21 = s21_strpbrk(str1, str2);
  char *actual = strpbrk(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_str1) {
  char str1[10] = {"\0"};
  char str2[10] = "Hello";
  char *s21 = s21_strpbrk(str1, str2);
  char *actual = strpbrk(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_str2) {
  char str1[10] = "Hello";
  char str2[10] = {"\0"};
  char *s21 = s21_strpbrk(str1, str2);
  char *actual = strpbrk(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_strings) {
  char str1[10] = {"\0"};
  char str2[10] = {"\0"};
  char *s21 = s21_strpbrk(str1, str2);
  char *actual = strpbrk(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(no_match) {
  char str1[12] = "Hello, world";
  char str2[5] = "12345";
  char *s21 = s21_strpbrk(str1, str2);
  char *actual = strpbrk(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}

Suite *s21_strpbrk_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_strpbrk");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, default_input);
  tcase_add_test(test_case, multichar);
  tcase_add_test(test_case, double_char);
  tcase_add_test(test_case, empty_str1);
  tcase_add_test(test_case, empty_str2);
  tcase_add_test(test_case, empty_strings);
  tcase_add_test(test_case, no_match);
  suite_add_tcase(suite, test_case);

  return suite;
}