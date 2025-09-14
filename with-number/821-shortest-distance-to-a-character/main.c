#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 821. 字 符的最短距离 - 给你一个字符串 s 和一个字符 c ，且 c 是 s 中出现过的字符。
// 返回一个整数数组 answer ，其中 answer.length == s.length 且 answer[i] 是 s 中从下标 i 到离它 最近 的字符 c 的 距离 。
// 两个下标 i 和 j 之间的 距离 为 abs(i - j) ，其中 abs 是绝对值函数。
//  
// 示例 1：
// 输入：s = "loveleetcode", c = "e"
// 输出：[3,2,1,0,1,0,0,1,2,2,1,0]
// 解释：字符 'e' 出现在下标 3、5、6 和 11 处（下标从 0 开始计数）。
// 距下标 0 最近的 'e' 出现在下标 3 ，所以距离为 abs(0 - 3) = 3 。
// 距下标 1 最近的 'e' 出现在下标 3 ，所以距离为 abs(1 - 3) = 2 。
// 对于下标 4 ，出现在下标 3 和下标 5 处的 'e' 都离它最近，但距离是一样的 abs(4 - 3) == abs(4 - 5) = 1 。
// 距下标 8 最近的 'e' 出现在下标 6 ，所以距离为 abs(8 - 6) = 2 。
// 示例 2：
// 输入：s = "aaab", c = "b"
// 输出：[3,2,1,0]
//  
// 提示：
//  * 1 &lt;= s.length &lt;= 104
//  * s[i] 和 c 均为小写英文字母
//  * 题目数据保证 c 在 s 中至少出现一次

// #v1
int myAbs(int a) {
  return a >= 0 ? a : -a;
}

int bbsearch(int *a, int n, int t) {
  if (n == 1) return abs(t-a[0]);

  int l = 0, r = n - 1, m, ret;
  while (l < r) {
    m = (l + r + 1) >> 1;
    if (a[m] < t) {
      l = m;
    } else if (a[m] > t) {
      r = m - 1;
    }
  }

  ret = abs(a[l] - t);
  if (l + 1 < n) {
    int tmp = abs(a[l+1] - t);
    if (tmp < ret) ret = tmp;
  }

  return ret;
}

int* shortestToChar(char* s, char c, int* returnSize) {
  char *p = s;
  int len = 0, retLen = 0, *ret, t[10001] = {0}, tLen = 0, i;

  while (*p) {
    if (*p == c) t[tLen++] = len;
    ++len;
    ++p;
  }

  // allocate
  *returnSize = len;
  ret = (int *)malloc(sizeof(int) * len);

  p = s;
  i = 0;
  while (*p) {
    if (*p == c) {
      ret[retLen++] = 0;
    } else {
      ret[retLen++] = bbsearch(t, tLen, i);
    }

    ++p;
    ++i;
  }

  return ret;
}
// #v1

// read one line from stream
char* read_line(char *buffer, size_t size, FILE *stream) {
  if (fgets(buffer, size, stream) == NULL) {
    return NULL;
  }

  size_t len = strlen(buffer);
  if (len > 0 && buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';
  }

  return buffer;
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
  char s[100], c;
  int *a, n;
  read_line(s, 99, stdin);
  c = getchar();
  a = shortestToChar(s, c, &n);
  print_1d_arr(a, n);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
