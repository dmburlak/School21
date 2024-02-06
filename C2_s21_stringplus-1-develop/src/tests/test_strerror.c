#include "suites.h"

#if defined(__APPLE__) || defined(__MACH__)

START_TEST(default_input) {
  char *s21, *actual;
  for (int i = 0; i < 107; i++) {
    s21 = s21_strerror(i);
    actual = strerror(i);
    ck_assert_pstr_eq(actual, s21);
  }
}
END_TEST

#endif

#if defined(__linux__)

START_TEST(default_input) {
  char *s21, *actual;
  for (int i = 0; i < 134; i++) {
    s21 = s21_strerror(i);
    actual = strerror(i);
    ck_assert_pstr_eq(actual, s21);
  }
}
END_TEST

#endif

START_TEST(int_less_zero) {
  int n = -1;
  char *s21 = s21_strerror(n);
  char *actual = strerror(n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(int_greater_limit) {
  int n = 300;
  char *s21 = s21_strerror(n);
  char *actual = strerror(n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

Suite *s21_strerror_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_strerror");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, default_input);
  tcase_add_test(test_case, int_less_zero);
  tcase_add_test(test_case, int_greater_limit);
  suite_add_tcase(suite, test_case);

  return suite;
}