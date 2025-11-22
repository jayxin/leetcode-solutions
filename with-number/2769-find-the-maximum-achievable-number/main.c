#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2769. 找出最大的可达成数字 - 给你两个整数 num 和 t 。如果整数 x 可以在执行下述操作 不超过 t 次的情况下变为与 num 相等，则称其为 可达成数字 ：
//  * 每次操作将 x 的值增加或减少 1 ，同时可以选择将 num 的值增加或减少 1 。
// 返回所有可达成数字中的 最大 值 x。
//  
// 示例 1：
// 输入：num = 4, t = 1
// 输出：6
// 解释：
// 执行下述操作可以使最大可达成数字等于 num ：
//  * 最大可达成数字减少 1 ，同时 num 增加 1 。
// 示例 2：
// 输入：num = 3, t = 2
// 输出：7
// 解释：
// 执行两次下述操作可以使最大可达成数字等于 num ：
//  * 最大可达成数字减少 1 ，同时 num 增加 1。
//  
// 提示：
//  * 1 <= num, t <= 50

// #v1
int theMaximumAchievableX(int num, int t) {
  return num + (t << 1);
}
// #v1

int main(int argc, char *argv[])
{
  int n, t;
  scanf("%d%d", &n, &t);
  printf("%d\n", theMaximumAchievableX(n, t));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
