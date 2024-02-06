#include "suites.h"

START_TEST(default_string) {
  const char *str = "Hello, world";
  size_t s21 = s21_strlen(str);
  size_t actual = strlen(str);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(empty_string) {
  const char str[10] = {"\0"};
  size_t s21 = s21_strlen(str);
  size_t actual = strlen(str);
  ck_assert_int_eq(actual, s21);
}
END_TEST

START_TEST(multichar_string) {
  const char str[] = "Хихихи, хахаха";
  size_t s21 = s21_strlen(str);
  size_t actual = strlen(str);
  ck_assert_int_eq(actual, s21);
}
END_TEST

Suite *s21_strlen_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_strlen");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, default_string);
  tcase_add_test(test_case, empty_string);
  tcase_add_test(test_case, multichar_string);
  suite_add_tcase(suite, test_case);

  return suite;
}