#include "../../s21_matrix.h"

void s21_minor(int x, int y, matrix_t *A, matrix_t *result) {
  s21_create_matrix(A->rows - 1, A->columns - 1, result);
  int flag_x = 0, flag_y = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == y) {
      flag_y = 1;
      continue;
    }
    for (int j = 0; j < A->columns; j++) {
      if (j == x) {
        flag_x = 1;
        continue;
      }
      result->matrix[i - flag_y][j - flag_x] = A->matrix[i][j];
    }
    flag_x = 0;
  }
}