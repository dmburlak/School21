#include "s21_cat.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_flags(int argc, char *argv[], struct my_flags_bool *flags);
void show_me_file(FILE *file, struct my_flags_bool flags);
int number_of_files(int argc, char *argv[]);
int flow_activate(int argc, char *argv[], struct my_flags_bool flags);

int main(int argc, char *argv[]) {
  int code_res = 0;
  struct my_flags_bool flags = {
      0};  // теперь все переменные в структууре равны нулю по умолчанию
  if (find_flags(argc, argv, &flags) ==
      0) {  // если прошли дальше, то не было ошибок
    code_res = flow_activate(argc, argv, flags);
  }
  return code_res;
}

int find_flags(int argc, char *argv[], struct my_flags_bool *flags) {
  int x = 0, error = 0;
  while ((x = getopt_long(argc, argv, "beEnstTv", long_flags, 0)) !=
         -1) {  // смотрим какие опции были введены пользователем
    switch (x) {
      case 'b':
        flags->b = 1;  //активировали флаг -b, если пользователь ввел б
        break;
      case 'e':
        flags->e = 1;
        flags->v = 1;
        break;
      case 'E':
        flags->e = 1;
        break;
      case 'n':
        flags->n = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 't':
        flags->t = 1;
        flags->v = 1;
        break;
      case 'T':
        flags->t = 1;
        break;
      case 'v':
        flags->v = 1;
        break;
      case '?':
        error = 1;
        fprintf(stderr, "usage: s21cat [-benstuv] [pattern] [file ...]\n");
    }
    if (error) break;
  }
  return error;
}

int number_of_files(int argc, char *argv[]) {
  /*  считаем количество файлов, введенных пользователем в строки ввода */
  int stdin_files = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      stdin_files++;
    }
  }
  return stdin_files;
}

int flow_activate(int argc, char *argv[], struct my_flags_bool flags) {
  FILE *file;
  int back_code = 0;
  int stdin_file = number_of_files(argc, argv);
  if (stdin_file != 0) {
    for (int j = argc - stdin_file; j < argc; j++) {
      /*  Если файл не существует, то программа завершается с ошибкой */
      /*  Если файл пустой, то программа завершается */
      file = fopen(argv[j], "r");
      if (file != NULL) {
        show_me_file(file, flags);  //  запускаем файлы с флагами
        fclose(file);
      } else {
        fprintf(stderr, "%s: No such file or directory\n", argv[j]);
        back_code = 1;
      }
    }
  } else {
    show_me_file(stdin, flags);
  }
  return back_code;
}

void show_me_file(FILE *file, struct my_flags_bool flags) {
  int current_symb;
  char previous_symb = '\n';
  int number_of_stroka = 1;
  int empty_line = 0;

  while ((current_symb = getc(file)) != EOF) {
    /* Если выбран флаг -s */
    if (flags.s && current_symb == '\n' && previous_symb == '\n') {
      empty_line++;
      if (empty_line > 1) {
        continue;
      }
    } else {
      empty_line = 0;
    }
    /* Если выбран флаг -n */
    if (flags.n && previous_symb == '\n' && !flags.b) {
      printf("%6d\t", number_of_stroka++);
    }
    /* Если выбран флаг -b */
    if (flags.b && current_symb != '\n' && previous_symb == '\n') {
      printf("%6d\t", number_of_stroka++);
    }
    /* Если выбран флаг -v */
    if (flags.v) {
      if ((current_symb >= 0 && current_symb < 9) ||
          (current_symb > 10 && current_symb < 32) ||
          (current_symb > 126 && current_symb < 161)) {
        printf("^");
        if (current_symb > 126) {
          current_symb -= 64;
        } else {
          current_symb += 64;
        }
      }
    }
    /* Если выбран флаг -e */
    if (flags.e && current_symb == '\n') {  // 10-ый символ ASCII
      printf("$");
    }
    /* Если выбран флаг -t */
    if (flags.t && current_symb == '\t') {  // 9-ый символ ASCII
      printf("^I");
    }
    if (!(flags.t && current_symb == '\t')) {
      printf("%c", current_symb);
    }
    previous_symb = current_symb;
  }
}
