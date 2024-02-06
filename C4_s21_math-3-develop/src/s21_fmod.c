#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0.0;

  if (s21_isNan(x) || s21_isNan(y) || s21_fabs(y) < 1e-20 ||
      s21_fabs(x) == S21_INF || y == 0.0 || y == -0.0) {
    res = S21_NAN;
  } else if (x == y) {
    res = 0;
  } else if (s21_fabs(x) >= s21_fabs(y)) {
    res = x - y * s21_floor(x / y);
  } else {
    res = x;
  }

  return res;
}