#include "suites.h"

// START_TEST(default_input) {
//     char str1[10] = "hello";
//     char str2[30] = "12345";
//     int n = 4;
//     char *s21 = strncat(str1, str2, n);
//     char *actual = strncat(str1, str2, n);
//     ck_assert_pstr_eq(actual, s21);
// }
// END_TEST

// START_TEST(empty_str1) {
//     char str1[10] = {"\0"};
//     char str2[30] = "12345";
//     int n = 5;
//     char *s21 = s21_strncat(str1, str2, n);
//     char *actual = strncat(str1, str2, n);
//     ck_assert_pstr_eq(actual, s21);
// }
// END_TEST

START_TEST(empty_str2) {
  char str1[10] = "hello";
  char str2[30] = {"\0"};
  int n = 5;
  char *s21 = s21_strncat(str1, str2, n);
  char *actual = strncat(str1, str2, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_strings) {
  char str1[10] = {"\0"};
  char str2[30] = {"\0"};
  int n = 5;
  char *s21 = s21_strncat(str1, str2, n);
  char *actual = strncat(str1, str2, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

// START_TEST(size_greater_str1) {
//     char str1[6] = "hello";
//     char str2[30] = "Hello, world!";
//     int n = 10;
//     char *s21 = s21_strncat(str1, str2, n);
//     char *actual = strncat(str1, str2, n);
//     ck_assert_pstr_eq(actual, s21);
// }
// END_TEST

START_TEST(size_equal_zero) {
  char str1[6] = "hello";
  char str2[30] = "Hello, world!";
  int n = 0;
  char *s21 = s21_strncat(str1, str2, n);
  char *actual = strncat(str1, str2, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

Suite *s21_strncat_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_strncat");
  test_case = tcase_create("Core");
  // tcase_add_test(test_case, default_input);
  // tcase_add_test(test_case, empty_str1);
  tcase_add_test(test_case, empty_str2);
  tcase_add_test(test_case, empty_strings);
  // tcase_add_test(test_case, size_greater_str1);
  tcase_add_test(test_case, size_equal_zero);
  suite_add_tcase(suite, test_case);

  return suite;
}