#include "../suites.h"

START_TEST(create_matrix_1) {
  matrix_t result;
  ck_assert_int_eq(s21_create_matrix(-2, 2, &result), MATRIX_ERR);
}
END_TEST

START_TEST(create_matrix_2) {
  ck_assert_int_eq(s21_create_matrix(0, 2, (void *)0), MATRIX_ERR);
}
END_TEST

START_TEST(create_matrix_3) {
  ck_assert_int_eq(s21_create_matrix(0, 0, (void *)0), MATRIX_ERR);
}
END_TEST

START_TEST(create_matrix_4) {
  ck_assert_int_eq(s21_create_matrix(0, 0, (void *)0), MATRIX_ERR);
}
END_TEST

START_TEST(create_matrix_5) {
  matrix_t result;
  int res = s21_create_matrix(2, 2, &result);
  ck_assert_int_eq(res, OK);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) ck_assert_double_eq(result.matrix[i][j], 0);
  s21_remove_matrix(&result);
}
END_TEST
START_TEST(create_matrix_6) {
  matrix_t result;
  int res = s21_create_matrix(5, 12, &result);
  ck_assert_int_eq(res, OK);
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 12; j++) ck_assert_double_eq(result.matrix[i][j], 0);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_matrix_7) {
  int rows = 2;
  int columns = 2;
  matrix_t myMatrix;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &myMatrix), OK);
  s21_remove_matrix(&myMatrix);
}
END_TEST

START_TEST(create_matrix_8) {
  int res = 1;
  matrix_t A = {0};

  res = s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_9) {
  int rows = -2;
  int columns = -2;
  matrix_t myMatrix;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &myMatrix), MATRIX_ERR);
}

START_TEST(create_matrix_10) {
  ck_assert_int_eq(s21_create_matrix(2, 2, NULL), MATRIX_ERR);
}
END_TEST

START_TEST(create_matrix_11) {
  ck_assert_int_eq(s21_create_matrix(2, 2, (void *)0), MATRIX_ERR);
}
END_TEST

Suite *s21_create_matrix_suite() {
  Suite *suite = suite_create("s21_create_matrix");
  TCase *tcase = tcase_create("Core");
  tcase_add_test(tcase, create_matrix_1);
  tcase_add_test(tcase, create_matrix_2);
  tcase_add_test(tcase, create_matrix_3);
  tcase_add_test(tcase, create_matrix_4);
  tcase_add_test(tcase, create_matrix_5);
  tcase_add_test(tcase, create_matrix_6);
  tcase_add_test(tcase, create_matrix_7);
  tcase_add_test(tcase, create_matrix_8);
  tcase_add_test(tcase, create_matrix_9);
  tcase_add_test(tcase, create_matrix_10);
  tcase_add_test(tcase, create_matrix_11);
  suite_add_tcase(suite, tcase);
  return suite;
}