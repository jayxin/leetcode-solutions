#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 390. 消除游戏 - 列表 arr 由在范围 [1, n] 中的所有整数组成，并按严格递增排序。请你对 arr 应用下 述算法：
//  * 从左到右，删除第一个数字，然后每隔一个数字删除一个，直到到达列表末尾。
//  * 重复上面的步骤，但这次是从右到左。也就是，删除最右侧的数字，然后剩下的数字每隔一个删除一个。
//  * 不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
// 给你整数 n ，返回 arr 最后剩下的数字。
//  
// 示例 1：
// 输入：n = 9
// 输出：6
// 解释：
// arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
// arr = [2, 4, 6, 8]
// arr = [2, 6]
// arr = [6]
// 示例 2：
// 输入：n = 1
// 输出：1
//  
// 提示：
//  * 1 &lt;= n &lt;= 109

// #v1
// 左右指针模拟
#define LEFT -1
#define RIGHT 1

int lastRemaining(int n) {
  if (n == 1) return 1;

  int l = 2, r = ((n & 1) ? n - 1 : n);
  // step 是剩余元素的间距
  int step = 2, direction = RIGHT, cnt; // 假设做了第一次删除, 删除了奇数

  while (l < r) {
    //printf("l: %d, r: %d step: %d\n", l, r, step);

    cnt = (r - l) / step + 1; // 元素的个数

    if (l + step > r || r - step < l) break;

    if (cnt & 1) { // 剩余奇数个元素
      // 左右指针同时变化
      l += step;
      r -= step;

      // 方向变化
      if (direction == LEFT) { // 从左往右删除
        direction = RIGHT;
      } else { // 从右往左删除
        direction = LEFT;
      }
    } else { // 剩余偶数个元素
      if (direction == RIGHT) {
        // 改变右指针
        r -= step;

        // 方向变化
        direction = LEFT;
      } else {
        // 改变左指针
        l += step;

        // 方向变化
        direction = RIGHT;
      }
    }

    step *= 2;
  }

  return l;
}
// #v1

//// #v2
//// 朴素解法
//#define LEFT -1
//#define RIGHT 1
//void print_arr(int *arr, int n) {
  //for (int i = 0; i < n; i++) {
    //if (arr[i]) {
      //printf("%d ", arr[i]);
    //}
  //}
  //printf("\n");
//}
//int lastRemaining(int n) {
  //int *arr = (int *)malloc(sizeof(int) * n);
  //int remaining = n;
  //int direction = LEFT, i;
  //for (i = 0; i < n; i++) {
    //arr[i] = i + 1;
  //}
  //while (remaining != 1) {
    //print_arr(arr, n);
    //if (direction == LEFT) {
      //int del = 1;
      //for (i = 0; i < n; i++) {
        //if (arr[i]) {
          //if (del) {
            //arr[i] = 0;
            //remaining--;
          //}
          //del = !del;
        //}
      //}
      //direction = RIGHT;
    //} else {
      //int del = 1;
      //for (i = n - 1; i >= 0; i--) {
        //if (arr[i]) {
          //if (del) {
            //arr[i] = 0;
            //remaining--;
          //}
          //del = !del;
        //}
      //}
      //direction = LEFT;
    //}
  //}
  //return 1;
//}
//// #v2

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", lastRemaining(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
