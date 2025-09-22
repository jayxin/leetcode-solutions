#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1437. 是否所有 1 都至少相隔 k 个元素 - 给你一个由若干 0 和 1 组成的数组 nums 以及整数 k。如果所有 1 都至少相隔 k 个元素，则返回 true ；否则，返回 false  。
//  
// 示例 1：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/03/sample_1_1791.png]
// 输入：nums = [1,0,0,0,1,0,0,1], k = 2
// 输出：true
// 解释：每个 1 都至少相隔 2 个元素。
// 示例 2：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/03/sample_2_1791.png]
// 输入：nums = [1,0,0,1,0,1], k = 2
// 输出：false
// 解释：第二个 1 和第三个 1 之间只隔了 1 个元素。
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 105
//  * 0 &lt;= k &lt;= nums.length
//  * nums[i] 的值为 0 或 1

// #v1
bool kLengthApart(int* nums, int numsSize, int k) {
  if (numsSize == 1) return true;

  int i, j, t;

  for (i = 0; i < numsSize; i++) {
    if (nums[i] & 1) {
      for (j = 1; j <= k; j++) {
        t = i + j;
        if (t < numsSize && (nums[t] & 1)) return false;
        else if (t >= numsSize) break;
      }
      i += k;
    }
  }

  return true;
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

int main(int argc, char *argv[])
{
  int n, *a, k;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);
  if (kLengthApart(a, n, k)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
