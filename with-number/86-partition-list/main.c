#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 86. 分隔链表 - 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
// 你应当 保留 两个分区中每个节点的初始相对位置。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/01/04/partition.jpg]
// 输入：head = [1,4,3,2,5,2], x = 3
// 输出：[1,2,2,4,3,5]
// 示例 2：
// 输入：head = [2,1], x = 2
// 输出：[1,2]
//  
// 提示：
//  * 链表中节点的数目在范围 [0, 200] 内
//  * -100 &lt;= Node.val &lt;= 100
//  * -200 &lt;= x &lt;= 200

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* newListNode(int);

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

void destroyList(struct ListNode *h) {
  if (!h) return;
  struct ListNode *t;
  while (h) {
    t = h;
    h = h->next;
    free(t);
  }
}

// #v1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* newListNode(int val) {
  struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
  ret->next = NULL;
  ret->val = val;
  return ret;
}

struct ListNode* partition(struct ListNode* head, int x) {
  if (!head) return NULL;
  struct ListNode *ret = NULL, *p = head, *q = NULL, *rp = NULL;
  while (p) {
    if (p->val < x) {
      q = newListNode(p->val);
      if (!ret) {
        ret = q;
        rp = q;
      } else {
        rp->next = q;
        rp = q;
      }
    }
    p = p->next;
  }
  p = head;

  while (p) {
    if (p->val >= x) {
      q = newListNode(p->val);
      if (!ret) {
        ret = q;
        rp = q;
      } else {
        rp->next = q;
        rp = q;
      }
    }
    p = p->next;
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

// free 1d array
void free_1d_arr(int *arr) {
  if (!arr) {
    return;
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  int n, x;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  scanf("%d", &x);
  struct ListNode *h = buildList(arr, n);
  free_1d_arr(arr);

  struct ListNode *ret = partition(h, x);
  printList(ret);
  destroyList(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
