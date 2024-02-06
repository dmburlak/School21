#include "suites.h"

START_TEST(x_less_zero) {
  ck_assert_ldouble_eq_tol(s21_exp(_i), exp(_i), S21_EPS);
}
END_TEST

START_TEST(x_upper_zero) {
  ck_assert_ldouble_eq_tol(s21_exp(_i), exp(_i), S21_EPS);
}
END_TEST

START_TEST(x_equal_zero) {
  ck_assert_ldouble_eq_tol(s21_exp(0.0), exp(0.0), S21_EPS);
}
END_TEST

START_TEST(nan_test) {
  long double s21 = s21_exp(S21_NAN);
  long double actual = exp(S21_NAN);

  ck_assert_ldouble_nan(actual);
  ck_assert_ldouble_nan(s21);
}
END_TEST

START_TEST(infinity_test) {
  long double s21 = s21_exp(S21_INF);
  long double actual = exp(S21_INF);

  ck_assert_ldouble_infinite(s21);
  ck_assert_ldouble_infinite(actual);
}
END_TEST

START_TEST(exp_big_positive) {
  long double s21 = s21_exp(9999999);
  long double actual = exp(9999999);

  ck_assert_ldouble_infinite(actual);
  ck_assert_ldouble_infinite(s21);
}
END_TEST

START_TEST(exp_big_negative_test) {
  ck_assert_ldouble_eq_tol(s21_exp(-1000000), exp(-1000000), S21_EPS);
}
END_TEST

Suite *s21_exp_suite() {
  Suite *suite = suite_create("s21_exp");
  TCase *tcase = tcase_create("Core");

  tcase_add_loop_test(tcase, x_less_zero, -5.0, -1.0);
  tcase_add_loop_test(tcase, x_upper_zero, 1.0, 5.0);
  tcase_add_test(tcase, x_equal_zero);
  tcase_add_test(tcase, nan_test);
  tcase_add_test(tcase, infinity_test);
  tcase_add_test(tcase, exp_big_positive);
  tcase_add_test(tcase, exp_big_negative_test);

  suite_add_tcase(suite, tcase);
  return suite;
}
