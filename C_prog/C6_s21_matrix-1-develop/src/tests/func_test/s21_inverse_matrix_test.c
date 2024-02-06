#include "../suites.h"

START_TEST(inverse_1) {
  matrix_t m, B, R;
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &B);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = -38;
  B.matrix[1][1] = 41;
  B.matrix[1][2] = -34;
  B.matrix[2][0] = 27;
  B.matrix[2][1] = -29;
  B.matrix[2][2] = 24;

  int code = s21_inverse_matrix(&m, &R);

  ck_assert_int_eq(s21_eq_matrix(&R, &B), SUCCESS);
  ck_assert_int_eq(code, OK);
  s21_remove_matrix(&m);
  s21_remove_matrix(&R);
  s21_remove_matrix(&B);
}

END_TEST

START_TEST(inverse_2) {
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 4, &m);
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, CALC_ERR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
}

END_TEST

START_TEST(inverse_3) {
  matrix_t* B = NULL;
  matrix_t* R = NULL;
  int res = s21_inverse_matrix(B, R);
  ck_assert_int_eq(res, MATRIX_ERR);
}

END_TEST

START_TEST(inverse_4) {
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 44300.0 / 367429.0;
  C.matrix[0][1] = -236300.0 / 367429.0;
  C.matrix[0][2] = 200360.0 / 367429.0;
  C.matrix[1][0] = 20600.0 / 367429.0;
  C.matrix[1][1] = 56000.0 / 367429.0;
  C.matrix[1][2] = -156483.0 / 367429.0;
  C.matrix[2][0] = 30900.0 / 367429.0;
  C.matrix[2][1] = 84000.0 / 367429.0;
  C.matrix[2][2] = -51010.0 / 367429.0;
  A.matrix[0][0] = 2.8;
  A.matrix[0][1] = 1.3;
  A.matrix[0][2] = 7.01;
  A.matrix[1][0] = -1.03;
  A.matrix[1][1] = -2.3;
  A.matrix[1][2] = 3.01;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 2;
  s21_inverse_matrix(&A, &B);

  int res = s21_eq_matrix(&B, &C);

  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}

END_TEST

START_TEST(inverse_5) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_6) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (!codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, 2);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(inverse_7) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(inverse_8) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 4, &m);
  if (!codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, 2);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(inverse_9) {
  matrix_t m = {0};
  matrix_t expected = {0};
  int codec1, codec2;
  codec1 = s21_create_matrix(3, 3, &m);
  if (!codec1) codec2 = s21_create_matrix(3, 3, &expected);

  if (!codec1 && !codec2) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 5;
    m.matrix[0][2] = 7;

    m.matrix[1][0] = 6;
    m.matrix[1][1] = 3;
    m.matrix[1][2] = 4;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = -3;

    expected.matrix[0][0] = 1;
    expected.matrix[0][1] = -1;
    expected.matrix[0][2] = 1;

    expected.matrix[1][0] = -38;
    expected.matrix[1][1] = 41;
    expected.matrix[1][2] = -34;

    expected.matrix[2][0] = 27;
    expected.matrix[2][1] = -29;
    expected.matrix[2][2] = 24;
    matrix_t result = {0};
    int code = s21_inverse_matrix(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, 0);

    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
}
END_TEST

START_TEST(inverse_10) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {0};
  s21_inverse_matrix(&m, &res);

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);

  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_11) {
  matrix_t A;
  matrix_t R;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.0;
  int res = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(res, CALC_ERR);
  s21_remove_matrix(&A);
}

END_TEST

START_TEST(inverse_12) {
  int rows_1 = 3;
  int columns_1 = 3;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[0][1] = 5;
  matrix_1.matrix[0][2] = 7;
  matrix_1.matrix[1][0] = 6;
  matrix_1.matrix[1][1] = 3;
  matrix_1.matrix[1][2] = 4;
  matrix_1.matrix[2][0] = 5;
  matrix_1.matrix[2][1] = -2;
  matrix_1.matrix[2][2] = -3;

  matrix_t result;

  int flag = s21_inverse_matrix(&matrix_1, &result);

  int rows = 3;
  int columns = 3;

  matrix_t true_result;
  s21_create_matrix(rows, columns, &true_result);

  true_result.matrix[0][0] = 1;
  true_result.matrix[0][1] = -1;
  true_result.matrix[0][2] = 1;
  true_result.matrix[1][0] = -38;
  true_result.matrix[1][1] = 41;
  true_result.matrix[1][2] = -34;
  true_result.matrix[2][0] = 27;
  true_result.matrix[2][1] = -29;
  true_result.matrix[2][2] = 24;

  if (!flag) {
    flag = s21_eq_matrix(&result, &true_result);
  }

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(inverse_13) {
  int rows_1 = 3;
  int columns_1 = 3;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[0][2] = 3;
  matrix_1.matrix[1][0] = 4;
  matrix_1.matrix[1][1] = 5;
  matrix_1.matrix[1][2] = 6;
  matrix_1.matrix[2][0] = 7;
  matrix_1.matrix[2][1] = 8;
  matrix_1.matrix[2][2] = 9;

  matrix_t result;

  int flag = s21_inverse_matrix(&matrix_1, &result);

  s21_remove_matrix(&matrix_1);

  ck_assert_int_eq(2, flag);
}
END_TEST

Suite* s21_inverse_matrix_suite() {
  Suite* suite = suite_create("s21_inverse_matrix");
  TCase* tcase = tcase_create("Core");

  tcase_add_test(tcase, inverse_1);
  tcase_add_test(tcase, inverse_2);
  tcase_add_test(tcase, inverse_3);
  tcase_add_test(tcase, inverse_4);
  tcase_add_test(tcase, inverse_5);
  tcase_add_test(tcase, inverse_6);
  tcase_add_test(tcase, inverse_7);
  tcase_add_test(tcase, inverse_8);
  tcase_add_test(tcase, inverse_9);
  tcase_add_test(tcase, inverse_10);
  tcase_add_test(tcase, inverse_11);
  tcase_add_test(tcase, inverse_12);
  tcase_add_test(tcase, inverse_13);

  suite_add_tcase(suite, tcase);
  return suite;
}