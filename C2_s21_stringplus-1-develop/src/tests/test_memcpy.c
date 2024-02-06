#include "suites.h"

START_TEST(default_input) {
  char dest[15] = "hello, world";
  const char src[] = "hello";
  size_t n = 5;
  char *s21 = s21_memcpy(dest, src, n);
  char *actual = memcpy(dest, src, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(multichar) {
  char dest[30] = "привет, мир";
  const char src[] = "привет";
  size_t n = 5;
  char *s21 = s21_memcpy(dest, src, n);
  char *actual = memcpy(dest, src, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

// START_TEST(size_greater_dest) {
//     char dest[2] = "hi";
//     const char src[] = "hello";
//     size_t n = 4;
//     char *s21 = s21_memcpy(dest, src, n);
//     char *actual = memcpy(dest, src, n);
//     ck_assert_pstr_eq(actual, s21);
// }
// END_TEST

START_TEST(size_greater_src) {
  char dest[10] = {"\0"};
  const char *src = "hello";
  size_t n = 10;
  char *s21 = s21_memcpy(dest, src, n);
  char *actual = memcpy(dest, src, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_src) {
  char dest[] = "hello";
  const char src[] = {"\0"};
  size_t n = 4;
  char *s21 = s21_memcpy(dest, src, n);
  char *actual = memcpy(dest, src, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_dest) {
  char dest[] = {"\0"};
  const char *src = "hello";
  size_t n = 1;
  char *s21 = s21_memcpy(dest, src, n);
  char *actual = memcpy(dest, src, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(empty_strings) {
  char dest[5] = {"\0"};
  const char src[5] = {"\0"};
  size_t n = 4;
  char *s21 = s21_memcpy(dest, src, n);
  char *actual = memcpy(dest, src, n);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

// START_TEST(empty_strings_size_greater) {
//     char dest[5] = {"\0"};
//     const char src[5] = {"\0"};
//     size_t n = 10;
//     char *s21 = s21_memcpy(dest, src, n);
//     char *actual = memcpy(dest, src, n);
//     ck_assert_pstr_eq(actual, s21);
// }
// END_TEST

Suite *s21_memcpy_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_memcpy");

  test_case = tcase_create("Core");
  tcase_add_test(test_case, default_input);
  tcase_add_test(test_case, multichar);
  // tcase_add_test(test_case, size_greater_dest);
  tcase_add_test(test_case, size_greater_src);
  tcase_add_test(test_case, empty_src);
  tcase_add_test(test_case, empty_dest);
  tcase_add_test(test_case, empty_strings);
  // tcase_add_test(test_case, empty_strings_size_greater);
  suite_add_tcase(suite, test_case);

  return suite;
}