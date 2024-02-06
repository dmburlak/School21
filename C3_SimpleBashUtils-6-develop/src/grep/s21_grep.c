#include "s21_grep.h"

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int file_number(int argc, char *argv[], struct flags my_flags);
int find_flags(int argc, char *argv[], struct flags *my_flags);
void find_file(int argc, char *argv[], struct flags my_flags);
void reader(struct flags my_flags, char *pattern, FILE *file, int file_numb,
            char *filename);
void compiler_reg(regex_t *reg, char *pattern, struct flags my_flags);
void detect_output(regex_t reg, struct flags my_flags, char *buffer,
                   int file_numb, char *filename, int *c_count, int *line_count,
                   int *previous);
void print_output(char *buffer, struct flags my_flags, int file_numb,
                  char *filename, int *c_count, int *line_count);
void another_print(regex_t reg, regmatch_t match, struct flags my_flags,
                   char *buffer, int file_numb, char *filename, int *line_count,
                   int *previous);
void another_output(char *file, int count_files, char *line,
                    struct flags my_flags, int *line_count, regmatch_t match,
                    int *previous);
void numb_lines(char *filename, int c_count, int file_numb, int no_filename);
void compiler_patterns(char *pattern, struct flags *my_flags);
void compiler_pattern_from_file(char *file, struct flags *my_flags);

int main(int argc, char *argv[]) {
  struct flags my_flags = {0};
  if (find_flags(argc, argv, &my_flags) == 0) {
    find_file(argc, argv, my_flags);
  }
  return 0;
}

/* фунция для определения поиска флагов в потоке ввода */
int find_flags(int argc, char *argv[], struct flags *my_flags) {
  int x, error = 0;
  while ((x = getopt_long(argc, argv, "live:sonf:ch", 0, 0)) != -1) {
    switch (x) {
      case 'l':
        my_flags->l = 1;
        break;
      case 'i':
        my_flags->i = 1;
        break;
      case 'v':
        my_flags->v = 1;
        break;
      case 'e':
        my_flags->e = 1;
        compiler_patterns(optarg, my_flags);
        break;
      case 's':
        my_flags->s = 1;
        break;
      case 'o':
        my_flags->o = 1;
        break;
      case 'n':
        my_flags->n = 1;
        break;
      case 'f':
        my_flags->f = 1;
        compiler_pattern_from_file(optarg, my_flags);
        break;
      case 'c':
        my_flags->c = 1;
        break;
      case 'h':
        my_flags->h = 1;
        break;
      case '?':
        error = 1;
        fprintf(stderr,
                "usage: s21grep [-live:sonf:ch] [pattern] [file ...]\n");
    }
    if (error) break;
  }
  if (my_flags->e || my_flags->f) {
    my_flags->pattern[my_flags->index - 1] =
        '\0';  //мы смещаем следующий паттерн на индекс предыдущего
  }
  return error;
}

/* фунция для определения поиска файлы в потоке ввода */
void find_file(int argc, char *argv[], struct flags my_flags) {
  FILE *file;
  char *pattern = NULL;

  int file_numb = 0;

  for (int i = optind; i < argc;
       i++) {  // фильтр, который не дает бегать по флагам или опциям опций
    if (my_flags.e || my_flags.f) {
      pattern = my_flags.pattern;
    } else {
      if (pattern == NULL) {
        pattern = argv[i];
        continue;
      }
    }
    if (file_numb == 0) {
      file_numb = argc - i;
    }

    if ((file = fopen(argv[i], "r")) != NULL) {
      reader(my_flags, pattern, file, file_numb, argv[i]);
      fclose(file);
    } else {
      if (my_flags.s == 0) {
        fprintf(stderr, "%s: No such file or directory\n", argv[i]);
      }
    }
  }
}

/* фунция для определения чтения файла */
void reader(struct flags my_flags, char *pattern, FILE *file, int file_numb,
            char *filename) {
  regex_t reg;  //хранит в себе наш паттерн
  compiler_reg(&reg, pattern, my_flags);
  char buffer[10000];  // строка в файле
  int c_count = 0;  // считает количество совпадающих строк с паттернами
  int previous = 0;
  // int l_count = 0;  // определяет наличие паттерна в файле
  int line_count = 0;  // фиксировать номер строки с паттерном
  while (fgets(buffer, 10000, file) != NULL) {
    if (my_flags.n || my_flags.o) line_count++;
    if (my_flags.n == 0 && my_flags.v == 0 && buffer[0] == '\n') {
      continue;
    }
    detect_output(reg, my_flags, buffer, file_numb, filename, &c_count,
                  &line_count, &previous);
    if (my_flags.l && c_count > 0) break;
  }
  if (my_flags.c == 1) {
    numb_lines(filename, c_count, file_numb, my_flags.h);
  }
  if (my_flags.l && c_count > 0) printf("%s\n", filename);
  regfree(&reg);
}

/* фунция для компилирования регулярного выражения */
void compiler_reg(regex_t *reg, char *pattern, struct flags my_flags) {
  if (my_flags.f || my_flags.e) {
    my_flags.i ? regcomp(reg, pattern, REG_ICASE | REG_EXTENDED)
               : regcomp(reg, pattern, REG_EXTENDED);
  } else {
    my_flags.i ? regcomp(reg, pattern, REG_ICASE) : regcomp(reg, pattern, 0);
  }
}

/* фунция для определения типа вывода */
void detect_output(regex_t reg, struct flags my_flags, char *buffer,
                   int file_numb, char *filename, int *c_count, int *line_count,
                   int *previous) {
  regmatch_t
      match;  //содержит в себе индексы паттерна, которые лежат в структуре рег
  /* если запущен флаг -v для инвертированного вывода */
  if (my_flags.v) {  // обратный греп - печать не паттерновых строк
    if (regexec(&reg, buffer, 1, &match,
                0)) {  // regexec находит или нет паттерн в строке
      print_output(buffer, my_flags, file_numb, filename, c_count, line_count);
    }
  } else {  // стандартный греп
    if (!regexec(&reg, buffer, 1, &match, 0)) {
      if (my_flags.o == 1 && (my_flags.l == 0 && my_flags.c == 0)) {
        another_print(reg, match, my_flags, buffer, file_numb, filename,
                      line_count, previous);
      } else {
        print_output(buffer, my_flags, file_numb, filename, c_count,
                     line_count);
      }
    }
  }
}

void another_print(regex_t reg, regmatch_t match, struct flags my_flags,
                   char *buffer, int file_numb, char *filename, int *line_count,
                   int *previous) {
  another_output(filename, file_numb, buffer, my_flags, line_count, match,
                 previous);
  char *buff = buffer + match.rm_eo;
  while (!regexec(&reg, buff, 1, &match, 0)) {
    another_output(filename, file_numb, buff, my_flags, line_count, match,
                   previous);
    buff += match.rm_eo;
  }
}

void another_output(char *file, int count_files, char *line,
                    struct flags my_flags, int *line_count, regmatch_t match,
                    int *previous) {
  if (my_flags.h == 1 || count_files == 1 || *previous == *line_count) {
    if (my_flags.n && *previous != *line_count) {
      printf("%d:%.*s\n", *line_count, (int)(match.rm_eo - match.rm_so),
             line + match.rm_so);
    } else {
      printf("%.*s\n", (int)(match.rm_eo - match.rm_so), line + match.rm_so);
    }
  } else {
    if (my_flags.n == 1) {
      printf("%s:%d:%.*s\n", file, *line_count,
             (int)(match.rm_eo - match.rm_so), line + match.rm_so);
    } else {
      printf("%s:%.*s\n", file, (int)(match.rm_eo - match.rm_so),
             line + match.rm_so);
    }
  }
  *previous = *line_count;
}

void print_output(char *buffer, struct flags my_flags, int file_numb,
                  char *filename, int *c_count, int *line_count) {
  int length = strlen(buffer);
  if (my_flags.c || my_flags.l) {
    (*c_count)++;
  } else {
    if (file_numb > 1 && my_flags.h == 0) {
      if (my_flags.n) {
        printf("%s:%d:%s", filename, *line_count, buffer);
      } else {
        printf("%s:%s", filename, buffer);
      }
    } else {
      if (my_flags.n) {
        printf("%d:%s", *line_count, buffer);
      } else {
        printf("%s", buffer);
      }
    }
    if (buffer[length - 1] != '\n') {
      printf("\n");
    }
  }
}

/* выводит комличество паттернов в введенных файлах */
void numb_lines(char *filename, int c_count, int file_numb, int no_filename) {
  if (file_numb > 1 && no_filename == 0) {
    printf("%s:%d\n", filename, c_count);
  } else {
    printf("%d\n", c_count);
  }
}

void compiler_patterns(char *pattern, struct flags *my_flags) {
  char c;
  int i = 0;
  while ((c = pattern[i]) != '\0') {
    my_flags->pattern[my_flags->index + i] = c;
    i++;
  }
  my_flags->pattern[my_flags->index + i] = '|';
  my_flags->pattern[my_flags->index + i + 1] = '\0';
  my_flags->index += i + 1;
}

void compiler_pattern_from_file(char *file, struct flags *my_flags) {
  FILE *fd;
  if ((fd = fopen(file, "r")) != NULL) {
    char c;
    int i = 0;
    while ((c = getc(fd)) != EOF) {
      if (c == '\n') c = '|';
      my_flags->pattern[my_flags->index + i] = c;
      i++;
    }
    my_flags->pattern[my_flags->index + i] = '|';
    my_flags->pattern[my_flags->index + i + 1] = '\0';
    my_flags->index += i + 1;
    fclose(fd);
  } else {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", file);
  }
}
