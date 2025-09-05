#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 540. 有序数组中的单一元素
// 给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
// 请你找出并返回只出现一次的那个数。
// 你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。

//  1 <= nums.length <= 10^5
//  0 <= nums[i] <= 10^5


// #v1
int singleNonDuplicate(int *nums, int numsSize) {
  int l = 0, r = numsSize - 1, m;

  // array: 1 1 2 2 [3] 4 4 5 5
  // index: 1 2 3 4 [5] 6 7 8 9
  // 目标的 index 必然是奇数
  // 目标之前的元素的 index 遵循 奇-偶 的模式
  // 目标之后的元素的 index 遵循 偶-奇 的模式

  while (l < r) {
    m = l + (r - l + 1) / 2;

    if (((m + 1) & 1) == 0) { // 偶数索引, 必然不是目标索引
      if (m - 1 >= 0 && nums[m - 1] == nums[m]) { // 奇偶模式, 说明目标在nums[m]右边
        l = m + 1;
      } else if (m + 1 < numsSize && nums[m + 1] == nums[m]) { // 偶奇模式, 说明目标在左边
        r = m - 1;
      }
    } else { // 奇数索引
      if (m - 1 >= 0 && nums[m - 1] == nums[m]) { // 偶奇模式, 说明目标在左边
        r = m - 2;
      } else if (m + 1 < numsSize && nums[m + 1] == nums[m]) { // 奇偶模式, 说明目标在nums[m]右边
        l = m + 2;
      } else { // 发现目标
        return nums[m];
      }
    }
  }

  return nums[l];
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  int *arr;
  scanf("%d", &n);
  arr = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr +i);
  }
  printf("%d\n", singleNonDuplicate(arr, n));
  free(arr);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
