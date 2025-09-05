#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 60. 排列序列 - 给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。
// 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
//  1. "123"
//  2. "132"
//  3. "213"
//  4. "231"
//  5. "312"
//  6. "321"
// 给定 n 和 k，返回第 k 个排列。
//  
// 示例 1：
// 输入：n = 3, k = 3
// 输出："213"
// 示例 2：
// 输入：n = 4, k = 9
// 输出："2314"
// 示例 3：
// 输入：n = 3, k = 1
// 输出："123"
//  
// 提示：
//  * 1 <= n <= 9
//  * 1 <= k <= n!

// #v1
char *result;
int resultLen;

int fact(int n) {
  int ret = 1;
  while (n) {
    ret = ret * n;
    n--;
  }
  return ret;
}

void _getPermutation(int k, int *arr, int len) {
  //printf("k: %d\n", k);
  // 递归出口
  if (k <= 1) {
    for (int i = 0; i < len; i++) {
      result[resultLen++] = arr[i] + '0';
    }
    return ;
  }

  // n! 个排列分为 n 组, 每组 (n-1)! 个
  int groupNum = fact(len - 1); // 一组多少个
  int q = k / groupNum, r = k % groupNum;

  // 确定属于哪一组
  int group = q; // group 取值范围 1 - n
  if (r) { // 非整除
    group += 1;
  }

  // 数组索引
  int index = group - 1;
  // 添加到结果
  result[resultLen++] = arr[index] + '0';

  // 通过移动数组来删除用掉的数字
  for (int i = index; i < len - 1; i++) {
    arr[i] = arr[i + 1];
  }

  // 递归, 这里需要注意
  if (r) { // 非整除
    // | groupNum | groupNum | groupNum | 第r个(*) | groupNum
    // aaaa aaaa aa*a aaaa
    _getPermutation(r, arr, len - 1);
  } else { // 整除
    // | groupNum | groupNum | groupNum | groupNum(*) | groupNum
    // aaaa aaaa aaa* aaaa
    _getPermutation((k - (q - 1) * groupNum), arr, len - 1);
  }
}

char* getPermutation(int n, int k) {
  // 分配内存
  result = (char *)malloc(sizeof(char) * (n + 1));
  resultLen = 0;
  int *arr = (int *)malloc(sizeof(int) * n), len = n;

  // 初始化数组, 填充数字 1 - n
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }

  _getPermutation(k, arr, n);

  free(arr);

  // string end
  result[n] = '\0';
  return result;
}
// #v1

int main(int argc, char *argv[])
{
  int n, k;
  scanf("%d%d", &n, &k);
  printf("%s\n", getPermutation(n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
