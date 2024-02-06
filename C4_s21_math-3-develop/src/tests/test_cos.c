#include "suites.h"

START_TEST(enumeration_integer_values) {
  ck_assert_ldouble_eq_tol(s21_cos(s21_rad(_i)), cos(s21_rad(_i)), S21_EPS);
}
END_TEST

START_TEST(cos_zero) {
  ck_assert_ldouble_eq_tol(sin(0.0), s21_sin(0.0), S21_EPS);
}
END_TEST

START_TEST(cos_2pi) {
  ck_assert_ldouble_eq_tol(s21_cos(S21_2PI), s21_cos(S21_2PI), S21_EPS);
}
END_TEST

START_TEST(cos_pi) {
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI), cos(S21_PI), S21_EPS);
}
END_TEST

START_TEST(cos_nan) {
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_nan(cos(S21_NAN));
}
END_TEST

START_TEST(cos_inf) {
  ck_assert_ldouble_nan(s21_cos(S21_INF));
  ck_assert_ldouble_nan(cos(S21_INF));
}
END_TEST

START_TEST(cos_inf_negative) {
  ck_assert_ldouble_nan(s21_cos(-S21_INF));
  ck_assert_ldouble_nan(cos(-S21_INF));
}
END_TEST

START_TEST(cos_loop) {
  for (double test = 0.0 + 1e-4; test <= S21_2PI; test += 0.0161573) {
    ck_assert_ldouble_eq_tol(s21_cos(test), cos(test), S21_EPS);
  }
}
END_TEST

START_TEST(over_bound_positive) {
  ck_assert_ldouble_eq_tol(s21_cos(903.0), cos(903.0), S21_EPS);
}
END_TEST

START_TEST(over_bound_negative) {
  ck_assert_ldouble_eq_tol(s21_cos(-553.0), cos(-553.0), S21_EPS);
}
END_TEST

START_TEST(close_to_inbound) {
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI - 1e-5), cos(S21_PI - 1e-5), S21_EPS);
}
END_TEST

START_TEST(close_to_pi_half) {
  ck_assert_ldouble_eq_tol(s21_cos(1.57079633), cos(1.57079633), S21_EPS);
}
END_TEST

Suite *s21_cos_suite() {
  Suite *suite = suite_create("s21_cos");
  TCase *tcase = tcase_create("Core");

  tcase_add_loop_test(tcase, enumeration_integer_values, -90, 90);
  tcase_add_test(tcase, cos_zero);
  tcase_add_test(tcase, cos_2pi);
  tcase_add_test(tcase, cos_pi);
  tcase_add_test(tcase, cos_nan);
  tcase_add_test(tcase, cos_inf);
  tcase_add_test(tcase, cos_inf_negative);
  tcase_add_test(tcase, cos_loop);
  tcase_add_test(tcase, over_bound_positive);
  tcase_add_test(tcase, over_bound_negative);
  tcase_add_test(tcase, close_to_inbound);
  tcase_add_test(tcase, close_to_pi_half);

  suite_add_tcase(suite, tcase);
  return suite;
}