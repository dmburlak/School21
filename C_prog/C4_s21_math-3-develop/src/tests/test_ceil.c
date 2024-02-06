#include "suites.h"

START_TEST(default_input) {
  ck_assert_ldouble_eq_tol(s21_ceil(12.99), ceil(12.99), S21_EPS);
}
END_TEST

START_TEST(value_less_zero) {
  ck_assert_ldouble_eq_tol(s21_ceil(-12.0009), ceil(-12.0009), S21_EPS);
}
END_TEST

START_TEST(value_eq_zero) {
  ck_assert_ldouble_eq_tol(s21_ceil(0.0), ceil(0.0), S21_EPS);
}
END_TEST

START_TEST(value_eq_int) {
  ck_assert_ldouble_eq_tol(s21_ceil(15), ceil(15), S21_EPS);
}
END_TEST

START_TEST(value_eq_int_less_zero) {
  ck_assert_ldouble_eq_tol(s21_ceil(-15), ceil(-15), S21_EPS);
}
END_TEST

Suite *s21_ceil_suite() {
  Suite *suite = suite_create("s21_ceil");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, default_input);
  tcase_add_test(tcase, value_less_zero);
  tcase_add_test(tcase, value_eq_zero);
  tcase_add_test(tcase, value_eq_int);
  tcase_add_test(tcase, value_eq_int_less_zero);
  suite_add_tcase(suite, tcase);
  return suite;
}