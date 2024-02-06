#include "s21_math.h"

long double s21_floor(double x) {
  return x < (int)x ? (long double)((int)--x) : (long double)((int)x);
}