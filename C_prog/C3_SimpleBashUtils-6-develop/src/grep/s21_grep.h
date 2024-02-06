#ifndef GREP_H
#define GREP_H

#define MAX_LENGTH 10000

struct flags {
  int l;
  int i;
  int v;
  int e;
  int s;
  int o;
  int n;
  int f;
  int c;
  int h;
  char pattern[MAX_LENGTH];
  int index;
};

#endif
