#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3079. 求出加密整数的和 - 给你一个整数数组 nums ，数组中的元素都是 正 整数。定义一个加 密函数 encrypt ，encrypt(x) 将一个整数 x 中 每一个 数位都用 x 中的 最大 数位替换 。比方说 encrypt(523) = 555 且 encrypt(213) = 333 。
// 请你返回数组中所有元素加密后的 和 。
//  
// 示例 1：
// 输入：nums = [1,2,3]
// 输出：6
// 解释：加密后的元素位 [1,2,3] 。加密元素的和为 1 + 2 + 3 == 6 。
// 示例 2：
// 输入：nums = [10,21,31]
// 输出：66
// 解释：加密后的元素为 [11,22,33] 。加密元素的和为 11 + 22 + 33 == 66 。
//  
// 提示：
//  * 1 <= nums.length <= 50
//  * 1 <= nums[i] <= 1000

// #v1
int encrypt(int x) {
  int len = 0, maxDigit = 0, ret = 0;

  while (x) {
    int r = x % 10;
    if (r > maxDigit) maxDigit = r;
    ++len;
    x /= 10;
  }

  while (len--) {
    ret = ret * 10 + maxDigit;
  }

  return ret;
}

int sumOfEncryptedInt(int* nums, int numsSize) {
  int ret = 0;

  for (int i = 0; i < numsSize; i++) ret += encrypt(nums[i]);

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

int main(int argc, char *argv[])
{
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", sumOfEncryptedInt(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
