#include "../suites.h"

START_TEST(test1_transpose) {
  matrix_t A = {0};
  matrix_t res = {0};

  A.rows = 3;
  A.columns = 2;
  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[1][0] = 2;
  A.matrix[2][0] = 3;
  A.matrix[0][1] = 0;
  A.matrix[1][1] = 4;
  A.matrix[2][1] = 2;

  ck_assert_int_eq(OK, s21_transpose(&A, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test2_transpose) {
  matrix_t A = {0};
  matrix_t res = {0};

  A.rows = 2;
  A.columns = 3;
  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;

  ck_assert_int_eq(OK, s21_transpose(&A, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test3_transpose) {
  matrix_t A = {0};
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

  ck_assert_int_eq(OK, s21_transpose(&A, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test4_transpose) {
  matrix_t A = {0};
  matrix_t res = {0};

  A.rows = -2;
  A.columns = -2;
  s21_create_matrix(A.rows, A.columns, &A);

  ck_assert_int_eq(MATRIX_ERR, s21_transpose(&A, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test5_transpose) {
  matrix_t A = {0};
  matrix_t res = {0};

  A.rows = 0;
  A.columns = 0;
  s21_create_matrix(A.rows, A.columns, &A);

  ck_assert_int_eq(MATRIX_ERR, s21_transpose(&A, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test6_transpose) {
  matrix_t A = {.matrix = NULL};
  matrix_t res = {0};

  ck_assert_int_eq(MATRIX_ERR, s21_transpose(&A, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test7_transpose) {
  ck_assert_int_eq(s21_transpose(NULL, NULL), MATRIX_ERR);
}
END_TEST

START_TEST(test8_transpose) {
  ck_assert_int_eq(s21_transpose((void*)0, (void*)0), MATRIX_ERR);
}

START_TEST(test9_transpose) {
  matrix_t A;
  matrix_t C;
  matrix_t C2;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &C2);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  C2.matrix[0][0] = 1;
  C2.matrix[0][1] = 2;
  C2.matrix[0][2] = 3;
  C2.matrix[1][0] = 4;
  C2.matrix[1][1] = 5;
  C2.matrix[1][2] = 6;
  ck_assert_int_eq(s21_transpose(&A, &C), OK);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++)
      ck_assert_double_eq(C2.matrix[i][j], C.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&C2);
}

START_TEST(test10_transpose) {
  matrix_t A;
  matrix_t C;
  s21_create_matrix(3, 5, &A);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &C), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

Suite* s21_transpose_suite() {
  Suite* suite = suite_create("s21_transpose");
  TCase* tcase = tcase_create("Core");

  tcase_add_test(tcase, test1_transpose);
  tcase_add_test(tcase, test2_transpose);
  tcase_add_test(tcase, test3_transpose);
  tcase_add_test(tcase, test4_transpose);
  tcase_add_test(tcase, test5_transpose);
  tcase_add_test(tcase, test6_transpose);
  tcase_add_test(tcase, test7_transpose);
  tcase_add_test(tcase, test8_transpose);
  tcase_add_test(tcase, test9_transpose);
  tcase_add_test(tcase, test10_transpose);

  suite_add_tcase(suite, tcase);
  return suite;
}