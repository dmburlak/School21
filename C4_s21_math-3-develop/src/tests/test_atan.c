#include "suites.h"

START_TEST(enumeration_integer_values) {
  ck_assert_ldouble_eq_tol(s21_atan(s21_rad(_i)), atan(s21_rad(_i)), S21_EPS);
}
END_TEST

START_TEST(big_value) {
  ck_assert_ldouble_eq_tol(s21_atan(s21_rad(720)), atan(s21_rad(720)), S21_EPS);
}
END_TEST

START_TEST(atan_nan) {
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_nan(atan(S21_NAN));
}
END_TEST

START_TEST(atan_inf) {
  ck_assert_ldouble_eq_tol(atan(S21_INF), s21_atan(S21_INF), S21_EPS);
}
END_TEST

START_TEST(atan_inf_negative) {
  ck_assert_ldouble_eq_tol(atan(-S21_INF), s21_atan(-S21_INF), S21_EPS);
}
END_TEST

START_TEST(over_bound_positive) {
  ck_assert_ldouble_eq_tol(s21_atan(903.0), atan(903.0), S21_EPS);
}
END_TEST

START_TEST(over_bound_negative) {
  ck_assert_ldouble_eq_tol(s21_atan(-903.3), atan(-903.3), S21_EPS);
}
END_TEST

START_TEST(close_to_inbound) {
  ck_assert_ldouble_eq_tol(s21_atan(S21_PI - 1e-5), atan(S21_PI - 1e-5),
                           S21_EPS);
}
END_TEST

START_TEST(close_to_pi_half) {
  ck_assert_ldouble_eq_tol(s21_atan(1.57079633), atan(1.57079633), S21_EPS);
}
END_TEST

START_TEST(pi_4) {
  ck_assert_ldouble_eq_tol(atan(S21_PI / 4), s21_atan(S21_PI / 4), S21_EPS);
}
END_TEST

Suite *s21_atan_suite() {
  Suite *suite = suite_create("s21_atan");
  TCase *tcase = tcase_create("Core");

  tcase_add_loop_test(tcase, enumeration_integer_values, -10, 10);
  tcase_add_test(tcase, big_value);
  tcase_add_test(tcase, atan_nan);
  tcase_add_test(tcase, atan_inf);
  tcase_add_test(tcase, atan_inf_negative);
  tcase_add_test(tcase, over_bound_positive);
  tcase_add_test(tcase, over_bound_negative);
  tcase_add_test(tcase, close_to_inbound);
  tcase_add_test(tcase, close_to_pi_half);
  tcase_add_test(tcase, pi_4);
  suite_add_tcase(suite, tcase);
  return suite;
}