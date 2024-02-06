#include "../suites.h"

START_TEST(calc_comp_0) {
  ck_assert_int_eq(s21_calc_complements((void*)0, (void*)0), MATRIX_ERR);
}
START_TEST(calc_comp_1) {
  ck_assert_int_eq(s21_calc_complements(NULL, NULL), MATRIX_ERR);
}
START_TEST(calc_comp_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  ck_assert_int_eq(s21_calc_complements(&A, &B), CALC_ERR);
  s21_remove_matrix(&A);
}
START_TEST(calc_comp_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  B.matrix[0][0] = 0;
  B.matrix[0][1] = 10;
  B.matrix[0][2] = -20;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = -14;
  B.matrix[1][2] = 8;
  B.matrix[2][0] = -8;
  B.matrix[2][1] = -2;
  B.matrix[2][2] = 4;
  ck_assert_int_eq(s21_calc_complements(&A, &C), OK);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      ck_assert_double_eq(B.matrix[i][j], C.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
START_TEST(calc_comp_4) {
  matrix_t A;
  matrix_t C;
  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, &C), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
START_TEST(calc_comp_5) {
  matrix_t A = {0}, result = {0};
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j / 3.3;
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_calc_complements(NULL, &result), MATRIX_ERR);
  ck_assert_int_eq(s21_calc_complements((void*)0, &result), MATRIX_ERR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_comp_6) {
  matrix_t A = {0}, result = {0}, result_true = {0};
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &result_true);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  result_true.matrix[0][0] = 0;
  result_true.matrix[0][1] = 10;
  result_true.matrix[0][2] = -20;
  result_true.matrix[1][0] = 4;
  result_true.matrix[1][1] = -14;
  result_true.matrix[1][2] = 8;
  result_true.matrix[2][0] = -8;
  result_true.matrix[2][1] = -2;
  result_true.matrix[2][2] = 4;
  s21_calc_complements(&A, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &result_true), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result_true);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_comp_7) {
  matrix_t A = {0};
  matrix_t res = {0};

  A.rows = 3;
  A.columns = 3;
  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  ck_assert_int_eq(OK, s21_calc_complements(&A, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_comp_8) {
  matrix_t A = {0};
  matrix_t res = {0};

  A.rows = 3;
  A.columns = 3;
  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  ck_assert_int_eq(OK, s21_calc_complements(&A, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_comp_9) {
  matrix_t A = {0};
  matrix_t res = {0};

  A.rows = 2;
  A.columns = 3;
  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;

  ck_assert_int_eq(CALC_ERR, s21_calc_complements(&A, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_comp_10) {
  matrix_t A = {0};
  matrix_t res = {0};

  A.rows = -2;
  A.columns = -2;
  s21_create_matrix(A.rows, A.columns, &A);

  ck_assert_int_eq(MATRIX_ERR, s21_calc_complements(&A, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_comp_11) {
  ck_assert_int_eq(s21_calc_complements(NULL, NULL), MATRIX_ERR);
}
END_TEST

START_TEST(calc_comp_12) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  ck_assert_int_eq(s21_calc_complements(NULL, &A), MATRIX_ERR);
}
END_TEST

START_TEST(calc_comp_13) {
  matrix_t A, B;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;
  ck_assert_int_eq(s21_calc_complements(&A, &B), MATRIX_ERR);
}
END_TEST

Suite* s21_calc_complements_suite() {
  Suite* suite = suite_create("s21_calc_complements");
  TCase* tcase = tcase_create("Core");

  tcase_add_test(tcase, calc_comp_0);
  tcase_add_test(tcase, calc_comp_1);
  tcase_add_test(tcase, calc_comp_2);
  tcase_add_test(tcase, calc_comp_3);
  tcase_add_test(tcase, calc_comp_4);
  tcase_add_test(tcase, calc_comp_5);
  tcase_add_test(tcase, calc_comp_6);
  tcase_add_test(tcase, calc_comp_7);
  tcase_add_test(tcase, calc_comp_8);
  tcase_add_test(tcase, calc_comp_9);
  tcase_add_test(tcase, calc_comp_10);
  tcase_add_test(tcase, calc_comp_11);
  tcase_add_test(tcase, calc_comp_12);
  tcase_add_test(tcase, calc_comp_13);

  suite_add_tcase(suite, tcase);
  return suite;
}
