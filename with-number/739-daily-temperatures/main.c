#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 739. 每日温度 - 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
//  
// 示例 1:
// 输入: temperatures = [73,74,75,71,69,72,76,73]
// 输出: [1,1,4,2,1,1,0,0]
// 示例 2:
// 输入: temperatures = [30,40,50,60]
// 输出: [1,1,1,0]
// 示例 3:
// 输入: temperatures = [30,60,90]
// 输出: [1,1,0]
//  
// 提示：
//  * 1 &lt;= temperatures.length &lt;= 105
//  * 30 &lt;= temperatures[i] &lt;= 100

// #v1
struct StackNode {
  int val, idx;
};
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
  *returnSize = temperaturesSize;

  struct StackNode s[10000];
  int top, *ret, i, end = temperaturesSize - 1;
  ret = (int *)malloc(sizeof(int) * temperaturesSize);
  ret[end] = 0;

  // push
  top = 0;
  s[top].val = temperatures[end];
  s[top].idx = end;

  for (i = end - 1; i >= 0; i--) {
    // pop
    // 一直找到一个严格大于当前值的或者栈为空说明没找到
    while (top >= 0 && s[top].val <= temperatures[i]) { // 注意等号可取
      --top;
    }

    ret[i] = (top < 0) ? 0 : (s[top].idx - i);

    // push
    ++top;
    s[top].val = temperatures[i];
    s[top].idx = i;
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

int main(int argc, char *argv[])
{
  int n, *a, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = dailyTemperatures(a, n, &s);
  print_1d_arr(ret, s);
  free(ret);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
