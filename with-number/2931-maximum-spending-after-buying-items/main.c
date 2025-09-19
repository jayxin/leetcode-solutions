#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2931. 购买物品的最大开销 - 给你一个下标从 0 开始大小为 m * n 的整数矩阵 values ，表 示 m 个不同商店里 m * n 件不同的物品。每个商店有 n 件物品，第 i 个商店的第 j 件物品的价值为 values[i][j] 。除此以外，第 i 个商店的物品已经按照价值非递增排好序了，也就是说对于所有 0 &lt;= j &lt; n - 1 都有 values[i][j] &gt;= values[i][j + 1] 。
// 每一天，你可以在一个商店里购买一件物品。具体来说，在第 d 天，你可以：
//  * 选择商店 i 。
//  * 购买数组中最右边的物品 j ，开销为 values[i][j] * d 。换句话说，选择该商店中还 没购买过的物品中最大的下标 j ，并且花费 values[i][j] * d 去购买。
// 注意，所有物品都视为不同的物品。比方说如果你已经从商店 1 购买了物品 0 ，你还可以 在别的商店里购买其他商店的物品 0 。
// 请你返回购买所有 m * n 件物品需要的 最大开销 。
//  
// 示例 1：
// 输入：values = [[8,5,2],[6,4,1],[9,7,3]]
// 输出：285
// 解释：第一天，从商店 1 购买物品 2 ，开销为 values[1][2] * 1 = 1 。
// 第二天，从商店 0 购买物品 2 ，开销为 values[0][2] * 2 = 4 。
// 第三天，从商店 2 购买物品 2 ，开销为 values[2][2] * 3 = 9 。
// 第四天，从商店 1 购买物品 1 ，开销为 values[1][1] * 4 = 16 。
// 第五天，从商店 0 购买物品 1 ，开销为 values[0][1] * 5 = 25 。
// 第六天，从商店 1 购买物品 0 ，开销为 values[1][0] * 6 = 36 。
// 第七天，从商店 2 购买物品 1 ，开销为 values[2][1] * 7 = 49 。
// 第八天，从商店 0 购买物品 0 ，开销为 values[0][0] * 8 = 64 。
// 第九天，从商店 2 购买物品 0 ，开销为 values[2][0] * 9 = 81 。
// 所以总开销为 285 。
// 285 是购买所有 m * n 件物品的最大总开销。
// 示例 2：
// 输入：values = [[10,8,6,4,2],[9,7,5,3,2]]
// 输出：386
// 解释：第一天，从商店 0 购买物品 4 ，开销为 values[0][4] * 1 = 2 。
// 第二天，从商店 1 购买物品 4 ，开销为 values[1][4] * 2 = 4 。
// 第三天，从商店 1 购买物品 3 ，开销为 values[1][3] * 3 = 9 。
// 第四天，从商店 0 购买物品 3 ，开销为 values[0][3] * 4 = 16 。
// 第五天，从商店 1 购买物品 2 ，开销为 values[1][2] * 5 = 25 。
// 第六天，从商店 0 购买物品 2 ，开销为 values[0][2] * 6 = 36 。
// 第七天，从商店 1 购买物品 1 ，开销为 values[1][1] * 7 = 49 。
// 第八天，从商店 0 购买物品 1 ，开销为 values[0][1] * 8 = 64 。
// 第九天，从商店 1 购买物品 0 ，开销为 values[1][0] * 9 = 81 。
// 第十天，从商店 0 购买物品 0 ，开销为 values[0][0] * 10 = 100 。
// 所以总开销为 386 。
// 386 是购买所有 m * n 件物品的最大总开销。
//  
// 提示：
//  * 1 &lt;= m == values.length &lt;= 10
//  * 1 &lt;= n == values[i].length &lt;= 104
//  * 1 &lt;= values[i][j] &lt;= 106
//  * values[i] 按照非递增顺序排序。

//// #v1
//// 小根堆
//
//// heap
//int *h, size, tmp;
//
//void HeapSwap(int i, int j) {
  //tmp = h[i];
  //h[i] = h[j];
  //h[j] = tmp;
//}
//
//void HeapUp(int p) {
  //while (p > 1) {
    //if (h[p] < h[p>>1]) {
      //HeapSwap(p, p>>1);
      //p >>= 1;
    //} else {
      //return;
    //}
  //}
//}
//
//void HeapDown(int p) {
  //int s = p << 1;
//
  //while (s <= size) {
    //if (s < size && h[s] > h[s+1]) s++;
    //if (h[s] < h[p]) {
      //HeapSwap(s, p);
      //p = s;
      //s <<= 1;
    //} else {
      //return;
    //}
  //}
//}
//
//void HeapInsert(int v) {
  //h[++size] = v;
  //HeapUp(size);
//}
//
//void HeapExtract() {
  //h[1] = h[size--];
  //HeapDown(1);
//}
//
//long long maxSpending(int** values, int valuesSize, int* valuesColSize) {
  //long long ret = 0LL;
  //int m = valuesSize, n = *valuesColSize, mn = m * n, i, j;
//
  //// heap init
  //h = (int *)malloc(sizeof(int) * (mn + 1));
  //size = 0;
//
  //for (i = 0; i < m; i++)
    //for (j = n-1; j >= 0; j--) HeapInsert(values[i][j]);
//
  //for (i = 1; i <= mn; i++) {
    //ret += (long long)h[1] * i;
    //HeapExtract();
  //}
//
  //return ret;
//}
//// #v1

//// #v2
//// 小根堆
//
//// heap
//int *h, size, tmp;
//
//void HeapSwap(int i, int j) {
  //tmp = h[i];
  //h[i] = h[j];
  //h[j] = tmp;
//}
//
//void HeapUp(int p) {
  //while (p > 1) {
    //if (h[p] < h[p>>1]) {
      //HeapSwap(p, p>>1);
      //p >>= 1;
    //} else {
      //return;
    //}
  //}
//}
//
//void HeapDown(int p) {
  //int s = p << 1;
//
  //while (s <= size) {
    //if (s < size && h[s] > h[s+1]) s++;
    //if (h[s] < h[p]) {
      //HeapSwap(s, p);
      //p = s;
      //s <<= 1;
    //} else {
      //return;
    //}
  //}
//}
//
//void HeapInsert(int v) {
  //h[++size] = v;
  //HeapUp(size);
//}
//
//void HeapExtract() {
  //h[1] = h[size--];
  //HeapDown(1);
//}
//
//long long maxSpending(int** values, int valuesSize, int* valuesColSize) {
  //long long ret = 0LL;
  //int m = valuesSize, n = *valuesColSize, mn = m * n, i, j, day = 1;
//
  //// heap init
  //h = (int *)malloc(sizeof(int) * (mn + 1));
  //size = 0;
//
  //for (i = 0; i < m; i++) {
    //for (j = n-1; j >= 0; j--) {
      //HeapInsert(values[i][j]);
    //}
  //}
//
  //while (size) {
    //ret += (long long)h[1] * day;
    //++day;
    //HeapExtract();
  //}
//
  //free(h);
  //h = NULL;
//
  //return ret;
//}
//// #v2

// #v3
// 排序
int iCmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

long long maxSpending(int** values, int valuesSize, int* valuesColSize) {
  long long ret = 0LL;
  int m = valuesSize, n = *valuesColSize, mn = m * n,
      i, j, hLen = 0, h[mn];

  for (i = 0; i < m; i++) {
    for (j = n-1; j >= 0; j--) {
      h[hLen++] = values[i][j];
    }
  }

  qsort(h, hLen, sizeof(int), iCmp);

  for (i = 1; i <= mn; i++) {
    ret += (long long)i * h[i-1];
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

int main(int argc, char *argv[])
{
  int r, c, **a;
  scanf("%d%d", &r, &c);
  a = read_2d_arr(r, c);
  printf("%lld\n", maxSpending(a, r, &c));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
