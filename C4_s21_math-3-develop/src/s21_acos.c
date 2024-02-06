#include "s21_math.h"
long double s21_acos(double x) {
  long double res;
  if (x == 1.) {
    res = 0;
  } else if (x == -1.) {
    res = S21_PI;
  } else if (0.0 <= x && x < 1.0) {
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (-1.0 < x && x < 0.0) {
    res = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  } else {
    res = S21_NAN;
  }
  return res;
}