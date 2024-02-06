#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

#define D_MIN 1e-28
#define D_MAX 79228162514264337593543950335.0

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[6];
  unsigned int general;
} s21_long_decimal;

// math
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_add_long(s21_long_decimal value_1, s21_long_decimal value_2, s21_long_decimal *res);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_sub_long(s21_long_decimal val_1, s21_long_decimal val_2, s21_long_decimal* res);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// comprasion
int s21_is_less(s21_decimal, s21_decimal);
bool s21_less_long(s21_long_decimal value_1, s21_long_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_greater_long(s21_long_decimal l_dec_1, s21_long_decimal l_dec_2);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_greater_or_equal_long(s21_long_decimal value_1, s21_long_decimal value_2);
int s21_is_equal(s21_decimal, s21_decimal);
bool s21_equality(s21_long_decimal value_1, s21_long_decimal value_2);
int s21_is_not_equal(s21_decimal, s21_decimal);

// convert
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int get_string_exp(char *str);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// other
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
void s21_long_truncate(s21_long_decimal value, s21_long_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// support
void s21_decimal_cpy(s21_long_decimal *value, s21_long_decimal source);
int s21_div_by_ten(s21_long_decimal* value);
int s21_get_bit(s21_long_decimal value, unsigned char index);
int s21_get_exp(s21_long_decimal value);
bool s21_get_sign(s21_long_decimal value);
bool s21_is_zero(s21_long_decimal value);
void s21_left_shift(s21_long_decimal *value);
int s21_long_to_normal(s21_long_decimal value_1, s21_decimal* res);
long s21_get_upper_bits_sum(s21_long_decimal value);
void s21_mul_ten(s21_long_decimal *value);
void s21_same_exp(s21_long_decimal *value_1, s21_long_decimal *value_2);
void s21_limit_exp(s21_long_decimal *value);
void s21_set_exp(s21_long_decimal* value, unsigned int exp);
void s21_set_sign(s21_long_decimal *value, bool sign);
void s21_set_zero(s21_decimal *value);
void s21_long_set_zero(s21_long_decimal *value);
void s21_to_long_decimal(s21_decimal value, s21_long_decimal *res);

#endif