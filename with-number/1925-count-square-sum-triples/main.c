#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1925. 统计平方和三元组的数目 - 一个 平方和三元组 (a,b,c) 指的是满足 a2 + b2 = c2 的 整数 三元组 a，b 和 c 。
// 给你一个整数 n ，请你返回满足 1 <= a, b, c <= n 的 平方和三元组 的数目。
//  
// 示例 1：
// 输入：n = 5
// 输出：2
// 解释：平方和三元组为 (3,4,5) 和 (4,3,5) 。
// 示例 2：
// 输入：n = 10
// 输出：4
// 解释：平方和三元组为 (3,4,5)，(4,3,5)，(6,8,10) 和 (8,6,10) 。
//  
// 提示：
//  * 1 <= n <= 250

// #v1
int l, r, m, v;

int mySqrt(int x) {
  l = 1, r = x >> 1;

  while (l < r) {
    m = (l + r) >> 1;

    v = m * m;
    if (v == x) return m;
    else if (v < x) l = m + 1;
    else r = m - 1;
  }

  if (l * l == x) return l;

  return -1;
}

int countTriples(int n) {
  int t, cnt = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      t = i * i + j * j;
      t = mySqrt(t);
      if (t > 0 && t <= n) cnt += 2;
    }
  }

  return cnt;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", countTriples(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
