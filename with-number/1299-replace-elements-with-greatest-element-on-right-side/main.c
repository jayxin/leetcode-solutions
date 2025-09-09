#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1299. 将每个元素替换为右侧最大元素 - 给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。
// 完成所有替换操作后，请你返回这个数组。
//  
// 示例 1：
// 输入：arr = [17,18,5,4,6,1]
// 输出：[18,6,6,6,1,-1]
// 解释：
// - 下标 0 的元素 --&gt; 右侧最大元素是下标 1 的元素 (18)
// - 下标 1 的元素 --&gt; 右侧最大元素是下标 4 的元素 (6)
// - 下标 2 的元素 --&gt; 右侧最大元素是下标 4 的元素 (6)
// - 下标 3 的元素 --&gt; 右侧最大元素是下标 4 的元素 (6)
// - 下标 4 的元素 --&gt; 右侧最大元素是下标 5 的元素 (1)
// - 下标 5 的元素 --&gt; 右侧没有其他元素，替换为 -1
// 示例 2：
// 输入：arr = [400]
// 输出：[-1]
// 解释：下标 0 的元素右侧没有其他元素。
//  
// 提示：
//  * 1 &lt;= arr.length &lt;= 104
//  * 1 &lt;= arr[i] &lt;= 105

// #v1
int* replaceElements(int* arr, int arrSize, int* returnSize) {
  int end = arrSize - 1, i, curMax, t;
  *returnSize = arrSize;
  curMax = arr[end];
  arr[end] = -1;
  for (i = end - 1; i >= 0; i--) {
    t = arr[i];
    arr[i] = curMax;
    if (t > curMax) curMax = t;
  }
  return arr;
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
  int n, *a, *r, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  r = replaceElements(a, n, &s);
  print_1d_arr(r, s);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
