#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 56. 合并区间 - 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中 的所有区间 。
//  
// 示例 1：
// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2：
// 输入：intervals = [[1,4],[4,5]]
// 输出：[[1,5]]
// 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
// 示例 3：
// 输入：intervals = [[4,7],[1,4]]
// 输出：[[1,7]]
// 解释：区间 [1,4] 和 [4,7] 可被视为重叠区间。
//  
// 提示：
//  * 1 &lt;= intervals.length &lt;= 104
//  * intervals[i].length == 2
//  * 0 &lt;= starti &lt;= endi &lt;= 104

//// #v1
//// 先排序再合并相邻区间
//// 正确但超时
///**
 //* Return an array of arrays of size *returnSize.
 //* The sizes of the arrays are returned as *returnColumnSizes array.
 //* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 //*/
//#define max(a, b) (a > b ? a : b)
//#define min(a, b) (a > b ? b : a)
//
//int** addInterval(int **arr, int *rows, int **cols, int start, int end) {
  //int **ret = NULL, i, *old_cols = *cols;
  //if (!arr) {
    //*rows = 1;
  //} else {
    //*rows += 1;
  //}
//
  //// allocate space
  //*cols = (int *)malloc(sizeof(int) * (*rows));
  //ret = (int **)malloc(sizeof(int *) * (*rows));
  //for (i = 0; i < *rows; i++) {
    //ret[i] = (int *)malloc(sizeof(int) * 2);
    //(*cols)[i] = 2;
  //}
//
  //// copy
  //for (i = 0; i < *rows - 1; i++) {
    //ret[i][0] = arr[i][0];
    //ret[i][1] = arr[i][1];
  //}
  //ret[i][0] = start;
  //ret[i][1] = end;
//
  //// free
  //if (arr) {
    //for (i = 0; i < *rows - 1; i++) {
      //free(arr[i]);
    //}
    //free(arr);
  //}
//
  //if (old_cols) {
    //free(old_cols);
  //}
  //return ret;
//}
//
//int arrCmp(const void *a, const void *b) {
  //int *aa = *(int **)a, *bb = *(int **)b;
  //int a0 = aa[0], a1 = aa[1], b0 = bb[0], b1 = bb[1];
  //return ((a0 == b0) ? a1 - b1 : a0 - b0);
//}
//
//int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
  //if (!intervals || intervalsSize <= 0) return NULL;
//
  //// sort
  //qsort(intervals, intervalsSize, sizeof(int) * (*intervalsColSize), arrCmp);
//
  //int start = intervals[0][0], end = intervals[0][1], i;
  //*returnSize = 0;
  //*returnColumnSizes = NULL;
  //int **ret = NULL;
//
  //// merge
  //for (i = 1; i < intervalsSize; i++) {
    //int l = intervals[i][0], r = intervals[i][1];
    //if (l <= end) {
      //start = min(start, l);
      //end = max(end, r);
    //} else {
      //ret = addInterval(ret, returnSize, returnColumnSizes, start, end);
      //start = l;
      //end = r;
    //}
  //}
  //ret = addInterval(ret, returnSize, returnColumnSizes, start, end);
//
  //return ret;
//}
//// #v1

//// #v2
//// 利用归并排序的思想, 在排序的过程中合并区间
///**
 //* Return an array of arrays of size *returnSize.
 //* The sizes of the arrays are returned as *returnColumnSizes array.
 //* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 //*/
//#define max(a, b) (a > b ? a : b)
//#define min(a, b) (a > b ? b : a)
//
//int** alloc_2d_arr(int size) {
  //int **ret = (int **)malloc(sizeof(int *) * size);
  //for (int i = 0; i < size; i++) {
    //ret[i] = (int *)malloc(sizeof(int) * 2);
  //}
  //return ret;
//}
//
//int** _merge(int** left, int leftSize, int** right, int rightSize, int *retSize) {
  //int **ret = alloc_2d_arr(leftSize + rightSize);
  //// left pointer, right pointer, return pointer
  //int lp = 0, rp = 0, retp = 0;
  //int lstart, lend, rstart, rend, retstart, retend;
  //int start, end;
  //while (lp < leftSize && rp < rightSize) {
    //lstart = left[lp][0];
    //lend = left[lp][1];
    //rstart = right[rp][0];
    //rend = right[rp][1];
//
    //if (lstart < rstart) {
      //start = lstart;
      //end = lend;
      //lp++;
    //} else {
      //start = rstart;
      //end = rend;
      //rp++;
    //}
//
    //if (retp > 0) {
      //retstart = ret[retp - 1][0];
      //retend = ret[retp - 1][1];
//
      //if (start <= retend) {
        //ret[retp - 1][0] = min(retstart, start);
        //ret[retp - 1][1] = max(retend, end);
      //} else {
        //ret[retp][0] = start;
        //ret[retp][1] = end;
        //retp++;
      //}
    //} else {
      //ret[retp][0] = start;
      //ret[retp][1] = end;
      //retp++;
    //}
  //}
//
  //while (lp < leftSize) {
    //start = left[lp][0];
    //end = left[lp][1];
    //lp++;
//
    //if (retp > 0) {
      //retstart = ret[retp - 1][0];
      //retend = ret[retp - 1][1];
      //if (start <= retend) {
        //ret[retp - 1][0] = min(retstart, start);
        //ret[retp - 1][1] = max(retend, end);
      //} else {
        //ret[retp][0] = start;
        //ret[retp][1] = end;
        //retp++;
      //}
    //} else {
      //ret[retp][0] = start;
      //ret[retp][1] = end;
      //retp++;
    //}
  //}
//
  //while (rp < rightSize) {
    //start = right[rp][0];
    //end = right[rp][1];
    //rp++;
//
    //if (retp > 0) {
      //retstart = ret[retp - 1][0];
      //retend = ret[retp - 1][1];
//
      //if (start <= retend) {
        //ret[retp - 1][0] = min(retstart, start);
        //ret[retp - 1][1] = max(retend, end);
      //} else {
        //ret[retp][0] = start;
        //ret[retp][1] = end;
        //retp++;
      //}
    //} else {
      //ret[retp][0] = start;
      //ret[retp][1] = end;
      //retp++;
    //}
  //}
//
  //*retSize = retp;
//
  //return ret;
//}
//
//int** sortAndMerge(int **start, int **end, int* returnSize) {
  //int len = (end - start) >> 1;
  //if (len == 0) {
    //*returnSize = 1;
    //return start;
  //}
//
  //int leftSize, rightSize;
//
  //int **left = sortAndMerge(start, start + len, &leftSize);
  //int **right = sortAndMerge(start + len, end, &rightSize);
  //int **ret = _merge(left, leftSize, right, rightSize, returnSize);
//
  //return ret;
//}
//
//int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
  //if (!intervals || intervalsSize <= 0) return NULL;
//
  //int **ret = sortAndMerge(intervals, intervals + intervalsSize, returnSize);
  //*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
  //for (int i = 0; i < *returnSize; i++) {
    //(*returnColumnSizes)[i] = 2;
  //}
  //return ret;
//}
//// #v2

// #v3
// 利用归并排序的思想, 在排序的过程中合并区间
// 在 v2 基础上优化内存分配, 代码执行路径
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

int **global_arr = NULL;

void alloc_2d_arr(int size) {
  global_arr = (int **)malloc(sizeof(int *) * size);
  for (int i = 0; i < size; i++) {
    global_arr[i] = (int *)malloc(sizeof(int) * 2);
  }
}

int** _merge(int** left, int leftSize, int** right, int rightSize, int *retSize) {
  int **ret = global_arr;
  // left pointer, right pointer, return pointer
  int lp = 0, rp = 0, retp = 0;
  int lstart, lend, rstart, rend, retstart, retend;
  int start, end;
  while (lp < leftSize && rp < rightSize) {
    lstart = left[lp][0];
    lend = left[lp][1];
    rstart = right[rp][0];
    rend = right[rp][1];

    if (lstart < rstart) {
      start = lstart;
      end = lend;
      lp++;
    } else {
      start = rstart;
      end = rend;
      rp++;
    }

    if (retp > 0) {
      retstart = ret[retp - 1][0];
      retend = ret[retp - 1][1];

      if (start <= retend) {
        ret[retp - 1][0] = min(retstart, start);
        ret[retp - 1][1] = max(retend, end);
        continue;
      }
    }

    ret[retp][0] = start;
    ret[retp][1] = end;
    retp++;
  }

  while (lp < leftSize) {
    start = left[lp][0];
    end = left[lp][1];
    lp++;

    if (retp > 0) {
      retstart = ret[retp - 1][0];
      retend = ret[retp - 1][1];
      if (start <= retend) {
        ret[retp - 1][0] = min(retstart, start);
        ret[retp - 1][1] = max(retend, end);
        continue;
      }
    }
    ret[retp][0] = start;
    ret[retp][1] = end;
    retp++;
  }

  while (rp < rightSize) {
    start = right[rp][0];
    end = right[rp][1];
    rp++;

    if (retp > 0) {
      retstart = ret[retp - 1][0];
      retend = ret[retp - 1][1];

      if (start <= retend) {
        ret[retp - 1][0] = min(retstart, start);
        ret[retp - 1][1] = max(retend, end);
        continue;
      }
    }
    ret[retp][0] = start;
    ret[retp][1] = end;
    retp++;
  }

  *retSize = retp;

  for (int i = 0; i < retp; i++) {
    left[i][0] = ret[i][0];
    left[i][1] = ret[i][1];
  }

  return left;
}

int** sortAndMerge(int **start, int **end, int* returnSize) {
  int len = (end - start) >> 1;
  if (len == 0) {
    *returnSize = 1;
    return start;
  }

  int leftSize, rightSize;

  int **left = sortAndMerge(start, start + len, &leftSize);
  int **right = sortAndMerge(start + len, end, &rightSize);
  int **ret = _merge(left, leftSize, right, rightSize, returnSize);

  return ret;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
  if (!intervals || intervalsSize <= 0) return NULL;
  alloc_2d_arr(intervalsSize);

  int **ret = sortAndMerge(intervals, intervals + intervalsSize, returnSize);

  *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
  for (int i = 0; i < *returnSize; i++) {
    (*returnColumnSizes)[i] = 2;
  }
  return ret;
}
// #v3

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

void print_2d_arr(int **arr, int rows, int *cols) {
  if (!arr || rows <= 0) {
    putchar('\n');
    return ;
  }
  int i, j;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols[0]; j++) {
      if (j) {
        putchar(' ');
      }
      printf("%d", arr[i][j]);
    }
    putchar('\n');
  }
}

// free 2d array
void free_2d_arr(int **arr, int rows) {
  if (!arr) {
    return;
  }
  for (int i = 0; i < rows; i++) {
    free(arr[i]);
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  int r, c, retRows, *retCols;
  scanf("%d%d", &r, &c);
  int **arr = read_2d_arr(r, c);
  int **ret = merge(arr, r, &c, &retRows, &retCols);
  print_2d_arr(ret, retRows, retCols);
  free_2d_arr(arr, r);
  //free_2d_arr(ret, retRows);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
