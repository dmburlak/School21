#include "../suites.h"

START_TEST(first_gt_second) {
  s21_decimal value_1 = {{831, 478, 1284, 0}};
  s21_decimal value_2 = {{0, 3785, 3812, 0}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(first_lt_second) {
  s21_decimal value_1 = {{831, 478, 1284, 0}};
  s21_decimal value_2 = {{0, 3785, 3812, 0}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(equality) {
  s21_decimal value_1 = {{1, 2, 3, 1 << 16}};
  s21_decimal value_2 = {{1, 2, 3, 1 << 16}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(empty) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(eq_with_diff_mantiss) {
  s21_decimal value_1 = {{100, 0, 0, 1 << 16}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

Suite* s21_is_not_equal_suite() {
  Suite* suite = suite_create("s21_is_not_equal");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, first_gt_second);
  tcase_add_test(tcase, first_lt_second);
  tcase_add_test(tcase, equality);
  tcase_add_test(tcase, empty);
  tcase_add_test(tcase, eq_with_diff_mantiss);
  suite_add_tcase(suite, tcase);
  return suite;
}