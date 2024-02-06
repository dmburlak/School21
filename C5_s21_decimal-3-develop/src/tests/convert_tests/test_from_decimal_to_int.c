#include "../suites.h"

START_TEST(simple_test) {
  s21_decimal value = {{126, 0, 0, 1 << 16}};
  int s21 = 0;
  int res = 12;
  s21_from_decimal_to_int(value, &s21);
  ck_assert_int_eq(s21, res);
}
END_TEST

START_TEST(decimal_less_zero) {
  s21_decimal value = {{126, 0, 0, (1 << 16) + (1 << 31)}};
  int s21 = 0;
  int res = -12;
  s21_from_decimal_to_int(value, &s21);
  ck_assert_int_eq(s21, res);
}
END_TEST

START_TEST(big_decimal) {
  s21_decimal value = {{0, 1, 0, 0}};
  int s21 = 0;
  ck_assert_int_eq(s21_from_decimal_to_int(value, &s21), 1);
}
END_TEST

Suite* s21_from_decimal_to_int_suite() {
  Suite* suite = suite_create("s21_from_decimal_to_int");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, simple_test);
  tcase_add_test(tcase, decimal_less_zero);
  tcase_add_test(tcase, big_decimal);
  suite_add_tcase(suite, tcase);
  return suite;
}