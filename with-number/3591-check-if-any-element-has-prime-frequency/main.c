#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 3591. 检查元素频次是否为质数 - 给你一个整数数组 nums。
// 如果数组中任一元素的 频次 是 质数，返回 true；否则，返回 false。
// 元素 x 的 频次 是它在数组中出现的次数。
// 质数是一个大于 1 的自然数，并且只有两个因数：1 和它本身。
//  
// 示例 1：
// 输入： nums = [1,2,3,4,5,4]
// 输出： true
// 解释：
// 数字 4 的频次是 2，而 2 是质数。
// 示例 2：
// 输入： nums = [1,2,3,4,5]
// 输出： false
// 解释：
// 所有元素的频次都是 1。
// 示例 3：
// 输入： nums = [2,2,2,4,4]
// 输出： true
// 解释：
// 数字 2 和 4 的频次都是质数。
//  
// 提示：
//  * 1 <= nums.length <= 100
//  * 0 <= nums[i] <= 100

// #v1
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n == 2) return true;

  if (!(n & 1)) return false;

  int b = sqrt(n);

  for (int i = 2; i <= b; i++) {
    if (n % i == 0) return false;
  }

  return true;
}

bool checkPrimeFrequency(int* nums, int numsSize) {
  int t[101] = {0}, i;

  for (i = 0; i < numsSize; i++) {
    ++t[nums[i]];
  }

  for (i = 0; i <= 100; i++) {
    if (t[i] && isPrime(t[i]))
      return true;
  }

  return false;
}
// #v1

// read 1d array
int* read_1d_arr(int n) {
  int *ret = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", ret + i);
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  if (checkPrimeFrequency(a, n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
