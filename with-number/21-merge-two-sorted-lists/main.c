#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 21. 合 并两个有序链表 - 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg]
// 输入：l1 = [1,2,4], l2 = [1,3,4]
// 输出：[1,1,2,3,4,4]
// 示例 2：
// 输入：l1 = [], l2 = []
// 输出：[]
// 示例 3：
// 输入：l1 = [], l2 = [0]
// 输出：[0]
//  
// 提示：
//  * 两个链表的节点数目范围是 [0, 50]
//  * -100 &lt;= Node.val &lt;= 100
//  * l1 和 l2 均按 非递减顺序 排列

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
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
  if (list1 == NULL) {
    return list2;
  }
  if (list2 == NULL) {
    return list1;
  }

  struct ListNode *p1, *p2, *ret, *cur, *tmp;

  p1 = list1;
  p2 = list2;
  ret = cur = NULL;

  while (p1 && p2) {
    if (p1->val < p2->val) {
      if (!ret) {
        ret = p1;
        cur = ret;
      } else {
        tmp = p1;
        p1 = p1->next;
        cur->next = tmp;
        cur = tmp;
      }
    } else {
      if (!ret) {
        ret = p2;
        cur = ret;
      } else {
        tmp = p2;
        p2 = p2->next;
        cur->next = tmp;
        cur = tmp;
      }
    }
  }

  if (p1) {
    cur->next = p1;
  }
  if (p2) {
    cur->next = p2;
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
  int n1, n2, *a1, *a2;
  scanf("%d", &n1);
  a1 = read_1d_arr(n1);
  scanf("%d", &n2);
  a2 = read_1d_arr(n2);
  struct ListNode *l1 = buildList(a1, n1);
  struct ListNode *l2 = buildList(a2, n2);
  struct ListNode *ret = mergeTwoLists(l1, l2);
  printList(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
