#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 19. 删除链表的倒数第 N 个结点 - 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg]
// 输入：head = [1,2,3,4,5], n = 2
// 输出：[1,2,3,5]
// 示例 2：
// 输入：head = [1], n = 1
// 输出：[]
// 示例 3：
// 输入：head = [1,2], n = 1
// 输出：[1]
//  
// 提示：
//  * 链表中结点的数目为 sz
//  * 1 <= sz <= 30
//  * 0 <= Node.val <= 100
//  * 1 <= n <= sz
// 进阶：你能尝试使用一趟扫描实现吗？

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* newListNode(int val) {
  struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
  ret->next = NULL;
  ret->val = val;
  return ret;
}

struct ListNode* buildList(int *arr, int n) {
  struct ListNode *head = NULL, *p, *q;
  int i;
  for (i = 0; i < n; i++) {
    q = newListNode(arr[i]);
    if (!head) {
      head = q;
      p = head;
    } else {
      p->next = q;
      p = q;
    }
  }
  return head;
}

void destroyList(struct ListNode *h) {
  if (!h) return;
  struct ListNode *t;
  while (h) {
    t = h;
    h = h->next;
    free(t);
  }
}

void printList(struct ListNode *h) {
  if (!h) {
    printf("\n");
    return ;
  }
  struct ListNode *p = h;
  while (p) {
    if (p != h) {
      putchar(' ');
    }
    printf("%d", p->val);
    p = p->next;
  }
  printf("\n");
}

// #v1
// 双指针
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  int cnt = 0;
  struct ListNode *p, *q, *prev;

  p = q = head;

  // p 走 n 步, 走到第 n + 1 个节点
  while (cnt < n) {
    ++cnt;
    p = p->next;
  }

  // p 走 sz-n 步, q 走 sz-n 步
  // p 走到 NULL, q 走到第 sz-n+1 个节点即倒数第 n 个节点
  while (p) {
    prev = q;
    q = q->next;
    p = p->next;
  }

  if (q == head) return head->next;

  prev->next = q->next;

  return head;
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
  int n, *a, m;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &m);
  struct ListNode *h = buildList(a, n), *ret;
  free(a);
  ret = removeNthFromEnd(h, m);
  printList(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
