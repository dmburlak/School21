#include "suites.h"
START_TEST(enumeration_integer_values) {
  ck_assert_ldouble_eq_tol(s21_asin(s21_rad(_i)), asin(s21_rad(_i)), S21_EPS);
}
END_TEST

START_TEST(big_value) {
  ck_assert_ldouble_nan(s21_asin(720));
  ck_assert_ldouble_nan(asin(720));
}
END_TEST

START_TEST(asin_nan) {
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_nan(asin(S21_NAN));
}
END_TEST

START_TEST(asin_inf) {
  ck_assert_ldouble_nan(s21_asin(S21_INF));
  ck_assert_ldouble_nan(asin(S21_INF));
}
END_TEST

START_TEST(asin_inf_negative) {
  ck_assert_ldouble_nan(s21_asin(-S21_INF));
  ck_assert_ldouble_nan(asin(-S21_INF));
}
END_TEST

START_TEST(over_bound_positive) {
  ck_assert_ldouble_nan(s21_asin(903.3));
  ck_assert_ldouble_nan(asin(903.3));
}
END_TEST

START_TEST(over_bound_negative) {
  ck_assert_ldouble_nan(s21_asin(-903.3));
  ck_assert_ldouble_nan(asin(-903.3));
}
END_TEST

START_TEST(pi_4) {
  ck_assert_ldouble_eq_tol(asin(S21_PI / 4), s21_asin(S21_PI / 4), S21_EPS);
}
END_TEST

START_TEST(x_eq_1) {
  ck_assert_ldouble_eq_tol(asin(1.0), s21_asin(1.0), S21_EPS);
}
END_TEST

START_TEST(x_eq_1_less_zero) {
  ck_assert_ldouble_eq_tol(asin(-1.0), s21_asin(-1.0), S21_EPS);
}
END_TEST

Suite *s21_asin_suite() {
  Suite *suite = suite_create("s21_asin");
  TCase *tcase = tcase_create("Core");

  tcase_add_loop_test(tcase, enumeration_integer_values, -10, 10);
  tcase_add_test(tcase, big_value);

  tcase_add_test(tcase, asin_nan);
  tcase_add_test(tcase, asin_inf);
  tcase_add_test(tcase, asin_inf_negative);
  tcase_add_test(tcase, over_bound_positive);
  tcase_add_test(tcase, over_bound_negative);
  tcase_add_test(tcase, pi_4);
  tcase_add_test(tcase, x_eq_1);
  tcase_add_test(tcase, x_eq_1_less_zero);

  suite_add_tcase(suite, tcase);
  return suite;
}