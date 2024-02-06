#include "../suites.h"

START_TEST(to_plus) {
  s21_decimal s21 = {{10, 418, 5438, 1 << 31}};
  s21_decimal res = {{10, 418, 5438, 0}};
  s21_negate(s21, &s21);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(s21.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(to_minus) {
  s21_decimal s21 = {{10, 418, 5438, 0}};
  s21_decimal res = {{10, 418, 5438, 1 << 31}};
  s21_negate(s21, &s21);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(s21.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(null_test) {
  s21_decimal s21 = {{94, 821, 9, 0}};
  s21_decimal* buffer = NULL;
  ck_assert_int_eq(s21_negate(s21, buffer), 1);
}
END_TEST

START_TEST(buff_eq_zero) {
  s21_decimal s21 = {{94, 821, 9, 0}};
  s21_decimal buffer = {0};
  ck_assert_int_eq(s21_negate(s21, &buffer), 0);
}
END_TEST

Suite* s21_negate_suite() {
  Suite* suite = suite_create("s21_negate");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, to_plus);
  tcase_add_test(tcase, to_minus);
  tcase_add_test(tcase, null_test);
  tcase_add_test(tcase, buff_eq_zero);
  suite_add_tcase(suite, tcase);
  return suite;
}