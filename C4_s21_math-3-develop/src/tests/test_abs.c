#include "suites.h"

START_TEST(small_pos_neg_value) { ck_assert_int_eq(s21_abs(_i), abs(_i)); }
END_TEST

START_TEST(char_) { ck_assert_int_eq(s21_abs((char)_i), abs((char)_i)); }
END_TEST

START_TEST(big_num) {
  int num = 32000;
  ck_assert_int_eq(s21_abs(num), abs(num));
}
END_TEST

START_TEST(big_num_less_zero) {
  int num = -32000;
  ck_assert_int_eq(s21_abs(num), abs(num));
}
END_TEST

Suite *s21_abs_suite() {
  Suite *suite = suite_create("s21_abs");
  TCase *tcase = tcase_create("Core");

  tcase_add_loop_test(tcase, small_pos_neg_value, -2, 2);
  tcase_add_loop_test(tcase, char_, -2, 2);
  tcase_add_test(tcase, big_num);
  tcase_add_test(tcase, big_num_less_zero);
  suite_add_tcase(suite, tcase);

  return suite;
}