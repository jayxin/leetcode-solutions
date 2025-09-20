#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 167. 两数之和 II - 输入有序数组 - 给你一个下标从 1 开始的整数数组 numbers ， 该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 &lt;= index1 &lt; index2 &lt;= numbers.length 。
// 以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。
// 你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
// 你所设计的解决方案必须只使用常量级的额外空间。
//  
// 示例 1：
// 输入：numbers = [2,7,11,15], target = 9
// 输出：[1,2]
// 解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
// 示例 2：
// 输入：numbers = [2,3,4], target = 6
// 输出：[1,3]
// 解释：2 与 4 之和等于目标数 6 。因此 index1 = 1, index2 = 3 。返回 [1, 3] 。
// 示例 3：
// 输入：numbers = [-1,0], target = -1
// 输出：[1,2]
// 解释：-1 与 0 之和等于目标数 -1 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
//  
// 提示：
//  * 2 &lt;= numbers.length &lt;= 3 * 104
//  * -1000 &lt;= numbers[i] &lt;= 1000
//  * numbers 按 非递减顺序 排列
//  * -1000 &lt;= target &lt;= 1000
//  * 仅存在一个有效答案

// #v1
// 双指针
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
  *returnSize = 2;
  int l = 0, r = numbersSize - 1, *ret, t;
  ret = (int *)malloc(sizeof(int) * 2);
  ret[0] = ret[1] = -1;

  while (l < r) {
    t = numbers[l] + numbers[r];
    if (t == target) {
      ret[0] = l + 1;
      ret[1] = r + 1;
      break;
    } else if (t > target) {
      --r;
    } else {
      ++l;
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
  int n, *a, *ret, s, t;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &t);
  ret = twoSum(a, n, t, &s);
  printf("%d %d\n", ret[0], ret[1]);
  free(ret);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
