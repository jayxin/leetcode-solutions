#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 705. 设计 哈希集合 - 不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
// 实现 MyHashSet 类：
//  * void add(key) 向哈希集合中插入值 key 。
//  * bool contains(key) 返回哈希集合中是否存在这个值 key 。
//  * void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
//  
// 示例：
// 输入：
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
// [[], [1], [2], [1], [3], [2], [2], [2], [2]]
// 输出：
// [null, null, null, true, false, null, true, null, false]
// 解释：
// MyHashSet myHashSet = new MyHashSet();
// myHashSet.add(1);      // set = [1]
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(1); // 返回 True
// myHashSet.contains(3); // 返回 False ，（未找到）
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(2); // 返回 True
// myHashSet.remove(2);   // set = [1]
// myHashSet.contains(2); // 返回 False ，（已移除）
//  
// 提示：
//  * 0 <= key <= 106
//  * 最多调用 104 次 add、remove 和 contains

// #v1
struct HashNode {
  int val;
  struct HashNode *next;
};

typedef struct {
  struct HashNode **a;
  int capacity;
} MyHashSet;

#define HashFunc(t, k) ((k) % (t->capacity))

struct HashNode* NewHashNode(int v) {
  struct HashNode *h = (struct HashNode *)malloc(sizeof(struct HashNode));
  h->val = v;
  h->next = NULL;
  return h;
}

MyHashSet* myHashSetCreate() {
  MyHashSet *h = (MyHashSet *)malloc(sizeof(MyHashSet));

  h->capacity = 10111;
  h->a = (struct HashNode **)malloc(sizeof(struct HashNode *) * h->capacity);
  for (int i = 0; i < h->capacity; i++) (h->a)[i] = NULL;

  return h;
}

struct HashNode* find(MyHashSet *obj, int key) {
  int h = HashFunc(obj, key);
  struct HashNode *p = (obj->a)[h];

  while (p) {
    if (p->val == key) return p;
    p = p->next;
  }

  return NULL;
}

void myHashSetAdd(MyHashSet* obj, int key) {
  struct HashNode *q;
  q = find(obj, key);
  // 已经存在
  if (q) return ;

  // 不存在
  int h = HashFunc(obj, key);
  struct HashNode *p = (obj->a)[h], *n;

  n = NewHashNode(key);
  if (!p) {
    (obj->a)[h] = n;
  } else {
    n->next = p;
    (obj->a)[h] = n;
  }
}

void myHashSetRemove(MyHashSet* obj, int key) {
  struct HashNode *p = find(obj, key);

  if (!p) return ;

  int h = HashFunc(obj, key);
  struct HashNode *prev = NULL, *q = (obj->a)[h];

  while (q != p) {
    prev = q;
    q = q->next;
  }
  if (prev) prev->next = p->next;
  else {
    // 只有一个节点
    if (p->next == NULL)
      (obj->a)[h] = NULL;
    // 有多个节点且 p 是第一个节点
    else
      (obj->a)[h] = p->next;
  }

  free(p);
}

bool myHashSetContains(MyHashSet* obj, int key) {
  struct HashNode *p = find(obj, key);
  return p != NULL;
}

void myHashSetFree(MyHashSet* obj) {
  struct HashNode *p, *q;

  for (int i = 0; i < obj->capacity; i++) {
    p = (obj->a)[i];
    while (p) {
      q = p;
      p = p->next;
      free(q);
    }
  }

  free(obj->a);
  free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
 */
// #v1

int main(int argc, char *argv[])
{
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
