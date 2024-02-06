#include "../suites.h"

START_TEST(from_float_to_decimal_test_1) {
  s21_decimal value = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = -123456789;
  s21_from_int_to_decimal(tmp, &value);
  s21_from_decimal_to_int(value, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(from_float_to_decimal_test_2) {
  s21_decimal dec = {0};
  float tmp = 0;
  float tmp1 = 0.03;
  s21_from_float_to_decimal(tmp1, &dec);
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, tmp1, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_test_3) {
  s21_decimal value;
  float num = -2147483648;
  s21_from_float_to_decimal(num, &value);
  ck_assert_int_eq(value.bits[0], 2147484000);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 2147483648);
}
END_TEST

START_TEST(from_float_to_decimal_test_4) {
  s21_decimal value = {0};
  float num = -1.0 / 0.0;
  s21_from_float_to_decimal(num, &value);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_9) {
  float x = 79228162514264337593543950500.;
  s21_decimal y = {}, result = {};
  int res_code = s21_from_float_to_decimal(x, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], y.bits[i]);
  ck_assert_int_eq(res_code, 1);
}
END_TEST

START_TEST(from_float_to_decimal_test_10) {
  float x = -79228162514264337593543950500.;
  s21_decimal y = {}, result = {};
  int res_code = s21_from_float_to_decimal(x, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], y.bits[i]);
  ck_assert_int_eq(res_code, 1);
}
END_TEST

START_TEST(from_float_to_decimal_test_11) {
  float x = 9999999.;
  s21_decimal y = {{9999999, 0, 0, 0}}, result = {};
  int res_code = s21_from_float_to_decimal(x, &result);
  ck_assert_int_eq(result.bits[0], y.bits[0]);
  ck_assert_int_eq(result.bits[1], y.bits[1]);
  ck_assert_int_eq(result.bits[2], y.bits[2]);
  ck_assert_int_eq(result.bits[3], y.bits[3]);
  ck_assert_int_eq(res_code, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_12) {
  float x = -9999999.;
  s21_decimal y = {{9999999, 0, 0, 0x80000000}}, result;
  int res_code = s21_from_float_to_decimal(x, &result);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], y.bits[i]);
  ck_assert_int_eq(res_code, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_13) {
  float x = 792281.6251426433759354395054346;
  s21_decimal result;  //  792281.625
  int res_code0 = s21_from_float_to_decimal(x, &result);
  ck_assert_int_eq(res_code0, 0);
  ck_assert_int_eq(result.bits[3], SET_EXP_AND_SIGN(1, 0));
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 7922816);
}
END_TEST

START_TEST(from_float_to_decimal_test_14) {
  float x = -79228.1625142643375935439505234523;
  s21_decimal result = {};  //  -79228.1640625
  int res_code0 = s21_from_float_to_decimal(x, &result);
  ck_assert_int_eq(res_code0, 0);
  ck_assert_uint_eq(result.bits[3], SET_EXP_AND_SIGN(2u, 1u));
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[0], 7922816);
}
END_TEST

START_TEST(from_float_to_decimal_test_15) {
  float x = -0.0000000000625142643375935439505234523;
  s21_decimal result;
  float x_;
  int res_code0 = s21_from_float_to_decimal(x, &result);
  int res_code1 = s21_from_decimal_to_float(result, &x_);
  ck_assert_float_eq_tol(x, x_, 1e-8);
  ck_assert_int_eq(res_code0, 0);
  ck_assert_int_eq(res_code1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_16) {
  float x = 0.000000000925142643375935439505234523;
  s21_decimal result;
  float x_;
  int res_code0 = s21_from_float_to_decimal(x, &result);
  int res_code1 = s21_from_decimal_to_float(result, &x_);
  ck_assert_float_eq_tol(x, x_, 1e-8);
  ck_assert_int_eq(res_code0, 0);
  ck_assert_int_eq(res_code1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_17) {
  float x = 0.0092514264337547355935439505234523;
  s21_decimal result;
  float x_;
  int res_code0 = s21_from_float_to_decimal(x, &result);
  int res_code1 = s21_from_decimal_to_float(result, &x_);
  ck_assert_float_eq(x, x_);
  ck_assert_int_eq(res_code0, 0);
  ck_assert_int_eq(res_code1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_18) {
  float x = 0.;
  s21_decimal result = {};
  float x_ = 0.;
  int res_code0 = s21_from_float_to_decimal(x, &result);
  int res_code1 = s21_from_decimal_to_float(result, &x_);
  ck_assert_float_eq_tol(x, x_, 1e-8);
  ck_assert_int_eq(res_code0, 1);
  ck_assert_int_eq(res_code1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_test_24) {
  float x = INFINITY;
  s21_decimal y = {}, result = {};
  int res_code = s21_from_float_to_decimal(x, &result);
  ck_assert_int_eq(res_code, 1);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], (int)y.bits[i]);
}
END_TEST

START_TEST(from_float_to_decimal_test_25) {
  float x = -INFINITY;
  s21_decimal y = {}, result = {};
  int res_code = s21_from_float_to_decimal(x, &result);
  ck_assert_int_eq(res_code, 1);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], (int)y.bits[i]);
}
END_TEST

Suite* s21_from_float_to_decimal_suite() {
  Suite* suite = suite_create("s21_from_float_to_decimal");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, from_float_to_decimal_test_1);
  tcase_add_test(tcase, from_float_to_decimal_test_2);
  tcase_add_test(tcase, from_float_to_decimal_test_3);
  tcase_add_test(tcase, from_float_to_decimal_test_4);
  tcase_add_test(tcase, from_float_to_decimal_test_9);
  tcase_add_test(tcase, from_float_to_decimal_test_10);
  tcase_add_test(tcase, from_float_to_decimal_test_11);
  tcase_add_test(tcase, from_float_to_decimal_test_12);
  tcase_add_test(tcase, from_float_to_decimal_test_13);
  tcase_add_test(tcase, from_float_to_decimal_test_14);
  tcase_add_test(tcase, from_float_to_decimal_test_15);
  tcase_add_test(tcase, from_float_to_decimal_test_16);
  tcase_add_test(tcase, from_float_to_decimal_test_17);
  tcase_add_test(tcase, from_float_to_decimal_test_18);
  tcase_add_test(tcase, from_float_to_decimal_test_24);
  tcase_add_test(tcase, from_float_to_decimal_test_25);
  suite_add_tcase(suite, tcase);
  return suite;
}