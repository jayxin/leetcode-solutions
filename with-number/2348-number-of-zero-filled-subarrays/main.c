#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2348. 全 0 子数组的数目 - 给你一个整数数组 nums ，返回全部为 0 的 子数组 数目。
// 子数组 是一个数组中一段连续非空元素组成的序列。
//  
// 示例 1：
// 输入：nums = [1,3,0,0,2,0,0,4]
// 输出：6
// 解释：
// 子数组 [0] 出现了 4 次。
// 子数组 [0,0] 出现了 2 次。
// 不存在长度大于 2 的全 0 子数组，所以我们返回 6 。
// 示例 2：
// 输入：nums = [0,0,0,2,0,0]
// 输出：9
// 解释：
// 子数组 [0] 出现了 5 次。
// 子数组 [0,0] 出现了 3 次。
// 子数组 [0,0,0] 出现了 1 次。
// 不存在长度大于 3 的全 0 子数组，所以我们返回 9 。
// 示例 3：
// 输入：nums = [2,10,2019]
// 输出：0
// 解释：没有全 0 子数组，所以我们返回 0 。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * -109 <= nums[i] <= 109

// #v1
long long zeroFilledSubarray(int* nums, int numsSize) {
  long long ret = 0LL;
  int i, j, cnt;

  for (i = 0; i < numsSize; i++) {
    if (!nums[i]) {
      // init
      j = i;

      // forward
      while (j < numsSize && nums[j] == 0) ++j;
      // backward
      --j;

      cnt = j - i + 1;
      ret += (long long)(1 + cnt) * cnt / 2;

      // update index
      i = j;
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%lld\n", zeroFilledSubarray(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
