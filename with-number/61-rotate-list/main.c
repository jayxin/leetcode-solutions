#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 61. 旋转链表 - 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg]
// 输入：head = [1,2,3,4,5], k = 2
// 输出：[4,5,1,2,3]
// 示例 2：
// [https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg]
// 输入：head = [0,1,2], k = 4
// 输出：[2,0,1]
//  
// 提示：
//  * 链表中节点的数目在范围 [0, 500] 内
//  * -100 <= Node.val <= 100
//  * 0 <= k <= 2 * 10^9

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
struct ListNode* listLength(struct ListNode *h, int *len) {
  *len = 0;
  struct ListNode *prev = NULL;
  while (h) {
    *len += 1;
    prev = h;
    h = h->next;
  }
  return prev;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
  if (!head || !(head->next)) return head;

  int len, pos, cur_pos;
  struct ListNode *listEnd = listLength(head, &len), *p, *prev;
  pos = k % len;
  if (!pos) return head;

  cur_pos = 0;
  pos = len - pos;
  p = head;
  prev = NULL;
  while (cur_pos != pos) {
    cur_pos++;
    prev = p;
    p = p->next;
  }
  prev->next = NULL;
  listEnd->next = head;
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
  int n, *a, k;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);
  struct ListNode *h = buildList(a, n);
  struct ListNode *ret = rotateRight(h, k);
  printList(ret);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
