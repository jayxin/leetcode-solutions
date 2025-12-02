#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 503. 下一个更大元素 II - 给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素 。
// 数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 。
//  
// 示例 1:
// 输入: nums = [1,2,1]
// 输出: [2,-1,2]
// 解释: 第一个 1 的下一个更大的数是 2；
// 数字 2 找不到下一个更大的数；
// 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
// 示例 2:
// 输入: nums = [1,2,3,4,3]
// 输出: [2,3,4,-1,4]
//  
// 提示:
//  * 1 <= nums.length <= 104
//  * -109 <= nums[i] <= 109

// #v1
// 单调栈, 环形数组
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;

  int stack[numsSize * 2], top = -1, *ret, end = numsSize-1;

  // allocate
  ret = (int *)malloc(sizeof(int) * numsSize);

  // 先 push 和 pop 一遍, 形成环
  for (int i = end; i >= 0; i--) {
    // 栈中的元素需要满足单调性
    while (top >= 0 && nums[i] >= stack[top]) --top;

    // push
    stack[++top] = nums[i];
  }

  for (int i = end; i >= 0; i--) {
    // 栈中的元素需要满足单调性
    while (top >= 0 && nums[i] >= stack[top]) --top;

    ret[i] = top < 0 ? -1 : stack[top];

    // push
    stack[++top] = nums[i];
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
  ret = nextGreaterElements(a, n, &s);
  print_1d_arr(ret, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
