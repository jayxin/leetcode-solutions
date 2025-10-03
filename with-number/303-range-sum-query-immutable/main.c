#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 303. 区域和检索 - 数组不可变 - 给定一个整数数组  nums，处理以下类型的多个查询:
//  1. 计算索引 left 和 right （包含 left 和 right）之间的 nums 元素的 和 ，其中 left <= right
// 实现 NumArray 类：
//  * NumArray(int[] nums) 使用数组 nums 初始化对象
//  * int sumRange(int i, int j) 返回数组 nums 中索引 left 和 right 之间的元素的 总 和 ，包含 left 和 right 两点（也就是 nums[left] + nums[left + 1] + ... + nums[right] )
//  
// 示例 1：
// 输入：
// ["NumArray", "sumRange", "sumRange", "sumRange"]
// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// 输出：
// [null, 1, -1, -3]
// 解释：
// NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
// numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
// numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1))
// numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
//  
// 提示：
//  * 1 <= nums.length <= 104
//  * -105 <= nums[i] <= 105
//  * 0 <= i <= j < nums.length
//  * 最多调用 10^4 次 sumRange 方法

// #v1
typedef struct {
  int *a, size, *sum;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
  NumArray* ret = (NumArray *)malloc(sizeof(NumArray));

  ret->a = nums;
  ret->size = numsSize;
  ret->sum = (int *)malloc(sizeof(int) * numsSize);

  ret->sum[0] = nums[0];
  for (int i = 1; i < numsSize; i++) {
    ret->sum[i] = ret->sum[i-1] + nums[i];
  }

  return ret;
}

int numArraySumRange(NumArray* obj, int left, int right) {
  if (!obj) return 0;
  if (!left) return obj->sum[right];
  return obj->sum[right] - obj->sum[left-1];
}

void numArrayFree(NumArray* obj) {
  if (!obj) return ;
  free(obj->sum);
  free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/
// #v1

int main(int argc, char *argv[])
{
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
