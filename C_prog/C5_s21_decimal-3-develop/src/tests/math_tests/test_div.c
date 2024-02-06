#include "../suites.h"

START_TEST(fake) {
  s21_decimal value_1, value_2, res = {};
  ck_assert_int_eq(s21_div(value_1, value_2, &res), 0);
}

Suite* s21_div_suite() {
  Suite* suite = suite_create("s21_div");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, fake);
  suite_add_tcase(suite, tcase);
  return suite;
}