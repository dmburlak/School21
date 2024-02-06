#include "s21_math.h"

long double s21_tan(double x) {
  // Используем тригонометрическое тождество: tan(x) = sin(x) / cos(x)
  return s21_sin(x) / s21_cos(x);
}