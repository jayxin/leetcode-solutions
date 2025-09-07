#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1287. 有序数组中出现次数超过25%的元素 - 给你一个非递减的 有序 整数数组 ，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。
// 请你找到并返回这个整数
//  
// 示例：
// 输入：arr = [1,2,2,6,6,6,6,7,10]
// 输出：6
//  
// 提示：
//  * 1 &lt;= arr.length &lt;= 10^4
//  * 0 &lt;= arr[i] &lt;= 10^5

// #v1
int findSpecialInteger(int* arr, int arrSize) {
  int cnt = 0, ret = arr[0], limit = arrSize / 4;
  for (int i = 1; i < arrSize; i++) {
    if (ret != arr[i]) {
      if (cnt >= limit) {
        return ret;
      }
      ret = arr[i];
      cnt = 0;
    } else {
      cnt++;
    }
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", findSpecialInteger(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
