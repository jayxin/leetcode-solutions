#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1550. 存在连续三个奇数的数组 - 给你一个整数数组 arr，请你判断数组中是否存在连续 三个元素都是奇数的情况：如果存在，请返回 true ；否则，返回 false 。
//  
// 示例 1：
// 输入：arr = [2,6,4,1]
// 输出：false
// 解释：不存在连续三个元素都是奇数的情况。
// 示例 2：
// 输入：arr = [1,2,34,3,4,5,7,23,12]
// 输出：true
// 解释：存在连续三个元素都是奇数的情况，即 [5,7,23] 。
//  
// 提示：
//  * 1 &lt;= arr.length &lt;= 1000
//  * 1 &lt;= arr[i] &lt;= 1000

// #v1
bool threeConsecutiveOdds(int* arr, int arrSize) {
  int oddCnt = 0;

  for (int i = 0; i < arrSize; i++) {
    if (arr[i] & 1) {
      ++oddCnt;
      if (oddCnt == 3) return true;
    } else {
      oddCnt = 0;
    }
  }

  return false;
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  if (threeConsecutiveOdds(a, n))
    printf("true\n");
  else
    printf("false\n");
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
