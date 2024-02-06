#include "../suites.h"

void s21_assign_matrix(double number, matrix_t* A) {
  for (int x = 0; x < A->rows; x++) {
    for (int y = 0; y < A->columns; y++) {
      A->matrix[x][y] = number;
      number += 1.0;
    }
  }
}

START_TEST(eq_matrix_01) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_assign_matrix(1.0, &A);
  s21_create_matrix(3, 2, &B);
  s21_assign_matrix(1.0, &B);
  res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(res, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_02) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 2, &A);
  s21_assign_matrix(1.0, &A);
  s21_create_matrix(3, 2, &B);
  s21_assign_matrix(2.0, &B);
  res = s21_eq_matrix(&B, &A);

  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_03) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);
  s21_assign_matrix(-5.0, &A);
  s21_create_matrix(3, 4, &B);
  s21_assign_matrix(1.0, &B);
  res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_04) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_assign_matrix(10.0, &A);
  s21_create_matrix(3, 2, &B);
  s21_assign_matrix(-10.0, &B);
  res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_05) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_assign_matrix(1.0, &A);
  s21_create_matrix(3, 3, &B);
  s21_assign_matrix(1.0, &B);
  res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_06) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(10, 10, &A);
  s21_assign_matrix(1.0, &A);
  s21_create_matrix(10, 10, &B);
  s21_assign_matrix(1.0, &B);
  res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(res, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_07) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.1234567;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1.1234568;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  ck_assert_double_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_08) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.12345677;
  A.matrix[0][1] = 2;
  B.matrix[0][0] = 1.12345678;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_09) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 1, &B);
  A.matrix[0][0] = 1.12345677;
  A.matrix[0][1] = 0.5;
  B.matrix[0][0] = 1.12345678;
  B.matrix[1][0] = 2;

  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_10) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 1, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  B.matrix[0][0] = 1;
  B.matrix[1][0] = 1;

  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_12) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1.0;
      B.matrix[i][j] = 1.0;
    }
  }

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_13) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite* s21_eq_matrix_suite() {
  Suite* suite = suite_create("s21_eq_matrix");
  TCase* tcase = tcase_create("Core");

  tcase_add_test(tcase, eq_matrix_01);
  tcase_add_test(tcase, eq_matrix_02);
  tcase_add_test(tcase, eq_matrix_03);
  tcase_add_test(tcase, eq_matrix_04);
  tcase_add_test(tcase, eq_matrix_05);
  tcase_add_test(tcase, eq_matrix_06);
  tcase_add_test(tcase, eq_matrix_07);
  tcase_add_test(tcase, eq_matrix_08);
  tcase_add_test(tcase, eq_matrix_09);
  tcase_add_test(tcase, eq_matrix_10);
  tcase_add_test(tcase, eq_matrix_12);
  tcase_add_test(tcase, eq_matrix_13);

  suite_add_tcase(suite, tcase);
  return suite;
}