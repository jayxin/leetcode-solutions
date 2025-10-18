#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 474. 一和零 - 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
// 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
// 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
//  
// 示例 1：
// 输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
// 输出：4
// 解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
// 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
// 示例 2：
// 输入：strs = ["10", "0", "1"], m = 1, n = 1
// 输出：2
// 解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
//  
// 提示：
//  * 1 <= strs.length <= 600
//  * 1 <= strs[i].length <= 100
//  * strs[i] 仅由 '0' 和 '1' 组成
//  * 1 <= m, n <= 100

// #v1
// 动态规划, 记忆化搜索
struct Pair {
  int c0, c1;
};

#define max(a, b) ((a) >= (b) ? (a) : (b))

int ***tab;

int _f(struct Pair *p, int len, int m, int n) {
  // 递归出口
  if (m <= 0 && n <= 0) return 0;
  if (len == 1) { // 只剩下一个元素
    // 当前元素可以加入集合
    if (m >= p[0].c0 && n >= p[0].c1) return 1;
    // 当前元素无法加入集合
    return 0;
  }

  int x = p[0].c0, y = p[0].c1, r1 = 0, r2 = 0;

  // 不加入集合
  if (tab[m][n][len-1] >= 0)
    r2 = tab[m][n][len-1];
  else
    r2 = _f(p+1, len-1, m, n);
  if (m < x || n < y) { // 当前元素无法加入集合
    tab[m][n][len] = r2;
    return tab[m][n][len];
  }

  // 加入集合
  if (tab[m-x][n-y][len-1] >= 0)
    r1 = tab[m-x][n-y][len-1] + 1;
  else
    r1 = _f(p+1, len-1, m-x, n-y) + 1;

  tab[m][n][len] = max(r1, r2);

  return tab[m][n][len];
}

int findMaxForm(char** strs, int strsSize, int m, int n) {
  struct Pair p[strsSize];
  int i, **t[m+1], j;
  size_t b0 = sizeof(int *) * (n+1),
         b1 = sizeof(int) * (strsSize+1);

  // allocate
  for (i = 0; i <= m; i++) {
    t[i] = (int **)malloc(b0);

    for (j = 0; j <= n; j++) {
      t[i][j] = (int *)malloc(b1);
      memset(t[i][j], 0xff, b1);
    }
  }
  tab = t;

  // count 1 and 0
  for (i = 0; i < strsSize; i++) {
    char *s = strs[i];
    p[i].c0 = p[i].c1 = 0;

    while (*s) {
      if (*s == '1') ++p[i].c1;
      else ++p[i].c0;

      ++s;
    }
  }

  return _f(p, strsSize, m, n);
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

int main(int argc, char *argv[])
{
  int m, n, strsSize;
  char **strs;
  scanf("%d%d\n", &m, &n);
  scanf("%d\n", &strsSize);
  strs = (char **)malloc(sizeof(char *) * strsSize);
  for (int i = 0 ; i < strsSize; i++) {
    strs[i] = (char *)malloc(sizeof(char) * 100);
    read_line(strs[i], 98, stdin);
  }
  printf("%d\n", findMaxForm(strs, strsSize, m, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
