#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1720. 解码异或后的数组 - 未知 整数数组 arr 由 n 个非负整数组成。
// 经编码后变为长度为 n - 1 的另一个整数数组 encoded ，其中 encoded[i] = arr[i] XOR arr[i + 1] 。例如，arr = [1,0,2,1] 经编码后得到 encoded = [1,2,3] 。
// 给你编码后的数组 encoded 和原数组 arr 的第一个元素 first（arr[0]）。
// 请解码返回原数组 arr 。可以证明答案存在并且是唯一的。
//  
// 示例 1：
// 输入：encoded = [1,2,3], first = 1
// 输出：[1,0,2,1]
// 解释：若 arr = [1,0,2,1] ，那么 first = 1 且 encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
// 示例 2：
// 输入：encoded = [6,2,7,3], first = 4
// 输出：[4,2,0,7,4]
//  
// 提示：
//  * 2 &lt;= n &lt;= 104
//  * encoded.length == n - 1
//  * 0 &lt;= encoded[i] &lt;= 105
//  * 0 &lt;= first &lt;= 105

// #v1
int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
  *returnSize = encodedSize + 1;
  int n = *returnSize, *ret = (int *)malloc(sizeof(int) * n), i;

  ret[0] = first;
  for (i = 1; i < n; i++) ret[i] = ret[i-1] ^ encoded[i-1];

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
  int n, *a, f, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &f);
  ret = decode(a, n, f, &s);
  print_1d_arr(ret, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
