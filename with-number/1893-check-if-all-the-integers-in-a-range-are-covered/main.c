#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1893. 检查是否区域内所有整数都被覆盖 - 给你一个二维整数数组 ranges 和两 个整数 left 和 right 。每个 ranges[i] = [starti, endi] 表示一个从 starti 到 endi 的 闭区间 。
// 如果闭区间 [left, right] 内每个整数都被 ranges 中 至少一个 区间覆盖，那么请你返回 true ，否则返回 false 。
// 已知区间 ranges[i] = [starti, endi] ，如果整数 x 满足 starti &lt;= x &lt;= endi  ，那么我们称整数x 被覆盖了。
//  
// 示例 1：
// 输入：ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
// 输出：true
// 解释：2 到 5 的每个整数都被覆盖了：
// - 2 被第一个区间覆盖。
// - 3 和 4 被第二个区间覆盖。
// - 5 被第三个区间覆盖。
// 示例 2：
// 输入：ranges = [[1,10],[10,20]], left = 21, right = 21
// 输出：false
// 解释：21 没有被任何一个区间覆盖。
//  
// 提示：
//  * 1 &lt;= ranges.length &lt;= 50
//  * 1 &lt;= starti &lt;= endi &lt;= 50
//  * 1 &lt;= left &lt;= right &lt;= 50

// #v1
bool isCovered(int** ranges, int rangesSize, int* rangesColSize, int left, int right) {
  int t[51] = {0};
  for (int i = 0; i < rangesSize; i++) {
    for (int j = ranges[i][0]; j <= ranges[i][1]; j++) {
      t[j] = 1;
    }
  }
  for (int i = left; i <= right; i++) {
    if (t[i] == 0) return false;
  }
  return true;
}
// #v1

// read 2d array
int** read_2d_arr(int rows, int cols) {
  int i, j;
  int **ret = (int **)malloc(sizeof(int *) * rows);
  for (i = 0; i < rows; i++) {
    ret[i] = (int *)malloc(sizeof(int) * cols);
  }

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &ret[i][j]);
    }
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int l, r, **a, m, n;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  scanf("%d%d", &l, &r);
  if (isCovered(a, m, &n, l, r)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
