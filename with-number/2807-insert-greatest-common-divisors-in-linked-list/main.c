#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2807. 在链表中插入最大公约数 - 给你一个链表的头 head ，每个结点包含一个整数值。
// 在相邻结点之间，请你插入一个新的结点，结点值为这两个相邻结点值的 最大公约数 。
// 请你返回插入之后的链表。
// 两个数的 最大公约数 是可以被两个数字整除的最大正整数。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2023/07/18/ex1_copy.png]
// 输入：head = [18,6,10,3]
// 输出：[18,6,6,2,10,1,3]
// 解释：第一幅图是一开始的链表，第二幅图是插入新结点后的图（蓝色结点为新插入结点） 。
// - 18 和 6 的最大公约数为 6 ，插入第一和第二个结点之间。
// - 6 和 10 的最大公约数为 2 ，插入第二和第三个结点之间。
// - 10 和 3 的最大公约数为 1 ，插入第三和第四个结点之间。
// 所有相邻结点之间都插入完毕，返回链表。
// 示例 2：
// [https://assets.leetcode.com/uploads/2023/07/18/ex2_copy1.png]
// 输入：head = [7]
// 输出：[7]
// 解释：第一幅图是一开始的链表，第二幅图是插入新结点后的图（蓝色结点为新插入结点） 。
// 没有相邻结点，所以返回初始链表。
//  
// 提示：
//  * 链表中结点数目在 [1, 5000] 之间。
//  * 1 <= Node.val <= 1000

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

//// #v1
//int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
//
//struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
  //struct ListNode *p, *prev;
//
  //p = head;
  //prev = NULL;
  //while (p) {
    //if (prev) {
      //struct ListNode *n = calloc(1, sizeof(struct ListNode));
      //n->val = gcd(prev->val, p->val);
      //n->next = p;
      //prev->next = n;
    //}
//
    //prev = p;
    //p = p->next;
  //}
//
  //return head;
//}
//// #v1

// #v2
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
  struct ListNode *prev = head, *p = prev->next, *n;

  while (p) {
    n = malloc(sizeof(struct ListNode));
    n->val = gcd(prev->val, p->val);
    n->next = p;
    prev->next = n;

    prev = p;
    p = p->next;
  }

  return head;
}
// #v2

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
  struct ListNode *l = buildList(a, n);
  l = insertGreatestCommonDivisors(l);
  printList(l);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
