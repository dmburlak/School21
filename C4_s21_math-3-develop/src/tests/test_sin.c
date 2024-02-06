#include "suites.h"

START_TEST(enumeration_integer_values) {
  ck_assert_ldouble_eq_tol(s21_sin(s21_rad(_i)), sin(s21_rad(_i)), S21_EPS);
}
END_TEST

START_TEST(big_value) {
  ck_assert_ldouble_eq_tol(s21_sin(s21_rad(720)), sin(s21_rad(720)), S21_EPS);
}
END_TEST

START_TEST(sin_zero) {
  ck_assert_ldouble_eq_tol(sin(0.0), s21_sin(0.0), S21_EPS);
}
END_TEST

START_TEST(sin_nan) {
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_nan(sin(S21_NAN));
}
END_TEST

START_TEST(sin_inf) {
  ck_assert_ldouble_nan(s21_sin(S21_INF));
  ck_assert_ldouble_nan(sin(S21_INF));
}
END_TEST

START_TEST(sin_inf_negative) {
  ck_assert_ldouble_nan(s21_sin(-S21_INF));
  ck_assert_ldouble_nan(sin(-S21_INF));
}
END_TEST

START_TEST(sin_loop) {
  for (double test = 0.0 + 1e-4; test <= S21_2PI; test += 0.0161573) {
    ck_assert_ldouble_eq_tol(s21_sin(test), sin(test), S21_EPS);
  }
}
END_TEST

START_TEST(over_bound_positive) {
  ck_assert_ldouble_eq_tol(s21_sin(903.0), sin(903.0), S21_EPS);
}
END_TEST

START_TEST(over_bound_negative) {
  ck_assert_ldouble_eq_tol(s21_sin(-553.0), sin(-553.0), S21_EPS);
}
END_TEST

START_TEST(close_to_inbound) {
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI - 1e-5), sin(S21_PI - 1e-5), S21_EPS);
}
END_TEST

START_TEST(close_to_pi_half) {
  ck_assert_ldouble_eq_tol(s21_sin(1.57079633), sin(1.57079633), S21_EPS);
}
END_TEST

Suite *s21_sin_suite() {
  Suite *suite = suite_create("s21_sin");
  TCase *tcase = tcase_create("Core");

  tcase_add_loop_test(tcase, enumeration_integer_values, -90, 90);
  tcase_add_test(tcase, big_value);
  tcase_add_test(tcase, sin_zero);
  tcase_add_test(tcase, sin_nan);
  tcase_add_test(tcase, sin_inf);
  tcase_add_test(tcase, sin_inf_negative);
  tcase_add_test(tcase, sin_loop);
  tcase_add_test(tcase, over_bound_positive);
  tcase_add_test(tcase, over_bound_negative);
  tcase_add_test(tcase, close_to_inbound);
  tcase_add_test(tcase, close_to_pi_half);

  suite_add_tcase(suite, tcase);
  return suite;
}