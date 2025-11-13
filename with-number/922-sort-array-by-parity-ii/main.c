#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 922. 按奇偶排序数组 II - 给定一个非负整数数组 nums，  nums 中一半整数是 奇数 ，一半整 数是 偶数 。
// 对数组进行排序，以便当 nums[i] 为奇数时，i 也是 奇数 ；当 nums[i] 为偶数时， i 也是 偶数 。
// 你可以返回 任何满足上述条件的数组作为答案 。
//  
// 示例 1：
// 输入：nums = [4,2,5,7]
// 输出：[4,5,2,7]
// 解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
// 示例 2：
// 输入：nums = [2,3]
// 输出：[2,3]
//  
// 提示：
//  * 2 <= nums.length <= 2 * 104
//  * nums.length 是偶数
//  * nums 中一半是偶数
//  * 0 <= nums[i] <= 1000
//  
// 进阶：可以不使用额外空间解决问题吗？

//// #v1
//// double pointer
//void swap(int *a, int i, int j) {
  //int tmp = a[i];
  //a[i] = a[j];
  //a[j] = tmp;
//}
//
//int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
  //*returnSize = numsSize;
//
  //// p 指向的索引为偶数, q 指向的索引为奇数
  //int p = 0, q = 1;
//
  //while (1) {
    //while (p < numsSize && (nums[p] & 1) == (p & 1)) p += 2;
    //while (q < numsSize && (nums[q] & 1) == (q & 1)) q += 2;
    //if (p < numsSize && q < numsSize) swap(nums, p, q);
    //else break;
  //}
//
  //return nums;
//}
//// #v1

// #v2
// double pointer
void swap(int *a, int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;

  // p 指向的索引为偶数, q 指向的索引为奇数
  int p = 0, q = 1;

  while (1) {
    while (p < numsSize && !(nums[p] & 1)) p += 2;
    while (q < numsSize && (nums[q] & 1)) q += 2;
    if (p < numsSize && q < numsSize) swap(nums, p, q);
    else break;
  }

  return nums;
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
  int n, *a, *ret, returnSize;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = sortArrayByParityII(a, n, &returnSize);
  print_1d_arr(ret, returnSize);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
