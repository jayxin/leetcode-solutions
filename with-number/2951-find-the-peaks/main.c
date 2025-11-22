#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2951. 找出峰 值 - 给你一个下标从 0 开始的数组 mountain 。你的任务是找出数组 mountain 中的所有 峰值。
// 以数组形式返回给定数组中 峰值 的下标，顺序不限 。
// 注意：
//  * 峰值 是指一个严格大于其相邻元素的元素。
//  * 数组的第一个和最后一个元素 不 是峰值。
//  
// 示例 1：
// 输入：mountain = [2,4,4]
// 输出：[]
// 解释：mountain[0] 和 mountain[2] 不可能是峰值，因为它们是数组的第一个和最后一个元素。
// mountain[1] 也不可能是峰值，因为它不严格大于 mountain[2] 。
// 因此，答案为 [] 。
// 示例 2：
// 输入：mountain = [1,4,3,8,5]
// 输出：[1,3]
// 解释：mountain[0] 和 mountain[4] 不可能是峰值，因为它们是数组的第一个和最后一个元素。
// mountain[2] 也不可能是峰值，因为它不严格大于 mountain[3] 和 mountain[1] 。
// 但是 mountain[1] 和 mountain[3] 严格大于它们的相邻元素。
// 因此，答案是 [1,3] 。
//  
// 提示：
//  * 3 <= mountain.length <= 100
//  * 1 <= mountain[i] <= 100

// #v1
int max(int a, int b) { return a >= b ? a : b; }
int* findPeaks(int* mountain, int mountainSize, int* returnSize) {
  int *ret = (int *)malloc(sizeof(int) * max(mountainSize-2, 1)), retLen = 0;

  for (int i = 1; i < mountainSize-1; i++) {
    if (mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]) ret[retLen++] = i;
  }

  *returnSize  = retLen;

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
  int *mountain, mountainSize, returnSize, *ret;
  scanf("%d", &mountainSize);
  mountain = read_1d_arr(mountainSize);
  ret = findPeaks(mountain, mountainSize, &returnSize);
  print_1d_arr(ret, returnSize);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
