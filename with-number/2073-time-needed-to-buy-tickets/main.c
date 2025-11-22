#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// 2073.  买票需要的时间 - 有 n 个人前来排队买票，其中第 0 人站在队伍 最前方 ，第 (n - 1)  人站在队伍 最后方 。
// 给你一个下标从 0 开始的整数数组 tickets ，数组长度为 n ，其中第 i 人想要购买的票 数为 tickets[i] 。
// 每个人买票都需要用掉 恰好 1 秒 。一个人 一次只能买一张票 ，如果需要购买更多票，他必须走到  队尾 重新排队（瞬间 发生，不计时间）。如果一个人没有剩下需要买的票，那 他将会 离开 队伍。
// 返回位于位置 k（下标从 0 开始）的人完成买票需要的时间（以秒为单位）。
//  
// 示例 1：
// 输入：tickets = [2,3,2], k = 2
// 输出：6
// 解释：
//  * 队伍一开始为 [2,3,2]，第 k 个人以下划线标识。
//  * 在最前面的人买完票后，队伍在第 1 秒变成 [3,2,1]。
//  * 继续这个过程，队伍在第 2 秒变为[2,1,2]。
//  * 继续这个过程，队伍在第 3 秒变为[1,2,1]。
//  * 继续这个过程，队伍在第 4 秒变为[2,1]。
//  * 继续这个过程，队伍在第 5 秒变为[1,1]。
//  * 继续这个过程，队伍在第 6 秒变为[1]。第 k 个人完成买票，所以返回 6。
// 示例 2：
// 输入：tickets = [5,1,1,1], k = 0
// 输出：8
// 解释：
//  * 队伍一开始为 [5,1,1,1]，第 k 个人以下划线标识。
//  * 在最前面的人买完票后，队伍在第 1 秒变成 [1,1,1,4]。
//  * 继续这个过程 3 秒，队伍在第 4 秒变为[4]。
//  * 继续这个过程 4 秒，队伍在第 8 秒变为[]。第 k 个人完成买票，所以返回 8。
//  
// 提示：
//  * n == tickets.length
//  * 1 <= n <= 100
//  * 1 <= tickets[i] <= 100
//  * 0 <= k < n

// #v1
typedef unsigned char u_char;

typedef struct queue {
  struct queue *prev, *next;
} queue;

queue* queue_init(queue *q) {
  q->prev = q->next = q;
  return q;
}

void enqueue(queue *q, queue *n) {
  n->prev = q->prev;
  n->next = q;
  q->prev->next = n;
  q->prev = n;
}

queue* dequeue(queue *q) {
  queue *ret = q->next;
  ret->next->prev = q;
  q->next = ret->next;
  return ret;
}

#define queue_data(q, type, link) \
  (type *) ((u_char *)q - offsetof(type, link))

#define queue_empty(q) ((q) == (q)->next)

typedef struct node {
  int v; // value
  int idx; // index
  queue q;
} node;

int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
  node n[ticketsSize];
  // qs is queue sentinel
  queue qs, *h = &qs;
  int ret = 0;

  h = queue_init(h);

  for (int i = 0; i < ticketsSize; i++) {
    n[i].v = tickets[i], n[i].idx = i;
    enqueue(h, &n[i].q);
  }

  while (!queue_empty(h)) {
    queue *p = dequeue(h);
    node *a = queue_data(p, node, q);

    --a->v;
    ++ret;

    if (a->v) enqueue(h, p);
    else {
      if (a->idx == k) break;
    }
  }

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

int main(int argc, char *argv[])
{
  int n, *a, k;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);
  printf("%d\n", timeRequiredToBuy(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
