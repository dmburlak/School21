#include "../suites.h"

START_TEST(simple_test) {
  s21_decimal s21 = {};
  s21_decimal res = {{321, 0, 0, 0}};
  int num = 321;
  s21_from_int_to_decimal(num, &s21);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(s21.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(num_less_zero) {
  s21_decimal s21 = {};
  s21_decimal res = {{321, 0, 0, 1 << 31}};
  int num = -321;
  s21_from_int_to_decimal(num, &s21);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(s21.bits[i], res.bits[i]);
  }
}
END_TEST

START_TEST(null_test) {
  s21_decimal* s21 = NULL;
  int num = 481;
  ck_assert_int_eq(s21_from_int_to_decimal(num, s21), 1);
}
END_TEST

Suite* s21_from_int_to_decimal_suite() {
  Suite* suite = suite_create("s21_from_int_to_decimal");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, simple_test);
  tcase_add_test(tcase, num_less_zero);
  tcase_add_test(tcase, null_test);
  suite_add_tcase(suite, tcase);
  return suite;
}