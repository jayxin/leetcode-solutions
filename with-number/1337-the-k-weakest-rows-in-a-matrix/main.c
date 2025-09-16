#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1337. 矩阵中战斗力最弱的 K 行 - 给你一个大小为 m * n 的矩阵 mat，矩阵由若干军人和平民组成，分别用 1 和 0 表示。
// 请你返回矩阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。
// 如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，那么我们认为第 i 行的战斗力比第 j 行弱。
// 军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。
//  
// 示例 1：
// 输入：mat =
// [[1,1,0,0,0],
//  [1,1,1,1,0],
//  [1,0,0,0,0],
//  [1,1,0,0,0],
//  [1,1,1,1,1]],
// k = 3
// 输出：[2,0,3]
// 解释：
// 每行中的军人数目：
// 行 0 -&gt; 2
// 行 1 -&gt; 4
// 行 2 -&gt; 1
// 行 3 -&gt; 2
// 行 4 -&gt; 5
// 从最弱到最强对这些行排序后得到 [2,0,3,1,4]
// 示例 2：
// 输入：mat =
// [[1,0,0,0],
//  [1,1,1,1],
//  [1,0,0,0],
//  [1,0,0,0]],
// k = 2
// 输出：[0,2]
// 解释：
// 每行中的军人数目：
// 行 0 -&gt; 1
// 行 1 -&gt; 4
// 行 2 -&gt; 1
// 行 3 -&gt; 1
// 从最弱到最强对这些行排序后得到 [0,2,3,1]
//  
// 提示：
//  * m == mat.length
//  * n == mat[i].length
//  * 2 &lt;= n, m &lt;= 100
//  * 1 &lt;= k &lt;= m
//  * matrix[i][j] 不是 0 就是 1

// #v1
struct Pair {
  int cnt; int idx;
};

int pairCmp(const void *a, const void *b) {
  struct Pair *p1 = (struct Pair *)a, *p2 = (struct Pair *)b;
  if (p1->cnt != p2->cnt) return p1->cnt-p2->cnt;
  return p1->idx-p2->idx;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
  struct Pair p[matSize];
  int i, j, *ret = (int *)malloc(sizeof(int) * k);
  *returnSize = k;
  for (i = 0; i < matSize; i++) {
    p[i].cnt = 0;
    for (j = 0; j < *matColSize; j++) {
      p[i].idx = i;
      if (mat[i][j] == 1) ++p[i].cnt;
    }
  }
  qsort(p, matSize, sizeof(struct Pair), pairCmp);
  for (i = 0; i < k; i++) {
    ret[i] = p[i].idx;
  }
  return ret;
}
// #v1

// read 2d array
int** read_2d_arr(int rows, int cols) {
  int i, j;
  int **ret = (int **)malloc(sizeof(int *) * rows);
  for (i = 0; i < rows; i++) {
    ret[i] = (int *)malloc(sizeof(int) * cols);
  }

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &ret[i][j]);
    }
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
  int **a, r, c, s, k, *ret;
  scanf("%d%d", &r, &c);
  a = read_2d_arr(r, c);
  scanf("%d", &k);
  ret = kWeakestRows(a, r, &c, k, &s);
  print_1d_arr(ret, s);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
