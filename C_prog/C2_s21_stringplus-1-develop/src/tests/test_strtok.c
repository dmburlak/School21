#include "suites.h"

START_TEST(default_input) {
  char str[] = "test, str sTr";
  char delim[] = ", ";

  char *s21 = s21_strtok(str, delim);
  while (s21 != NULL) {
    s21 = s21_strtok(NULL, delim);
  }

  char *actual = strtok(str, delim);
  while (actual != NULL) {
    actual = strtok(NULL, delim);
  }

  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(multichar) {
  char str[] = "привет, поехали в Авиапарк";
  char delim[] = ", ";

  char *s21 = s21_strtok(str, delim);
  while (s21 != NULL) {
    s21 = s21_strtok(NULL, delim);
  }

  char *actual = strtok(str, delim);
  while (actual != NULL) {
    actual = strtok(NULL, delim);
  }

  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_delim) {
  char str[] = "test, str sTr";
  char delim[] = "";

  char *s21 = s21_strtok(str, delim);
  while (s21 != NULL) {
    s21 = s21_strtok(NULL, delim);
  }

  char *actual = strtok(str, delim);
  while (actual != NULL) {
    actual = strtok(NULL, delim);
  }

  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(word_delim) {
  char str[] = "test, str sTr";
  char delim[] = "str";

  char *s21 = s21_strtok(str, delim);
  while (s21 != NULL) {
    s21 = s21_strtok(NULL, delim);
  }

  char *actual = strtok(str, delim);
  while (actual != NULL) {
    actual = strtok(NULL, delim);
  }

  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(null_delim) {
  char str[] = "test, str sTr";
  char delim[] = {"\0"};

  char *s21 = s21_strtok(str, delim);
  while (s21 != NULL) {
    s21 = s21_strtok(NULL, delim);
  }

  char *actual = strtok(str, delim);
  while (actual != NULL) {
    actual = strtok(NULL, delim);
  }

  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_str) {
  char str[] = "";
  char delim[] = {"\0"};

  char *s21 = s21_strtok(str, delim);
  while (s21 != NULL) {
    s21 = s21_strtok(NULL, delim);
  }

  char *actual = strtok(str, delim);
  while (actual != NULL) {
    actual = strtok(NULL, delim);
  }

  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(null_str) {
  char *str = S21_NULL;
  char delim[] = {"\0"};

  char *s21 = s21_strtok(str, delim);
  while (s21 != NULL) {
    s21 = s21_strtok(NULL, delim);
  }

  char *actual = strtok(str, delim);
  while (actual != NULL) {
    actual = strtok(NULL, delim);
  }

  ck_assert_pstr_eq(actual, s21);
}
END_TEST

Suite *s21_strtok_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_strtok");

  test_case = tcase_create("Core");
  tcase_add_test(test_case, default_input);
  tcase_add_test(test_case, multichar);
  tcase_add_test(test_case, empty_delim);
  tcase_add_test(test_case, word_delim);
  tcase_add_test(test_case, null_delim);
  tcase_add_test(test_case, empty_str);
  tcase_add_test(test_case, null_str);
  suite_add_tcase(suite, test_case);

  return suite;
}
