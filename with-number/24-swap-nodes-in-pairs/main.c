#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 24. 两两交换链表中的节点 - 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的 头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg]
// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]
// 示例 2：
// 输入：head = []
// 输出：[]
// 示例 3：
// 输入：head = [1]
// 输出：[1]
//  
// 提示：
//  * 链表中节点的数目在范围 [0, 100] 内
//  * 0 &lt;= Node.val &lt;= 100

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

// #v1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
  // 0 或 1 个节点
  if (!head || !(head->next)) return head;

  // 这里开始至少 2 个节点
  int cnt = 1; // 节点索引值, 从 1 开始
  struct ListNode *ret = NULL, // 返回值
                  *p = head, // 当前节点
                  *prev = NULL, // 前一个节点
                  *next, // 下一个节点
                  *tmp;

  while (p) {
    if (cnt & 1) { // 奇数索引
      next = p->next; // 获取下一个节点, 可能为 NULL

      // * 表示当前节点
      // 交换前: p(*) -> next -> tmp
      // 交换后: next(*) -> p -> tmp
      if (next) { // 存在下一个节点则进行交换
        tmp = next->next; // 获取下下个节点, 可能为 NULL

        p->next = tmp;
        next->next = p;

        p = next; // 更新当前节点
      }

      if (!ret) { // 第一个元素
        ret = p;
      } else { // 不是第一个元素, 设置 prev 的指向
        // * 表示当前节点
        // 情况 1: prev -> p(*) -> next -> tmp ==> prev -> next(*) -> p -> tmp
        // 情况 2: prev -> p(*) -> NULL ==> prev -> p(*) -> NULL
        prev->next = p;
      }
    }

    prev = p; // 更新 prev
    p = p->next; // 更新当前节点
    cnt++; // 更新索引
  }
  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  struct ListNode *h = buildList(arr, n);
  free_1d_arr(arr);
  struct ListNode *ret = swapPairs(h);
  printList(ret);
  destroyList(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
