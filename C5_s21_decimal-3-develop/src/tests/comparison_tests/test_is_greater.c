#include "../suites.h"

START_TEST(first_gt_second) {
  s21_decimal value_1 = {{1, 2, 3, 1 << 16}};
  s21_decimal value_2 = {{1, 2, 0, 1 << 16}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
}
END_TEST

START_TEST(second_gt_first) {
  s21_decimal value_1 = {{1, 2, 0, 1 << 16}};
  s21_decimal value_2 = {{1, 2, 3, 1 << 16}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

START_TEST(empty) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

START_TEST(equality) {
  s21_decimal value_1 = {{1, 2, 3, 1 << 17}};
  s21_decimal value_2 = {{1, 2, 3, 1 << 17}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

Suite* s21_is_greater_suite() {
  Suite* suite = suite_create("s21_is_greater");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, first_gt_second);
  tcase_add_test(tcase, second_gt_first);
  tcase_add_test(tcase, empty);
  tcase_add_test(tcase, equality);
  suite_add_tcase(suite, tcase);
  return suite;
}