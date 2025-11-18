#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 481. 神奇字 符串 - 神奇字符串 s 仅由 '1' 和 '2' 组成，并需要遵守下面的规 则：
//  * 神奇字符串 s 的神奇之处在于，串联字符串中 '1' 和 '2' 的连 续出现次数可以生成该字符串。
// s 的前几个元素是 s = "1221121221221121122……" 。如果将 s 中连续的若干 1 和 2 进行分组，可以得到 "1 22 11 2 1 22 1 22 11 2 11 22 ......" 。每组 中 1 或者 2 的出现次数分别是 "1 2 2 1 1 2 1 2 2 1 2 2 ......" 。上面的 出现次数正是 s 自身。
// 给你一个整数 n ，返回在神奇字符串 s 的前 n 个数字中 1 的数目。
//  
// 示例 1：
// 输入：n = 6
// 输出：3
// 解释：神奇字符串 s 的前 6 个元素是 “122112”，它包含三个 1，因此返回 3 。
// 示例 2：
// 输入：n = 1
// 输出：1
//  
// 提示：
//  * 1 <= n <= 105

// #v1
// digit times pos
// 1     1     1
// 2     2     2
// 1     2     3
// 2     1     4
// 1     1     5
int magicalString(int n) {
  if (n == 1) return 1;

  // magical string
  char s[n+1];
  // digit 表示当前数字是 1 或者 2
  // times 表示当前数字出现的次数
  // pos 指向 s 的索引, 用来跟踪 times 的值
  // sum 表示当前已经形成的字符串的长度
  // one_cnt 表示已经形成的字符串中数字 1 出现的次数
  int digit = 1, times = 1, pos = 1, sum = 1, one_cnt = 1;

  s[1] = 1;
  s[2] = 2;
  while (sum < n) {
    times = s[++pos];
    digit = digit == 1 ? 2 : 1;

    int b = sum + times <= n ? sum+times : n;

    for (int i = sum+1; i <= b; i++) {
      s[i] = digit;
    }

    if (digit == 1) one_cnt += b - sum;

    sum = b;
  }

  return one_cnt;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", magicalString(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
