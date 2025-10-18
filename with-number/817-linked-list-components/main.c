#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 817. 链表组件 - 给定链表头结点 head，该链表上的每个结点都有一个 唯一的整型值 。同时给定列表 nums，该列表是上述链表中整型值的一个子集。
// 返回列表 nums 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值 必须在列表 nums 中）构成的集合。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/07/22/lc-linkedlistcom1.jpg]
// 输入: head = [0,1,2,3], nums = [0,1,3]
// 输出: 2
// 解释: 链表中,0 和 1 是相连接的，且 nums 中不包含 2，所以 [0, 1] 是 nums 的一个组 件，同理 [3] 也是一个组件，故返回 2。
// 示例 2：
//  [https://assets.leetcode.com/uploads/2021/07/22/lc-linkedlistcom2.jpg]
// 输入: head = [0,1,2,3,4], nums = [0,3,1,4]
// 输出: 2
// 解释: 链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个 组件，故返回 2。
//  
// 提示：
//  * 链表中节点数为n
//  * 1 <= n <= 104
//  * 0 <= Node.val < n
//  * Node.val 中所有值 不同
//  * 1 <= nums.length <= n
//  * 0 <= nums[i] < n
//  * nums 中所有值 不同

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
int numComponents(struct ListNode* head, int* nums, int numsSize) {
  struct ListNode *p = head;
  int len = 0, ret = 0;
  char *set, f;

  // 计算链表长度
  while (p) {
    ++len;
    p = p->next;
  }

  set = (char *)malloc(sizeof(char) * len);
  memset(set, 0, sizeof(char) * len);

  // 将 nums[i] 加入集合
  for (int i = 0; i < numsSize; i++) set[nums[i]] = 1;

  // 计数
  p = head;
  f = 0;
  while (p) {
    if (!set[p->val] && f) {
      ++ret;
      f = 0;
    } else if (set[p->val]) {
      f = 1;
    }

    p = p->next;
  }

  if (f) ++ret;

  free(set);

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

int main(int argc, char *argv[])
{
  int n, *a, *nums, numsSize;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &numsSize);
  nums = read_1d_arr(numsSize);
  struct ListNode *l = buildList(a, n);
  free(a);
  printf("%d\n", numComponents(l, nums, numsSize));
  free(nums);
  destroyList(l);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
