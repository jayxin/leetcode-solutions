#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// #v1
int* plusOne(int* digits, int digitsSize, int* returnSize) {
  int i, *ret, more = 0, retLen = digitsSize;
  for (i = digitsSize - 1; i >= 0; i--) {
    if (digits[i] == 9) {
      digits[i] = 0;
      if (i == 0)
        more = 1;
    } else {
      digits[i] += 1;
      break;
    }
  }
  if (more) {
    digits[0] = 1;
    retLen += 1;
  }
  ret = (int *)malloc(sizeof(int) * retLen);
  *returnSize = retLen;

  for (i = 0; i < digitsSize; i++) {
    ret[i] = digits[i];
  }

  if (more) {
    ret[retLen - 1] = 0;
  }

  return ret;
}
// #v1

// read 1d array
int* read_1d_arr(int n) {
  int *ret = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", ret + i);
  }
  return ret;
}

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

// free 1d array
void free_1d_arr(int *arr) {
  if (!arr) {
    return;
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  int n, retSize;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  int *ret = plusOne(arr, n, &retSize);
  print_1d_arr(ret, retSize);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
