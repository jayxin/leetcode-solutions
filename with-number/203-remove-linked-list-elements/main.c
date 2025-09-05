#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 203. 移除 链表元素 - 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg]
// 输入：head = [1,2,6,3,4,5,6], val = 6
// 输出：[1,2,3,4,5]
// 示例 2：
// 输入：head = [], val = 1
// 输出：[]
// 示例 3：
// 输入：head = [7,7,7,7], val = 7
// 输出：[]
// 提示：
//  * 列表中的节点数目在范围 [0, 104] 内
//  * 1 &lt;= Node.val &lt;= 50
//  * 0 &lt;= val &lt;= 50

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
  if (!head) return head;

  struct ListNode *prev = NULL,
                  *cur = head,
                  *tmp;
  while (cur) {
    tmp = NULL;
    if (cur->val == val) { // target val to be deleted
      if (prev) { // change connection
        prev->next = cur->next;
      }
      if (cur == head) { // change head
        head = cur->next;
      }
      tmp = cur;
    }

    if (!tmp) { // update prev
      prev = cur;
    }

    cur = cur->next;

    if (tmp) { // free node
      free(tmp);
    }
  }
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

// free 1d array
void free_1d_arr(int *arr) {
  if (!arr) {
    return;
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  int n, val;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  scanf("%d", &val);
  struct ListNode *h = buildList(arr, n);
  free_1d_arr(arr);
  struct ListNode *ret = removeElements(h, val);
  printList(ret);
  destroyList(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
