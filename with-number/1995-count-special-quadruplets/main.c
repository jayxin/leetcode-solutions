#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1995.  统计特殊四元组 - 给你一个 下标从 0 开始 的整数数组 nums ，返回满足下述条件的 不同 四元组 (a, b, c, d) 的 数目 ：
//  * nums[a] + nums[b] + nums[c] == nums[d] ，且
//  * a < b < c < d
//  
// 示例 1：
// 输入：nums = [1,2,3,6]
// 输出：1
// 解释：满足要求的唯一一个四元组是 (0, 1, 2, 3) 因为 1 + 2 + 3 == 6 。
// 示例 2：
// 输入：nums = [3,3,6,4,5]
// 输出：0
// 解释：[3,3,6,4,5] 中不存在满足要求的四元组。
// 示例 3：
// 输入：nums = [1,1,1,3,5]
// 输出：4
// 解释：满足要求的 4 个四元组如下：
// - (0, 1, 2, 3): 1 + 1 + 1 == 3
// - (0, 1, 3, 4): 1 + 1 + 3 == 5
// - (0, 2, 3, 4): 1 + 1 + 3 == 5
// - (1, 2, 3, 4): 1 + 1 + 3 == 5
//  
// 提示：
//  * 4 <= nums.length <= 50
//  * 1 <= nums[i] <= 100

// #v1
int countQuadruplets(int* nums, int numsSize) {
  int c = 0;
  for (int i = 0; i < numsSize; i++) {
    for (int j = i+1; j < numsSize; j++) {
      for (int l = j+1; l < numsSize; l++) {
        for (int k = l+1; k < numsSize; k++) {
          if (nums[i] + nums[j] + nums[l] == nums[k]) ++c;
        }
      }
    }
  }
  return c;
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
  printf("%d\n", countQuadruplets(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
