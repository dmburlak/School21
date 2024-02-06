#include "../suites.h"

START_TEST(test1_sub_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 1.3456679;
  A.matrix[0][1] = -3;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = -1;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 9;
  A.matrix[2][2] = -2;

  B.matrix[0][0] = 3;
  B.matrix[0][1] = -4;
  B.matrix[0][2] = 5;
  B.matrix[1][0] = 2.56432783;
  B.matrix[1][1] = -3;
  B.matrix[1][2] = 1;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = -5;
  B.matrix[2][2] = 2;

  ck_assert_int_eq(OK, s21_sub_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test2_sub_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};

  matrix_t res = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = -3;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = -1;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 9;
  A.matrix[2][2] = -2;

  B.matrix[0][0] = 3;
  B.matrix[0][1] = -4;
  B.matrix[0][2] = 5;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = -3;
  B.matrix[1][2] = 1;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = -5;
  B.matrix[2][2] = 2;

  C.matrix[0][0] = -2;
  C.matrix[0][1] = 1;
  C.matrix[0][2] = -6;
  C.matrix[1][0] = -3;
  C.matrix[1][1] = 7;
  C.matrix[1][2] = 0;
  C.matrix[2][0] = -2;
  C.matrix[2][1] = 14;
  C.matrix[2][2] = -4;

  ck_assert_int_eq(OK, s21_sub_matrix(&A, &B, &res));
  ck_assert_int_eq(C.matrix[2][0], res.matrix[2][0]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test3_sub_matrix) {
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

  ck_assert_int_eq(CALC_ERR, s21_sub_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test4_sub_matrix) {
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

  ck_assert_int_eq(MATRIX_ERR, s21_sub_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test5_sub_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  A.rows = -2;
  A.columns = -2;
  B.rows = 0;
  B.columns = -1;
  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(B.rows, B.columns, &B);

  ck_assert_int_eq(MATRIX_ERR, s21_sub_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test6_sub_matrix) {
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

  ck_assert_int_eq(OK, s21_sub_matrix(&A, &B, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test7_sub_matrix) {
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

  ck_assert_int_eq(MATRIX_ERR, s21_sub_matrix(&A, &B, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test8_sub_matrix) {
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

  ck_assert_int_eq(MATRIX_ERR, s21_sub_matrix(&A, &B, &res));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

// START_TEST(test9_sub_matrix) {
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

//   ck_assert_int_eq(OK, s21_sub_matrix(&A, &B, &res));
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
//   s21_remove_matrix(&res);
// }
// END_TEST

START_TEST(test10_sub_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};

  A.rows = 2;
  A.columns = -2;
  B.rows = 0;
  B.columns = -1;
  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(B.rows, B.columns, &B);

  ck_assert_int_eq(MATRIX_ERR, s21_sub_matrix(&A, &B, &res));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

Suite* s21_sub_matrix_suite() {
  Suite* suite = suite_create("s21_sub_matrix");
  TCase* tcase = tcase_create("Core");
  tcase_add_test(tcase, test1_sub_matrix);
  tcase_add_test(tcase, test2_sub_matrix);
  tcase_add_test(tcase, test3_sub_matrix);
  tcase_add_test(tcase, test4_sub_matrix);
  tcase_add_test(tcase, test5_sub_matrix);
  tcase_add_test(tcase, test6_sub_matrix);
  tcase_add_test(tcase, test7_sub_matrix);
  tcase_add_test(tcase, test8_sub_matrix);
  // tcase_add_test(tcase, test9_sub_matrix);
  tcase_add_test(tcase, test10_sub_matrix);
  suite_add_tcase(suite, tcase);
  return suite;
}