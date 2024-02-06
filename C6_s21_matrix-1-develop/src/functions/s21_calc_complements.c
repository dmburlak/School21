// вычисление матрицы алгебраических дополнений

#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code_rez = OK;

  if (!matrix_correct(A)) {
    code_rez = MATRIX_ERR;
  } else if (A->rows != A->columns || A->rows == 1) {
    code_rez = CALC_ERR;
  } else {
    double buffer = 0;
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        buffer = 0;
        matrix_t BufferMat = {0};
        s21_minor(j, i, A, &BufferMat);
        s21_determinant(&BufferMat, &buffer);
        // минор детерминировали и умножили на -1 в степени i+j
        result->matrix[i][j] = buffer * pow(-1, i + j);
        s21_remove_matrix(&BufferMat);
      }
    }
  }
  return code_rez;
}