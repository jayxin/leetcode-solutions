#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1207. 独一无二的出现次数 - 给你一个整数数组 arr，如果每个数的出现次数都是独一无二的 ，就返回 true；否则返回 false。
//  
// 示例 1：
// 输入：arr = [1,2,2,1,1,3]
// 输出：true
// 解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
// 示例 2：
// 输入：arr = [1,2]
// 输出：false
// 示例 3：
// 输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
// 输出：true
//  
// 提示：
//  * 1 <= arr.length <= 1000
//  * -1000 <= arr[i] <= 1000

// #v1
bool uniqueOccurrences(int* arr, int arrSize) {
  int tab[2002], i, pos;
  char isOccurred[1001];
  memset(tab, 0, sizeof(int) * 2002);
  memset(isOccurred, 0, sizeof(char) * 1001);
  for (i = 0; i < arrSize; i++) {
    pos = arr[i] % 2001 + 1000;
    tab[pos]++;
  }
  for (i = 1; i < 2001; i++) {
    if (tab[i]) {
      if (isOccurred[tab[i]]) {
        return false;
      }
      isOccurred[tab[i]] = 1;
    }
  }
  return true;
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
  if (uniqueOccurrences(a, n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
