#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1732. 找 到最高海拔 - 有一个自行车手打算进行一场公路骑行，这条路线总共由 n + 1 个不同海拔 的点组成。自行车手从海拔为 0 的点 0 开始骑行。
// 给你一个长度为 n 的整数数组 gain ，其中 gain[i] 是点 i 和点 i + 1 的 净海拔高度差（0 &lt;= i &lt; n）。请你返回 最高点的海拔 。
//  
// 示例 1：
// 输入：gain = [-5,1,5,0,-7]
// 输出：1
// 解释：海拔高度依次为 [0,-5,-4,1,1,-6] 。最高海拔为 1 。
// 示例 2：
// 输入：gain = [-4,-3,-2,-1,4,3,2]
// 输出：0
// 解释：海拔高度依次为 [0,-4,-7,-9,-10,-6,-3,-1] 。最高海拔为 0 。
//  
// 提示：
//  * n == gain.length
//  * 1 &lt;= n &lt;= 100
//  * -100 &lt;= gain[i] &lt;= 100

// #v1
int largestAltitude(int* gain, int gainSize) {
  int prev = 0, cur, ret = 0;

  for (int i = 0; i < gainSize; i++) {
    cur = prev + gain[i];
    if (cur > ret) ret = cur;
    prev = cur;
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

int main(int argc, char *argv[])
{
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", largestAltitude(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
