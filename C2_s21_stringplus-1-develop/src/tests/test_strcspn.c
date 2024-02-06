#include "suites.h"

START_TEST(default_input) {
  char *str1 = "Hello, world";
  char *str2 = "hello";
  size_t s21 = s21_strcspn(str1, str2);
  size_t actual = strcspn(str1, str2);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(equal_strings) {
  char *str1 = "Hello";
  char *str2 = "Hello";
  size_t s21 = s21_strcspn(str1, str2);
  size_t actual = strcspn(str1, str2);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(str1_empty) {
  char *str1 = {"\0"};
  char *str2 = "hello";
  size_t s21 = s21_strcspn(str1, str2);
  size_t actual = strcspn(str1, str2);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(str2_empty) {
  char *str1 = "hello";
  char *str2 = {"\0"};
  size_t s21 = s21_strcspn(str1, str2);
  size_t actual = strcspn(str1, str2);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(empty_strings) {
  char *str1 = {"\0"};
  char *str2 = {"\0"};
  size_t s21 = s21_strcspn(str1, str2);
  size_t actual = strcspn(str1, str2);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(multichar) {
  char *str1 = "хихихи";
  char *str2 = "хахаха";
  size_t s21 = s21_strcspn(str1, str2);
  size_t actual = strcspn(str1, str2);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(str1_greater_str2) {
  char str1[] = "Hello, world";
  char str2[] = "Hello,";
  size_t s21 = s21_strcspn(str1, str2);
  size_t actual = strcspn(str1, str2);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(str2_greater_str1) {
  char str1[] = "Hello,";
  char str2[] = "Hello, world";
  size_t s21 = s21_strcspn(str1, str2);
  size_t actual = strcspn(str1, str2);
  ck_assert_int_eq(actual, s21);
}
END_TEST

Suite *s21_strcspn_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_strcspn");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, default_input);
  tcase_add_test(test_case, equal_strings);
  tcase_add_test(test_case, str1_empty);
  tcase_add_test(test_case, str2_empty);
  tcase_add_test(test_case, empty_strings);
  tcase_add_test(test_case, multichar);
  tcase_add_test(test_case, str1_greater_str2);
  tcase_add_test(test_case, str2_greater_str1);

  suite_add_tcase(suite, test_case);

  return suite;
}