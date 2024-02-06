#include "suites.h"

START_TEST(first_char) {
  char *str = "hello";
  char c = 'h';
  char *s21 = s21_strrchr(str, c);
  char *actual = strrchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(last_char) {
  char *str = "hello";
  char c = 'o';
  char *s21 = s21_strrchr(str, c);
  char *actual = strrchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(double_char) {
  char *str = "hello";
  char c = 'l';
  char *s21 = s21_strrchr(str, c);
  char *actual = strrchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_char) {
  char *str = "hello";
  char c = '\0';
  char *s21 = s21_strrchr(str, c);
  char *actual = strrchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_str) {
  char *str = "\0";
  char c = 'v';
  char *s21 = s21_strrchr(str, c);
  char *actual = strrchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_elems) {
  char *str = "\0";
  char c = '\0';
  char *s21 = s21_strrchr(str, c);
  char *actual = strrchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(char_equal_space) {
  char *str = "hello, world";
  char c = ' ';
  char *s21 = s21_strrchr(str, c);
  char *actual = strrchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(char_equal_space_empty_str) {
  char *str = "\0";
  char c = ' ';
  char *s21 = s21_strrchr(str, c);
  char *actual = strrchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(char_equal_zero) {
  char *str = "hello";
  char c = 0;
  char *s21 = s21_strrchr(str, c);
  char *actual = strrchr(str, c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

Suite *s21_strrchr_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_strrchr");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, first_char);
  tcase_add_test(test_case, last_char);
  tcase_add_test(test_case, double_char);
  tcase_add_test(test_case, empty_char);
  tcase_add_test(test_case, empty_str);
  tcase_add_test(test_case, empty_elems);
  tcase_add_test(test_case, char_equal_space);
  tcase_add_test(test_case, char_equal_space_empty_str);
  tcase_add_test(test_case, char_equal_zero);
  suite_add_tcase(suite, test_case);

  return suite;
}