#include "suites.h"

START_TEST(default_input) {
  char str1[6] = "hello";
  char str2[9] = "12345678";
  size_t n = 5;
  char *s21 = s21_strncpy(str1, str2, n);
  char *actual = strncpy(str1, str2, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(multichar) {
  char str1[30] = "привет?";
  char str2[8] = "пока";
  size_t n = 5;
  char *s21 = s21_strncpy(str1, str2, n);
  char *actual = strncpy(str1, str2, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

// START_TEST(str1_greater_str2) {
//     char str1[12] = "Hello, world";
//     char str2[5] = "hello";
//     size_t n = 12;
//     char *s21 = s21_strncpy(str1, str2, n);
//     char *actual = strncpy(str1, str2, n);
//     ck_assert_pstr_eq(actual, s21);
// }
// END_TEST

// START_TEST(str2_greater_str1) {
//     char str1[5] = "hello";
//     char str2[12] = "Hello, world";
//     size_t n = 12;
//     char *s21 = s21_strncpy(str1, str2, n);
//     char *actual = strncpy(str1, str2, n);
//     ck_assert_pstr_eq(actual, s21);
// }
// END_TEST

START_TEST(empty_str1) {
  char str1[6] = {"\0"};
  char str2[9] = "12345678";
  size_t n = 5;
  char *s21 = s21_strncpy(str1, str2, n);
  char *actual = strncpy(str1, str2, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_str2) {
  char str1[6] = "hello";
  char str2[9] = {"\0"};
  size_t n = 5;
  char *s21 = s21_strncpy(str1, str2, n);
  char *actual = strncpy(str1, str2, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_strings) {
  char str1[6] = {"\0"};
  char str2[9] = {"\0"};
  size_t n = 5;
  char *s21 = s21_strncpy(str1, str2, n);
  char *actual = strncpy(str1, str2, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

// START_TEST(size_greater_str1) {
//     char str1[6] = "hello";
//     char str2[12] = "hello, world";
//     size_t n = 12;
//     char *s21 = s21_strncpy(str1, str2, n);
//     char *actual = strncpy(str1, str2, n);
//     ck_assert_pstr_eq(actual, s21);
// }
// END_TEST

START_TEST(size_equal_zero) {
  char str1[6] = "hello";
  char str2[12] = "hello, world";
  size_t n = 0;
  char *s21 = s21_strncpy(str1, str2, n);
  char *actual = strncpy(str1, str2, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

Suite *s21_strncpy_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_strncpy");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, default_input);
  tcase_add_test(test_case, multichar);
  // tcase_add_test(test_case, str1_greater_str2);
  // tcase_add_test(test_case, str2_greater_str1);
  tcase_add_test(test_case, empty_str1);
  tcase_add_test(test_case, empty_str2);
  tcase_add_test(test_case, empty_strings);
  // tcase_add_test(test_case, size_greater_str1);
  tcase_add_test(test_case, size_equal_zero);
  suite_add_tcase(suite, test_case);

  return suite;
}