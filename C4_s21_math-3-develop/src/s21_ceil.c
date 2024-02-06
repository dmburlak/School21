#include "s21_math.h"

long double s21_ceil(double x) {
  return x > (int)x ? (long double)((int)++x) : (long double)((int)x);
}