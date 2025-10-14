#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2310. 个位数字为 K 的整数之和 - 给你两个整数 num 和 k ，考虑具有以下属性的正整 数多重集：
//  * 每个整数个位数字都是 k 。
//  * 所有整数之和是 num 。
// 返回该多重集的最小大小，如果不存在这样的多重集，返回 -1 。
// 注意：
//  * 多重集与集合类似，但多重集可以包含多个同一整数，空多重集的和为 0 。
//  * 个位数字 是数字最右边的数位。
//  
// 示例 1：
// 输入：num = 58, k = 9
// 输出：2
// 解释：
// 多重集 [9,49] 满足题目条件，和为 58 且每个整数的个位数字是 9 。
// 另一个满足条件的多重集是 [19,39] 。
// 可以证明 2 是满足题目条件的多重集的最小长度。
// 示例 2：
// 输入：num = 37, k = 2
// 输出：-1
// 解释：个位数字为 2 的整数无法相加得到 37 。
// 示例 3：
// 输入：num = 0, k = 7
// 输出：0
// 解释：空多重集的和为 0 。
//  
// 提示：
//  * 0 &lt;= num &lt;= 3000
//  * 0 &lt;= k &lt;= 9
// Try solving this recursively.
// Create a method that takes an integer x as a parameter. This method returns
// the minimum possible size of a set where each number has units digit k and
// the sum of the numbers in the set is x.

//// #v1
//// 递归, 记忆化搜索
//#define LIMIT 0x3f3f3f3f
//int kk, *t;
//
//int f(int n) {
  //// existed
  //if (t[n] >= 0) return t[n];
//
  //// edge case
  //if ((n < kk) || ((n & 1) && !(kk & 1))) {
    //t[n] = 0;
    //return t[n];
  //}
//
  //int ret = LIMIT, q, m, i, j;
//
  //// compute
  //for (i = kk; i <= n; i += 10) {
    //if (!i) continue;
//
    //// i != 0
    //m = n / i;
//
    //for (j = 1; j <= m; j++) {
      //q = f(n - i * j);
//
      //if (q) {
        //q += j;
        //if (ret > q) ret = q;
      //}
    //}
  //}
//
  //if (ret != LIMIT) t[n] = ret;
  //else t[n] = 0;
//
  //return t[n];
//}
//
//int minimumNumbers(int num, int k) {
  //// edge cases
  //// num == 0
  //if (!num) return 0;
  //// num 是奇数且 k 是偶数
  //if ((num & 1) && !(k & 1)) return -1;
//
  //int tab[3001], ret;
//
  //// init
  //memset(tab, 0xff, sizeof(int) * 3001);
  //t = tab;
  //kk = k;
  //for (int i = k; i <= num; i += 10) tab[i] = 1;
//
  //// compute
  //ret = f(num);
//
  //return ret == 0 ? -1 : ret;
//}
//// #v1

//// #v2
//// 动态规划
//#define min(a, b) ((a) >= (b) ? (b) : (a))
//
//int minimumNumbers(int num, int k) {
  //int isEven = (k & 1) == 0;
  //// num 是奇数且 k 是偶数
  //if ((num & 1) && isEven) return -1;
//
  //int dp[num + 1], ret, i, j, t, l, m;
//
  //// init
  //dp[0] = 0;
//
  //for (i = 1; i <= num; i++) {
    //if (i % 10 == k) dp[i] = 1;
    //else if (((i & 1) && isEven)) dp[i] = -1;
    //else {
      //dp[i] = -1;
//
      //for (j = k; j <= i; j += 10) {
        //if (!j) continue;
//
        //m = i / j;
//
        //for (l = 1; l <= m; l++) {
          //t = dp[i - l * j];
//
          //if (dp[i] == -1 && t != -1) {
            //dp[i] = t + l;
            //continue;
          //}
//
          //if (t != -1) {
            //dp[i] = min(dp[i], t+l);
          //} else {
            //break;
          //}
        //}
      //}
    //}
  //}
//
  //return dp[num];
//}
//// #v2

//// #v3
//// 动态规划 优化
//#define min(a, b) ((a) >= (b) ? (b) : (a))
//
//int minimumNumbers(int num, int k) {
  //// num 是奇数且 k 是偶数
  //if ((num & 1) && !(k & 1)) return -1;
//
  //// dp[i] 表示个位数字为 k 且集合中的数字之和为 i 的最小元素个数
  //int dp[num+1], ret, i, j, t;
//
  //// init
  //dp[0] = 0;
  //// compute
  //for (i = 1; i <= num; i++) {
    //if (i % 10 == k) {
      //dp[i] = 1;
      //continue;
    //}
//
    //dp[i] = -1;
    //for (j = k; j <= i; j += 10) {
      //t = dp[i-j];
      //if (t != -1) {
        //if (dp[i] == -1) dp[i] = t+1;
        //else dp[i] = min(dp[i], t+1);
      //}
    //}
  //}
//
  //return dp[num];
//}
//// #v3

// #v4
// 枚举选择的数的个数
int minimumNumbers(int num, int k) {
  // 空集合
  if (!num) return 0;

  int r = num % 10, t;

  // 最多选择 10 个数字
  // 因为若为 11 个数字, 11k 的各位数字也是 k, 可以把 11 个合并成 1 个
  // i * k 的个位数字应该和 num 的个位数字相同
  for (int i = 1; i <= 10; i++) {
    //if (k * i <= num && (num - k * i) % 10 == 0) return i;

    t = k * i;
    if (t <= num && t % 10 == r) return i;
  }

  return -1;
}
// #v4

int main(int argc, char *argv[])
{
  int n, k;
  scanf("%d%d", &n, &k);
  printf("%d\n", minimumNumbers(n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
