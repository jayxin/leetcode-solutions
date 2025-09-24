#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 40. 组合总和 II - 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates  中所有可以使数字和为 target 的组合。
// candidates 中的每个数字在每个组合中只能使用 一次 。
// 注意：解集不能包含重复的组合。 
//  
// 示例 1:
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 输出:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// 示例 2:
// 输入: candidates = [2,5,2,1,2], target = 5,
// 输出:
// [
// [1,2,2],
// [5]
// ]
//  
// 提示:
//  * 1 &lt;= candidates.length &lt;= 100
//  * 1 &lt;= candidates[i] &lt;= 50
//  * 1 &lt;= target &lt;= 30

//// #v1
//// 超时
//// 组合, 去重
//int **ret, retLen, *cols, t[60];
//
//void _combinationSum(int* a, int len, int target, int tLen) {
  //if (!len && target) return ;
//
  //if (target == 0) {
    //bool f;
    //int i, j;
//
    //for (i = 0; i < retLen; i++) {
      //if (cols[i] != tLen) continue;
//
      //f = true;
      //for (j = 0; j < tLen; j++) {
        //if (t[j] != ret[i][j]) {
          //f = false;
          //break;
        //}
      //}
      //if (f) return ;
    //}
//
    //int *arr = (int *)malloc(sizeof(int) * tLen);
//
    //for (i = 0; i < tLen; i++) arr[i] = t[i];
//
    //ret[retLen] = arr;
    //cols[retLen++] = tLen;
//
    //return ;
  //}
//
  //if (target < a[0]) return ;
//
  //t[tLen] = a[0];
  //_combinationSum(a + 1, len - 1, target - a[0], tLen + 1);
//
  //_combinationSum(a + 1, len - 1, target, tLen);
//}
//
//int cmp(const void *a, const void *b) {
  //return *(int *)a - *(int *)b;
//}
//
//int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
  //ret = (int **)malloc(sizeof(int *) * 180);
  //retLen = 0;
//
  //cols = (int *)malloc(sizeof(int) * 180);
  //*returnColumnSizes = cols;
//
  //qsort(candidates, candidatesSize, sizeof(int), cmp);
//
  //_combinationSum(candidates, candidatesSize, target, 0);
//
  //*returnSize = retLen;
//
  //return ret;
//}
//// #v1

// #v2
// 组合, 去重, 将数值相同的数字分为一组, 分别统计不同的数字
int **ret, retLen, *cols, t[100], *cnts;
char *visited;

void _combinationSum(int* a, int len, int target, int tLen) {
  if (!len && target) return ;

  if (target == 0) {
    int i, j, *arr = (int *)malloc(sizeof(int) * tLen);

    for (i = 0; i < tLen; i++) arr[i] = t[i];

    ret[retLen] = arr;
    cols[retLen++] = tLen;

    return ;
  }

  if (target < a[0]) return ;

  if (visited[a[0]]) {
    _combinationSum(a + 1, len - 1, target, tLen);
    return ;
  }

  visited[a[0]] = 1;
  int i, j;
  for (i = cnts[a[0]]; i >= 0; i--) {
    for (j = 0; j < i; j++) t[tLen + j] = a[0];
    _combinationSum(a + 1, len - 1, target - a[0] * i, tLen + i);
  }
  visited[a[0]] = 0;
}

int cmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
  int c[51] = {0};
  char v[51] = {0};

  ret = (int **)malloc(sizeof(int *) * 160);
  retLen = 0;
  cols = (int *)malloc(sizeof(int) * 160);
  *returnColumnSizes = cols;

  cnts = c;
  visited = v;

  qsort(candidates, candidatesSize, sizeof(int), cmp);

  for (int i = 0; i < candidatesSize; i++) cnts[candidates[i]]++;

  _combinationSum(candidates, candidatesSize, target, 0);

  *returnSize = retLen;

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
  ret = combinationSum2(a, n, target, &s, &cols);
  print_2d_arr(ret, s, cols);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
