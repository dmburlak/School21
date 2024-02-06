#include "s21_string.h"

void s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  s21_size_t i, j;
  for (i = 0, j = 0; format[i] != 0; i++, j++) {
    if (format[i] == '%') {
      flags flag = {0};
      findFlags(format, &flag, &i);
      findWidth(format, &flag.width, &i);
      findPrecision(format, &flag, &i);
      findLength(format, &flag, &i);
      findSpecifier(format[i], &flag, args);
      fillStr(flag, str, &j);
    } else {
      str[j] = format[i];
    }
  }
  str[j] = '\0';
  va_end(args);
}

void findFlags(const char *format, flags *flag, s21_size_t *i) {
  bool point = true;
  while (point) {
    switch (format[++(*i)]) {
      case '-':
        flag->minus = true;
        break;
      case '+':
        flag->plus = true;
        break;
      case ' ':
        flag->space = true;
        break;
      default:
        point = false;
        break;
    }
  }
}

void findWidth(const char *format, s21_size_t *width, s21_size_t *i) {
  while (format[*i] >= '0' && format[*i] <= '9') {
    int num = format[*i] - '0';
    *width = *width * 10 + num;
    (*i)++;
  }
}

void findPrecision(const char *format, flags *flag, s21_size_t *i) {
  if (format[*i] == '.') {
    (*i)++;
    findWidth(format, &flag->precision, i);
  } else {
    flag->precision = 6;
    flag->def = true;
  }
}

void findLength(const char *format, flags *flag, s21_size_t *i) {
  while (format[*i] == 'h' || format[*i] == 'l') {
    flag->count_length++;
    flag->length = format[*i];
    (*i)++;
  }
}

void findSpecifier(char curr_ch, flags *flag, va_list args) {
  long long num = 0;
  double f_num = 0;
  char *str = NULL;
  switch (curr_ch) {
    case 'i':
    case 'd':
      lengthDecimal(&num, args, *flag);
      bufferFill(num, flag);
      break;
    case 'u':
      lengthUnsigned(&num, args, *flag);
      unsignedChanger(num, flag->value);
      break;
    case 'c':
      flag->value[0] = va_arg(args, int);
      break;
    case 'f':
      f_num = va_arg(args, double);
      floatChanger(f_num, flag);
      break;
    case 's':
      str = va_arg(args, char *);
      strFilling(flag, str);
      break;
  }
}

void fillStr(flags flag, char *str, s21_size_t *j) {
  int k = 0;
  int diff = flag.width - s21_strlen(flag.value);
  if (!flag.minus && flag.plus && flag.value[0] != '-') diff--;
  if (flag.space && (diff <= 0 || flag.minus)) {
    str[(*j)++] = ' ';
    diff--;
  }
  bool point = false;
  for (s21_size_t i = 0; flag.value[i] != '\0'; i++, (*j)++) {
    if (!flag.minus) spaceFill(str, &k, j, diff);
    if (flag.plus && flag.value[0] != '-' && !point) {
      str[(*j)++] = '+';
      diff--;
      point = true;
    }
    str[*j] = flag.value[i];
  }
  if (flag.minus) spaceFill(str, &k, j, diff);
  (*j)--;
}

void spaceFill(char *str, int *k, s21_size_t *j, int diff) {
  while ((*k)++ < diff) {
    str[(*j)++] = ' ';
  }
}

void bufferFill(long long num, flags *flag) {
  if (num == 0) {
    flag->value[0] = '0';
  } else {
    integerChanger(num, flag->value);
  }
  precisionCorrect(flag);
}

void lengthDecimal(long long *num, va_list args, flags flag) {
  if (flag.length == 'h') {
    if (flag.count_length > 1) {
      *num = (char)va_arg(args, int);
    } else {
      *num = (short)va_arg(args, int);
    }
  } else if (flag.length == 'l') {
    if (flag.count_length > 1) {
      *num = va_arg(args, long long);
    } else {
      *num = va_arg(args, long);
    }
  } else {
    *num = va_arg(args, int);
  }
}

void lengthUnsigned(long long *num, va_list args, flags flag) {
  if (flag.length == 'h') {
    if (flag.count_length > 1) {
      *num = (unsigned char)va_arg(args, unsigned);
    } else {
      *num = (unsigned short)va_arg(args, unsigned);
    }
  } else if (flag.length == 'l') {
    if (flag.count_length >= 1) {
      *num = va_arg(args, unsigned long long);
    }
  } else {
    *num = va_arg(args, unsigned);
  }
}

void integerChanger(long long num, char *buff) {
  int k = 0;
  if (num < 0) {
    num = -num;
    buff[k++] = '-';
  }
  s21_size_t i, j, count = countLen(num);
  for (i = 0, j = 1; j <= count; i++, j++) {
    buff[i + k] = '0' + (num % 10);
    num /= 10;
  }
  reverseArr(buff);
}

void strFilling(flags *flag, char *str) {
  if (flag->def || (flag->precision > s21_strlen(str))) {
    s21_strncat(flag->value, str, s21_strlen(str));
  } else {
    s21_strncat(flag->value, str, flag->precision);
  }
}

void precisionCorrect(flags *flag) {
  if (!flag->def) {
    s21_size_t len = s21_strlen(flag->value);
    int l = 0;
    if (flag->value[0] == '-') {
      len--;
      l++;
    }
    if (flag->precision > len) {
      s21_size_t diff = flag->precision - len;
      for (int i = len; i >= 0; i--) {
        flag->value[i + diff] = flag->value[i];
      }
      for (s21_size_t i = l; i < diff + l; i++) {
        flag->value[i] = '0';
      }
    }
  }
}

void unsignedChanger(unsigned long long num, char *buff) {
  s21_size_t i, count = countLen(num);
  for (i = 0; i < count; i++) {
    buff[i] = '0' + (num % 10);
    num /= 10;
  }
  reverseArr(buff);
}

void reverseArr(char *buff) {
  int last = s21_strlen(buff) - 1;
  char tmp;
  for (int i = 0; i < last; i++) {
    if (buff[i] == '-') continue;
    tmp = buff[i];
    buff[i] = buff[last];
    buff[last] = tmp;
    last--;
  }
}

void floatChanger(double f_num, flags *flag) {
  (void)f_num, (void)flag;
  s21_size_t point = 0, start = 0;
  f_num = wholeDetect(f_num, flag, &start, &point);
  for (s21_size_t i = 0; i < flag->precision + 1; i++) {
    f_num *= 10;
    flag->value[i + start] = '0' + (int)f_num % 10;
  }
  pointApprove(point, flag);
}

double wholeDetect(double f_num, flags *flag, s21_size_t *start,
                   s21_size_t *point) {
  if (f_num < 0) {
    f_num = -f_num;
    flag->value[(*start)++] = '-';
    (*point)++;
  }
  if ((int)f_num == 0) {
    flag->value[(*start)++] = '0';
    (*point)++;
  }
  int whole = (int)f_num;
  f_num -= whole;
  while (countLen(whole) != 0) {
    flag->value[(*start)++] = '0' + whole % 10;
    whole /= 10;
    (*point)++;
  }
  reverseArr(flag->value);
  return f_num;
}

void pointApprove(s21_size_t point, flags *flag) {
  s21_size_t len = s21_strlen(flag->value);
  for (s21_size_t i = len; i >= point; i--) {
    if (i == len - 1) {
      if (flag->value[i] >= '5' && flag->value[i] <= '9') {
        flag->value[i - 1] = (int)flag->value[i - 1] + 1;
      }
      flag->value[i] = '\0';
    }
    if (flag->value[i] == ':') {
      flag->value[i] = '0';
      flag->value[i - 1] = (int)flag->value[i - 1] + 1;
    }
    flag->value[i + 1] = flag->value[i];
  }
  if (flag->precision > 0) {
    flag->value[point] = '.';
  }
}

s21_size_t countLen(unsigned long long num) {
  s21_size_t count = 0;
  while (num > 0) {
    num /= 10;
    count++;
  }
  return count;
}