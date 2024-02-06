#include "../suites.h"

START_TEST(simple_test) {
  s21_decimal s21 = {{20384, 0, 0, 2 << 16}};
  s21_decimal res = {{203, 0, 0, 0}};
  s21_truncate(s21, &s21);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], s21.bits[i]);
  }
}
END_TEST

START_TEST(without_exp) {
  s21_decimal s21 = {{84291, 571, 48, 0}};
  s21_decimal res = {{84291, 571, 48, 0}};
  s21_truncate(s21, &s21);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], s21.bits[i]);
  }
}
END_TEST

START_TEST(empty) {
  s21_decimal s21 = {};
  s21_decimal res = {};
  s21_truncate(s21, &s21);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(s21.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(null_test) {
  s21_decimal s21 = {{9524, 2174, 923, 5 << 16}};
  s21_decimal* buffer = NULL;
  ck_assert_int_eq(s21_truncate(s21, buffer), 1);
}
END_TEST

START_TEST(buff_eq_zero) {
  s21_decimal s21 = {{9524, 2174, 923, 5 << 16}};
  s21_decimal buffer = {};
  ck_assert_int_eq(s21_truncate(s21, &buffer), 0);
}
END_TEST

Suite* s21_truncate_suite() {
  Suite* suite = suite_create("s21_truncate");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, simple_test);
  tcase_add_test(tcase, without_exp);
  tcase_add_test(tcase, empty);
  tcase_add_test(tcase, null_test);
  tcase_add_test(tcase, buff_eq_zero);
  suite_add_tcase(suite, tcase);
  return suite;
}