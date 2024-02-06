#include "suites.h"

START_TEST(default_input) {
  char *s21 = "hello, world!";
  char *final = "HELLO, WORLD!";
  ck_assert_pstr_eq(final, s21_to_upper(s21));
}
END_TEST

START_TEST(without_change) {
  char *s21 = "HELLO, WORLD!";
  char *final = "HELLO, WORLD!";
  ck_assert_pstr_eq(final, s21_to_upper(s21));
}
END_TEST

Suite *s21_to_upper_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_to_upper");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, default_input);
  tcase_add_test(test_case, without_change);
  suite_add_tcase(suite, test_case);

  return suite;
}