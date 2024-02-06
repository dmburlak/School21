#include "suites.h"

int main() {
  int failed = 0;
  Suite *suite[] = {
      s21_abs_suite(),   s21_acos_suite(), s21_asin_suite(), s21_atan_suite(),
      s21_ceil_suite(),  s21_cos_suite(),  s21_exp_suite(),  s21_fabs_suite(),
      s21_floor_suite(), s21_fmod_suite(), s21_log_suite(),  s21_pow_suite(),
      s21_sin_suite(),   s21_sqrt_suite(), s21_tan_sutie(),
  };
  SRunner *run;

  for (size_t i = 0; i < sizeof(suite) / sizeof(char *); i++) {
    run = srunner_create(suite[i]);
    srunner_run_all(run, CK_NORMAL);
    failed = srunner_ntests_failed(run);
    srunner_free(run);
  }

  return (failed == 0) ? 0 : 1;
}