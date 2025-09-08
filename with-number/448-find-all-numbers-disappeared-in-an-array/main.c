#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// 448. 找到所有数组中消失的数字 - 给你一个含 n 个整数的数组 nums ，其中 nums[i]  在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数 组的形式返回结果。
//  
// 示例 1：
// 输入：nums = [4,3,2,7,8,2,3,1]
// 输出：[5,6]
// 示例 2：
// 输入：nums = [1,1]
// 输出：[2]
//  
// 提示：
//  * n == nums.length
//  * 1 <= n <= 10^5
//  * 1 <= nums[i] <= n
// 进阶：你能在不使用额外空间且时间复杂度为 O(n) 的情况下解决这个问题吗? 你可以假定 返回的数组不算在额外空间内。

// #v1
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
  int *ret = (int *)malloc(sizeof(int) * (numsSize - 1)), retLen = 0, tmp, i;
  for (i = 0; i < numsSize; i++) {
    while (nums[i] != i + 1) {
      tmp = nums[nums[i] - 1];
      if (tmp == nums[i]) {
        break;
      }
      nums[nums[i] - 1] = nums[i];
      nums[i] = tmp;
    }
  }
  for (i = 0; i < numsSize; i++) {
    if (nums[i] != i + 1) {
      ret[retLen++] = i + 1;
    }
  }
  *returnSize = retLen;
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

// free 1d array
void free_1d_arr(int *arr) {
  if (!arr) {
    return;
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  int n, *a, s, *ret;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = findDisappearedNumbers(a, n, &s);
  print_1d_arr(ret, s);
  free(a);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
