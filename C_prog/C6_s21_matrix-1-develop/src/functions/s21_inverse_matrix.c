// поиск обратной матрицы

#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code_rez = OK;

  if (!matrix_correct(A)) {
    code_rez = MATRIX_ERR;
  }
  // Проверяем, что матрица A является квадратной
  // и состоит не из одно  колонки
  else if (A->rows != A->columns) {
    code_rez = CALC_ERR;
  } else if (A->columns == 1) {
    code_rez = CALC_ERR;
  } else {
    // этап 1 - найти детерминант
    double det;
    s21_determinant(A, &det);

    if (det != 0) {
      // этап 2 - создаем матрицу алгебраических дополнений
      matrix_t algoibr_matrix;
      code_rez = s21_calc_complements(A, &algoibr_matrix);

      if (code_rez == OK) {
        // этап 3 - создаем транспонированную матрицу
        matrix_t trans_matrix;
        code_rez = s21_transpose(&algoibr_matrix, &trans_matrix);

        if (code_rez == OK) {
          // этап 4 - умножаем транспонированную на
          // обратное значение детерминанта
          s21_mult_number(&trans_matrix, 1 / det, result);
        }
        s21_remove_matrix(&trans_matrix);
      }
      s21_remove_matrix(&algoibr_matrix);

    } else {
      code_rez = CALC_ERR;
    }
  }
  return code_rez;
}