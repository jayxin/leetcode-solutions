#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1716. 计算力扣银行的钱 - Hercy 想要为购买第一辆车存钱。他 每天 都往力扣银行里存钱。
// 最开始，他在周一的时候存入 1 块钱。从周二到周日，他每天都比前一天多存入 1 块钱。 在接下来每一个周一，他都会比 前一个周一 多存入 1 块钱。
// 给你 n ，请你返回在第 n 天结束的时候他在力扣银行总共存了多少块钱。
//  
// 示例 1：
// 输入：n = 4
// 输出：10
// 解释：第 4 天后，总额为 1 + 2 + 3 + 4 = 10 。
// 示例 2：
// 输入：n = 10
// 输出：37
// 解释：第 10 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37 。注意到 第二个星期一，Hercy 存入 2 块钱。
// 示例 3：
// 输入：n = 20
// 输出：96
// 解释：第 20 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96 。
//  
// 提示：
//  * 1 <= n <= 1000

// #v1
int totalMoney(int n) {
  int week, remain, ret = 0;

  week = n / 7;
  remain = n % 7;

  for (int i = 1; i <= week; i++) {
    //ret += (i + i + 6) * 7 / 2;
    ret += (((i << 1) + 6) >> 1) * 7;
  }

  if (!remain) return ret;

  ++week;
  //for (int i = 0; i < remain; i++) ret += week + i;
  ret += week * remain + (remain - 1) * remain / 2;

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", totalMoney(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
