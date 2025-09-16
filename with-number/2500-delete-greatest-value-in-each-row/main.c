#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2500. 删除每行中的最大值 - 给你一个 m x n 大小的矩阵 grid ，由若干正整数组成。
// 执行下述操作，直到 grid 变为空矩阵：
//  * 从每一行删除值最大的元素。如果存在多个这样的值，删除其中任何一个。
//  * 将删除元素中的最大值与答案相加。
// 注意 每执行一次操作，矩阵中列的数据就会减 1 。
// 返回执行上述操作后的答案。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2022/10/19/q1ex1.jpg]
// 输入：grid = [[1,2,4],[3,3,1]]
// 输出：8
// 解释：上图展示在每一步中需要移除的值。
// - 在第一步操作中，从第一行删除 4 ，从第二行删除 3（注意，有两个单元格中的值为 3 ，我们可以删除任一）。在答案上加 4 。
// - 在第二步操作中，从第一行删除 2 ，从第二行删除 3 。在答案上加 3 。
// - 在第三步操作中，从第一行删除 1 ，从第二行删除 1 。在答案上加 1 。
// 最终，答案 = 4 + 3 + 1 = 8 。
// 示例 2：
// [https://assets.leetcode.com/uploads/2022/10/19/q1ex2.jpg]
// 输入：grid = [[10]]
// 输出：10
// 解释：上图展示在每一步中需要移除的值。
// - 在第一步操作中，从第一行删除 10 。在答案上加 10 。
// 最终，答案 = 10 。
//  
// 提示：
//  * m == grid.length
//  * n == grid[i].length
//  * 1 &lt;= m, n &lt;= 50
//  * 1 &lt;= grid[i][j] &lt;= 100

// #v1
// 大根堆, 用 m 个大根堆记录 m 行中每一行的值, 不断从堆中弹出值进行比较
// 累加最大值
int tmp;
void HeapSwap(int *h, int i, int j) {
  tmp = h[i];
  h[i] = h[j];
  h[j] = tmp;
}

void HeapUp(int *h, int p) { // 向上调整
  while (p > 1) {
    if (h[p] > h[p>>1]) { // 子节点 > 父节点, 不满足大根堆性质
      HeapSwap(h, p, p>>1);
      p >>= 1;
    } else {
      return ;
    }
  }
}

void HeapDown(int *h, int size, int p) { // 向下调整
  int s = p << 1; // p 的左子节点

  while (s <= size) {
    if (s < size && h[s] < h[s+1]) s++; //左右子节点取较大
    if (h[s] > h[p]) { // 子节点 > 父节点
      HeapSwap(h, s, p);
      p = s;
      s = p<<1;
    } else {
      return ;
    }
  }
}

void HeapInsert(int *h, int *size, int v) {
  h[++(*size)] = v;
  HeapUp(h, *size);
}

void HeapExtract(int *h, int *size) {
  h[1] = h[(*size)--];
  HeapDown(h, *size, 1);
}

int deleteGreatestValue(int** grid, int gridSize, int* gridColSize) {
  // allocate
  int **heaps, *sizes, ret = 0, i, j, maxVal, cols = *gridColSize, t;
  heaps = (int **)malloc(sizeof(int *) * gridSize);
  sizes = (int *)malloc(sizeof(int) * gridSize);
  for (i = 0; i < gridSize; i++) {
    heaps[i] = (int *)malloc(sizeof(int) * (*gridColSize + 1));
    sizes[i] = 0;
  }

  // compute
  for (i = 0; i < gridSize; i++) {
    for (j = 0; j < cols; j++) {
      HeapInsert(heaps[i], sizes + i, grid[i][j]);
    }
  }

  while (cols) {
    maxVal = -1;
    for (i = 0; i < gridSize; i++) {
      t = heaps[i][1];
      HeapExtract(heaps[i], sizes + i);
      if (t > maxVal) maxVal = t;
    }
    --cols;
    ret += maxVal;
  }

  // free
  free(sizes);
  for (i = 0; i < gridSize; i++) free(heaps[i]);
  free(heaps);

  return ret;
}
// #v1

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
  int n, m, **a;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  printf("%d\n", deleteGreatestValue(a, m, &n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
