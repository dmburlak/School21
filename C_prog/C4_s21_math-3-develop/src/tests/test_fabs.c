#include "suites.h"

START_TEST(default_input) {
  for (double i = -3.1; i < 5.1; i++) {
    ck_assert_ldouble_eq_tol(s21_fabs(i), fabs(i), S21_EPS);
  }
}
END_TEST

START_TEST(pos_without_prec) {
  ck_assert_ldouble_eq_tol(s21_fabs(15.), fabs(15.), S21_EPS);
}
END_TEST

START_TEST(neg_without_prec) {
  ck_assert_ldouble_eq_tol(s21_fabs(-15.), fabs(-15.), S21_EPS);
}
END_TEST

START_TEST(big_prec) {
  ck_assert_ldouble_eq_tol(s21_fabs(41231.4124123654), fabs(41231.4124123654),
                           S21_EPS);
}
END_TEST

Suite *s21_fabs_suite() {
  Suite *suite = suite_create("s21_fabs");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, default_input);
  tcase_add_test(tcase, pos_without_prec);
  tcase_add_test(tcase, neg_without_prec);
  tcase_add_test(tcase, big_prec);
  suite_add_tcase(suite, tcase);
  return suite;
}