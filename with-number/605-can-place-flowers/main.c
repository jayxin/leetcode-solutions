#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 605. 种花问题 - 假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相 邻的地块上，它们会争夺水源，两者都会死去。
// 给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1  表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false 。
//  
// 示例 1：
// 输入：flowerbed = [1,0,0,0,1], n = 1
// 输出：true
// 示例 2：
// 输入：flowerbed = [1,0,0,0,1], n = 2
// 输出：false
//  
// 提示：
//  * 1 &lt;= flowerbed.length &lt;= 2 * 104
//  * flowerbed[i] 为 0 或 1
//  * flowerbed 中不存在相邻的两朵花
//  * 0 &lt;= n &lt;= flowerbed.length

// #v1
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
  if (flowerbedSize == 1 && flowerbed[0] == 0) return true;
  int prev, next, i;
  for (i = 0; i < flowerbedSize; i++) {
    // 种植完毕
    if (n == 0) break;

    // 当前的地已被种植
    if (flowerbed[i] == 1) continue;

    if (i == 0) {
      if (1 < flowerbedSize && flowerbed[1] == 0) {
        flowerbed[i] = 1;
        n--;
        i++;
      }
    } else if (i == flowerbedSize - 1) {
      prev = i - 1;
      if (prev >= 0 && flowerbed[prev] == 0) {
        flowerbed[i] = 1;
        n--;
      }
    } else {
      prev = i - 1;
      next = i + 1;
      if (flowerbed[prev] == 0 && flowerbed[next] == 0) {
        flowerbed[i] = 1;
        n--;
        i++;
      }
    }
  }
  return n == 0;
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

int main(int argc, char *argv[])
{
  int n, nn, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &nn);
  if (canPlaceFlowers(a, n, nn)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
