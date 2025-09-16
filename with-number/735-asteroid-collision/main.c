#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 735. 小行星 碰撞 - 给定一个整数数组 asteroids，表示在同一行的小行星。数组中小行星的索引表示它们在空间中的相对位置。
// 对于数组中的每一个元素，其绝对值表示小行星的大小，正负表示小行星的移动方向（正表 示向右移动，负表示向左移动）。每一颗小行星以相同的速度移动。
// 找出碰撞后剩下的所有小行星。碰撞规则：两个小行星相互碰撞，较小的小行星会爆炸。如 果两颗小行星大小相同，则两颗小行星都会爆炸。两颗移动方向相同的小行星，永远不会发 生碰撞。
//  
// 示例 1：
// 输入：asteroids = [5,10,-5]
// 输出：[5,10]
// 解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。
// 示例 2：
// 输入：asteroids = [8,-8]
// 输出：[]
// 解释：8 和 -8 碰撞后，两者都发生爆炸。
// 示例 3：
// 输入：asteroids = [10,2,-5]
// 输出：[10]
// 解释：2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。
//  
// 提示：
//  * 2 &lt;= asteroids.length &lt;= 104
//  * -1000 &lt;= asteroids[i] &lt;= 1000
//  * asteroids[i] != 0

// #v1
#define abs(x) ((x) >= (0) ? (x) : (-x))

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
  int *ret = (int *)malloc(sizeof(int) * asteroidsSize), retLen = 0,
      top = -1, stack[asteroidsSize], t1, t2;
  bool isEqual;

  for (int i = 0; i < asteroidsSize; i++) {
    if (asteroids[i] < 0) {
      isEqual = false;
      t1 = abs(asteroids[i]);

      while (top >= 0) {
        t2 = abs(stack[top]);

        if (t1 > t2) {
          --top;
        } else {
          if (t1 == t2) {
            isEqual = true;
            --top;
          }
          break;
        }
      }

      if (top < 0 && !isEqual) ret[retLen++] = asteroids[i];
    } else {
      stack[++top] = asteroids[i];
    }
  }

  for (int i = 0; i <= top; i++) {
    ret[retLen++] = stack[i];
  }

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
  int n, *a, *ret, s = 0;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = asteroidCollision(a, n, &s);
  print_1d_arr(ret, s);
  free(ret);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
