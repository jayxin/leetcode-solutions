#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3133. 数组最后一个元素的最小值 - 给你两个整数 n 和 x 。你需要构造一个长度为 n 的 正整数 数组 nums ，对于所有 0 <= i < n - 1 ，满足 nums[i + 1] 大于 nums[i] ，并且数组 nums 中所有元素的按位 AND 运算结果为 x 。
// 返回 nums[n - 1] 可能的 最小 值。
//  
// 示例 1：
// 输入：n = 3, x = 4
// 输出：6
// 解释：
// 数组 nums 可以是 [4,5,6] ，最后一个元素为 6 。
// 示例 2：
// 输入：n = 2, x = 7
// 输出：15
// 解释：
// 数组 nums 可以是 [7,15] ，最后一个元素为 15 。
//  
// 提示：
//  * 1 <= n, x <= 108

//// #v1
//// 超时
//int countBits(int n) {
  //int cnt = 0;
  //while (n) {
    //++cnt;
    //n >>= 1;
  //}
  //return cnt;
//}
//
//long long minEnd(int n, int x) {
  //int bits = countBits(x), i = 1;
  //long long ret = x, t, limit = (long long)i << bits; // 第 1 个是 x
  //bool b = false;
//
  //while (--n) {
    //if (!b) { // b == false 表示在 ret 的基础上 +1, 作进一步判断
      //if (x & 1) t = ret + 2;
      //else t = ret + 1;
//
      //if (t >= limit) b = !b; // 不符合条件则切换状态
      //else if ((t & x) != x) {
        //ret = t;
        //++n;
      //} else {
        //ret = t;
        //printf("%lld\n", ret);
      //}
    //}
//
    //if (b) { // b == true 表示需要移位
      //ret = limit | x;
      //printf("%lld\n", ret);
      //b = !b; // 无条件切换状态
      //++i;
      //limit = (long long)i << bits;
    //}
  //}
//
  //return ret;
//}
//// #v1

// #v2
int countBits(int n, int *zeroPos, int *zeroCnt) {
  int cnt = 0;
  *zeroCnt = 0;

  while (n) {
    if ((n & 1) == 0) {
      zeroPos[*zeroCnt] = cnt;
      *zeroCnt += 1;
    }
    ++cnt;
    n >>= 1;
  }

  return cnt;
}

int setBit(int x, int nth, int *zeroPos) {
  int i = 0;

  while (nth) {
    if (nth & 1) x |= 1 << zeroPos[i];
    i++;
    nth >>= 1;
  }

  return x;
}

long long minEnd(int n, int x) {
  // zeroPos 用于记录 x 的二进制表示中 0 所在的位置, 位置索引从 0 开始
  // 17 的二进制表示为 10001, 总共 5 个 bits
  // 可以通过将 0 替换为 1 来获得下一个数字
  // 对于 5 bit 的数字 17, 有 3 个 0 可用来替换, 有 2^3=8 种替换的方法
  // 对于多于 5 bit 的数字, (1<<5)|17 是第一个多于 5 bit 的数字
  // 每组有 8 种替换方法
  int zeroPos[30], zeroCnt, bits = countBits(x, zeroPos, &zeroCnt), y, step;
  long long ret, q, r, group;

  step = 1 << zeroCnt;
  q = n / step;
  r = n % step;
  if (!r) {
    q -= 1;
    r = step;
  }
  group = q << bits;
  y = setBit(x, r - 1, zeroPos);

  //ret = (6557LL<<bits)|8374159;
  ret = group|y;

  return ret;
}
// #v2

int main(int argc, char *argv[])
{
  int n, x;
  scanf("%d%d", &n, &x);
  printf("%lld\n", minEnd(n, x));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
