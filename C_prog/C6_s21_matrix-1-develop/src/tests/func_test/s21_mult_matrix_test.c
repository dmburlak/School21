#include "../suites.h"

START_TEST(test1_mult_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 5;
  B.matrix[0][1] = 6;
  B.matrix[1][0] = 7;
  B.matrix[1][1] = 8;

  ck_assert_int_eq(OK, s21_mult_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test2_mult_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);

  A.matrix[0][0] = 1;
  A.matrix[1][0] = 2;
  A.matrix[2][0] = 3;
  A.matrix[0][1] = 4;
  A.matrix[1][1] = 5;
  A.matrix[2][1] = 6.4955022;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4.35954221;

  ck_assert_int_eq(OK, s21_mult_matrix(&A, &B, &res));
  ck_assert_double_eq_tol(31.317416, res.matrix[2][2], 8);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test3_mult_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  A.rows = -2;
  A.columns = -2;
  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(2, 2, &B);

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  ck_assert_int_eq(MATRIX_ERR, s21_mult_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

END_TEST

START_TEST(test4_mult_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  A.rows = -2;
  A.columns = -2;
  B.rows = 0;
  B.columns = -1;
  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(B.rows, B.columns, &B);

  ck_assert_int_eq(MATRIX_ERR, s21_mult_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test5_mult_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2.12345678;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0;
  B.matrix[1][2] = 0;
  B.matrix[2][0] = 3.987655432;
  B.matrix[2][1] = 4;
  B.matrix[2][2] = 1;

  ck_assert_int_eq(OK, s21_mult_matrix(&A, &B, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test6_mult_matrix) {
  matrix_t A = {.matrix = NULL};
  matrix_t B = {0};
  matrix_t res = {0};

  s21_create_matrix(3, 3, &B);

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0;
  B.matrix[1][2] = 0;
  B.matrix[2][0] = 3.987655432;
  B.matrix[2][1] = 4;
  B.matrix[2][2] = 1;

  ck_assert_int_eq(MATRIX_ERR, s21_mult_matrix(&A, &B, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test7_mult_matrix) {
  matrix_t A = {0};
  matrix_t B = {.matrix = NULL};
  matrix_t res = {0};

  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 2.3445567;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 4;
  A.matrix[2][2] = 1;

  ck_assert_int_eq(MATRIX_ERR, s21_mult_matrix(&A, &B, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test8_mult_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);

  ck_assert_int_eq(CALC_ERR, s21_mult_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

START_TEST(test9_mult_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);

  ck_assert_int_eq(CALC_ERR, s21_mult_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

START_TEST(test10_mult_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  s21_create_matrix(0, -2, &A);
  s21_create_matrix(2, 2, &B);

  ck_assert_int_eq(MATRIX_ERR, s21_mult_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test11_mult_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 2, &B);

  ck_assert_int_eq(MATRIX_ERR, s21_mult_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test12_mult_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  A.rows = -2;
  A.columns = -2;
  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(-2, -2, &B);

  ck_assert_int_eq(MATRIX_ERR, s21_mult_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

Suite* s21_mult_matrix_suite() {
  Suite* suite = suite_create("s21_mult_matrix");
  TCase* tcase = tcase_create("Core");

  tcase_add_test(tcase, test1_mult_matrix);
  tcase_add_test(tcase, test2_mult_matrix);
  tcase_add_test(tcase, test3_mult_matrix);
  tcase_add_test(tcase, test4_mult_matrix);
  tcase_add_test(tcase, test5_mult_matrix);
  tcase_add_test(tcase, test6_mult_matrix);
  tcase_add_test(tcase, test7_mult_matrix);
  tcase_add_test(tcase, test8_mult_matrix);
  tcase_add_test(tcase, test9_mult_matrix);
  tcase_add_test(tcase, test10_mult_matrix);
  tcase_add_test(tcase, test11_mult_matrix);
  tcase_add_test(tcase, test12_mult_matrix);

  suite_add_tcase(suite, tcase);
  return suite;
}