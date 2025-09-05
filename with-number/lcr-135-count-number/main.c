#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// LCR 135. 报数
//
// - 实现一个十进制数字报数程序，请按照数字从小到大的顺序返回一个整数数列，该数列从 数字 1 开始，到最大的正整数 cnt 位数字结束。
//
// 示例 1：
//
// 输入：cnt = 2
// 输出：[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99]

// #v1
int* countNumbers(int cnt, int* returnSize) {
  int max = 1;
  while (cnt) {
    max *= 10;
    cnt--;
  }
  max -= 1;
  *returnSize = max;
  int *ret = (int *)malloc(sizeof(int) * (*returnSize));
  for (int i = 0; i < *returnSize; i++) {
    ret[i] = i + 1;
  }
  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  int len;
  scanf("%d", &n);
  int *arr = countNumbers(n, &len);
  for (int i = 0; i < len; i++) {
    printf("%d\n", arr[i]);
  }
  free(arr);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
