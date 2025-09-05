#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
  int arr[11], len = 0;
  int ret = 0;
  // sign of number
  int sign = (x >> 31) & 1;
  int positive_max = 2147483647 / 10,
      negative_max = -2147483648 / 10;

  // get every digit in `x`
  while (x) {
    arr[len++] = x % 10;
    x /= 10;
  }

  // leetcode 不允许进行溢出操作, 一旦溢出会直接报错
  // 每次 * 10 之前需要检测是否会溢出
  for (int i = 0; i < len; ++i) {
    if (i == 9) { // 最多 10 位
      if ((sign && ret < negative_max) || (!sign && ret > positive_max)) {
        return 0;
      }
    }
    ret = ret * 10 + arr[i];
  }

  return ret;
}

int reverse1(int x) {
  int cnt = 0, remainder;
  int ret = 0;
  int sign = (x >= 0 ? 0 : 1);
  int positive_max = 2147483647 / 10,
      negative_max = -2147483648 / 10;

  // 这里处理 x 前 9 位数字
  while (x) {
    remainder = x % 10;
    x /= 10;
    ++cnt;

    if (cnt != 10) { // 不是最后一位
      ret = ret * 10 + remainder;
    }
  }

  // leetcode 不允许进行溢出操作, 一旦溢出会直接报错
  // 最后一位 * 10 之前需要检测是否会溢出
  // 处理第 10 位
  if (cnt == 10) {
    if ((sign && ret < negative_max) || (!sign && ret > positive_max)) { // 溢出
      return 0;
    } else { // 不会溢出, 可以 * 10
      ret = ret * 10 + remainder;
    }
  }

  return ret;
}

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", reverse1(n));
  return EXIT_SUCCESS;
}
