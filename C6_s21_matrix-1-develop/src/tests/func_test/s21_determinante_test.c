#include "../suites.h"

START_TEST(det_0) { ck_assert_int_eq(s21_determinant(NULL, NULL), MATRIX_ERR); }
END_TEST

START_TEST(det_1) {
  ck_assert_int_eq(s21_determinant((void*)0, (void*)0), MATRIX_ERR);
}

START_TEST(det_2) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  ck_assert_int_eq(s21_determinant(&A, &result), CALC_ERR);
  s21_remove_matrix(&A);
}
START_TEST(det_3) {
  matrix_t A;
  double result;
  double result2;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  result2 = -9;
  ck_assert_double_eq(result, result2);
  s21_remove_matrix(&A);
}
START_TEST(det_4) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  s21_remove_matrix(&A);
}

START_TEST(det_5) {
  matrix_t A = {0};
  double result;
  A.rows = 3;
  A.columns = 3;
  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_6) {
  matrix_t A = {0};
  double result;
  A.rows = 2;
  A.columns = 2;
  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_7) {
  matrix_t A = {0};
  double result;
  A.rows = 3;
  A.columns = 3;
  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = -2.75;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 3.53;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = -1.33;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 0;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_9) {
  matrix_t A = {0};
  double result;

  A.rows = -2;
  A.columns = -2;
  s21_create_matrix(A.rows, A.columns, &A);

  ck_assert_int_eq(MATRIX_ERR, s21_determinant(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_10) {
  matrix_t* A = NULL;
  double result;

  ck_assert_int_eq(MATRIX_ERR, s21_determinant(A, &result));
}
END_TEST

START_TEST(det_11) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 13;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[1][3] = 16;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 90;
  A.matrix[2][3] = 19;
  A.matrix[3][0] = 1;
  A.matrix[3][1] = 7;
  A.matrix[3][2] = 7;
  A.matrix[3][3] = 17;

  s21_determinant(&A, &result);
  ck_assert_int_eq(result, 13608);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_12) {
  matrix_t A;
  double B, R = -69.0 / 4.0;
  s21_create_matrix(5, 5, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[0][3] = 3.25;
  A.matrix[0][4] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[1][3] = 5.25;
  A.matrix[1][4] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;
  A.matrix[2][3] = 6.25;
  A.matrix[2][4] = 6.25;
  A.matrix[3][0] = 6.25;
  A.matrix[3][1] = 7.25;
  A.matrix[3][2] = 8.25;
  A.matrix[3][3] = 6.25;
  A.matrix[3][4] = 7.25;
  A.matrix[4][0] = 6.25;
  A.matrix[4][1] = 7.25;
  A.matrix[4][2] = 8.25;
  A.matrix[4][3] = 6;
  A.matrix[4][4] = 8.25;

  s21_determinant(&A, &B);
  ck_assert(fabs(B - R) < 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

Suite* s21_determinante_suite() {
  Suite* suite = suite_create("s21_determinante");
  TCase* tcase = tcase_create("Core");

  tcase_add_test(tcase, det_0);
  tcase_add_test(tcase, det_1);
  tcase_add_test(tcase, det_2);
  tcase_add_test(tcase, det_3);
  tcase_add_test(tcase, det_4);
  tcase_add_test(tcase, det_5);
  tcase_add_test(tcase, det_6);
  tcase_add_test(tcase, det_7);
  tcase_add_test(tcase, det_9);
  tcase_add_test(tcase, det_10);
  tcase_add_test(tcase, det_11);
  tcase_add_test(tcase, det_12);

  suite_add_tcase(suite, tcase);
  return suite;
}