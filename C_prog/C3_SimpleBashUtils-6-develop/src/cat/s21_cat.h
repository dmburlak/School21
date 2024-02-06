#ifndef CAT_H
#define CAT_H
#include <getopt.h>
#include <stddef.h>

struct my_flags_bool {  // создали структуру, где будут содержаться все краткие
                        // названия флагов
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} flags;

struct option long_flags[] = {
    // создали структуру, где будут обрабатываться поданные опции
    {"number-nonblank", 0, NULL, 'b'},  // если ввели длинное название флага, то
                                        // оно переименуется в короткое
    {"number", 0, NULL, 'n'},
    {"squeeze-blank", 0, NULL, 's'},
    {0, 0, 0, 0},
};

#endif
