#include "suites.h"

START_TEST(enumeration_integer_values) {
  ck_assert_ldouble_eq_tol(s21_cos(s21_rad(_i)), cos(s21_rad(_i)), S21_EPS);
}
END_TEST

START_TEST(tan_zero) {
  ck_assert_ldouble_eq_tol(s21_tan(0.0), tan(0.0), S21_EPS);
}
END_TEST

START_TEST(tan_nan) {
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_nan(tan(S21_NAN));
}
END_TEST

START_TEST(tan_inf) {
  ck_assert_ldouble_nan(s21_tan(S21_INF));
  ck_assert_ldouble_nan(tan(S21_INF));
}
END_TEST

START_TEST(tan_inf_negative) {
  ck_assert_ldouble_nan(s21_tan(-S21_INF));
  ck_assert_ldouble_nan(tan(-S21_INF));
}
END_TEST

START_TEST(tan_loop) {
  for (double test = 0.0 + 1e-4; test <= S21_2PI; test += 0.0161573) {
    long double s21 = s21_tan(test);
    long double actual = tan(test);
    ck_assert_ldouble_eq_tol(s21, actual, S21_EPS);
  }
}
END_TEST

START_TEST(over_bound_positive) {
  ck_assert_ldouble_eq_tol(s21_tan(903.0), tan(903.0), S21_EPS);
}
END_TEST

START_TEST(over_bound_negative) {
  ck_assert_ldouble_eq_tol(s21_tan(-553.0), tan(-553.0), S21_EPS);
}
END_TEST

START_TEST(close_to_inbound) {
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI - 1e-9), tan(S21_PI - 1e-9), S21_EPS);
}
END_TEST

START_TEST(close_to_nan_bound) {
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI / 2 - 1e-4), tan(S21_PI / 2 - 1e-4),
                           S21_EPS);
}
END_TEST

Suite *s21_tan_sutie() {
  Suite *suite = suite_create("s21_tan");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, enumeration_integer_values);
  tcase_add_test(tcase, tan_zero);
  tcase_add_test(tcase, tan_nan);
  tcase_add_test(tcase, tan_inf);
  tcase_add_test(tcase, tan_inf_negative);
  tcase_add_test(tcase, tan_loop);
  tcase_add_test(tcase, over_bound_positive);
  tcase_add_test(tcase, over_bound_negative);
  tcase_add_test(tcase, close_to_inbound);
  tcase_add_test(tcase, close_to_nan_bound);

  suite_add_tcase(suite, tcase);
  return suite;
}