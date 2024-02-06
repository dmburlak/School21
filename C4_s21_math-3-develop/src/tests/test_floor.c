#include "suites.h"

START_TEST(default_input) {
  ck_assert_ldouble_eq(s21_floor(12.99), floor(12.99));
}
END_TEST

START_TEST(value_less_zero) {
  ck_assert_ldouble_eq(s21_floor(-12.0009), floor(-12.0009));
}
END_TEST

START_TEST(value_eq_zero) { ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0)); }
END_TEST

START_TEST(value_eq_int) { ck_assert_ldouble_eq(s21_floor(15), floor(15)); }
END_TEST

START_TEST(value_eq_int_less_zero) {
  ck_assert_ldouble_eq_tol(s21_floor(-15), floor(-15), S21_EPS);
}
END_TEST

Suite *s21_floor_suite() {
  Suite *suite = suite_create("s21_floor");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, default_input);
  tcase_add_test(tcase, value_less_zero);
  tcase_add_test(tcase, value_eq_zero);
  tcase_add_test(tcase, value_eq_int);
  tcase_add_test(tcase, value_eq_int_less_zero);
  suite_add_tcase(suite, tcase);
  return suite;
}