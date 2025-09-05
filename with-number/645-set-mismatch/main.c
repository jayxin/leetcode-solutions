#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 645. 错误的集合
// 集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。
//
// 给定一个数组 nums 代表了集合 S 发生错误后的结果。
//
// 请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
//
//  2 <= nums.length <= 104
//  1 <= nums[i] <= 104

// #v1
/* max value of array elements */
#define ARR_EL_MAX 10000
#define BITMAP_EL_SIZE sizeof(unsigned char)
#define BITMAP_SIZE (ARR_EL_MAX / (BITMAP_EL_SIZE * 8))
unsigned char bitmap[BITMAP_SIZE];

void set_bit(int pos) {
  int byte_offset = pos / BITMAP_EL_SIZE,
      bit_offset = pos % BITMAP_EL_SIZE;
  bitmap[byte_offset] |= 1 << bit_offset;
}

int test_bit(int pos) {
  int byte_offset = pos / BITMAP_EL_SIZE,
      bit_offset = pos % BITMAP_EL_SIZE;
  return bitmap[byte_offset] & (1 << bit_offset);
}

int* findErrorNums(int *nums, int numsSize, int *returnSize) {
  *returnSize = 2;
  int *ret = (int *)malloc(sizeof(int) * 2);
  int tot = 0;
  // ret[0] : 重复
  // ret[1] : 丢失
  memset(bitmap, 0, BITMAP_SIZE);

  for (int i = 0; i < numsSize; ++i) {
    if (test_bit(nums[i])) {
      ret[0] = nums[i];
    }
    set_bit(nums[i]);
    tot += nums[i];
  }

  tot -= ret[0];

  int sum = (1 + numsSize) * numsSize / 2;
  ret[1] = sum - tot;

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n, m;
  int *arr;
  scanf("%d", &n);
  arr = (int *)malloc(sizeof(int) * n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  int *ret = findErrorNums(arr, n, &m);

  for (int i = 0; i < 2; ++i) {
    printf("%d\n", ret[i]);
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
