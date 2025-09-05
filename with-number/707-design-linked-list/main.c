#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 707. 设计链表 - 你可以选择使用单链表或者双链表，设计并实现自己的链表。
// 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
// 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点 下标从 0 开始。
// 实现 MyLinkedList 类：
//  * MyLinkedList() 初始化 MyLinkedList 对象。
//  * int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
//  * void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插 入完成后，新节点会成为链表的第一个节点。
//  * void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元 素。
//  * void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
//  * void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
//  
// 示例：
// 输入
// [&quot;MyLinkedList&quot;, &quot;addAtHead&quot;, &quot;addAtTail&quot;, &quot;addAtIndex&quot;, &quot;get&quot;, &quot;deleteAtIndex&quot;, &quot;get&quot;]
// [[], [1], [3], [1, 2], [1], [1], [1]]
// 输出
// [null, null, null, null, 2, null, 3]
// 解释
// MyLinkedList myLinkedList = new MyLinkedList();
// myLinkedList.addAtHead(1);
// myLinkedList.addAtTail(3);
// myLinkedList.addAtIndex(1, 2);    // 链表变为 1-&gt;2-&gt;3
// myLinkedList.get(1);              // 返回 2
// myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1-&gt;3
// myLinkedList.get(1);              // 返回 3
//  
// 提示：
//  * 0 &lt;= index, val &lt;= 1000
//  * 请不要使用内置的 LinkedList 库。
//  * 调用 get、addAtHead、addAtTail、addAtIndex 和 deleteAtIndex 的次数不超过 2000 。

// #v1
typedef struct MyLinkedList_t {
  int val;
  struct MyLinkedList_t *next;
} MyLinkedList;

MyLinkedList* newNode(int val) {
  MyLinkedList *ret = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  ret->val = val;
  ret->next = NULL;
  return ret;
}

MyLinkedList* myLinkedListCreate() {
  MyLinkedList *ret = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  ret->val = 0;
  ret->next = NULL;
  return ret;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
  if (index >= obj->val || index < 0) {
    return -1;
  }
  int cnt = 0;
  MyLinkedList *h = obj;
  while (cnt < index + 1) {
    h = h->next;
    cnt++;
  }
  return h->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
  if (!obj) return ;
  MyLinkedList *q = newNode(val);
  if (obj->val > 0) {
    q->next = obj->next;
    obj->next = q;
  } else {
    obj->next = q;
  }
  obj->val += 1;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
  if (!obj) return ;

  MyLinkedList *h = obj,
               *q = newNode(val);
  while (h->next) {
    h = h-> next;
  }
  h->next = q;
  obj->val += 1;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
  if (!obj) return ;
  if (index < 0 || index > obj->val) {
    return ;
  }
  MyLinkedList *q = newNode(val),
               *h = obj,
               *prev;
  int cnt = 0;
  while (cnt < index + 1) {
    prev = h;
    h = h->next;
    cnt++;
  }
  if (index == obj->val) {
    prev->next = q;
  } else {
    q->next = h;
    prev->next = q;
  }
  obj->val += 1;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
  if (!obj) return ;
  if (index < 0 || index >= obj->val) {
    return ;
  }
  MyLinkedList *h = obj,
               *prev;
  int cnt = 0;
  while (cnt < index + 1) {
    prev = h;
    h = h->next;
    cnt++;
  }
  prev->next = h->next;
  free(h);
  obj->val -= 1;
}

void myLinkedListFree(MyLinkedList* obj) {
  if (!obj) return ;
  MyLinkedList *h;
  while (obj) {
    h = obj;
    obj = obj->next;
    free(h);
  }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", compute(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
