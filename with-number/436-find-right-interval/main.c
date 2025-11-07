#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 436. 寻找右 区间 - 给你一个区间数组 intervals ，其中 intervals[i] = [starti, endi] ，且每个 starti 都 不同 。
// 区间 i 的 右侧区间 是满足 startj >= endi，且 startj 最小 的区间 j。注意 i 可能等于 j 。
// 返回一个由每个区间 i 对应的 右侧区间 下标组成的数组。如果某个区间 i 不存在对应的 右侧区间 ，则下标 i 处的值设为 -1 。
//  
// 示例 1：
// 输入：intervals = [[1,2]]
// 输出：[-1]
// 解释：集合中只有一个区间，所以输出-1。
// 示例 2：
// 输入：intervals = [[3,4],[2,3],[1,2]]
// 输出：[-1,0,1]
// 解释：对于 [3,4] ，没有满足条件的“右侧”区间。
// 对于 [2,3] ，区间[3,4]具有最小的“右”起点;
// 对于 [1,2] ，区间[2,3]具有最小的“右”起点。
// 示例 3：
// 输入：intervals = [[1,4],[2,3],[3,4]]
// 输出：[-1,2,-1]
// 解释：对于区间 [1,4] 和 [3,4] ，没有满足条件的“右侧”区间。
// 对于 [2,3] ，区间 [3,4] 有最小的“右”起点。
//  
// 提示：
//  * 1 <= intervals.length <= 2 * 104
//  * intervals[i].length == 2
//  * -106 <= starti <= endi <= 106
//  * 每个间隔的起点都 不相同

// #v1
struct Pair { int s, i; };

int cmp(const void *a, const void *b) {
  return ((struct Pair *)a)->s - ((struct Pair *)b)->s;
}

int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize) {
  *returnSize = intervalsSize;
  int *ret = calloc(*returnSize, sizeof(int));
  struct Pair p[intervalsSize];

  // init
  for (int i = 0; i < intervalsSize; i++) {
    p[i].s = intervals[i][0];
    p[i].i = i;
  }

  // sort
  qsort(p, intervalsSize, sizeof(struct Pair), cmp);

  for (int i = 0; i < intervalsSize; i++) {
    int target = intervals[i][1];
    int l = 0, r = intervalsSize-1, m;

    // binary search
    while (l < r) {
      m = (l + r) >> 1;

      if (p[m].s >= target) r = m;
      else l = m + 1;
    }

    ret[i] = p[l].s >= target ? p[l].i : -1;
  }

  return ret;
}
// #v1

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

int main(int argc, char *argv[])
{
  int m, n = 2, **a, *ret, s;
  scanf("%d", &m);
  a = read_2d_arr(m, n);
  ret = findRightInterval(a, m, &n, &s);
  print_1d_arr(ret, s);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
