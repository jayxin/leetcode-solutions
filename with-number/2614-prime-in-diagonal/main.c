#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2614.  对角线上的质数 - 给你一个下标从 0 开始的二维整数数组 nums 。
// 返回位于 nums 至少一条 对角线 上的最大 质数 。如果任一对角线上均不存在质数，返回 0 。
// 注意：
//  * 如果某个整数大于 1 ，且不存在除 1 和自身之外的正整数因子，则认为该整数是一个质数。
//  * 如果存在整数 i ，使得 nums[i][i] = val 或者 nums[i][nums.length - i - 1]= val ，则认为整数 val 位于 nums 的一条对角线上。
// [https://assets.leetcode.com/uploads/2023/03/06/screenshot-2023-03-06-at-45648-pm.png]
// 在上图中，一条对角线是 [1,5,9] ，而另一条对角线是 [3,5,7] 。
//  
// 示例 1：
// 输入：nums = [[1,2,3],[5,6,7],[9,10,11]]
// 输出：11
// 解释：数字 1、3、6、9 和 11 是所有 &quot;位于至少一条对角线上&quot; 的数字。由于 11 是最大的质数，故返回 11 。
// 示例 2：
// 输入：nums = [[1,2,3],[5,17,7],[9,11,10]]
// 输出：17
// 解释：数字 1、3、9、10 和 17 是所有满足&quot;位于至少一条对角线上&quot;的数字。由于 17 是最大的质数，故返回 17 。
//  
// 提示：
//  * 1 <= nums.length <= 300
//  * nums.length == numsi.length
//  * 1 <= nums[i][j] <= 4*106

//// #v1
//int isPrime(int x) {
  //if (x <= 1) return 0;
  //if (x == 2) return 1;
  //if (!(x & 1)) return 0;
//
  //for (int i = 2; i*i <= x; i++) {
    //if (x % i == 0) return 0;
  //}
//
  //return 1;
//}
//
//int diagonalPrime(int** nums, int numsSize, int* numsColSize) {
  //int ret = 0;
//
  //for (int i = 0; i < numsSize; i++) {
    //for (int j = 0; j < numsSize; j++) {
      //if (i == j || j == numsSize - i - 1) {
        //if (nums[i][j] > ret && isPrime(nums[i][j]))
          //ret = nums[i][j];
      //}
    //}
  //}
//
  //return ret;
//}
//// #v1

// #v2
int isPrime(int x) {
  if (x <= 1) return 0;
  if (x == 2) return 1;
  if (!(x & 1)) return 0;

  for (int i = 2; i*i <= x; i++) {
    if (x % i == 0) return 0;
  }

  return 1;
}

int diagonalPrime(int** nums, int numsSize, int* numsColSize) {
  int ret = 0, i = 0, j, end = numsSize - 1;

  while (i < numsSize) {
    if (nums[i][i] > ret && isPrime(nums[i][i]))
      ret = nums[i][i];

    j = end - i;
    if (nums[i][j] > ret && isPrime(nums[i][j]))
      ret = nums[i][j];

    i++;
  }

  return ret;
}
// #v2

// read 2d array
int** read_2d_arr(int rows, int cols) {
  int i, j;
  int **ret = (int **)malloc(sizeof(int *) * rows);
  for (i = 0; i < rows; i++) {
    ret[i] = (int *)malloc(sizeof(int) * cols);
  }

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &ret[i][j]);
    }
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int n, **a;
  scanf("%d", &n);
  a = read_2d_arr(n, n);
  printf("%d\n", diagonalPrime(a, n, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
