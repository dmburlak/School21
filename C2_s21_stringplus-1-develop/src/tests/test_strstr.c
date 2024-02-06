#include "suites.h"

START_TEST(default_input) {
  char *str1 = "hello, world";
  char *str2 = "world";
  char *s21 = s21_strstr(str1, str2);
  char *actual = strstr(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(char_input) {
  char *str1 = "hello, world";
  char *str2 = "w";
  char *s21 = s21_strstr(str1, str2);
  char *actual = strstr(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(multichar) {
  char *str1 = "привет, мир";
  char *str2 = "вет";
  char *s21 = s21_strstr(str1, str2);
  char *actual = strstr(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(no_match) {
  char *str1 = "hello, world";
  char *str2 = "1234";
  char *s21 = s21_strstr(str1, str2);
  char *actual = strstr(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_str1) {
  char str1[5] = {"\0"};
  char str2[5] = "12345";
  char *s21 = s21_strstr(str1, str2);
  char *actual = strstr(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_str2) {
  char str1[5] = "hello";
  char str2[5] = {"\0"};
  char *s21 = s21_strstr(str1, str2);
  char *actual = strstr(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_strings) {
  char str1[5] = {"\0"};
  char str2[5] = {"\0"};
  char *s21 = s21_strstr(str1, str2);
  char *actual = strstr(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(str1_greater_str2) {
  char str1[12] = "hello, world";
  char str2[5] = "hello";
  char *s21 = s21_strstr(str1, str2);
  char *actual = strstr(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(str2_greater_str1) {
  char str1[5] = "hello";
  char str2[12] = "hello, world";
  char *s21 = s21_strstr(str1, str2);
  char *actual = strstr(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(strings_equal) {
  char str1[12] = "Hello, world";
  char str2[12] = "Hello, world";
  char *s21 = s21_strstr(str1, str2);
  char *actual = strstr(str1, str2);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

Suite *s21_strstr_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_strstr");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, default_input);
  tcase_add_test(test_case, char_input);
  tcase_add_test(test_case, multichar);
  tcase_add_test(test_case, no_match);
  tcase_add_test(test_case, empty_str1);
  tcase_add_test(test_case, empty_str2);
  tcase_add_test(test_case, empty_strings);
  tcase_add_test(test_case, str1_greater_str2);
  tcase_add_test(test_case, str2_greater_str1);
  tcase_add_test(test_case, strings_equal);
  suite_add_tcase(suite, test_case);

  return suite;
}