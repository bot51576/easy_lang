#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

static char *p;

static void skip() {
  while (isspace(*p)) 
    p++;
}

static int expect_number() {
  skip();
  if (isdigit(*p)) {
    int val = *p++ - '0';
    while (isdigit(*p)) {
      val = val * 10 + (*p++ - '0');
    }
    return val;
  }
  printf("error\n");
}

static int eval() {
  int val = expect_number();
  skip();
  char op = *p++;
  if (op == '+')
    return val + eval();
  if (op == '-') 
    return val - eval();
  if (op == '*') 
    return val * eval();
  if (op == '/')
    return val / eval();

  return val;
}

int main(int argc, char **argv) {
  p = argv[1];
  printf("%d\n", eval());
  return 0;
}
