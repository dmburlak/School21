#include "../suites.h"

START_TEST(simple_test) {
  s21_decimal value = {{3214, 0, 0, 2 << 16}};
  float s21 = 0;
  float res = 32.14;
  s21_from_decimal_to_float(value, &s21);
  ck_assert_double_eq_tol(s21, res, 6);
}
END_TEST

START_TEST(decimal_less_zero) {
  s21_decimal value = {{3214, 0, 0, (2 << 16) + (1 << 31)}};
  float s21 = 0;
  float res = -32.14;
  s21_from_decimal_to_float(value, &s21);
  ck_assert_double_eq_tol(s21, res, 6);
}
END_TEST

START_TEST(empty) {
  s21_decimal value = {};
  float s21 = 0;
  float res = 0;
  s21_from_decimal_to_float(value, &s21);
  ck_assert_double_eq_tol(s21, res, 6);
}
END_TEST

Suite* s21_from_decimal_to_float_suite() {
  Suite* suite = suite_create("s21_from_decimal_to_float");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, simple_test);
  tcase_add_test(tcase, decimal_less_zero);
  tcase_add_test(tcase, empty);
  suite_add_tcase(suite, tcase);
  return suite;
}