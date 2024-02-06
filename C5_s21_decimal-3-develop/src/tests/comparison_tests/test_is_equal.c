#include "../suites.h"

START_TEST(equality) {
  s21_decimal value_1 = {{1, 2, 5, 0}};
  s21_decimal value_2 = {{1, 2, 5, 0}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(first_gt_second) {
  s21_decimal value_1 = {{10, 0, 0, 1 << 16}};
  s21_decimal value_2 = {{10, 0, 0, 1 << 14}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(empty) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(not_eq_mantiss) {
  s21_decimal value_1 = {{10, 38, 19, 1 << 16}};
  s21_decimal value_2 = {{13, 38, 19, 1 << 16}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(eq_with_diff_mantiss) {
  s21_decimal value_1 = {{100, 0, 0, 1 << 16}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(big_num_test) {
  s21_decimal value_1 = {{19993, 1, 0, 1 << 31}};
  s21_decimal value_2 = {{19993, 1, 0, 1 << 31}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

Suite* s21_is_equal_suite() {
  Suite* suite = suite_create("s21_is_equal");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, equality);
  tcase_add_test(tcase, first_gt_second);
  tcase_add_test(tcase, empty);
  tcase_add_test(tcase, not_eq_mantiss);
  tcase_add_test(tcase, eq_with_diff_mantiss);
  tcase_add_test(tcase, big_num_test);
  suite_add_tcase(suite, tcase);
  return suite;
}