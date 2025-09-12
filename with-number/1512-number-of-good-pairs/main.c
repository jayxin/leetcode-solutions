#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1512. 好 数对的数目 - 给你一个整数数组 nums 。
// 如果一组数字 (i,j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数 对 。
// 返回好数对的数目。
//  
// 示例 1：
// 输入：nums = [1,2,3,1,1,3]
// 输出：4
// 解释：有 4 组好数对，分别是 (0,3), (0,4), (3,4), (2,5) ，下标从 0 开始
// 示例 2：
// 输入：nums = [1,1,1,1]
// 输出：6
// 解释：数组中的每组数字都是好数对
// 示例 3：
// 输入：nums = [1,2,3]
// 输出：0
//  
// 提示：
//  * 1 <= nums.length <= 100
//  * 1 <= nums[i] <= 100

//// #v1
//// brute force
//int numIdenticalPairs(int* nums, int numsSize) {
  //int i, j, ret = 0;
  //for (i = 0; i < numsSize; i++) {
    //for (j = i + 1; j < numsSize; j++) {
      //if (nums[i] == nums[j]) ret++;
    //}
  //}
  //return ret;
//}
//// #v1

// #v2
// count
int numIdenticalPairs(int* nums, int numsSize) {
  int i, ret = 0, tab[101] = {0};
  for (i = 0; i < numsSize; i++) {
    tab[nums[i]]++;
  }
  for (i = 1; i <= 100; i++) {
    if (tab[i]) ret += (tab[i] * (tab[i] - 1)) >> 1;
  }
  return ret;
}
// #v2

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
  printf("%d\n", numIdenticalPairs(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
