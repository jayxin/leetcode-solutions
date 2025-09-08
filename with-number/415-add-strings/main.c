#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #v1
char* addStrings(char* num1, char* num2) {
  int l1 = strlen(num1), l2 = strlen(num2), retLen = 0, carray = 0, sum;
  char *s1 = num1 + l1 - 1,
       *s2 = num2 + l2 - 1,
       *ret = (char *)malloc(sizeof(char) * (l1 + l2 + 1)),
       c;
  while (s1 >= num1 && s2 >= num2) {
    sum = *s1 - '0' + *s2 - '0' + carray;
    carray = sum / 10;
    sum = sum % 10;
    ret[retLen++] = '0' + sum;
    s1--;
    s2--;
  }

  while (s1 >= num1) {
    sum = *s1 - '0' + carray;
    carray = sum / 10;
    sum = sum % 10;
    ret[retLen++] = '0' + sum;
    s1--;
  }

  while (s2 >= num2) {
    sum = *s2 - '0' + carray;
    carray = sum / 10;
    sum = sum % 10;
    ret[retLen++] = '0' + sum;
    s2--;
  }
  if (carray) {
    ret[retLen++] = '0' + carray;
  }
  ret[retLen] = '\0';
  for (int i = 0; i < retLen / 2; i++) {
    c = ret[i];
    ret[i] = ret[retLen - i - 1];
    ret[retLen - i - 1] = c;
  }
  return ret;
}
// #v1

// read one line from stream
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
  char s1[1000], s2[1000];
  read_line(s1, 999, stdin);
  read_line(s2, 999, stdin);
  printf("%s\n", addStrings(s1, s2));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
