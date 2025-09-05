#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 189. 轮转数组 - 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//  
// 示例 1:
// 输入: nums = [1,2,3,4,5,6,7], k = 3
// 输出: [5,6,7,1,2,3,4]
// 解释:
// 向右轮转 1 步: [7,1,2,3,4,5,6]
// 向右轮转 2 步: [6,7,1,2,3,4,5]
// 向右轮转 3 步: [5,6,7,1,2,3,4]
// 示例 2:
// 输入：nums = [-1,-100,3,99], k = 2
// 输出：[3,99,-1,-100]
// 解释:
// 向右轮转 1 步: [99,-1,-100,3]
// 向右轮转 2 步: [3,99,-1,-100]
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * -231 <= nums[i] <= 231 - 1
//  * 0 <= k <= 105
//  
// 进阶：
//  * 尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
//  * 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？

// #v1
// O(n)
void rotate(int* nums, int numsSize, int k) {
  if (k == 0 || !nums || numsSize == 1) return ;
  int *numsCopy = (int *)malloc(sizeof(int) * numsSize);
  int i;
  for (i = 0; i < numsSize; i++) {
    numsCopy[(i + k) % numsSize] = nums[i];
  }
  for (i = 0; i < numsSize; i++) {
    nums[i] = numsCopy[i];
  }
  free(numsCopy);
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

// free 1d array
void free_1d_arr(int *arr) {
  if (!arr) {
    return;
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  int n, k;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  scanf("%d", &k);
  rotate(arr, n, k);
  print_1d_arr(arr, n);
  free_1d_arr(arr);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
