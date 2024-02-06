#include "../suites.h"

START_TEST(first_gt_second) {
  s21_decimal value_1 = {{921, 283, 847, 2 << 18}};
  s21_decimal value_2 = {{0, 1, 5, 2 << 18}};
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(second_gt_first) {
  s21_decimal value_1 = {{0, 1, 5, 2 << 18}};
  s21_decimal value_2 = {{921, 283, 847, 2 << 18}};
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(empty) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(equality) {
  s21_decimal value_1 = {{4, 123, 38, 10 << 18}};
  s21_decimal value_2 = {{4, 123, 38, 10 << 18}};
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
}
END_TEST

Suite* s21_is_greater_or_equal_suite() {
  Suite* suite = suite_create("s21_is_greater_or_equal");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, first_gt_second);
  tcase_add_test(tcase, second_gt_first);
  tcase_add_test(tcase, empty);
  tcase_add_test(tcase, equality);
  suite_add_tcase(suite, tcase);
  return suite;
}