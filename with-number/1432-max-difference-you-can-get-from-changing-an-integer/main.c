#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1432. 改变一个整数能得到的最大差值 - 给你一个整数 num 。你可以对它进行以下步骤共计 两次：
//  * 选择一个数字 x (0 <= x <= 9).
//  * 选择另一个数字 y (0 <= y <= 9) 。数字 y 可以等于 x 。
//  * 将 num 中所有出现 x 的数位都用 y 替换。
// 令两次对 num 的操作得到的结果分别为 a 和 b 。
// 请你返回 a 和 b 的 最大差值 。
// 注意，a 和 b 必须不能 含有前导 0，并且 不为 0。
//  
// 示例 1：
// 输入：num = 555
// 输出：888
// 解释：第一次选择 x = 5 且 y = 9 ，并把得到的新数字保存在 a 中。
// 第二次选择 x = 5 且 y = 1 ，并把得到的新数字保存在 b 中。
// 现在，我们有 a = 999 和 b = 111 ，最大差值为 888
// 示例 2：
// 输入：num = 9
// 输出：8
// 解释：第一次选择 x = 9 且 y = 9 ，并把得到的新数字保存在 a 中。
// 第二次选择 x = 9 且 y = 1 ，并把得到的新数字保存在 b 中。
// 现在，我们有 a = 9 和 b = 1 ，最大差值为 8
// 示例 3：
// 输入：num = 123456
// 输出：820000
// 示例 4：
// 输入：num = 10000
// 输出：80000
// 示例 5：
// 输入：num = 9288
// 输出：8700
//  
// 提示：
//  * 1 <= num <= 10^8

// #v1
int getNum(int *a, int n) {
  int ret = 0;
  for (int i = n - 1; i >= 0; i--) {
    ret = ret * 10 + a[i];
  }
  return ret;
}

void getDigits(int x, int *a, int *n) {
  *n = 0;
  while (x) {
    a[(*n)++] = x % 10;
    x /= 10;
  }
}

int maxDiff(int num) {
  int numDigit[12], numLen = 0, aDigit[12], aLen, bDigit[12], bLen, a, b, i;
  bool isChanged;
  int x, y;

  getDigits(num, numDigit, &numLen);
  aLen = numLen;
  bLen = numLen;

  isChanged = false;
  for (i = numLen - 1; i >= 0; i--) {
    if (isChanged) { // 已经找到需要改变的数字
      if (numDigit[i] == x) { // 当前位置是需要改变的
        aDigit[i] = y;
      } else {
        aDigit[i] = numDigit[i];
      }
    } else { // 还未找到需要改变的数字
      if (numDigit[i] != 9) { // 可以改变
        x = numDigit[i];
        y = 9; // 替换成 9
        isChanged = true;
      }
      aDigit[i] = 9;
    }
  }

  isChanged = false;
  for (i = numLen - 1; i >= 0; i--) {
    if (isChanged) { // 已经找到需要改变的数字
      if (numDigit[i] == x) { // 当前位置是需要改变的
        bDigit[i] = y;
      } else {
        bDigit[i] = numDigit[i];
      }
    } else { // 还未找到需要改变的数字
      if (numDigit[numLen - 1] != 1) { // 最高位不是 1, 用 1 替换所有该数
        x = numDigit[numLen - 1];
        y = 1; // 替换成 1
        bDigit[i] = y;
        isChanged = true;
      } else { // 最高位是 1, 在后面找一个可以替换成 0 的数字
        if (numDigit[i] != 1 && numDigit[i] != 0) { // 找到了可以替换成 0 的数字
          x = numDigit[i];
          y = 0; // 替换成 0
          bDigit[i] = y;
          isChanged = true;
        } else { // 还未找到则原样复制, 1 和 0 不能被替换
          bDigit[i] = numDigit[i];
        }
      }
    }
  }

  a = getNum(aDigit, aLen);
  b = getNum(bDigit, bLen);

  //printf("a: %d, b: %d\n", a, b);

  return a - b;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", maxDiff(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
