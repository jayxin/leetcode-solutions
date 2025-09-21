#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 876. 链 表的中间结点 - 给你单链表的头结点 head ，请你找出并返回链表的中间结点。
// 如果有两个中间结点，则返回第二个中间结点。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/07/23/lc-midlist1.jpg]
// 输入：head = [1,2,3,4,5]
// 输出：[3,4,5]
// 解释：链表只有一个中间结点，值为 3 。
// 示例 2：
// [https://assets.leetcode.com/uploads/2021/07/23/lc-midlist2.jpg]
// 输入：head = [1,2,3,4,5,6]
// 输出：[4,5,6]
// 解释：该链表有两个中间结点，值分别为 3 和 4 ，返回第二个结点。
//  
// 提示：
//  * 链表的结点数范围是 [1, 100]
//  * 1 &lt;= Node.val &lt;= 100

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
int listLength(struct ListNode *p) {
  int cnt = 0;
  while (p) {
    ++cnt;
    p = p->next;
  }
  return cnt;
}

struct ListNode* middleNode(struct ListNode* head) {
  if (!head || !head->next) return head;

  int l = listLength(head), m = (l >> 1) + 1;
  struct ListNode *p = head;

  while (--m) p = p->next;

  return p;
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  struct ListNode *h = buildList(a, n), *ret;
  ret = middleNode(h);
  printList(ret);
  free(a);
  destroyList(h);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
