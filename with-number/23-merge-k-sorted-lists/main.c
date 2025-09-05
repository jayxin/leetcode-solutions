#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 23. 合并 K 个升序链表 - 给你一个链表数组，每个链表都已经按升序排列。
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。
//  
// 示例 1：
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
// 输出：[1,1,2,3,4,4,5,6]
// 解释：链表数组如下：
// [
//   1-&gt;4-&gt;5,
//   1-&gt;3-&gt;4,
//   2-&gt;6
// ]
// 将它们合并到一个有序链表中得到。
// 1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6
// 示例 2：
// 输入：lists = []
// 输出：[]
// 示例 3：
// 输入：lists = [[]]
// 输出：[]
//  
// 提示：
//  * k == lists.length
//  * 0 &lt;= k &lt;= 10^4
//  * 0 &lt;= lists[i].length &lt;= 500
//  * -10^4 &lt;= lists[i][j] &lt;= 10^4
//  * lists[i] 按 升序 排列
//  * lists[i].length 的总和不超过 10^4

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
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
  if (!lists || !listsSize) return NULL;

  struct ListNode *ret = NULL, *cur = NULL, *p, *min;
  int i, empty_cnt = 0, min_idx;
  char *tab = (char *)malloc(sizeof(char) * listsSize);
  memset(tab, 0, sizeof(char) * listsSize);

  while (empty_cnt < listsSize) {
    min = NULL;
    min_idx = -1;

    for (i = 0; i < listsSize; i++) {
      p = lists[i];

      if (!p) {
        if (!tab[i]) {
          empty_cnt++;
          tab[i] = 1;
        }
        continue;
      }

      if (min) {
        if (p->val < min->val) {
          min = p;
          min_idx = i;
        }
      } else {
        min = p;
        min_idx = i;
      }
    }

    if (min_idx >= 0) {
      lists[min_idx] = min->next;
    }

    if (!ret) {
      ret = min;
      cur = min;
    } else {
      cur->next = min;
      cur = cur->next;
    }
  }

  free(tab);

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
  int n;
  scanf("%d", &n);
  struct ListNode **a = (struct ListNode **)malloc(sizeof(struct ListNode *) * n);
  for (int i = 0; i < n; i++) {
    int len, *arr;
    scanf("%d", &len);
    arr = read_1d_arr(len);
    struct ListNode *p = buildList(arr, len);
    a[i] = p;
    free(arr);
  }
  struct ListNode *ret = mergeKLists(a, n);
  printList(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
