#include "../suites.h"

START_TEST(simple_test) {
  s21_decimal value_1 = {{3, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal res = {};
  s21_mul(value_1, value_2, &res);
  ck_assert_int_eq(res.bits[0], 9);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(zero_mul) {
  s21_decimal value_1 = {{4, 2, 1, 0}};
  s21_decimal value_2 = {};
  s21_decimal res = {};
  s21_mul(value_1, value_2, &res);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], 0);
  }
  s21_mul(value_2, value_1, &res);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], 0);
  }
}
END_TEST

START_TEST(with_convert) {
  int num1 = 10;
  int num2 = 20;
  int res = 200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res);
}
END_TEST

START_TEST(with_convert_less_zero) {
  int num1 = -10;
  int num2 = 20;
  int res = -200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res);
}
END_TEST

START_TEST(test_5) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  ck_assert_uint_eq(0, s21_mul(value_1, value_2, &result));
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(0, result.bits[i]);
  }
}
END_TEST

START_TEST(test_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(test_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(origin.bits[i], result.bits[i]);
  }
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

Suite* s21_mul_suite() {
  Suite* suite = suite_create("s21_mul");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, simple_test);
  tcase_add_test(tcase, zero_mul);
  tcase_add_test(tcase, with_convert);
  tcase_add_test(tcase, with_convert_less_zero);
  tcase_add_test(tcase, test_5);
  tcase_add_test(tcase, test_6);
  tcase_add_test(tcase, test_7);

  suite_add_tcase(suite, tcase);
  return suite;
}