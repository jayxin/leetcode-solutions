#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// 1313.  解压缩编码列表 - 给你一个以行程长度编码压缩的整数列表 nums 。
// 考虑每对相邻的两个元素 [freq, val] = [nums[2*i], nums[2*i+1]] （其中 i &gt;= 0 ），每一对都表示解压后子列表中有 freq 个值为 val 的元素，你需要从左到右连接所有子列表以生成解压后的列表。
// 请你返回解压后的列表。
//  
// 示例 1：
// 输入：nums = [1,2,3,4]
// 输出：[2,4,4,4]
// 解释：第一对 [1,2] 代表着 2 的出现频次为 1，所以生成数组 [2]。
// 第二对 [3,4] 代表着 4 的出现频次为 3，所以生成数组 [4,4,4]。
// 最后将它们串联到一起 [2] + [4,4,4] = [2,4,4,4]。
// 示例 2：
// 输入：nums = [1,1,2,3]
// 输出：[1,3,3]
//  
// 提示：
//  * 2 &lt;= nums.length &lt;= 100
//  * nums.length % 2 == 0
//  * 1 &lt;= nums[i] &lt;= 100

// #v1
int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
  int *ret, retLen = 0, retSize = 0, i, j;
  for (i = 0; i < numsSize; i += 2) {
    retSize += nums[i];
  }
  ret = (int *)malloc(sizeof(int) * retSize);
  for (i = 0; i < numsSize; i += 2) {
    for (j = 0; j < nums[i]; j++) {
      ret[retLen++] = nums[i + 1];
    }
  }
  *returnSize = retSize;
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
  int n, *a, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = decompressRLElist(a, n, &s);
  print_1d_arr(ret, s);
  free(a);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
