#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 216. 组合 总和 III - 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
//  * 只使用数字1到9
//  * 每个数字 最多使用一次 
// 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序 返回。
//  
// 示例 1:
// 输入: k = 3, n = 7
// 输出: [[1,2,4]]
// 解释:
// 1 + 2 + 4 = 7
// 没有其他符合的组合了。
// 示例 2:
// 输入: k = 3, n = 9
// 输出: [[1,2,6], [1,3,5], [2,3,4]]
// 解释:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// 没有其他符合的组合了。
// 示例 3:
// 输入: k = 4, n = 1
// 输出: []
// 解释: 不存在有效的组合。
// 在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 &gt; 1，没有有效的组合。
//  
// 提示:
//  * 2 &lt;= k &lt;= 9
//  * 1 &lt;= n &lt;= 60

// #v1
// 组合, 去重, 将数值相同的数字分为一组, 分别统计不同的数字
int **ret, retLen, *cols, t[10];

void _combinationSum(int* a, int len, int target, int tLen, int k) {
  if (!len && target) return ;

  if (target == 0) {
    if (k) return ;

    int i, j, *arr = (int *)malloc(sizeof(int) * tLen);

    for (i = 0; i < tLen; i++) arr[i] = t[i];

    ret[retLen] = arr;
    cols[retLen++] = tLen;

    return ;
  }

  if (target < a[0]) return ;

  t[tLen] = a[0];
  _combinationSum(a + 1, len - 1, target - a[0], tLen + 1, k - 1);

  _combinationSum(a + 1, len - 1, target, tLen, k);
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
  int a[10];
  for (int i = 1; i <= 9; i++) a[i] = i;

  ret = (int **)malloc(sizeof(int *) * 50);
  retLen = 0;
  cols = (int *)malloc(sizeof(int) * 50);
  *returnColumnSizes = cols;

  _combinationSum(a + 1, 9, n, 0, k);

  *returnSize = retLen;

  return ret;
}
// #v1

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
  int n, k, **ret, s, *cols;
  scanf("%d%d", &k, &n);
  ret = combinationSum3(k, n, &s, &cols);
  print_2d_arr(ret, s, cols);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
