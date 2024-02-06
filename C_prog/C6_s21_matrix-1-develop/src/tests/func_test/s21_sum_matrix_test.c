#include "../suites.h"

START_TEST(test1_sum_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
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
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 4;
  B.matrix[2][2] = 1;

  ck_assert_int_eq(OK, s21_sum_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test2_sum_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0;
  B.matrix[1][2] = 0;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 4;
  B.matrix[2][2] = 1;

  ck_assert_int_eq(CALC_ERR, s21_sum_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test3_sum_matrix) {
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

  ck_assert_int_eq(MATRIX_ERR, s21_sum_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test4_sum_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  A.rows = -2;
  A.columns = -2;
  B.rows = 0;
  B.columns = -1;
  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(B.rows, B.columns, &B);

  ck_assert_int_eq(MATRIX_ERR, s21_sum_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test5_sum_matrix) {
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

  ck_assert_int_eq(OK, s21_sum_matrix(&A, &B, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test6_sum_matrix) {
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

  ck_assert_int_eq(MATRIX_ERR, s21_sum_matrix(&A, &B, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test7_sum_matrix) {
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

  ck_assert_int_eq(MATRIX_ERR, s21_sum_matrix(&A, &B, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

// START_TEST(test8_sum_matrix) {
//   matrix_t A = {0};
//   matrix_t B = {0};
//   matrix_t res = {0};

//   s21_create_matrix(2, 3, &A);
//   s21_create_matrix(2, 3, &B);

//   A.matrix[0][0] = 5;
//   A.matrix[0][1] = -1;
//   A.matrix[0][2] = 4;
//   A.matrix[1][0] = 3;
//   A.matrix[1][1] = 7;
//   A.matrix[1][2] = -6;

//   B.matrix[0][0] = 0;
//   B.matrix[0][1] = 4;
//   B.matrix[0][2] = 2;
//   B.matrix[1][0] = -1;
//   B.matrix[1][1] = 3;
//   B.matrix[1][2] = -1;

//   ck_assert_int_eq(OK, s21_sum_matrix(&A, &B, &res));
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
//   s21_remove_matrix(&res);
// }

START_TEST(test9_sum_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  A.rows = 2;
  A.columns = -2;
  B.rows = 0;
  B.columns = -1;
  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(B.rows, B.columns, &B);

  ck_assert_int_eq(MATRIX_ERR, s21_sum_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test10_sum_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 3, &B);

  ck_assert_int_eq(CALC_ERR, s21_sum_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

Suite* s21_sum_matrix_suite() {
  Suite* suite = suite_create("s21_sum_matrix");
  TCase* tcase = tcase_create("Core");

  tcase_add_test(tcase, test1_sum_matrix);
  tcase_add_test(tcase, test2_sum_matrix);
  tcase_add_test(tcase, test3_sum_matrix);
  tcase_add_test(tcase, test4_sum_matrix);
  tcase_add_test(tcase, test5_sum_matrix);
  tcase_add_test(tcase, test6_sum_matrix);
  tcase_add_test(tcase, test7_sum_matrix);
  // tcase_add_test(tcase, test8_sum_matrix);
  tcase_add_test(tcase, test9_sum_matrix);
  tcase_add_test(tcase, test10_sum_matrix);

  suite_add_tcase(suite, tcase);
  return suite;
}