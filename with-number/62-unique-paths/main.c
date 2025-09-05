#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 62. 不同路径 - 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
// 问总共有多少条不同的路径？
//  
// 示例 1：
// [https://pic.leetcode.cn/1697422740-adxmsI-image.png]
// 输入：m = 3, n = 7
// 输出：28
// 示例 2：
// 输入：m = 3, n = 2
// 输出：3
// 解释：
// 从左上角开始，总共有 3 条路径可以到达右下角。
// 1. 向右 -> 向下 -> 向下
// 2. 向下 -> 向下 -> 向右
// 3. 向下 -> 向右 -> 向下
// 示例 3：
// 输入：m = 7, n = 3
// 输出：28
// 示例 4：
// 输入：m = 3, n = 3
// 输出：6
//  
// 提示：
//  * 1 <= m, n <= 100
//  * 题目数据保证答案小于等于 2 * 10^9

// #v1
// 递归
int table[101][101];
int _uniquePaths(int m, int n) {
  if (m <= 0 || n <= 0) {
    return 0;
  }
  if (table[m][n]) {
    return table[m][n];
  }
  table[m][n] = _uniquePaths(m - 1, n) + _uniquePaths(m, n - 1);
  table[n][m] = table[m][n];
  return table[m][n];
}

int uniquePaths(int m, int n) {
  memset(table, 0, sizeof(int) * 101 * 101);
  table[1][1] = 1;
  return _uniquePaths(m, n);
}
// #v1

int main(int argc, char *argv[])
{
  int n, m;
  scanf("%d%d", &m, &n);
  printf("%d\n", uniquePaths(m, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
