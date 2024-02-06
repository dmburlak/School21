#include "suites.h"

START_TEST(two_letters) {
  char *str = "hello";
  char c = 'l';
  char *s21 = s21_strchr(str, c);
  char *actual = strchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(first_input) {
  char *str = "hello";
  char c = 'h';
  char *s21 = s21_strchr(str, c);
  char *actual = strchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(non_exist_char) {
  char *str = "hello";
  char c = 'v';
  char *s21 = s21_strchr(str, c);
  char *actual = strchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_str) {
  char *str = {"\0"};
  char c = 'v';
  char *s21 = s21_strchr(str, c);
  char *actual = strchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_char) {
  char *str = "hello";
  char c = '\0';
  char *s21 = s21_strchr(str, c);
  char *actual = strchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(char_equal_zero) {
  char *str = "hello";
  char c = 0;
  char *s21 = s21_strchr(str, c);
  char *actual = strchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(char_less_zero) {
  char *str = "hello";
  char c = -1;
  char *s21 = s21_strchr(str, c);
  char *actual = strchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(overflow) {
  char str[10] = "hello";
  int c = -33000;
  char *s21 = s21_strchr(str, c);
  char *actual = strchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

Suite *s21_strchr_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_strchr");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, two_letters);
  tcase_add_test(test_case, first_input);
  tcase_add_test(test_case, non_exist_char);
  tcase_add_test(test_case, empty_str);
  tcase_add_test(test_case, empty_char);
  tcase_add_test(test_case, char_equal_zero);
  tcase_add_test(test_case, char_less_zero);
  tcase_add_test(test_case, overflow);
  suite_add_tcase(suite, test_case);

  return suite;
}