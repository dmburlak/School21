#include "../suites.h"

START_TEST(first_lt_second) {
  s21_decimal value_1 = {{1, 2, 3, 1 << 16}};
  s21_decimal value_2 = {{1, 2, 2, 1 << 16}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(second_lt_first) {
  s21_decimal value_1 = {{1, 2, 2, 1 << 16}};
  s21_decimal value_2 = {{1, 2, 3, 1 << 16}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
}
END_TEST

START_TEST(equality) {
  s21_decimal value_1 = {{1, 2, 3, 1 << 18}};
  s21_decimal value_2 = {{1, 2, 3, 1 << 18}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(empty) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(less_zero) {
  s21_decimal value_1 = {{83, 73, 17, 1 << 31}};
  s21_decimal value_2 = {{83, 73, 17, 1 << 31}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(less_zero_first_gt) {
  s21_decimal value_1 = {{83, 73, 17, 1 << 31}};
  s21_decimal value_2 = {{83, 921, 17, 1 << 31}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(less_zero_second_gt) {
  s21_decimal value_1 = {{83, 73, 17, 1 << 31}};
  s21_decimal value_2 = {{83, 38, 17, 1 << 31}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
}
END_TEST

START_TEST(only_first_less_zero) {
  s21_decimal value_1 = {{83, 73, 17, 1 << 31}};
  s21_decimal value_2 = {{83, 38, 17, 0}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
}
END_TEST

START_TEST(only_second_less_zero) {
  s21_decimal value_1 = {{83, 73, 17, 0}};
  s21_decimal value_2 = {{83, 38, 17, 1 << 31}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

Suite* s21_is_less_suite() {
  Suite* suite = suite_create("s21_is_less");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, first_lt_second);
  tcase_add_test(tcase, second_lt_first);
  tcase_add_test(tcase, equality);
  tcase_add_test(tcase, empty);
  tcase_add_test(tcase, less_zero);
  tcase_add_test(tcase, less_zero_first_gt);
  tcase_add_test(tcase, less_zero_second_gt);
  tcase_add_test(tcase, only_first_less_zero);
  tcase_add_test(tcase, only_second_less_zero);
  suite_add_tcase(suite, tcase);
  return suite;
}