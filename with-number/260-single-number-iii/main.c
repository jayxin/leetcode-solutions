#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 260. 只出现一次的数字 III - 给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
// 你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
//  
// 示例 1：
// 输入：nums = [1,2,1,3,2,5]
// 输出：[3,5]
// 解释：[5, 3] 也是有效的答案。
// 示例 2：
// 输入：nums = [-1,0]
// 输出：[-1,0]
// 示例 3：
// 输入：nums = [0,1]
// 输出：[1,0]
//  
// 提示：
//  * 2 &lt;= nums.length &lt;= 3 * 10^4
//  * -2^31 &lt;= nums[i] &lt;= 2^31 - 1
//  * 除两个只出现一次的整数外，nums 中的其他数字都出现两次

// #v1
// 把数组中的元素分成两类
int* singleNumber(int* nums, int numsSize, int* returnSize) {
  *returnSize = 2;
  int *ret = (int *)malloc(sizeof(int) * 2), i, xorVal = 0, t, q;

  for (i = 0; i < numsSize; i++) xorVal ^= nums[i];

  t = xorVal;

  for (i = 0; i < numsSize; i++) {
    q = xorVal ^ nums[i];
    if ((long long)q - nums[i] < 0) t ^= nums[i];
  }

  ret[0] = t;
  ret[1] = t^xorVal;

  if (ret[0] > ret[1]) {
    t = ret[0];
    ret[0] = ret[1];
    ret[1] = t;
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
  ret = singleNumber(a, n, &s);
  print_1d_arr(ret, s);
  free(a);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
