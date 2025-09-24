#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 39. 组合总和 - 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
// 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
//  
// 示例 1：
// 输入：candidates = [2,3,6,7], target = 7
// 输出：[[2,2,3],[7]]
// 解释：
// 2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
// 7 也是一个候选， 7 = 7 。
// 仅有这两种组合。
// 示例 2：
// 输入: candidates = [2,3,5], target = 8
// 输出: [[2,2,2,2],[2,3,3],[3,5]]
// 示例 3：
// 输入: candidates = [2], target = 1
// 输出: []
//  
// 提示：
//  * 1 &lt;= candidates.length &lt;= 30
//  * 2 &lt;= candidates[i] &lt;= 40
//  * candidates 的所有元素 互不相同
//  * 1 &lt;= target &lt;= 40

// #v1
int **ret, retLen, *cols, t[80];

void _combinationSum(int* a, int len, int target, int tLen) {
  if (!len && target) return ;

  if (target == 0) {
    int *arr = (int *)malloc(sizeof(int) * tLen);

    for (int i = 0; i < tLen; i++) arr[i] = t[i];

    ret[retLen] = arr;
    cols[retLen++] = tLen;

    return ;
  }

  int l = target / a[0], i, j;
  for (i = l; i >= 0; i--) {
    for (j = 0; j < i; j++) {
      t[tLen + j] = a[0];
    }

    _combinationSum(a + 1, len - 1, target - i * a[0], tLen + i);
  }
}

int cmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
  ret = (int **)malloc(sizeof(int *) * 180);
  retLen = 0;

  cols = (int *)malloc(sizeof(int) * 180);
  *returnColumnSizes = cols;

  qsort(candidates, candidatesSize, sizeof(int), cmp);

  _combinationSum(candidates, candidatesSize, target, 0);

  *returnSize = retLen;

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

void print_2d_arr(int **arr, int rows, int *cols) {
  if (!arr || rows <= 0) {
    putchar('\n');
    return ;
  }
  int i, j;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols[i]; j++) {
      if (j) {
        putchar(' ');
      }
      printf("%d", arr[i][j]);
    }
    putchar('\n');
  }
}

int main(int argc, char *argv[])
{
  int n, *a, target, **ret, s, *cols;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &target);
  ret = combinationSum(a, n, target, &s, &cols);
  print_2d_arr(ret, s, cols);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
