#include "suites.h"

START_TEST(default_input) {
  ck_assert_ldouble_eq_tol(s21_sqrt(25), sqrt(25), S21_EPS);
}
END_TEST

START_TEST(value_eq_zero) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0.0), sqrt(0.0), S21_EPS);
}
END_TEST

START_TEST(value_less_zero) {
  ck_assert_ldouble_nan(s21_sqrt(-12));
  ck_assert_ldouble_nan(sqrt(-12));
}
END_TEST

START_TEST(value_less_1) {
  ck_assert_ldouble_eq_tol(sqrt(0.4), s21_sqrt(0.4), S21_EPS);
}
END_TEST

START_TEST(sqrt_INFINITY) {
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF));
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF));
}
END_TEST

START_TEST(sqrt_neg_INFINITY) {
  ck_assert_ldouble_nan(s21_sqrt(-S21_INF));
  ck_assert_ldouble_nan(sqrt(-S21_INF));
}
END_TEST

START_TEST(sqrt_NAN) {
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
}
END_TEST

START_TEST(sqrt_float_loop) {
  for (double test = 0.0; test < 15; test += 0.10649355) {
    long double S21 = s21_sqrt(test);
    long double actual = sqrt(test);

    ck_assert_ldouble_eq_tol(S21, actual, S21_EPS);
  }
}
END_TEST

START_TEST(sqrt_whole_loop) {
  for (double test = 0.0; test < 700; test += 2) {
    long double S21 = s21_sqrt(test);
    long double actual = sqrt(test);

    ck_assert_ldouble_eq_tol(S21, actual, S21_EPS);
  }
}
END_TEST

START_TEST(sqrt_large_float_loop) {
  for (double test = 0.0; test < 2107483610; test += 949355.07241564963) {
    long double S21 = s21_sqrt(test);
    long double actual = sqrt(test);

    ck_assert_ldouble_eq_tol(S21, actual, S21_EPS);
  }
}
END_TEST

START_TEST(sqrt_small_float_loop) {
  for (double test = 0.0; test < 1; test += 0.0007241564963) {
    long double S21 = s21_sqrt(test);
    long double actual = sqrt(test);

    ck_assert_ldouble_eq_tol(S21, actual, S21_EPS);
  }
}
END_TEST

Suite *s21_sqrt_suite() {
  Suite *suite = suite_create("s21_sqrt");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, default_input);
  tcase_add_test(tcase, value_eq_zero);
  tcase_add_test(tcase, value_less_zero);
  tcase_add_test(tcase, value_less_1);
  tcase_add_test(tcase, sqrt_INFINITY);
  tcase_add_test(tcase, sqrt_neg_INFINITY);
  tcase_add_test(tcase, sqrt_NAN);
  tcase_add_test(tcase, sqrt_float_loop);
  tcase_add_test(tcase, sqrt_whole_loop);
  tcase_add_test(tcase, sqrt_large_float_loop);
  tcase_add_test(tcase, sqrt_small_float_loop);

  suite_add_tcase(suite, tcase);
  return suite;
}