#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2433. 找出前缀异或的原始数组 - 给你一个长度为 n 的 整数 数组 pref 。找出并返回满足下述条件且长度为 n 的数组 arr ：
//  * pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
// 注意 ^ 表示 按位异或（bitwise-xor）运算。
// 可以证明答案是 唯一 的。
//  
// 示例 1：
// 输入：pref = [5,2,0,3,1]
// 输出：[5,7,2,3,2]
// 解释：从数组 [5,7,2,3,2] 可以得到如下结果：
// - pref[0] = 5
// - pref[1] = 5 ^ 7 = 2
// - pref[2] = 5 ^ 7 ^ 2 = 0
// - pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3
// - pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1
// 示例 2：
// 输入：pref = [13]
// 输出：[13]
// 解释：pref[0] = arr[0] = 13
//  
// 提示：
//  * 1 <= pref.length <= 10^5
//  * 0 <= pref[i] <= 10^6

// #v1
int* findArray(int* pref, int prefSize, int* returnSize) {
  *returnSize = prefSize;
  int *ret = (int *)malloc(sizeof(int) * prefSize), i;

  ret[0] = pref[0];
  for (i = 1; i < prefSize; i++) ret[i] = pref[i] ^ pref[i-1];

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

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int n, *a, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = findArray(a, n, &s);
  print_1d_arr(ret, s);
  free(a);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
