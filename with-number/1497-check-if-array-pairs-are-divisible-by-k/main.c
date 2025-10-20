#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1497. 检查数组对是否可以被 k 整除 - 给你一个整数数组 arr 和一个整数 k ，其 中数组长度是偶数，值为 n 。
// 现在需要把数组恰好分成 n / 2 对，以使每对数字的和都能够被 k 整除。
// 如果存在这样的分法，请返回 true ；否则，返回 false。
//  
// 示例 1：
// 输入：arr = [1,2,3,4,5,10,6,7,8,9], k = 5
// 输出：true
// 解释：划分后的数字对为 (1,9),(2,8),(3,7),(4,6) 以及 (5,10) 。
// 示例 2：
// 输入：arr = [1,2,3,4,5,6], k = 7
// 输出：true
// 解释：划分后的数字对为 (1,6),(2,5) 以及 (3,4) 。
// 示例 3：
// 输入：arr = [1,2,3,4,5,6], k = 10
// 输出：false
// 解释：无法在将数组中的数字分为三对的同时满足每对数字和能够被 10 整除的条件。
//  
// 提示：
//  * arr.length == n
//  * 1 <= n <= 105
//  * n 为偶数
//  * -109 <= arr[i] <= 109
//  * 1 <= k <= 105
// Keep an array of the frequencies of ((x % k) + k) % k for each x in arr.
// for each i in [0, k - 1] we need to check if freq[i] == freq[k - i]
// Take care of the case when i == k - i and when i == 0

// #v1
// 分类, 配对, 计数, 模算术
bool canArrange(int* arr, int arrSize, int k) {
  int remainderCnts[k], r1, r2;

  memset(remainderCnts, 0, sizeof(remainderCnts));

  for (int i = 0; i < arrSize; i++) {
    // 数组中每个元素对 k 求余数, 对余数出现的次数进行计数
    // 因为数组中的元素可能存在负数, 所以 +k
    ++remainderCnts[((arr[i] % k) + k) % k];
  }

  if (remainderCnts[0] & 1) return false;

  for (int i = 1; i < k; i++) {
    r1 = i;
    r2 = k - i;

    if (r1 == r2) {
      if (remainderCnts[r1] & 1) return false;
    } else {
      if (remainderCnts[r1] != remainderCnts[r2]) return false;
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
  if (canArrange(a, n, k)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
