#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 706. 设计 哈希映射 - 不使用任何内建的哈希表库设计一个哈希映射（HashMap）。
// 实现 MyHashMap 类：
//  * MyHashMap() 用空映射初始化对象
//  * void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
//  * int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
//  * void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。
//  
// 示例：
// 输入：
// ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
// [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
// 输出：
// [null, null, null, 1, -1, null, 1, null, -1]
// 解释：
// MyHashMap myHashMap = new MyHashMap();
// myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
// myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
// myHashMap.get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
// myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
// myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
// myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
// myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
// myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]
//  
// 提示：
//  * 0 &lt;= key, value &lt;= 106
//  * 最多调用 104 次 put、get 和 remove 方法

// #v1
struct HashNode {
  int k, v;
  struct HashNode *next;
};

typedef struct {
  struct HashNode **a;
  int capacity;
} MyHashMap;

#define HashFunc(t, k) ((k) % (t->capacity))

struct HashNode* NewHashNode(int k, int v) {
  struct HashNode *h = (struct HashNode *)malloc(sizeof(struct HashNode));
  h->k = k;
  h->v = v;
  h->next = NULL;
  return h;
}

MyHashMap* myHashMapCreate() {
  MyHashMap *h = (MyHashMap *)malloc(sizeof(MyHashMap));

  h->capacity = 10111;
  h->a = (struct HashNode **)malloc(sizeof(struct HashNode *) * h->capacity);
  for (int i = 0; i < h->capacity; i++) (h->a)[i] = NULL;

  return h;
}

struct HashNode* find(MyHashMap *obj, int key) {
  int h = HashFunc(obj, key);
  struct HashNode *p = (obj->a)[h];

  while (p) {
    if (p->k == key) return p;
    p = p->next;
  }

  return NULL;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
  struct HashNode *q;
  q = find(obj, key);
  // 已经存在
  if (q) {
    q->v = value;
    return ;
  }

  // 不存在
  int h = HashFunc(obj, key);
  struct HashNode *p = (obj->a)[h], *n;

  n = NewHashNode(key, value);
  if (!p) {
    (obj->a)[h] = n;
  } else {
    n->next = p;
    (obj->a)[h] = n;
  }
}

int myHashMapGet(MyHashMap* obj, int key) {
  struct HashNode *h = find(obj, key);
  if (!h) return -1;
  return h->v;
}

void myHashMapRemove(MyHashMap* obj, int key) {
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

void myHashMapFree(MyHashMap* obj) {
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
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);

 * int param_2 = myHashMapGet(obj, key);

 * myHashMapRemove(obj, key);

 * myHashMapFree(obj);
*/
// #v1

int main(int argc, char *argv[])
{
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
