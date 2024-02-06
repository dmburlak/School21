#include "s21_math.h"

long double s21_log(double x) {
  int whole_part = 0;
  long double rest_part = 0, c = 0;
  long double result = 0.0;

  if (x == 1.0) {
    result = 0.0;
  } else if (x == 0) {
    result = -S21_INF;
  } else if (x < 0) {
    result = S21_NAN;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else {
    // вычисляем целую часть ответа.
    // делим экспоненту на саму себя так много раз,
    // пока не найдем все целые итерации.
    for (; x >= S21_EXP; whole_part++) {
      x /= S21_EXP;
      continue;
    }
    // вычисляем часть после запятой.
    // используем метод Галлея.
    for (int i = 0; i < 200; i++) {
      c = rest_part;
      rest_part = c + 2 * (x - s21_exp(c)) / (x + s21_exp(c));
    }
    result = whole_part + rest_part;
  }
  return (result);
}
