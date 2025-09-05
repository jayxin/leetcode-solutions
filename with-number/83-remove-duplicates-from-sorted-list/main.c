#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 83. 删除排序链表中的重复元素
// - 给定一个已排序的链表的头 head ， 删除所有重复的元素，
// 使每个元素只出现一次 。返回 已排序的链表 。
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/01/04/list1.jpg]
// 输入：head = [1,1,2]
// 输出：[1,2]
// 示例 2：
// [https://assets.leetcode.com/uploads/2021/01/04/list2.jpg]
// 输入：head = [1,1,2,3,3]
// 输出：[1,2,3]
//  
// 提示：
//  * 链表中节点数目在范围 [0, 300] 内
//  * -100 &lt;= Node.val &lt;= 100
//  * 题目数据保证链表已经按升序 排列

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
struct ListNode* deleteDuplicates(struct ListNode* head) {
  if (!head) return NULL;
  struct ListNode *prev = NULL, *cur = NULL, *t;
  cur = head;
  while (cur) {
    if (prev && prev->val == cur->val) {
      prev->next = cur->next;
      t = cur;
      cur = cur->next;
      free(t);
    } else {
      prev = cur;
      cur = cur->next;
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
  int n;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  struct ListNode *h = buildList(arr, n);
  free_1d_arr(arr);
  struct ListNode *ret = deleteDuplicates(h);
  printList(ret);
  destroyList(h);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
