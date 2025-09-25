#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 283. 移动零 - 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺 序。
// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
//  
// 示例 1:
// 输入: nums = [0,1,0,3,12]
// 输出: [1,3,12,0,0]
// 示例 2:
// 输入: nums = [0]
// 输出: [0]
//  
// 提示:
//  * 1 &lt;= nums.length &lt;= 104
//  * -231 &lt;= nums[i] &lt;= 231 - 1
//  
// 进阶：你能尽量减少完成的操作次数吗？

// #v1
void moveZeroes(int* nums, int numsSize) {
  int l = -1, i;
  for (i = 0; i < numsSize; i++) {
    if (nums[i] != 0) {
      ++l;
      if (l == i) continue;
      nums[l] = nums[i];
      nums[i] = 0;
    }
  }
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  moveZeroes(a, n);
  print_1d_arr(a, n);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
