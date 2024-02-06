// транспонирование матриц

#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int code_rez = OK;

  if (matrix_correct(A)) {
    code_rez = s21_create_matrix(A->columns, A->rows, result);

    if (code_rez == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  } else {
    code_rez = MATRIX_ERR;
  }
  return code_rez;
}