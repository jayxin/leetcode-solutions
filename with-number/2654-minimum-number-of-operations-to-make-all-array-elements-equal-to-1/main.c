#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2654. 使数组所有元素变成 1 的最少操作次数 - 给你一个下标从 0 开始的 正 整数数组 nums 。你可以对数组执行以下操作 任意 次：
//  * 选择一个满足 0 <= i < n - 1 的下标 i ，将 nums[i] 或者 nums[i+1] 两者之 一替换成它们的最大公约数。
// 请你返回使数组 nums 中所有元素都等于 1 的 最少 操作次数。如果无法让数组全部变成 1 ，请你返回 -1 。
// 两个正整数的最大公约数指的是能整除这两个数的最大正整数。
//  
// 示例 1：
// 输入：nums = [2,6,3,4]
// 输出：4
// 解释：我们可以执行以下操作：
// - 选择下标 i = 2 ，将 nums[2] 替换为 gcd(3,4) = 1 ，得到 nums = [2,6,1,4] 。
// - 选择下标 i = 1 ，将 nums[1] 替换为 gcd(6,1) = 1 ，得到 nums = [2,1,1,4] 。
// - 选择下标 i = 0 ，将 nums[0] 替换为 gcd(2,1) = 1 ，得到 nums = [1,1,1,4] 。
// - 选择下标 i = 2 ，将 nums[3] 替换为 gcd(1,4) = 1 ，得到 nums = [1,1,1,1] 。
// 示例 2：
// 输入：nums = [2,10,6,14]
// 输出：-1
// 解释：无法将所有元素都变成 1 。
//  
// 提示：
//  * 2 <= nums.length <= 50
//  * 1 <= nums[i] <= 106
// 1. Note that if you have at least one occurrence of 1 in the array, then you
// can make all the other elements equal to 1 with one operation each.
// 2. Try finding the shortest subarray with a gcd equal to 1.

// #v1
#define INF 0x7fffffff

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}

int minOperations(int* nums, int numsSize) {
  int c = 0;
  int i, j;

  for (i = 0; i < numsSize; i++) {
    if (nums[i] != 1) ++c;
  }

  // nums 中存在 1, 只要将 nums[i] != 1 变为 1 即可
  if (c < numsSize) return c;

  int len = INF;
  for (i = 0; i < numsSize-1; i++) {
    int g = gcd(nums[i], nums[i+1]);

    if (g == 1) {
      // 这里没有比 2 更短的子数组了
      len = 2;
      break;
    }

    for (j = i+2; j < numsSize; j++) {
      g = gcd(g, nums[j]);

      if (g == 1) {
        int tmp = j - i + 1;
        if (tmp < len) len = tmp;
        break;
      }
    }
  }

  if (len == INF) return -1;

  return numsSize + len - 2;
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
  printf("%d\n", minOperations(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
