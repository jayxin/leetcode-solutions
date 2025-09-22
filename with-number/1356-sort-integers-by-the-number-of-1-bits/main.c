#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1356. 根据数字二进制下 1 的数目排序 - 给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。
// 如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。
// 请你返回排序后的数组。
//  
// 示例 1：
// 输入：arr = [0,1,2,3,4,5,6,7,8]
// 输出：[0,1,2,4,8,3,5,6,7]
// 解释：[0] 是唯一一个有 0 个 1 的数。
// [1,2,4,8] 都有 1 个 1 。
// [3,5,6] 有 2 个 1 。
// [7] 有 3 个 1 。
// 按照 1 的个数排序得到的结果数组为 [0,1,2,4,8,3,5,6,7]
// 示例 2：
// 输入：arr = [1024,512,256,128,64,32,16,8,4,2,1]
// 输出：[1,2,4,8,16,32,64,128,256,512,1024]
// 解释：数组中所有整数二进制下都只有 1 个 1 ，所以你需要按照数值大小将它们排序。
// 示例 3：
// 输入：arr = [10000,10000]
// 输出：[10000,10000]
// 示例 4：
// 输入：arr = [2,3,5,7,11,13,17,19]
// 输出：[2,3,5,17,7,11,13,19]
// 示例 5：
// 输入：arr = [10,100,1000,10000]
// 输出：[10,100,10000,1000]
//  
// 提示：
//  * 1 &lt;= arr.length &lt;= 500
//  * 0 &lt;= arr[i] &lt;= 10^4

// #v1
// 排序
struct Pair { int val; char ones; };

// 计算 x 的二进制表示中有多少个 bit 为 1
int countOnes(int x) {
  char cnt = 0;

  while (x > 0) {
    ++cnt;
    x -= x & (-x);
  }

  return cnt;
}

int pairCmp(const void *a, const void *b) {
  struct Pair *aa = (struct Pair *)a,
              *bb = (struct Pair *)b;
  if (aa->ones != bb->ones) return aa->ones - bb->ones;
  return aa->val - bb->val;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
  *returnSize = arrSize;
  if (!arr || arrSize <= 0) return NULL;

  struct Pair p[arrSize];
  int i;

  // init
  for (i = 0; i < arrSize; i++) {
    p[i].val = arr[i];
    p[i].ones = countOnes(arr[i]);
  }

  // sort
  qsort(p, arrSize, sizeof(struct Pair), pairCmp);

  // copy
  for (i = 0; i < arrSize; i++)
    arr[i] = p[i].val;

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
  int n, *a, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = sortByBits(a, n, &s);
  print_1d_arr(ret, s);

  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
