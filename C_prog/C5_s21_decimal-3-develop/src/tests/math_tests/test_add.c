#include "../suites.h"

START_TEST(simple_test) {
  s21_decimal value_1 = {{1, 0, 5, 0}};
  s21_decimal value_2 = {{6, 0, 4, 0}};
  s21_decimal res = {};
  s21_add(value_1, value_2, &res);
  ck_assert_int_eq(res.bits[0], 7);
  ck_assert_int_eq(res.bits[2], 9);
}
END_TEST

START_TEST(first_less_zero) {
  s21_decimal value_1 = {{7, 0, 5, 1 << 31}};
  s21_decimal value_2 = {{3, 0, 4, 0}};
  s21_decimal res = {};
  s21_add(value_1, value_2, &res);
  ck_assert_int_eq(res.bits[0], 4);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1);
  ck_assert_int_eq(res.bits[3], value_1.bits[3]);
}
END_TEST

START_TEST(second_less_zero) {
  s21_decimal value_1 = {{5, 0, 5, 0}};
  s21_decimal value_2 = {{3, 0, 4, 1 << 31}};
  s21_decimal res = {};
  s21_add(value_1, value_2, &res);
  ck_assert_int_eq(res.bits[0], 2);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(both_less_zero) {
  s21_decimal value_1 = {{5, 0, 5, 1 << 31}};
  s21_decimal value_2 = {{3, 0, 4, 1 << 31}};
  s21_decimal res = {};
  s21_add(value_1, value_2, &res);
  ck_assert_int_eq(res.bits[0], 8);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 9);
  ck_assert_int_eq(res.bits[3], value_1.bits[3]);
}
END_TEST

START_TEST(fail_test) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 1 << 31}};
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 1 << 31}};
  s21_decimal res = {};
  ck_assert_int_eq(s21_add(value_1, value_2, &res), 2);
}
END_TEST

START_TEST(big_exp) {
  s21_decimal value_1 = {{54, 21, 43, 70 << 16}};
  s21_decimal value_2 = {{21, 35, 432, 70 << 16}};
  s21_decimal res = {};
  ck_assert_int_eq(s21_add(value_1, value_2, &res), 0);
}
END_TEST

Suite* s21_add_suite() {
  Suite* suite = suite_create("s21_add");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, simple_test);
  tcase_add_test(tcase, first_less_zero);
  tcase_add_test(tcase, second_less_zero);
  tcase_add_test(tcase, both_less_zero);
  tcase_add_test(tcase, fail_test);
  tcase_add_test(tcase, big_exp);
  suite_add_tcase(suite, tcase);
  return suite;
}