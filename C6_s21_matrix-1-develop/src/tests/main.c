#include "suites.h"

int main() {
  int failed;
  Suite *suite[] = {

      s21_calc_complements_suite(), s21_create_matrix_suite(),
      s21_determinante_suite(),     s21_eq_matrix_suite(),
      s21_inverse_matrix_suite(),   s21_mult_matrix_suite(),
      s21_mult_number_suite(),      s21_sub_matrix_suite(),
      s21_sum_matrix_suite(),       s21_transpose_suite(),
  };

  SRunner *runner;

  for (size_t i = 0; i < sizeof(suite) / sizeof(char *); i++) {
    runner = srunner_create(suite[i]);
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return (failed == 0) ? 0 : 1;
}
