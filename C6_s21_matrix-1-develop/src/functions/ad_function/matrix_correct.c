#include "../../s21_matrix.h"

// проверка на существование матрицы и корректность

int matrix_correct(matrix_t *matrix) {
  return (matrix != NULL && matrix->matrix != NULL && matrix->rows >= 1 &&
          matrix->columns >= 1);
}