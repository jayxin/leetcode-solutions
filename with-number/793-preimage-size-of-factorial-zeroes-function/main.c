#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 793. 阶乘函数后 K 个零 -  f(x) 是 x! 末尾是 0 的数量。回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 。
//  * 例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。
// 给定 k，找出返回能满足 f(x) = k 的非负整数 x 的数量。
//  
// 示例 1：
// 输入：k = 0
// 输出：5
// 解释：0!, 1!, 2!, 3!, 和 4! 均符合 k = 0 的条件。
// 示例 2：
// 输入：k = 5
// 输出：0
// 解释：没有匹配到这样的 x!，符合 k = 5 的条件。
// 示例 3:
// 输入: k = 3
// 输出: 5
//  
// 提示:
//  * 0 &lt;= k &lt;= 109

// #v1
// binary search
// 计算 n! 的结果有多少个 0
// n/5+n/25+n/125+...
long trailingZeroes(long n) {
  long ret = 0, t = n, d = 5;

  while (t / d) {
    ret += t / d;
    d *= 5;
  }

  return ret;
}

// 要么是 5 个, 要么是 0 个
int preimageSizeFZF(int k) {
  int64_t l = 0, r = ((int64_t)1 << 33), m, t;

  while (l < r) {
    m = (l + r) >> 1;
    t = trailingZeroes(m);

    if (t > k) {
      r = m - 1;
    } else if (t == k) {
      return 5;
    } else {
      l = m + 1;
    }
  }

  return 0;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", preimageSizeFZF(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
