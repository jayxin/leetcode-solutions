#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3483. 不同三位偶数的数目 - 给你一个数字数组 digits，你需要从中选择三个数字组成一个三位偶数，你的任务是求出 不同 三位偶数的数量。
// 注意：每个数字在三位偶数中都只能使用 一次 ，并且 不能 有前导零。
//  
// 示例 1：
// 输入： digits = [1,2,3,4]
// 输出： 12
// 解释： 可以形成的 12 个不同的三位偶数是 124，132，134，142，214，234，312，314，324，342，412 和 432。注意，不能形成 222，因为数字 2 只有一个。
// 示例 2：
// 输入： digits = [0,2,2]
// 输出： 2
// 解释： 可以形成的三位偶数是 202 和 220。注意，数字 2 可以使用两次，因为数组中有两个 2 。
// 示例 3：
// 输入： digits = [6,6,6]
// 输出： 1
// 解释： 只能形成 666。
// 示例 4：
// 输入： digits = [1,3,5]
// 输出： 0
// 解释： 无法形成三位偶数。
//  
// 提示：
//  * 3 &lt;= digits.length &lt;= 10
//  * 0 &lt;= digits[i] &lt;= 9

// #v1
int totalNumbers(int* digits, int digitsSize) {
  char cnts[10] = {0};
  int ret = 0, tmp, i, j, t;
  bool b;

  for (i = 0; i < digitsSize; i++) cnts[digits[i]] += 1;

  for (i = 100; i < 1000; i += 2) {
    tmp = i;
    b = true;
    char nums[10] = {0};

    while (tmp) {
      t = tmp % 10;
      if (cnts[t] == 0) {
        b = false;
        break;
      }
      ++nums[t];
      tmp /= 10;
    }

    for (j = 0; j < 10; j++) {
      if (!b || cnts[j] < nums[j]) {
        b = false;
        break;
      }
    }

    if (b) ++ret;
  }

  return ret;
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
  printf("%d\n", totalNumbers(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
