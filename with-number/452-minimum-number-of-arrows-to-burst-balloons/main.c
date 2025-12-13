#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 452. 用最少数量的箭引爆气球 - 有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面 上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。
// 一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气 球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。
// 给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。
//  
// 示例 1：
// 输入：points = [[10,16],[2,8],[1,6],[7,12]]
// 输出：2
// 解释：气球可以用2支箭来爆破:
// -在x = 6处射出箭，击破气球[2,8]和[1,6]。
// -在x = 11处发射箭，击破气球[10,16]和[7,12]。
// 示例 2：
// 输入：points = [[1,2],[3,4],[5,6],[7,8]]
// 输出：4
// 解释：每个气球需要射出一支箭，总共需要4支箭。
// 示例 3：
// 输入：points = [[1,2],[2,3],[3,4],[4,5]]
// 输出：2
// 解释：气球可以用2支箭来爆破:
// - 在x = 2处发射箭，击破气球[1,2]和[2,3]。
// - 在x = 4处射出箭，击破气球[3,4]和[4,5]。
//  
// 提示:
//  * 1 <= points.length <= 105
//  * points[i].length == 2
//  * -231 <= xstart < xend <= 231 - 1

//// #v1
//// sort, greedy method, interval
//int cmp(const void *a, const void *b) {
  //const int *aa = *(const int **)a, *bb = *(const int **)b;
  //if (aa[0] != bb[0]) return aa[0] < bb[0] ? -1 : 1;
  //if (aa[1] == bb[1]) return 0;
  //return aa[1] < bb[1] ? -1 : 1;
//}
//
//int min(int a, int b) {
  //return a <= b ? a : b;
//}
//
//int max(int a, int b) {
  //return a >= b ? a : b;
//}
//
//int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
  //qsort(points, pointsSize, sizeof(int *), cmp);
//
  //int c = 1, l = points[0][0], r = points[0][1];
//
  //for (int i = 1; i < pointsSize; i++) {
    //if (points[i][0] > r) { // 区间没有交集
      //// 生成新的区间
      //++c;
      //l = points[i][0];
      //r = points[i][1];
    //} else { // 区间存在交集
      //// 合并区间
      //l = max(l, points[i][0]);
      //r = min(r, points[i][1]);
//
      //if (l > r) { // 区间合并后不满足 l <= r
        //// 生成新的区间
        //++c;
        //l = points[i][0];
        //r = points[i][1];
      //}
    //}
  //}
//
  //return c;
//}
//// #v1

// #v2
// sort, greedy method, interval
int cmp(const void *a, const void *b) {
  const int *aa = *(const int **)a, *bb = *(const int **)b;

  if (aa[0] ^ bb[0]) return aa[0] < bb[0] ? -1 : 1;
  if (aa[1] ^ bb[1]) return aa[1] < bb[1] ? -1 : 1;

  return 0;
}

int min(int a, int b) {
  return a <= b ? a : b;
}

int max(int a, int b) {
  return a >= b ? a : b;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
  qsort(points, pointsSize, sizeof(int *), cmp);

  int c = 1, l = points[0][0], r = points[0][1];

  for (int i = 1; i < pointsSize; i++) {
    // 合并区间
    //l = max(l, points[i][0]);
    //r = min(r, points[i][1]);
    l = l > points[i][0] ? l : points[i][0];
    r = r < points[i][1] ? r : points[i][1];

    if (l > r) { // 合并后的区间不满足 l <= r
      ++c;
      l = points[i][0];
      r = points[i][1];
    }
  }

  return c;
}
// #v2

int main(int argc, char *argv[])
{
  int n, **a, c = 2;
  scanf("%d", &n);
  a = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(sizeof(int) * 2);
    scanf("%d%d", &a[i][0], &a[i][1]);
  }
  printf("%d\n", findMinArrowShots(a, n, &c));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
