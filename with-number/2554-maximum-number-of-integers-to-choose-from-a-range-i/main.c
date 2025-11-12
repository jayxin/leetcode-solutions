#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2554. 从一个范围内选择最多整数 I - 给你一个整数数组 banned 和两个整数 n 和 maxSum 。你需要按照以下规则选择一些整数：
//  * 被选择整数的范围是 [1, n] 。
//  * 每个整数 至多 选择 一次 。
//  * 被选择整数不能在数组 banned 中。
//  * 被选择整数的和不超过 maxSum 。
// 请你返回按照上述规则 最多 可以选择的整数数目。
//  
// 示例 1：
// 输入：banned = [1,6,5], n = 5, maxSum = 6
// 输出：2
// 解释：你可以选择整数 2 和 4 。
// 2 和 4 在范围 [1, 5] 内，且它们都不在 banned 中，它们的和是 6 ，没有超过 maxSum  。
// 示例 2：
// 输入：banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
// 输出：0
// 解释：按照上述规则无法选择任何整数。
// 示例 3：
// 输入：banned = [11], n = 7, maxSum = 50
// 输出：7
// 解释：你可以选择整数 1, 2, 3, 4, 5, 6 和 7 。
// 它们都在范围 [1, 7] 中，且都没出现在 banned 中，它们的和是 28 ，没有超过 maxSum  。
//  
// 提示：
//  * 1 <= banned.length <= 104
//  * 1 <= banned[i], n <= 104
//  * 1 <= maxSum <= 109
// 1. Keep the banned numbers that are less than or equal to n in a set.
// 2. Loop over the numbers from 1 to n and if the number is not banned, use
// it.
// 3.Keep adding numbers while they are not banned, and their sum is less than
// or equal to k.

// #v1
int maxCount(int* banned, int bannedSize, int n, int maxSum) {
  char isBanned[n+1];
  int ret = 0, sum = 0;

  memset(isBanned, 0, sizeof(isBanned));

  for (int i = 0; i < bannedSize; i++) {
    if (banned[i] <= n) isBanned[banned[i]] = 1;
  }

  for (int i = 1; i <= n; i++) {
    if (!isBanned[i]) {
      if (sum + i <= maxSum) {
        sum += i;
        ++ret;
      }
      else break;
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

int main(int argc, char *argv[])
{
  int n, *a, k, m;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d%d", &k, &m);
  printf("%d\n", maxCount(a, n, k, m));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
