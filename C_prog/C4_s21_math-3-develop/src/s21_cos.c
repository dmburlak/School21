#include "s21_math.h"

long double s21_cos(double x) {
  // Использование тригонометрического тождества: cos(x) = sin(x + π/2)
  return s21_sin(x + S21_PI / 2);
}
