#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 142. 环形链表 II - 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环 ，则返回 null。
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
// 不允许修改 链表。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png]
// 输入：head = [3,2,0,-4], pos = 1
// 输出：返回索引为 1 的链表节点
// 解释：链表中有一个环，其尾部连接到第二个节点。
// 示例 2：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png]
// 输入：head = [1,2], pos = 0
// 输出：返回索引为 0 的链表节点
// 解释：链表中有一个环，其尾部连接到第一个节点。
// 示例 3：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png]
// 输入：head = [1], pos = -1
// 输出：返回 null
// 解释：链表中没有环。
//  
// 提示：
//  * 链表中节点的数目范围在范围 [0, 104] 内
//  * -105 <= Node.val <= 105
//  * pos 的值为 -1 或者链表中的一个有效索引
//  
// 进阶：你是否可以使用 O(1) 空间解决此题？

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

//// #v1
//// 哈希表
//struct HashNode {
  //int val;
  //struct ListNode *node;
  //struct HashNode *next;
//};
//
//struct HashTable {
  //int capacity;
  //struct HashNode **table;
//};
//
//struct HashNode* NewHashNode(int val, struct ListNode *n) {
  //struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  //ret->val = val;
  //ret->node = n;
  //ret->next = NULL;
  //return ret;
//}
//
//struct HashTable* NewHashTable(int capacity) {
  //struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  //ret->capacity = capacity;
  //int table_bytes = sizeof(struct HashNode *) * capacity;
  //ret->table = (struct HashNode **)malloc(table_bytes);
  //memset(ret->table, 0, table_bytes);
//
  //return ret;
//}
//
//int HashFunc(struct HashTable *t, int key) {
  //int ret = key % t->capacity;
  //if (ret < 0) {
    //ret += t->capacity;
  //}
  //return ret;
//}
//
//struct HashNode* HashTableFind(struct HashTable *t, int val, struct ListNode *n) {
  //if (!t) return NULL;
  //int h = HashFunc(t, val);
  //struct HashNode *p = (t->table)[h];
  //while (p) {
    //if (p->val == val && p->node == n) {
      //return p;
    //}
    //p = p->next;
  //}
  //return NULL;
//}
//
//void HashTableAdd(struct HashTable *t, int val, struct ListNode *node) {
  //int h = HashFunc(t, val);
  //struct HashNode *n, *p = (t->table)[h];
  //n = NewHashNode(val, node);
  //if (!p) {
    //(t->table)[h] = n;
  //} else {
    //n->next = p;
    //(t->table)[h] = n;
  //}
//}
//
//struct ListNode *detectCycle(struct ListNode *head) {
  //if (!head) return NULL;
  //struct HashTable *h = NewHashTable(131);
//
  //while (head) {
    //if (HashTableFind(h, head->val, head)) {
      //return head;
    //}
    //HashTableAdd(h, head->val, head);
    //head = head->next;
  //}
//
  //return NULL;
//}
//// #v1

// #v2
// 快慢指针
// 慢指针 slow 走 1 步, 快指针 fast 走 2 步
// a-b-c, 环长度 b+c, slow 和 fast 在 b 处相遇
// slow 走了a+b, fast 走了 a+b+n圈环
// a+b, a+b+n(b+c)
// fast 走的距离是 slow 的 2 倍
// a+b+n(b+c) = 2(a+b)
// a = c + (n-1)(b+c)
struct ListNode *detectCycle(struct ListNode *head) {
  struct ListNode *fast = head, *slow = head, *p = head;

  while (fast) {
    // slow 走 1 步
    slow = slow->next;

    if (!fast->next) return NULL;
    // fast 走 2 步
    fast = fast->next->next;

    // fast 和 slow 相遇
    if (fast == slow) {
      // p 和 slow 的相遇点就是入环点
      while (p != slow) {
        // p 和 slow 一起走
        p = p->next;
        slow = slow->next;
      }
      return p;
    }
  }

  return NULL;
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
  struct ListNode *l = buildList(a, n), *ret;
  free(a);
  ret = detectCycle(l);
  printList(l);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
