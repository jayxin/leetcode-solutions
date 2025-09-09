#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 263. 丑数 - 丑数  就是只包含质因数 2、3 和 5 的 正 整数。
// 给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
//  
// 示例 1：
// 输入：n = 6
// 输出：true
// 解释：6 = 2 × 3
// 示例 2：
// 输入：n = 1
// 输出：true
// 解释：1 没有质因数。
// 示例 3：
// 输入：n = 14
// 输出：false
// 解释：14 不是丑数，因为它包含了另外一个质因数 7 。
//  
// 提示：
//  * -231 &lt;= n &lt;= 231 - 1

// #v1
bool isUgly(int n) {
  if (n <= 0) return false;
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else if (n % 3 == 0) {
      n /= 3;
    } else if (n % 5 == 0) {
      n /= 5;
    } else {
      return false;
    }
  }
  return true;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  if (isUgly(n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
