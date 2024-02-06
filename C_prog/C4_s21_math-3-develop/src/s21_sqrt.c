#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res = 0.0;
  if (x < 0.0) {
    res = S21_NAN;
  } else if (x == S21_INF || s21_isNan(x)) {
    res = x;
  } else {
    double low = 0.0;
    double high = 1;
    if (x > 1) {
      high = x;
    }
    while (high - low > S21_EPS) {
      double mid = (low + high) / 2.0;
      if (mid * mid < x) {
        low = mid;
      } else {
        high = mid;
      }
    }
    res = low;
  }
  return res;
}
