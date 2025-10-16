#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2154. 将找到的值乘以 2 - 给你一个整数数组 nums ，另给你一个整数 original ，这是需要在 nums 中搜索的第一个数字。
// 接下来，你需要按下述步骤操作：
//  1. 如果在 nums 中找到 original ，将 original 乘以 2 ，得到新 original（即，令 original = 2 * original）。
//  2. 否则，停止这一过程。
//  3. 只要能在数组中找到新 original ，就对新 original 继续 重复 这一过程。
// 返回 original 的 最终 值。
//  
// 示例 1：
// 输入：nums = [5,3,6,1,12], original = 3
// 输出：24
// 解释：
// - 3 能在 nums 中找到。3 * 2 = 6 。
// - 6 能在 nums 中找到。6 * 2 = 12 。
// - 12 能在 nums 中找到。12 * 2 = 24 。
// - 24 不能在 nums 中找到。因此，返回 24 。
// 示例 2：
// 输入：nums = [2,7,9], original = 4
// 输出：4
// 解释：
// - 4 不能在 nums 中找到。因此，返回 4 。
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 1000
//  * 1 &lt;= nums[i], original &lt;= 1000

// #v1
int findFinalValue(int* nums, int numsSize, int original) {
  int t[1001] = {0};

  for (int i = 0; i < numsSize; i++) {
    t[nums[i]] = 1;
  }

  while (1) {
    if (original <= 1000 && t[original]) original <<= 1;
    else break;
  }

  return original;
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
  int n, t, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &t);
  printf("%d\n", findFinalValue(a, n, t));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
