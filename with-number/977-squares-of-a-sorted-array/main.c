#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 977. 有序数组的平方 - 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序 。
//  
// 示例 1：
// 输入：nums = [-4,-1,0,3,10]
// 输出：[0,1,9,16,100]
// 解释：平方后，数组变为 [16,1,0,9,100]
// 排序后，数组变为 [0,1,9,16,100]
// 示例 2：
// 输入：nums = [-7,-3,2,3,11]
// 输出：[4,9,9,49,121]
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 104
//  * -104 &lt;= nums[i] &lt;= 104
//  * nums 已按 非递减顺序 排序
//  
// 进阶：
//  * 请你设计时间复杂度为 O(n) 的算法解决本问题

//// #v1
//int* sortedSquares(int* nums, int numsSize, int* returnSize) {
  //*returnSize = numsSize;
  //int *ret = (int *)malloc(sizeof(int) * numsSize);
  //if (nums[0] >= 0) { // nums[i] >= 0
    //for (int i = 0; i < numsSize; i++) {
      //ret[i] = nums[i] * nums[i];
    //}
  //} else if (nums[numsSize - 1] < 0) { // nums[i] < 0
    //for (int i = 0; i < numsSize; i++) {
      //ret[numsSize - i - 1] = nums[i] * nums[i];
    //}
  //} else {
    //int l, r = 0, lVal, rVal, retLen = 0;
    //while (nums[r] < 0) {
      //r++;
    //}
    //l = r - 1;
    //while (l >= 0 && r < numsSize) {
      //lVal = nums[l] * nums[l];
      //rVal = nums[r] * nums[r];
      //if (lVal < rVal) {
        //ret[retLen++] = lVal;
        //l--;
      //} else {
        //ret[retLen++] = rVal;
        //r++;
      //}
    //}
//
    //while (l >= 0) {
      //lVal = nums[l] * nums[l];
      //ret[retLen++] = lVal;
      //l--;
    //}
//
    //while (r < numsSize) {
      //rVal = nums[r] * nums[r];
      //ret[retLen++] = rVal;
      //r++;
    //}
  //}
  //return ret;
//}
//// #v1

// #v2
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  int *ret = (int *)malloc(sizeof(int) * numsSize);
  int l, r = 0, retLen = 0, lVal, rVal;

  // 3种情况, 利用 nums 的有序性
  // 1. nums[i] >= 0
  // 2. nums[i] < 0
  // 3. 同时存在 nums[i] >= 0 和 nums[i] < 0
  // 找到数量级最小的数, nums[r] >= 0, nums[r-1] < 0
  // 正数(索引 r)和负数(索引 r-1)都从数量级最小的开始计算
  // 负数索引往前走, 正数索引往后走
  while (r < numsSize && nums[r] < 0) {
    r++;
  }
  l = r - 1;
  while (l >= 0 && r < numsSize) {
    lVal = nums[l] * nums[l];
    rVal = nums[r] * nums[r];
    if (lVal < rVal) {
      ret[retLen++] = lVal;
      l--;
    } else {
      ret[retLen++] = rVal;
      r++;
    }
  }

  while (l >= 0) {
    lVal = nums[l] * nums[l];
    ret[retLen++] = lVal;
    l--;
  }

  while (r < numsSize) {
    rVal = nums[r] * nums[r];
    ret[retLen++] = rVal;
    r++;
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
  int n, *a, *r, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  r = sortedSquares(a, n, &s);
  print_1d_arr(r, s);
  free(a);
  free(r);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
