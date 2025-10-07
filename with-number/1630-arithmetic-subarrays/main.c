#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1630. 等差 子数组 - 如果一个数列由至少两个元素组成，且每两个连续元素之间的差值都相同，那么这个序列就是 等差数列 。更正式地，数列 s 是等差数列，只需要满足：对于每个有效的 i  ， s[i+1] - s[i] == s[1] - s[0] 都成立。
// 例如，下面这些都是 等差数列 ：
// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// 下面的数列 不是等差数列 ：
// 1, 1, 2, 5, 7
// 给你一个由 n 个整数组成的数组 nums，和两个由 m 个整数组成的数组 l 和 r，后两个数 组表示 m 组范围查询，其中第 i 个查询对应范围 [l[i], r[i]] 。所有数组的下标都是 从 0 开始 的。
// 返回 boolean 元素构成的答案列表 answer 。如果子数组 nums[l[i]], nums[l[i]+1], ... , nums[r[i]] 可以 重新排列 形成 等差数列 ，answer[i] 的值就是 true；否则answer[i] 的值就是 false 。
//  
// 示例 1：
// 输入：nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
// 输出：[true,false,true]
// 解释：
// 第 0 个查询，对应子数组 [4,6,5] 。可以重新排列为等差数列 [6,5,4] 。
// 第 1 个查询，对应子数组 [4,6,5,9] 。无法重新排列形成等差数列。
// 第 2 个查询，对应子数组 [5,9,3,7] 。可以重新排列为等差数列 [3,5,7,9] 。
// 示例 2：
// 输入：nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
// 输出：[false,true,false,false,true,true]
//  
// 提示：
//  * n == nums.length
//  * m == l.length
//  * m == r.length
//  * 2 <= n <= 500
//  * 1 <= m <= 500
//  * 0 <= l[i] < r[i] < n
//  * -105 <= nums[i] <= 105

// #v1
// sort
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool isArithmeticSequence(int *a, int n) {
  if (n <= 2) return true;

  int diff = a[1] - a[0];

  for (int i = 2; i < n; i++) {
    if (a[i] - a[i-1] != diff) return false;
  }

  return true;
}

bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {
  int tmp[numsSize], tmpLen;
  bool *ret = (bool *)malloc(sizeof(bool) * lSize);

  *returnSize = lSize;

  for (int i = 0; i < lSize; i++) {
    tmpLen = 0;
    for (int j = l[i]; j <= r[i]; j++) {
      tmp[tmpLen++] = nums[j];
    }
    qsort(tmp, tmpLen, sizeof(int), cmp);
    ret[i] = isArithmeticSequence(tmp, tmpLen);
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

void print_1d_arr(bool *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    if (arr[i])
      printf("true");
    else
      printf("false");
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int n, *arr, *l, *r, n1, n2, s;
  bool *ret;
  scanf("%d", &n);
  arr = read_1d_arr(n);
  scanf("%d", &n1);
  l = read_1d_arr(n1);
  scanf("%d", &n2);
  r = read_1d_arr(n2);
  ret = checkArithmeticSubarrays(arr, n, l, n1, r, n2, &s);
  print_1d_arr(ret, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
