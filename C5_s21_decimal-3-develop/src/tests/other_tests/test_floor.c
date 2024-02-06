#include "../suites.h"

START_TEST(simple_test) {
  s21_decimal s21 = {{8321, 0, 0, 1 << 16}};
  s21_decimal res = {{832, 0, 0, 0}};
  s21_floor(s21, &s21);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(s21.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(without_exp) {
  s21_decimal s21 = {{948, 8321, 93, 0}};
  s21_decimal res = {{948, 8321, 93, 0}};
  s21_floor(s21, &s21);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(s21.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(round_test) {
  s21_decimal s21 = {{919, 0, 0, 1 << 16}};
  s21_decimal res = {{91, 0, 0, 0}};
  s21_floor(s21, &s21);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(s21.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(less_zero) {
  s21_decimal s21 = {{918, 0, 0, (1 << 16) + (1 << 31)}};
  s21_decimal res = {{92, 0, 0, 1 << 31}};
  s21_floor(s21, &s21);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(s21.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(empty) {
  s21_decimal s21 = {};
  s21_decimal res = {};
  s21_floor(s21, &s21);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(s21.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(null_test) {
  s21_decimal s21 = {{38, 0, 3, 0}};
  s21_decimal* buffer = NULL;
  ck_assert_int_eq(s21_floor(s21, buffer), 1);
}
END_TEST

START_TEST(buff_eq_zero) {
  s21_decimal s21 = {{38, 0, 3, 0}};
  s21_decimal buffer = {};
  ck_assert_int_eq(s21_floor(s21, &buffer), 0);
}
END_TEST

Suite* s21_floor_suite() {
  Suite* suite = suite_create("s21_floor");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, simple_test);
  tcase_add_test(tcase, without_exp);
  tcase_add_test(tcase, round_test);
  tcase_add_test(tcase, empty);
  tcase_add_test(tcase, less_zero);
  tcase_add_test(tcase, null_test);
  tcase_add_test(tcase, buff_eq_zero);
  suite_add_tcase(suite, tcase);
  return suite;
}