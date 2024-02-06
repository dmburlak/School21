#include "../suites.h"

START_TEST(simple_test) {
  s21_decimal value_1 = {{8, 2, 3, 0}};
  s21_decimal value_2 = {{4, 1, 0, 0}};
  s21_decimal res = {};
  s21_sub(value_1, value_2, &res);
  ck_assert_int_eq(res.bits[0], 4);
  ck_assert_int_eq(res.bits[1], 1);
  ck_assert_int_eq(res.bits[2], 3);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(first_less_zero) {
  s21_decimal value_1 = {{8, 2, 3, 1 << 31}};
  s21_decimal value_2 = {{4, 1, 0, 0}};
  s21_decimal res = {};
  s21_sub(value_1, value_2, &res);
  ck_assert_int_eq(res.bits[0], 12);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 3);
  ck_assert_int_eq(res.bits[3], 2147483648);
}
END_TEST

START_TEST(second_less_zero) {
  s21_decimal value_1 = {{8, 2, 3, 0}};
  s21_decimal value_2 = {{4, 1, 0, 1 << 31}};
  s21_decimal res = {};
  s21_sub(value_1, value_2, &res);
  ck_assert_int_eq(res.bits[0], 12);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 3);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(both_less_zero) {
  s21_decimal value_1 = {{8, 2, 3, 1 << 31}};
  s21_decimal value_2 = {{4, 1, 0, 1 << 31}};
  s21_decimal res = {};
  s21_sub(value_1, value_2, &res);
  ck_assert_int_eq(res.bits[0], 4);
  ck_assert_int_eq(res.bits[1], 1);
  ck_assert_int_eq(res.bits[2], 3);
  ck_assert_int_eq(res.bits[3], 2147483648);
}
END_TEST

START_TEST(second_greater_first) {
  s21_decimal value_1 = {{4, 1, 0, 0}};
  s21_decimal value_2 = {{8, 2, 3, 0}};
  s21_decimal res = {};
  s21_sub(value_1, value_2, &res);
  ck_assert_int_eq(res.bits[0], 4);
  ck_assert_int_eq(res.bits[1], 1);
  ck_assert_int_eq(res.bits[2], 3);
  ck_assert_int_eq(res.bits[3], 2147483648);
}
END_TEST

START_TEST(first_greater_second) {
  s21_decimal value_1 = {{3, 2, 3, 0}};
  s21_decimal value_2 = {{4, 1, 0, 0}};
  s21_decimal res = {};
  s21_sub(value_1, value_2, &res);
  ck_assert_int_eq(res.bits[0], UINT_MAX);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 3);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

Suite* s21_sub_suite() {
  Suite* suite = suite_create("s21_sub");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, simple_test);
  tcase_add_test(tcase, first_less_zero);
  tcase_add_test(tcase, second_less_zero);
  tcase_add_test(tcase, both_less_zero);
  tcase_add_test(tcase, second_greater_first);
  tcase_add_test(tcase, first_greater_second);
  suite_add_tcase(suite, tcase);
  return suite;
}