#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2749. 得到整数零需要执行的最少操作数 - 给你两个整数：num1 和 num2 。
// 在一步操作中，你需要从范围 [0, 60] 中选出一个整数 i ，并从 num1 减去 2^i + num2 。
// 请你计算，要想使 num1 等于 0 需要执行的最少操作数，并以整数形式返回。
// 如果无法使 num1 等于 0 ，返回 -1 。
//  
// 示例 1：
// 输入：num1 = 3, num2 = -2
// 输出：3
// 解释：可以执行下述步骤使 3 等于 0 ：
// - 选择 i = 2 ，并从 3 减去 2^2 + (-2) ，num1 = 3 - (4 + (-2)) = 1 。
// - 选择 i = 2 ，并从 1 减去 2^2 + (-2) ，num1 = 1 - (4 + (-2)) = -1 。
// - 选择 i = 0 ，并从 -1 减去 2^0 + (-2) ，num1 = (-1) - (1 + (-2)) = 0 。
// 可以证明 3 是需要执行的最少操作数。
// 示例 2：
// 输入：num1 = 5, num2 = 7
// 输出：-1
// 解释：可以证明，执行操作无法使 5 等于 0 。
//  
// 提示：
//  * 1 <= num1 <= 10^9
//  * -10^9 <= num2 <= 10^9

// #v1
// 考察正整数的二进制表示和分解
// k * num2 + 2^(i_1) + 2^(i_2) + ... + 2^(i_k) = num1
// 求最小的 k
// i_1, i_2, ..., i_k 可以重复, 范围 [0, 60]
// 2^(i_1) + 2^(i_2) + ... + 2^(i_k) = num1 - k * num2
// y = 2^(i_1) + 2^(i_2) + ... + 2^(i_k)
// x = num1 - k * num2
// y >= 0, y = 0 表示不进行任何操作, k = 0, 此时 num1 只能为 0
// x <= 0 一定不存在, k = -1
// x > 0 才可能存在, x 的 bit 为 1 的个数 <= k 且 x 存在可以分解的 bit

int count_bit_one(long long n) {
  int ret = 0;
  while (n) {
    if (n & 1) {
      ret++;
    }
    n >>= 1;
  }
  return ret;
}

int makeTheIntegerZero(int num1, int num2) {
  if (num1 - num2 <= 0) return -1;

  int k = -1, cur_k = 1, x_bits;
  long long x; // avoid overflow when multiply

  while (1) {
    x = (long long)num1 - (long long)num2 * cur_k;

    if (x <= 0) break;

    x_bits = count_bit_one(x);

    if (x_bits > cur_k || (x == 1 && cur_k >= 2)) { // x == 1 不可再分解
      cur_k++;
      continue;
    } else {
      k = cur_k;
      break;
    }

    if (k < 0) {
      k = cur_k;
      break;
    }

    cur_k++;
  }

  return k;
}
// #v1

int main(int argc, char *argv[])
{
  int n1, n2;
  scanf("%d%d", &n1, &n2);
  printf("%d\n", makeTheIntegerZero(n1, n2));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
