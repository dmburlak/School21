#include "suites.h"

START_TEST(infinity_x) {
  long double s21 = s21_fmod(S21_INF, 1.0);
  long double actual = fmod(S21_INF, 1.0);

  ck_assert_ldouble_nan(s21);
  ck_assert_ldouble_nan(actual);
}
END_TEST

START_TEST(infinity_y) {
  long double s21 = s21_fmod(5.0, S21_INF);
  long double actual = fmod(5.0, S21_INF);

  ck_assert_ldouble_eq_tol(s21, actual, S21_EPS);
}
END_TEST

START_TEST(y_minus_zero) {
  long double s21 = s21_fmod(S21_INF, -0.0);
  long double actual = fmod(S21_INF, -0.0);

  ck_assert_ldouble_nan(s21);
  ck_assert_ldouble_nan(actual);
}
END_TEST

START_TEST(x_NAN) {
  long double s21 = s21_fmod(S21_NAN, 2.0);
  long double actual = fmod(S21_NAN, 2.0);

  ck_assert_ldouble_nan(s21);
  ck_assert_ldouble_nan(actual);
}
END_TEST

START_TEST(y_NAN) {
  long double s21 = s21_fmod(2.0, S21_NAN);
  long double actual = fmod(2.0, S21_NAN);

  ck_assert_ldouble_nan(s21);
  ck_assert_ldouble_nan(actual);
}
END_TEST

START_TEST(int_y_lower_x) {
  ck_assert_ldouble_eq_tol(s21_fmod(5, 2), fmod(5, 2), S21_EPS);
}
END_TEST

START_TEST(double_y_lower_x) {
  ck_assert_ldouble_eq_tol(s21_fmod(5.65, 2.1), fmod(5.65, 2.1), S21_EPS);
}
END_TEST

START_TEST(y_lower_zero) {
  ck_assert_ldouble_eq_tol(s21_fmod(1.0, -5.0), fmod(1.0, -5.0), S21_EPS);
}
END_TEST

START_TEST(x_lower_y) {
  ck_assert_ldouble_eq_tol(s21_fmod(-1.0, 1.0), fmod(-1.0, 1.0), S21_EPS);
}
END_TEST

START_TEST(x_equal_y) {
  ck_assert_ldouble_eq_tol(s21_fmod(1.0, 1.0), fmod(1.0, 1.0), S21_EPS);
}
END_TEST

Suite *s21_fmod_suite() {
  Suite *suite = suite_create("s21_fmod");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, infinity_x);
  tcase_add_test(tcase, infinity_y);
  tcase_add_test(tcase, x_NAN);
  tcase_add_test(tcase, y_NAN);
  tcase_add_test(tcase, y_minus_zero);
  tcase_add_test(tcase, y_lower_zero);
  tcase_add_test(tcase, int_y_lower_x);
  tcase_add_test(tcase, double_y_lower_x);
  tcase_add_test(tcase, y_lower_zero);
  tcase_add_test(tcase, x_lower_y);
  tcase_add_test(tcase, x_equal_y);

  suite_add_tcase(suite, tcase);
  return suite;
}