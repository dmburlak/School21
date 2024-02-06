#include "../suites.h"

START_TEST(test1_mult_number) {
  matrix_t A = {0};
  double number = 2;
  matrix_t res = {0};

  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 4;

  ck_assert_int_eq(OK, s21_mult_number(&A, number, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test2_mult_number) {
  matrix_t A = {0};
  double number = 2.6642937;
  matrix_t res = {0};

  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3.43585021;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 4;

  ck_assert_double_eq(OK, s21_mult_number(&A, number, &res));
  ck_assert_double_eq(10.6571748, res.matrix[2][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test3_mult_number) {
  matrix_t A = {0};
  double number = -2.5;
  matrix_t res = {0};

  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 4.54292;

  ck_assert_int_eq(OK, s21_mult_number(&A, number, &res));
  ck_assert_double_eq_tol(-11.3573, res.matrix[2][2], 8);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test4_mult_number) {
  matrix_t A = {0};
  matrix_t res = {0};

  A.rows = -2;
  A.columns = -2;
  s21_create_matrix(A.rows, A.columns, &A);

  ck_assert_int_eq(MATRIX_ERR, s21_mult_number(&A, 2, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test5_mult_number) {
  matrix_t A = {0};
  matrix_t res = {0};

  A.rows = 0;
  A.columns = 0;
  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(2, 2, &res);

  ck_assert_int_eq(MATRIX_ERR, s21_mult_number(&A, 2, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test6_mult_number) {
  matrix_t A = {.matrix = NULL};
  matrix_t res = {0};

  ck_assert_int_eq(MATRIX_ERR, s21_mult_number(&A, 3, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test7_mult_number) {
  ck_assert_int_eq(s21_mult_number(NULL, 0, NULL), MATRIX_ERR);
}
END_TEST

START_TEST(test8_mult_number) {
  matrix_t A;
  matrix_t C;
  matrix_t C2;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &C2);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++) A.matrix[i][j] = (double)(rand()) / RAND_MAX;
  ck_assert_int_eq(s21_mult_number(&A, 5, &C), OK);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++) C2.matrix[i][j] = A.matrix[i][j] * 5;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      ck_assert_double_eq(C2.matrix[i][j], C.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&C2);
}

Suite* s21_mult_number_suite() {
  Suite* suite = suite_create("s21_mult_number");
  TCase* tcase = tcase_create("Core");

  tcase_add_test(tcase, test1_mult_number);
  tcase_add_test(tcase, test2_mult_number);
  tcase_add_test(tcase, test3_mult_number);
  tcase_add_test(tcase, test4_mult_number);
  tcase_add_test(tcase, test5_mult_number);
  tcase_add_test(tcase, test6_mult_number);
  tcase_add_test(tcase, test7_mult_number);
  tcase_add_test(tcase, test8_mult_number);

  suite_add_tcase(suite, tcase);
  return suite;
}