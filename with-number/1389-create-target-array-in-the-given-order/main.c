#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1389. 按既定顺序创建目标数组 - 给你两个整数数组 nums 和 index。你需要按照以下规 则创建目标数组：
//  * 目标数组 target 最初为空。
//  * 按从左到右的顺序依次读取 nums[i] 和 index[i]，在 target 数组中的下标 index[i] 处插入值 nums[i] 。
//  * 重复上一步，直到在 nums 和 index 中都没有要读取的元素。
// 请你返回目标数组。
// 题目保证数字插入位置总是存在。
//  
// 示例 1：
// 输入：nums = [0,1,2,3,4], index = [0,1,2,2,1]
// 输出：[0,4,1,3,2]
// 解释：
// nums       index     target
// 0            0        [0]
// 1            1        [0,1]
// 2            2        [0,1,2]
// 3            2        [0,1,3,2]
// 4            1        [0,4,1,3,2]
// 示例 2：
// 输入：nums = [1,2,3,4,0], index = [0,1,2,3,0]
// 输出：[0,1,2,3,4]
// 解释：
// nums       index     target
// 1            0        [1]
// 2            1        [1,2]
// 3            2        [1,2,3]
// 4            3        [1,2,3,4]
// 0            0        [0,1,2,3,4]
// 示例 3：
// 输入：nums = [1], index = [0]
// 输出：[1]
//  
// 提示：
//  * 1 <= nums.length, index.length <= 100
//  * nums.length == index.length
//  * 0 <= nums[i] <= 100
//  * 0 <= index[i] <= i

// #v1
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
  *returnSize = numsSize;

  int *ret = calloc(numsSize, sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    for (int j = numsSize - 2; j >= index[i]; j--) {
      ret[j+1] = ret[j];
    }
    ret[index[i]] = nums[i];
  }

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

int main(int argc, char *argv[])
{
  int *a0, n0, *a1, n1, *ret, returnSize;
  scanf("%d", &n0);
  a0 = read_1d_arr(n0);
  scanf("%d", &n1);
  a1 = read_1d_arr(n1);
  ret = createTargetArray(a0, n0, a1, n1, &returnSize);
  print_1d_arr(ret, returnSize);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
