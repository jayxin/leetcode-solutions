#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2429. 最小异 或 - 给你两个正整数 num1 和 num2 ，找出满足下述条件的正整数 x ：
//  * x 的置位数和 num2 相同，且
//  * x XOR num1 的值 最小
// 注意 XOR 是按位异或运算。
// 返回整数 x 。题目保证，对于生成的测试用例， x 是 唯一确定 的。
// 整数的 置位数 是其二进制表示中 1 的数目。
//  
// 示例 1：
// 输入：num1 = 3, num2 = 5
// 输出：3
// 解释：
// num1 和 num2 的二进制表示分别是 0011 和 0101 。
// 整数 3 的置位数与 num2 相同，且 3 XOR 3 = 0 是最小的。
// 示例 2：
// 输入：num1 = 1, num2 = 12
// 输出：3
// 解释：
// num1 和 num2 的二进制表示分别是 0001 和 1100 。
// 整数 3 的置位数与 num2 相同，且 3 XOR 1 = 2 是最小的。
//  
// 提示：
//  * 1 <= num1, num2 <= 10^9
// To arrive at a small xor, try to turn off some bits from num1
// If there are still left bits to set, try to set them from the least
// significant bit

// #v1
int countOnes(int x) {
  int cnt = 0;

  while (x) {
    ++cnt;
    x -= x & -x;
  }

  return cnt;
}

int minimizeXor(int num1, int num2) {
  int oneCnt1, oneCnt2, x, i, k;

  oneCnt1 = countOnes(num1);
  oneCnt2 = countOnes(num2);

  if (oneCnt1 == oneCnt2) return num1;

  x = num1;
  i = -1;
  if (oneCnt1 > oneCnt2) { // unset bit
    k = oneCnt1 - oneCnt2;
    while (k) {
      ++i;

      // unset
      if (x >> i & 1) {
        x &= ~(1 << i);
        --k;
      }
    }
  } else { // set bit
    k = oneCnt2 - oneCnt1;
    while (k) {
      ++i;

      if (x >> i & 1) continue;

      // set
      x |= 1 << i;
      --k;
    }
  }

  return x;
}
// #v1

int main(int argc, char *argv[])
{
  int n, m;
  scanf("%d%d", &n, &m);
  printf("%d\n", minimizeXor(n, m));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
