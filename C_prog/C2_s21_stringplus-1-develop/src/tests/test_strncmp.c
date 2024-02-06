#include "suites.h"

START_TEST(equal_strings) {
  char *str1 = "abcde";
  char *str2 = "abcde";
  int n = 6;
  int s21 = s21_strncmp(str1, str2, n);
  int actual = strncmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(multichar) {
  char *str1 = "абвгдЁ";
  char *str2 = "абвгде";
  int n = 6;
  int s21 = s21_strncmp(str1, str2, n);
  int actual = strncmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(empty_str1) {
  char *str1 = {"\0"};
  char *str2 = "abcde";
  int n = 6;
  int s21 = s21_strncmp(str1, str2, n);
  int actual = strncmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(empty_str2) {
  char *str1 = "abcde";
  char *str2 = {"\0"};
  int n = 6;
  int s21 = s21_strncmp(str1, str2, n);
  int actual = strncmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(empty_strings) {
  char *str1 = {"\0"};
  char *str2 = {"\0"};
  int n = 6;
  int s21 = s21_strncmp(str1, str2, n);
  int actual = strncmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(str1_greater_str2) {
  char str1[] = "Hello, world";
  char str2[] = "Hello";
  int s21 = s21_strncmp(str1, str2, s21_strlen(str1));
  int actual = strncmp(str1, str2, strlen(str1));
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(str2_greater_str1) {
  char str1[] = "Hello";
  char str2[] = "Hello, world";
  int s21 = s21_strncmp(str1, str2, s21_strlen(str2));
  int actual = strncmp(str1, str2, strlen(str2));
  ck_assert_int_eq(actual, s21);
}
END_TEST

// START_TEST(size_greater_strings) {
//     char str1[12] = "Hello, world";
//     char str2[12] = "Hello, world";
//     int n = 20;
//     int s21 = s21_strncmp(str1, str2, n);
//     int actual = strncmp(str1, str2, n);
//     ck_assert_int_eq(actual, s21);
// }
// END_TEST

START_TEST(size_equal_zero) {
  char str1[12] = "Hello, world";
  char str2[12] = "Hello, world";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int actual = strncmp(str1, str2, n);
  ck_assert_int_eq(actual, s21);
}
END_TEST

// START_TEST(size_less_zero) {
//     char str1[12] = "Hello, world";
//     char str2[12] = "Hello, world";
//     int n = -10;
//     int s21 = s21_strncmp(str1, str2, n);
//     int actual = strncmp(str1, str2, n);
//     ck_assert_int_eq(actual, s21);
// }
// END_TEST

Suite *s21_strncmp_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_strncmp");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, equal_strings);
  tcase_add_test(test_case, empty_str1);
  tcase_add_test(test_case, empty_str2);
  tcase_add_test(test_case, multichar);
  tcase_add_test(test_case, empty_strings);
  tcase_add_test(test_case, str1_greater_str2);
  tcase_add_test(test_case, str2_greater_str1);
  // tcase_add_test(test_case, size_greater_strings);
  tcase_add_test(test_case, size_equal_zero);
  // tcase_add_test(test_case, size_less_zero);
  suite_add_tcase(suite, test_case);

  return suite;
}