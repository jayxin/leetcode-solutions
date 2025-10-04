#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1734. 解码异或后的排列 - 给你一个整数数组 perm ，它是前 n 个正整数的排列，且 n 是个 奇数 。
// 它被加密成另一个长度为 n - 1 的整数数组 encoded ，满足 encoded[i] = perm[i] XOR perm[i + 1] 。比方说，如果 perm = [1,3,2] ，那么 encoded = [2,1] 。
// 给你 encoded 数组，请你返回原始数组 perm 。题目保证答案存在且唯一。
//  
// 示例 1：
// 输入：encoded = [3,1]
// 输出：[1,2,3]
// 解释：如果 perm = [1,2,3] ，那么 encoded = [1 XOR 2,2 XOR 3] = [3,1]
// 示例 2：
// 输入：encoded = [6,5,4,6]
// 输出：[2,4,1,5,3]
//  
// 提示：
//  * 3 <= n < 10^5
//  * n 是奇数。
//  * encoded.length == n - 1

//// #v1
//// encoded[0]^encoded[1]^...^encoded[n-2] = perm[0] ^ perm[n-1]
//// encoded[i] = perm[i]^perm[i+1]
//// encoded[end] = perm[n-2]^perm[n-1]
//// encoded[0] = perm[0]^perm[1]
//
//// 0 1 *
//// 1 2
//// 2 3 *
//// 3 4
//// 4 5 *
//// 5 6
//
//// 0 1 2 3 4 5
//// 1 2 3 4 5 6
//
//int* decode(int* encoded, int encodedSize, int* returnSize) {
  //int n = encodedSize + 1;
  //int *ret = (int *)malloc(sizeof(int) * n), i, v = 1;
//
  //*returnSize = n;
//
  //// 1^2^3^...^n
  //for (i = 2; i <= n; i++) v ^= i;
//
  //ret[0] = ret[encodedSize] = v;
//
  //// compute ret[encodedSize]
  //for (i = 0; i < encodedSize; i += 2) ret[encodedSize] ^= encoded[i];
  //// compute ret[0]
  //for (i = 1; i < encodedSize; i += 2) ret[0] ^= encoded[i];
  //// compute ret[1..encodedSize-1]
  //for (i = 1; i < encodedSize; i++) ret[i] = encoded[i-1] ^ ret[i-1];
//
  //return ret;
//}
//// #v1

// #v2
int* decode(int* encoded, int encodedSize, int* returnSize) {
  int n = encodedSize + 1;
  int *ret = (int *)malloc(sizeof(int) * n), i, v = 1;

  *returnSize = n;

  // 1^2^3^...^n
  for (i = 2; i <= n; i++) v ^= i;

  // compute ret[0]
  ret[0] = v;
  for (i = 1; i < encodedSize; i += 2) ret[0] ^= encoded[i];
  // compute ret[1..encodedSize]
  for (i = 1; i < n; i++) ret[i] = encoded[i-1] ^ ret[i-1];

  return ret;
}
// #v2

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
  ret = decode(a, n, &s);
  print_1d_arr(ret, s);
  free(a);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
