// перемножение матриц

#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code_rez = OK;

  if (matrix_correct(A) && matrix_correct(B)) {
    if (A->columns == B->rows || A->rows == B->columns) {
      code_rez = s21_create_matrix(A->rows, B->columns, result);
      if (code_rez == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            // Инициализация элемента результата
            result->matrix[i][j] = 0;
            for (int k = 0; k < B->rows; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      }
    } else {
      // Несовпадающие размеры матриц
      code_rez = CALC_ERR;
    }
  } else {
    // Некорректная матрица
    code_rez = MATRIX_ERR;
  }

  return code_rez;
}