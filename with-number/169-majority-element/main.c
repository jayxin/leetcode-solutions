#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 多数元素
// 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
//
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

//    n == nums.length
//    1 <= n <= 5 * 104
//    -109 <= nums[i] <= 109

// #v1
int majorityElement(int* nums, int numsSize) {
  if (numsSize <= 0 || nums == 0) {
    return -1;
  }

  int result = 0, cnt = 0, i;

  for (i = 0; i < numsSize; i++) {
    if (cnt == 0) { // 没有可以用来配对的, 将当前的值作为配对用的值
      result = nums[i];
    }

    if (result == nums[i]) { // 和 result 值相同, 可用来配对的数量 +1
      cnt++;
    } else { // result 和 nums[i] 配对
      cnt--;
    }
  }

  int result_cnt = 0;
  for (i = 0; i < numsSize; i++) {
    if (nums[i] == result) { // 计数
      result_cnt++;
    }
  }

  if (result_cnt <= numsSize / 2) {
    result = -1;
  }

  return result;
}
// #v1

int main(int argc, char *argv[])
{
  int arr[100] = {};
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }

  printf("%d\n", majorityElement(arr, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
