#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2683. 相邻值的按位异或 - 下标从 0 开始、长度为 n 的数组 derived 是由同样长度为 n 的原 始 二进制数组 original 通过计算相邻值的 按位异或（⊕）派生而来。
// 特别地，对于范围 [0, n - 1] 内的每个下标 i ：
//  * 如果 i = n - 1 ，那么 derived[i] = original[i] ⊕ original[0]
//  * 否则 derived[i] = original[i] ⊕ original[i + 1]
// 给你一个数组 derived ，请判断是否存在一个能够派生得到 derived 的 有效原始二进制数组 original 。
// 如果存在满足要求的原始二进制数组，返回 true ；否则，返回 false 。
//  * 二进制数组是仅由 0 和 1 组成的数组。
//  
// 示例 1：
// 输入：derived = [1,1,0]
// 输出：true
// 解释：能够派生得到 [1,1,0] 的有效原始二进制数组是 [0,1,0] ：
// derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1
// derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1
// derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0
// 示例 2：
// 输入：derived = [1,1]
// 输出：true
// 解释：能够派生得到 [1,1] 的有效原始二进制数组是 [0,1] ：
// derived[0] = original[0] ⊕ original[1] = 1
// derived[1] = original[1] ⊕ original[0] = 1
// 示例 3：
// 输入：derived = [1,0]
// 输出：false
// 解释：不存在能够派生得到 [1,0] 的有效原始二进制数组。
//  
// 提示：
//  * n == derived.length
//  * 1 &lt;= n &lt;= 10^5
//  * derived 中的值不是 0 就是 1 。
// Understand that from the original element, we are using each element twice to
// construct the derived array.
// The xor-sum of the derived array should be 0 since there is always a
// duplicate occurrence of each element.

// #v1
bool doesValidArrayExist(int* derived, int derivedSize) {
  int t = derived[0], i;

  for (i = 1; i < derivedSize; i++) t ^= derived[i];

  return t == 0;
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

  if (doesValidArrayExist(a, n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
