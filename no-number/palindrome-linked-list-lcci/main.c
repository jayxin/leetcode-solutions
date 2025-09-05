#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 面试 题 02.06. 回文链表 - 编写一个函数，检查输入的链表是否是回文的。
//  
// 示例 1：
// 输入： 1->2
// 输出： false
// 示例 2：
// 输入： 1->2->2->1
// 输出： true
//  
// 进阶：
// 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

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

int listLen(struct ListNode* p) {
  int len = 0;
  while (p) {
    len++;
    p = p->next;
  }
  return len;
}

bool isPalindrome(struct ListNode* head) {
  if (!head || !(head->next)) return true;
  int len, half;
  struct ListNode *p = head,
                  *left = head,
                  *left_end = NULL,
                  *right, *prev, *next;

  len = listLen(head);

  half = len / 2;
  int cnt = 0;
  p = head;
  while (p) {
    cnt++;
    if (cnt != half) {
      p = p->next;
    } else {
      break;
    }
  }
  left_end = p;

  if (len & 1) {
    right = left_end->next->next;
  } else {
    right = left_end->next;
  }
  left_end->next = NULL;

  // reverse right part
  p = right;
  prev = NULL;
  while (p) {
    next = p->next;
    p->next = prev;
    prev = p;
    p = next;
  }
  right = prev;

  cnt = 0;
  while (cnt < half) {
    if (left->val != right->val) {
      return false;
    }
    left = left->next;
    right = right->next;
    cnt++;
  }
  return true;
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
  int n;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  struct ListNode *ret = buildList(arr, n);
  if (isPalindrome(ret)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
