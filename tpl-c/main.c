#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// #v1
int compute(int x) {
  return x;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", compute(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
