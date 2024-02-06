#include "s21_math.h"

long double s21_atan(double x) {
  long double res = 0;
  if (x == S21_INF || x == -S21_INF) {
    res = x < 0 ? -S21_PI / 2 : S21_PI / 2;
  } else if (x <= 1. && x >= -1.) {
    for (long double i = 0.0; i < 5000; i += 1.0) {
      res += ((s21_pow(-1, i)) * (s21_pow(x, 2 * i + 1))) / (2 * i + 1);
    }
  } else {
    for (long double i = 0.0; i < 10000; i += 1.0) {
      res += ((s21_pow(-1, i)) * (s21_pow(x, -2 * i - 1))) / (2 * i + 1);
    }
    res = S21_PI * s21_sqrt(x * x) / (2 * x) - res;
  }
  return res;
}