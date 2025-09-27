#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 542. 01 矩阵 - 给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
// 两个相邻元素间的距离为 1 。
//  
// 示例 1：
// [https://pic.leetcode-cn.com/1626667201-NCWmuP-image.png]
// 输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
// 输出：[[0,0,0],[0,1,0],[0,0,0]]
// 示例 2：
// [https://pic.leetcode-cn.com/1626667205-xFxIeK-image.png]
// 输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
// 输出：[[0,0,0],[0,1,0],[1,2,1]]
//  
// 提示：
//  * m == mat.length
//  * n == mat[i].length
//  * 1 &lt;= m, n &lt;= 104
//  * 1 &lt;= m * n &lt;= 104
//  * mat[i][j] is either 0 or 1.
//  * mat 中至少有一个 0 

// #v1
// 使用队列进行广度优先搜索
// 队列节点
struct QueueNode {
  // i, j 是坐标, dist 是距离
  int i, j, dist;
  struct QueueNode *next;
};

// 队列
struct Queue { struct QueueNode *head, *tail; };

struct QueueNode* NewQueueNode(int i, int j, int dist) {
  struct QueueNode *q = (struct QueueNode *)malloc(sizeof(struct QueueNode));
  q->i = i;
  q->j = j;
  q->dist = dist;
  q->next = NULL;
  return q;
}

struct Queue* NewQueue() {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->head = q->tail = NULL;
  return q;
}

// 新增节点入队
void enqueue(struct Queue *q, int i, int j, int dist) {
  struct QueueNode *n = NewQueueNode(i, j, dist);
  if (!q->head) {
    q->head = q->tail = n;
    return ;
  }
  q->tail->next = n;
  q->tail = n;
}

// 复用节点入队
void enqueueNode(struct Queue *q, struct QueueNode *n) {
  if (!q->head) {
    q->head = q->tail = n;
    return ;
  }
  q->tail->next = n;
  q->tail = n;
}

struct QueueNode* dequeue(struct Queue *q) {
  if (!q || !q->head) return NULL;

  struct QueueNode *ret = NULL;

  if (q->head == q->tail) {
    ret = q->head;
    q->head = q->tail = NULL;
    return ret;
  }

  ret = q->head;
  q->head = q->head->next;

  return ret;
}

#define isQueueEmpty(q) (q->head == NULL)

// 节点可访问的方向
struct Direction { int up, down; };

int m, n, **ret;
char **visisted;

#define isValidRange(i, j) (i >= 0 && i < m && j >= 0 && j < n)

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
  m = matSize, n = *matColSize;

  int i, j, x, y;
  // 队列
  struct Queue *q = NewQueue();
  // 队列中的节点
  struct QueueNode *p, *prev = NULL;
  // 方向, 上下左右
  struct Direction d[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

  // init
  // 返回的行数
  *returnSize = m;
  // 返回的每行的列数
  *returnColumnSizes = (int *)malloc(sizeof(int) * m);
  // 返回的二维数组
  ret = (int **)malloc(sizeof(int *) * m);
  // 标记每个位置是否被访问过
  visisted = (char **)malloc(sizeof(char *) * m);
  for (i = 0; i < m; i++) {
    // 为二维数组的每行分配内存
    ret[i] = (int *)malloc(sizeof(int) * n);
    // 每行的列数是 n
    (*returnColumnSizes)[i] = n;

    // 为标记数组的每行分配内存
    visisted[i] = (char *)malloc(sizeof(char) * n);
    // 将标记数组的每行置 0, 表示还未访问
    memset(visisted[i], 0, n * sizeof(char));
  }

  // enqueue
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (!mat[i][j]) { // 将数值为 0 的坐标入队
        enqueue(q, i, j, 0);
        ret[i][j] = 0;
        visisted[i][j] = 1; // 标记
      }
    }
  }

  while (!isQueueEmpty(q)) { // 队列非空
    // 出队
    p = dequeue(q);

    // 记录结果
    if (p->dist)
      ret[p->i][p->j] = p->dist;

    // 针对每个方向进行入队
    for (i = 0; i < 4; i++) {
      x = p->i + d[i].up;
      y = p->j + d[i].down;

      if (isValidRange(x, y) && !visisted[x][y]) { // 坐标合法且还未访问
        if (prev) { // 复用已经出队的节点
          prev->i = x;
          prev->j = y;
          prev->dist = p->dist + 1;

          // 入队
          enqueueNode(q, prev);

          // 标记节点已被复用
          prev = NULL;
        } else { // 分配新的节点入队
          enqueue(q, x, y, p->dist + 1);
        }

        // 标记
        visisted[x][y] = 1;
      }
    }

    // 记录出队节点, 用于入队复用
    prev = p;
  }

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
  int **a, **ret, m, n, r1, *c1;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  ret = updateMatrix(a, m, &n, &r1, &c1);
  print_2d_arr(ret, r1, c1);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
