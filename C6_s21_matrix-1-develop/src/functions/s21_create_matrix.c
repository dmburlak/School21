// создание матрицы

#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int code_rez = OK;
  //  проверка на корректность матрицы
  if (rows <= 0 || columns <= 0 || result == NULL) {
    code_rez = MATRIX_ERR;
  } else {
    //  выделяем память для массива строчек типа double *
    result->matrix = (double **)calloc(rows, sizeof(double *));

    for (int i = 0; i < rows; i++) {
      //  вдыеляем память для массива double значений
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    result->rows = rows;
    result->columns = columns;
  }
  return code_rez;
}