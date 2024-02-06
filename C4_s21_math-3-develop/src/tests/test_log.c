#include "suites.h"

START_TEST(neg_inf_res) {
  long double s21 = s21_log(0.0);
  long double actual = log(0.0);

  ck_assert_ldouble_infinite(actual);
  ck_assert_ldouble_infinite(s21);
}
END_TEST

START_TEST(nan_res) {
  long double s21 = s21_log(_i);
  long double actual = log(_i);

  ck_assert_ldouble_nan(actual);
  ck_assert_ldouble_nan(s21);
}
END_TEST

START_TEST(x_equal_1) {
  ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), S21_EPS);
}
END_TEST

START_TEST(x_equal_inf) {
  long double s21 = s21_log(S21_INF);
  long double actual = log(S21_INF);

  ck_assert_ldouble_infinite(actual);
  ck_assert_ldouble_infinite(s21);
}
END_TEST

START_TEST(ex_x) {
  ck_assert_ldouble_eq_tol(s21_log(S21_PI / 5), log(S21_PI / 5), S21_EPS);
}
END_TEST

START_TEST(int_x) { ck_assert_ldouble_eq_tol(s21_log(_i), log(_i), S21_EPS); }
END_TEST

START_TEST(double_x) {
  for (double i = 5.4954245; i < 8.34243254; i += 0.5) {
    ck_assert_ldouble_eq_tol(s21_log(i), log(i), S21_EPS);
  }
}
END_TEST

Suite *s21_log_suite() {
  Suite *suite = suite_create("s21_log");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, neg_inf_res);
  tcase_add_test(tcase, x_equal_1);
  tcase_add_test(tcase, x_equal_inf);
  tcase_add_loop_test(tcase, nan_res, -10.0, -1.0);
  tcase_add_test(tcase, ex_x);
  tcase_add_loop_test(tcase, int_x, 2.0, 10.0);
  tcase_add_test(tcase, double_x);

  suite_add_tcase(suite, tcase);
  return suite;
}