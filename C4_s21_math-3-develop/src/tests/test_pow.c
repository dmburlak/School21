#include "suites.h"

START_TEST(neg_exp) {
  long double s21 = s21_pow(5.0, _i);
  long double actual = pow(5.0, _i);
  ck_assert_ldouble_eq_tol(actual, s21, S21_EPS);
}
END_TEST

START_TEST(neg_base) {
  long double s21 = s21_pow(_i, 5.0);
  long double actual = pow(_i, 5.0);
  ck_assert_ldouble_eq_tol(actual, s21, S21_EPS);
}
END_TEST

START_TEST(neg_base_2) {
  long double s21 = s21_pow(-2.0, 5.0);
  long double actual = pow(-2.0, 5.0);
  ck_assert_ldouble_eq_tol(actual, s21, S21_EPS);
}
END_TEST

START_TEST(double_input) {
  ck_assert_ldouble_eq_tol(s21_pow(1.32, 0.43), pow(1.32, 0.43), S21_EPS);
}
END_TEST

START_TEST(all_nan) {
  long double s21 = s21_pow(S21_NAN, S21_NAN);
  long double actual = pow(S21_NAN, S21_NAN);

  ck_assert_ldouble_nan(actual);
  ck_assert_ldouble_nan(s21);
}
END_TEST

START_TEST(neg_base_double_exp) {
  long double s21 = s21_pow(-2, 0.5);
  long double actual = pow(-2, 0.5);

  ck_assert_ldouble_nan(actual);
  ck_assert_ldouble_nan(s21);
}
END_TEST

START_TEST(neg_base_st_exp) {
  long double s21 = s21_pow(-2, 1e-09);
  long double actual = pow(-2, 1e-09);

  ck_assert_ldouble_nan(actual);
  ck_assert_ldouble_nan(s21);
}
END_TEST

START_TEST(all_huge) {
  long double s21 = s21_pow(960819125231409.01234, 6493596273704.0);
  long double actual = pow(960819125231409.01234, 6493596273704.0);

  ck_assert_ldouble_infinite(actual);
  ck_assert_ldouble_infinite(s21);
}
END_TEST

START_TEST(all_inf) {
  long double s21 = s21_pow(S21_INF, S21_INF);
  long double actual = pow(S21_INF, S21_INF);

  ck_assert_ldouble_infinite(actual);
  ck_assert_ldouble_infinite(s21);
}
END_TEST

START_TEST(exp_inf) {
  long double s21 = s21_pow(15.02, S21_INF);
  long double actual = pow(15.02, S21_INF);

  ck_assert_ldouble_infinite(actual);
  ck_assert_ldouble_infinite(s21);
}

START_TEST(zero_inf) {
  long double s21 = s21_pow(0.0, S21_INF);
  long double actual = pow(0.0, S21_INF);

  ck_assert_ldouble_eq_tol(s21, actual, S21_EPS);
}
END_TEST

START_TEST(all_neg_inf) {
  ck_assert_ldouble_eq_tol(s21_pow(-S21_INF, -S21_INF), pow(-S21_INF, -S21_INF),
                           S21_EPS);
}
END_TEST

START_TEST(base_neg_inf) {
  long double s21 = s21_pow(-S21_INF, S21_INF);
  long double actual = pow(-S21_INF, S21_INF);

  ck_assert_ldouble_infinite(actual);
  ck_assert_ldouble_infinite(s21);
}
END_TEST

START_TEST(exp_neg_inf) {
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF, -S21_INF), pow(S21_INF, -S21_INF),
                           S21_EPS);
}
END_TEST

START_TEST(nan_inf) {
  long double s21 = s21_pow(S21_NAN, S21_INF);
  long double actual = pow(S21_NAN, S21_INF);

  ck_assert_ldouble_nan(actual);
  ck_assert_ldouble_nan(s21);
}
END_TEST

START_TEST(neg_base_neg_inf_exp) {
  long double s21 = s21_pow(-17.04, -S21_INF);
  long double actual = pow(-17.04, -S21_INF);

  ck_assert_ldouble_eq_tol(s21, actual, S21_EPS);
}
END_TEST

START_TEST(pow_pos_loop_test) {
  double x = 1.0;
  double y = 0.54962542;
  for (; x < 10; x += 0.72354736) {
    y += 0.73642;
    long double s21 = s21_pow(x, y);
    long double actual = pow(x, y);
    ck_assert_double_eq_tol(s21, actual, 1e-04);
  }
}
END_TEST

START_TEST(base_less_1_exp_inf) {
  double x = 0.5;
  double y = S21_INF;
  ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), S21_EPS);
}
END_TEST

START_TEST(base_less_1_exp_inf_neg) {
  double x = 0.5;
  double y = S21_INF;
  ck_assert_ldouble_infinite(s21_pow(x, -y));
  ck_assert_ldouble_infinite(pow(x, -y));
}
END_TEST

START_TEST(base_eq_1_exp_inf) {
  double x = 1;
  double y = S21_INF;
  ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), S21_EPS);
}
END_TEST

Suite *s21_pow_suite() {
  Suite *suite = suite_create("s21_pow");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, double_input);
  tcase_add_loop_test(tcase, neg_exp, -5.0, 3.0);
  tcase_add_loop_test(tcase, neg_base, -5.0, 3.0);
  tcase_add_test(tcase, double_input);
  tcase_add_test(tcase, neg_base_2);
  tcase_add_test(tcase, all_nan);
  tcase_add_test(tcase, neg_base_double_exp);
  tcase_add_test(tcase, all_huge);
  tcase_add_test(tcase, all_inf);
  tcase_add_test(tcase, exp_inf);
  tcase_add_test(tcase, zero_inf);
  tcase_add_test(tcase, all_neg_inf);
  tcase_add_test(tcase, base_neg_inf);
  tcase_add_test(tcase, exp_neg_inf);
  tcase_add_test(tcase, nan_inf);
  tcase_add_test(tcase, neg_base_neg_inf_exp);
  tcase_add_test(tcase, neg_base_st_exp);
  tcase_add_test(tcase, pow_pos_loop_test);
  tcase_add_test(tcase, base_less_1_exp_inf);
  tcase_add_test(tcase, base_less_1_exp_inf_neg);
  tcase_add_test(tcase, base_eq_1_exp_inf);

  suite_add_tcase(suite, tcase);

  return suite;
}
