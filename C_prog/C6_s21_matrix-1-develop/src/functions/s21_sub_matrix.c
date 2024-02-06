// вычитание

#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code_rez = OK;

  if (!matrix_correct(A) || !matrix_correct(B)) {
    code_rez = MATRIX_ERR;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    code_rez = CALC_ERR;
  }
  // else

  if (code_rez == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return code_rez;
}