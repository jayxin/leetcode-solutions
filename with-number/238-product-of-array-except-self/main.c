#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 238. 除自身以外数组的乘积 - 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
// 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
// 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
//  
// 示例 1:
// 输入: nums = [1,2,3,4]
// 输出: [24,12,8,6]
// 示例 2:
// 输入: nums = [-1,1,0,-3,3]
// 输出: [0,0,9,0,0]
//  
// 提示：
//  * 2 &lt;= nums.length &lt;= 105
//  * -30 &lt;= nums[i] &lt;= 30
//  * 输入 保证 数组 answer[i] 在  32 位 整数范围内
//  
// 进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组 不被视为 额外空间。）

//// #v1
//// O(n)
///**
 //* Note: The returned array must be malloced, assume caller calls free().
 //*/
//int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
  //if (!nums || numsSize <= 0) return NULL;
//
  //*returnSize = numsSize;
  //int *ret = (int *)malloc(sizeof(int) * numsSize),
      //*leftProduct = (int *)malloc(sizeof(int) * numsSize),
      //*rightProduct = (int *)malloc(sizeof(int) * numsSize);
  //int i;
  //leftProduct[0] = 1;
  //rightProduct[numsSize - 1] = 1;
  //for (i = 1; i < numsSize; i++) {
    //leftProduct[i] = leftProduct[i-1] * nums[i-1];
  //}
  //for (i = numsSize - 2; i >= 0; i--) {
    //rightProduct[i] = rightProduct[i+1] * nums[i+1];
  //}
  //for (i = 0; i < numsSize; i++) {
    //ret[i] = leftProduct[i] * rightProduct[i];
  //}
  //free(leftProduct);
  //free(rightProduct);
  //return ret;
//}
//// #v1

// #v2
// O(n)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
  if (!nums || numsSize <= 0) return NULL;

  *returnSize = numsSize;
  int *ret = (int *)malloc(sizeof(int) * numsSize),
      *leftProduct = (int *)malloc(sizeof(int) * numsSize);
  int oldRightProduct, rightProduct;
  int i;
  leftProduct[0] = 1;
  for (i = 1; i < numsSize; i++) {
    leftProduct[i] = leftProduct[i-1] * nums[i-1];
  }
  ret[numsSize - 1] = leftProduct[numsSize - 1];
  oldRightProduct = 1;
  for (i = numsSize - 2; i >= 0; i--) {
    rightProduct = oldRightProduct * nums[i+1];
    ret[i] = leftProduct[i] * rightProduct;
    oldRightProduct = rightProduct;
  }
  free(leftProduct);
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
  int n;
  scanf("%d", &n);
  int *arr = read_1d_arr(n), retSize;
  int *ret = productExceptSelf(arr, n, &retSize);
  print_1d_arr(ret, retSize);
  free_1d_arr(arr);
  free_1d_arr(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
