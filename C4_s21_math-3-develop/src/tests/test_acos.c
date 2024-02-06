#include "suites.h"

START_TEST(enumeration_integer_values) {
  ck_assert_ldouble_eq_tol(s21_acos(s21_rad(_i)), acos(s21_rad(_i)), S21_EPS);
}
END_TEST

START_TEST(big_value) {
  ck_assert_ldouble_nan(s21_acos(720));
  ck_assert_ldouble_nan(acos(720));
}
END_TEST

START_TEST(acos_nan) {
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_nan(acos(S21_NAN));
}
END_TEST

START_TEST(acos_inf) {
  ck_assert_ldouble_nan(s21_acos(S21_INF));
  ck_assert_ldouble_nan(acos(S21_INF));
}
END_TEST

START_TEST(acos_inf_negative) {
  ck_assert_ldouble_nan(s21_acos(-S21_INF));
  ck_assert_ldouble_nan(acos(-S21_INF));
}
END_TEST

START_TEST(over_bound_positive) {
  ck_assert_ldouble_nan(s21_acos(903.3));
  ck_assert_ldouble_nan(acos(903.3));
}
END_TEST

START_TEST(over_bound_negative) {
  ck_assert_ldouble_nan(s21_acos(-903.3));
  ck_assert_ldouble_nan(acos(-903.3));
}
END_TEST

START_TEST(pi_4) {
  ck_assert_ldouble_eq_tol(acos(S21_PI / 4), s21_acos(S21_PI / 4), S21_EPS);
}
END_TEST

START_TEST(x_eq_1) {
  ck_assert_ldouble_eq_tol(acos(1.0), s21_acos(1.0), S21_EPS);
}
END_TEST

START_TEST(x_eq_1_less_zero) {
  ck_assert_ldouble_eq_tol(acos(-1.0), s21_acos(-1.0), S21_EPS);
}
END_TEST

Suite *s21_acos_suite() {
  Suite *suite = suite_create("s21_acos");
  TCase *tcase = tcase_create("Core");

  tcase_add_loop_test(tcase, enumeration_integer_values, -10, 10);
  tcase_add_test(tcase, big_value);
  tcase_add_test(tcase, acos_nan);
  tcase_add_test(tcase, acos_inf);
  tcase_add_test(tcase, acos_inf_negative);
  tcase_add_test(tcase, over_bound_positive);
  tcase_add_test(tcase, over_bound_negative);
  tcase_add_test(tcase, pi_4);
  tcase_add_test(tcase, x_eq_1);
  tcase_add_test(tcase, x_eq_1_less_zero);

  suite_add_tcase(suite, tcase);
  return suite;
}