#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 292. Nim 游戏 - 你和你的朋友，两个人一起玩 Nim 游戏 [https://baike.baidu.com/item/Nim游戏/6737105]：
//  * 桌子上有一堆石头。
//  * 你们轮流进行自己的回合， 你作为先手 。
//  * 每一回合，轮到的人拿掉 1 - 3 块石头。
//  * 拿掉最后一块石头的人就是获胜者。
// 假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 n 的情况下赢得游戏。如果可以赢，返回 true；否则，返回 false 。
//  
// 示例 1：
// 输入：n = 4
// 输出：false
// 解释：以下是可能的结果:
// 1. 移除1颗石头。你的朋友移走了3块石头，包括最后一块。你的朋友赢了。
// 2. 移除2个石子。你的朋友移走2块石头，包括最后一块。你的朋友赢了。
// 3.你移走3颗石子。你的朋友移走了最后一块石头。你的朋友赢了。
// 在所有结果中，你的朋友是赢家。
// 示例 2：
// 输入：n = 1
// 输出：true
// 示例 3：
// 输入：n = 2
// 输出：true
//  
// 提示：
//  * 1 <= n <= 2^31 - 1

// #v1
bool canWinNim(int n) {
  if (n % 4 == 0) return false;
  if ((n-1)%4 == 0 || (n-2)%4 == 0 || (n-3)%4 == 0)
    return true;
  return false;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", canWinNim(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
