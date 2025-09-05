#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 349. 两 个数组的交集 - 给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个 元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
//  
// 示例 1：
// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
// 输出：[2]
// 示例 2：
// 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// 输出：[9,4]
// 解释：[4,9] 也是可通过的
//  
// 提示：
//  * 1 &lt;= nums1.length, nums2.length &lt;= 1000
//  * 0 &lt;= nums1[i], nums2[i] &lt;= 1000

// #v1
#define min(a, b) (a > b ? b : a)
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int n1 = nums1Size, n2 = nums2Size, retLen = 0, i;
  int *ret = (int *)malloc(sizeof(int) * min(n1, n2));
  int table[1001];
  memset(table, 0, sizeof(int) * 1001);
  for (i = 0; i < n1; i++) {
    table[nums1[i]] = 1;
  }

  for (i = 0; i < n2; i++) {
    if (table[nums2[i]] == 1) {
      ret[retLen++] = nums2[i];
      table[nums2[i]] = 0;
    }
  }

  *returnSize = retLen;
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
  int n1, n2, *a1, *a2, retSize;
  scanf("%d", &n1);
  a1 = read_1d_arr(n1);
  scanf("%d", &n2);
  a2 = read_1d_arr(n2);
  int *ret = intersection(a1, n1, a2, n2, &retSize);
  print_1d_arr(ret, retSize);
  free_1d_arr(a1);
  free_1d_arr(a2);
  free_1d_arr(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
