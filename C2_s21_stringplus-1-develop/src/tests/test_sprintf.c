#include "suites.h"

START_TEST(without_args) {
  char s21[15] = {"\0"};
  char actual[15] = {"\0"};
  s21_sprintf(s21, "Hello, world");
  sprintf(actual, "Hello, world");
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(char_check) {
  char c = 'c';
  char s21[] = {"\0"};
  char actual[] = {"\0"};
  s21_sprintf(s21, "%c", c);
  sprintf(actual, "%c", c);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(int_check) {
  char s21[10] = {"\0"};
  char actual[10] = {"\0"};
  for (int i = -10; i < 2; i++) {
    s21_sprintf(s21, "%d", i);
    sprintf(actual, "%d", i);
    ck_assert_pstr_eq(actual, s21);
  }
}
END_TEST

START_TEST(str_check) {
  char str[] = "hello";
  char s21[10] = {"\0"};
  char actual[10] = {"\0"};
  s21_sprintf(s21, "%s", str);
  sprintf(actual, "%s", str);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(str_check_with_precision) {
  char str[] = "hello";
  char s21[10] = {"\0"};
  char actual[10] = {"\0"};
  s21_sprintf(s21, "%.15s", str);
  sprintf(actual, "%.15s", str);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(str_check_without_precision) {
  char str[] = "hello";
  char s21[10] = {"\0"};
  char actual[10] = {"\0"};
  s21_sprintf(s21, "%.1s", str);
  sprintf(actual, "%.1s", str);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(str_check_left_alignment) {
  char str[] = "hello";
  char s21[16] = {"\0"};
  char actual[16] = {"\0"};
  s21_sprintf(s21, "%-15s", str);
  sprintf(actual, "%-15s", str);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(str_check_right_alignment) {
  char str[] = "hello";
  char s21[16] = {"\0"};
  char actual[16] = {"\0"};
  s21_sprintf(s21, "%15s", str);
  sprintf(actual, "%15s", str);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(float_check) {
  char s21[10] = {"\0"};
  char actual[10] = {"\0"};
  for (float i = -2.345; i < 5; i += 0.5) {
    s21_sprintf(s21, "%f", i);
    sprintf(actual, "%f", i);
    ck_assert_pstr_eq(actual, s21);
  }
}
END_TEST

START_TEST(big_float) {
  char s21[10] = {"\0"};
  char actual[10] = {"\0"};
  float num = 41.12543;
  s21_sprintf(s21, "%f", num);
  sprintf(actual, "%f", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(round_float) {
  char s21[10] = {"\0"};
  char actual[10] = {"\0"};
  float num = 38.19999;
  s21_sprintf(s21, "%f", num);
  sprintf(actual, "%f", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(float_less_zero) {
  char s21[10] = {"\0"};
  char actual[10] = {"\0"};
  float num = -0.19999;
  s21_sprintf(s21, "%f", num);
  sprintf(actual, "%f", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(round_float_less_zero) {
  char s21[10] = {"\0"};
  char actual[10] = {"\0"};
  float num = -9.99999;
  s21_sprintf(s21, "%f", num);
  sprintf(actual, "%f", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(unsigned_check) {
  unsigned int num = 65535;
  char s21[10] = {"\0"};
  char actual[10] = {"\0"};
  s21_sprintf(s21, "%u", num);
  sprintf(actual, "%u", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(flag_minus) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  int num = 1235;
  s21_sprintf(s21, "TEST %-10d", num);
  sprintf(actual, "TEST %-10d", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(flag_plus) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  int num = 1235;
  s21_sprintf(s21, "TEST %+10d", num);
  sprintf(actual, "TEST %+10d", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(flag_plus_with_number_less_zero) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  int num = -1235;
  s21_sprintf(s21, "TEST %+10d", num);
  sprintf(actual, "TEST %+10d", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(flag_space) {
  char s21[100] = "test vas";
  char actual[100] = "test vas";
  int num = 1235;
  s21_sprintf(s21, "TEST % 10d", num);
  sprintf(actual, "TEST % 10d", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(length_l) {
  char s21[100] = "test vas";
  char actual[100] = "test vas";
  long num = 1235;
  s21_sprintf(s21, "TEST %ld", num);
  sprintf(actual, "TEST %ld", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(length_ll_left_alignment) {
  char s21[100] = "test vas";
  char actual[100] = "test vas";
  long long num = 123456789;
  s21_sprintf(s21, "TEST %-10lld", num);
  sprintf(actual, "TEST %-10lld", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(length_ll_right_alignment) {
  char s21[100] = "test vas";
  char actual[100] = "test vas";
  long long num = 123456789;
  s21_sprintf(s21, "TEST % 15.10lld", num);
  sprintf(actual, "TEST % 15.10lld", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(length_ll) {
  char s21[100] = "test vas";
  char actual[100] = "test vas";
  long long num = 123456789;
  s21_sprintf(s21, "TEST %lld", num);
  sprintf(actual, "TEST %lld", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(length_h) {
  char s21[100] = "test vas";
  char actual[100] = "test vas";
  short num = 1235;
  s21_sprintf(s21, "TEST %hd", num);
  sprintf(actual, "TEST %hd", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(length_hh) {
  char s21[100] = "test vas";
  char actual[100] = "test vas";
  short num = 1235;
  s21_sprintf(s21, "TEST %hhd", num);
  sprintf(actual, "TEST %hhd", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(float_without_precision) {
  char s21[10] = {"\0"};
  char actual[10] = {"\0"};
  float pi = 3.1415926;
  s21_sprintf(s21, "%.f", pi);
  sprintf(actual, "%.f", pi);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(float_without_precision_less_zero) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  float pi = -3.1415926;
  s21_sprintf(s21, "%.f", pi);
  sprintf(actual, "%.f", pi);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(int_precision) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  int num = 312;
  s21_sprintf(s21, "%.12d", num);
  sprintf(actual, "%.12d", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(int_precision_less_zero) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  int num = -312;
  s21_sprintf(s21, "%.12d", num);
  sprintf(actual, "%.12d", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(unsigned_length_l) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  unsigned long num = -1;
  s21_sprintf(s21, "%lu", num);
  sprintf(actual, "%lu", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(unsigned_length_ll) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  unsigned long long num = -1;
  s21_sprintf(s21, "%llu", num);
  sprintf(actual, "%llu", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(unsigned_length_h) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  unsigned short num = -1;
  s21_sprintf(s21, "%hu", num);
  sprintf(actual, "%hu", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(unsigned_length_hh) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  short num = -1;
  s21_sprintf(s21, "%hhu", num);
  sprintf(actual, "%hhu", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(minus_space) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  int num = 100;
  s21_sprintf(s21, "%- 10i", num);
  sprintf(actual, "%- 10i", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(space_minus) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  int num = 100;
  s21_sprintf(s21, "% -10i", num);
  sprintf(actual, "% -10i", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(minus_plus) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  int num = 100;
  s21_sprintf(s21, "%-+10i", num);
  sprintf(actual, "%-+10i", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(plus_minus) {
  char s21[100] = {"\0"};
  char actual[100] = {"\0"};
  int num = 100;
  s21_sprintf(s21, "%+-10i", num);
  sprintf(actual, "%+-10i", num);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(big_sprintf_1) {
  char s21[2048] = {"\0"};
  char actual[2048] = {"\0"};
  int number = 100;
  unsigned int number2 = 12;
  float pi = -2.345888888;
  char character = 'A';
  char *string = "Hello";
  short int short_number = 1235;
  long int long_number = 123456789;
  unsigned short int ushort_number = 65535;
  unsigned long int ulong_number = 4294967295;
  s21_sprintf(s21, "%-5c %+.5d %-7u %+.3f %7s %15hd % -15ld %-12hu %15lu",
              character, number, number2, pi, string, short_number, long_number,
              ushort_number, ulong_number);
  sprintf(actual, "%-5c %+.5d %-7u %+.3f %7s %15hd % -15ld %-12hu %15lu",
          character, number, number2, pi, string, short_number, long_number,
          ushort_number, ulong_number);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

START_TEST(big_sprintf_2) {
  char s21[2048] = {"\0"};
  char actual[2048] = {"\0"};
  int number = 100;
  unsigned int number2 = 12;
  float pi = -2.345888888;
  char character = 'A';
  char *string = "Hello";
  short int short_number = 1235;
  long int long_number = 123456789;
  unsigned short int ushort_number = 65535;
  unsigned long int ulong_number = 4294967295;
  s21_sprintf(s21, "%5c %.2d %5u %5f %.17s %-15hd %+15ld %12hu %-15lu",
              character, number, number2, pi, string, short_number, long_number,
              ushort_number, ulong_number);
  sprintf(actual, "%5c %.2d %5u %5f %.17s %-15hd %+15ld %12hu %-15lu",
          character, number, number2, pi, string, short_number, long_number,
          ushort_number, ulong_number);
  ck_assert_pstr_eq(actual, s21);
}
END_TEST

Suite *s21_sprintf_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21_sprintf");
  test_case = tcase_create("Core");
  tcase_add_test(test_case, without_args);
  tcase_add_test(test_case, char_check);
  tcase_add_test(test_case, int_check);
  tcase_add_test(test_case, str_check);
  tcase_add_test(test_case, str_check_with_precision);
  tcase_add_test(test_case, str_check_without_precision);
  tcase_add_test(test_case, str_check_left_alignment);
  tcase_add_test(test_case, str_check_right_alignment);
  tcase_add_test(test_case, float_check);
  tcase_add_test(test_case, big_float);
  tcase_add_test(test_case, round_float);
  tcase_add_test(test_case, float_less_zero);
  tcase_add_test(test_case, round_float_less_zero);
  tcase_add_test(test_case, unsigned_check);
  tcase_add_test(test_case, flag_minus);
  tcase_add_test(test_case, flag_plus);
  tcase_add_test(test_case, flag_plus_with_number_less_zero);
  tcase_add_test(test_case, flag_space);
  tcase_add_test(test_case, length_l);
  tcase_add_test(test_case, length_ll_left_alignment);
  tcase_add_test(test_case, length_ll_right_alignment);
  tcase_add_test(test_case, length_ll);
  tcase_add_test(test_case, length_h);
  tcase_add_test(test_case, length_hh);
  tcase_add_test(test_case, float_without_precision);
  tcase_add_test(test_case, float_without_precision_less_zero);
  tcase_add_test(test_case, int_precision);
  tcase_add_test(test_case, int_precision_less_zero);
  tcase_add_test(test_case, unsigned_length_l);
  tcase_add_test(test_case, unsigned_length_ll);
  tcase_add_test(test_case, unsigned_length_h);
  tcase_add_test(test_case, unsigned_length_hh);
  tcase_add_test(test_case, minus_space);
  tcase_add_test(test_case, space_minus);
  tcase_add_test(test_case, minus_plus);
  tcase_add_test(test_case, plus_minus);
  tcase_add_test(test_case, big_sprintf_1);
  tcase_add_test(test_case, big_sprintf_2);
  suite_add_tcase(suite, test_case);
  return suite;
}
