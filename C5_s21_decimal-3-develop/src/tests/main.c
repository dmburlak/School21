#include "suites.h"

int main() {
  int failed;
  Suite *suite[] = {

      s21_div_suite(),
      s21_add_suite(),
      s21_sub_suite(),
      s21_mul_suite(),

      s21_is_less_suite(),
      s21_is_less_or_equal_suite(),
      s21_is_greater_suite(),
      s21_is_greater_or_equal_suite(),
      s21_is_equal_suite(),
      s21_is_not_equal_suite(),

      s21_from_decimal_to_float_suite(),
      s21_from_float_to_decimal_suite(),
      s21_from_int_to_decimal_suite(),
      s21_from_decimal_to_int_suite(),

      s21_floor_suite(),
      s21_round_suite(),
      s21_truncate_suite(),
      s21_negate_suite(),
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