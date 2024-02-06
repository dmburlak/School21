// умножение на число

#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int code_rez = OK;

  if (!matrix_correct(A)) {
    code_rez = MATRIX_ERR;
  } else if (code_rez == OK) {
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return code_rez;
}