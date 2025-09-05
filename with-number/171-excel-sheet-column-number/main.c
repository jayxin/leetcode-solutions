#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #v1
int titleToNumber(char* columnTitle) {
  int ret = 0, weight = 1;
  char *s = columnTitle + strlen(columnTitle) - 1,
       c;

  while (s >= columnTitle) {
    c = *s;
    ret += weight * (c - 'A' + 1);
    s--;
    if (s < columnTitle) {
      break;
    }
    weight *= 26;
  }

  return ret;
}
// #v1

char* read_line(char *buffer, size_t size, FILE *stream) {
  if (fgets(buffer, size, stream) == NULL) {
    return NULL;
  }

  size_t len = strlen(buffer);
  if (len > 0 && buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';
  }

  return buffer;
}

int main(int argc, char *argv[])
{
  char s[10];
  read_line(s, 9, stdin);
  printf("%d\n", titleToNumber(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
