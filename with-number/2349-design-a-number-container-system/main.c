#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2349. 设计数字容器系统 - 设计一个数字容器系统，可以实现以下功能：
//  * 在系统中给定下标处 插入 或者 替换 一个数字。
//  * 返回 系统中给定数字的最小下标。
// 请你实现一个 NumberContainers 类：
//  * NumberContainers() 初始化数字容器系统。
//  * void change(int index, int number) 在下标 index 处填入 number 。如果该下标 index 处已经有数字了，那么用 number 替换该数字。
//  * int find(int number) 返回给定数字 number 在系统中的最小下标。如果系统中没有 number ，那么返回 -1 。
//  
// 示例：
// 输入：
// ["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
// [[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
// 输出：
// [null, -1, null, null, null, null, 1, null, 2]
// 解释：
// NumberContainers nc = new NumberContainers();
// nc.find(10); // 没有数字 10 ，所以返回 -1 。
// nc.change(2, 10); // 容器中下标为 2 处填入数字 10 。
// nc.change(1, 10); // 容器中下标为 1 处填入数字 10 。
// nc.change(3, 10); // 容器中下标为 3 处填入数字 10 。
// nc.change(5, 10); // 容器中下标为 5 处填入数字 10 。
// nc.find(10); // 数字 10 所在的下标为 1 ，2 ，3 和 5 。因为最小下标为 1 ，所以返回 1 。
// nc.change(1, 20); // 容器中下标为 1 处填入数字 20 。注意，下标 1 处之前为 10 ，现在被替换为 20 。
// nc.find(10); // 数字 10 所在下标为 2 ，3 和 5 。最小下标为 2 ，所以返回 2 。
//  
// 提示：
//  * 1 &lt;= index, number &lt;= 109
//  * 调用 change 和 find 的 总次数 不超过 105 次。

//// #v1
//// 正确但超时
//struct HashNode {
  //int val, idx;
  //struct HashNode *next;
//};
//
//struct HashTable {
  //int capacity;
  //int size;
  //struct HashNode **table;
//};
//
//struct HashNode* NewHashNode(int val, int idx) {
  //struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  //ret->val = val;
  //ret->idx = idx;
  //ret->next = NULL;
  //return ret;
//}
//
//struct HashTable* NewHashTable(int capacity) {
  //if (capacity <= 0) {
    //return NULL;
  //}
//
  //struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  //ret->capacity = capacity;
  //ret->size = 0;
  //int table_bytes = sizeof(struct HashNode *) * capacity;
  //ret->table = (struct HashNode **)malloc(table_bytes);
  //memset(ret->table, 0, table_bytes);
//
  //return ret;
//}
//
//int HashFunc(struct HashTable *t, int key) {
  //if (!t) return 0;
//
  //int ret = key % t->capacity;
  //if (ret < 0) ret += t->capacity;
  //return ret;
//}
//
//void HashTablePrint(struct HashTable *);
//
//struct HashNode* HashTableFind(struct HashTable *t, int val) {
  //if (!t) return NULL;
//
//
  //int h = HashFunc(t, val);
//
  //struct HashNode *p = (t->table)[h], *minEl = NULL;
  //int minIdx = -1;
  //while (p) {
    //if (p->val == val) {
      //if (minIdx < 0 || p->idx < minIdx) {
        //minIdx = p->idx;
        //minEl = p;
      //}
    //}
//
    //p = p->next;
  //}
//
  //return minEl;
//}
//
//struct HashNode* HashTableFind1(struct HashTable *t, int val, int idx) {
  //if (!t) return NULL;
//
  //int h = HashFunc(t, val);
  //struct HashNode *p = (t->table)[h];
//
  //while (p) {
    //if (p->val == val && p->idx == idx) return p;
    //p = p->next;
  //}
//
  //return NULL;
//}
//
//void HashTableAdd(struct HashTable *t, int val, int idx) {
  //if (!t) return ;
//
  //int h = HashFunc(t, val);
  //struct HashNode *n, *p = (t->table)[h], *q = NULL;
//
  //n = NewHashNode(val, idx);
//
  //// p == NULL
  //if (!p) {
    //(t->table)[h] = n;
    //return ;
  //}
//
  //// p != NULL
  //n->next = p;
  //(t->table)[h] = n;
//}
//
//void HashTableRemove(struct HashTable *t, int val, int idx) {
  //if (!t) return ;
//
  //int h = HashFunc(t, val);
  //struct HashNode *p = (t->table)[h], *prev = NULL;
//
  //while (p) {
    //if (p->val == val && p->idx == idx) {
      //break;
    //}
    //prev = p;
    //p = p->next;
  //}
//
  //if (p) {
    //if (prev) {
      //prev->next = p->next;
    //} else {
      //(t->table)[h] = (t->table)[h]->next;
    //}
    //free(p);
  //}
//}
//
//typedef struct { struct HashTable *h1, *h2; } NumberContainers;
//
//NumberContainers* numberContainersCreate() {
  //NumberContainers *ret = (NumberContainers *)malloc(sizeof(NumberContainers));
  //ret->h1 = NewHashTable(10007);
  //ret->h2 = NewHashTable(10007);
  //return ret;
//}
//
//void numberContainersChange(NumberContainers* obj, int index, int number) {
  //if (!obj) return ;
//
  //int idx = index - 1;
//
  //struct HashNode *p = NULL;
  //p = HashTableFind(obj->h2, idx);
  //if (p) {
    //int i = p->idx, v = p->val;
    //HashTableRemove(obj->h1, i, idx);
    ////HashTableRemove(obj->h2, v, i);
//
    //p->idx = number;
    //HashTableAdd(obj->h1, number, idx);
  //} else {
    //HashTableAdd(obj->h1, number, idx);
    //HashTableAdd(obj->h2, idx, number);
  //}
//}
//
//void HashTablePrint(struct HashTable *t) {
  //if (!t) return ;
  //struct HashNode *p;
  //int i;
  //for (i = 0; i < t->capacity; i++) {
    //if (t->table[i] == NULL) {
      //continue;
    //}
    //p = t->table[i];
    //while (p) {
      //printf("i: %d val: %d idx: %d\n", i, t->table[i]->val, t->table[i]->idx);
      //p = p->next;
    //}
    //putchar('\n');
  //}
//}
//
//int numberContainersFind(NumberContainers* obj, int number) {
  //struct HashNode *p = HashTableFind(obj->h1, number);
  //if (p) return p->idx + 1;
  //return -1;
//}
//
//void numberContainersFree(NumberContainers* obj) {
  //if (!obj) return ;
//
  //free(obj->h1);
  //free(obj->h2);
  //free(obj);
//}
//
///**
 //* Your NumberContainers struct will be instantiated and called as such:
 //* NumberContainers* obj = numberContainersCreate();
 //* numberContainersChange(obj, index, number);
//
 //* int param_2 = numberContainersFind(obj, number);
//
 //* numberContainersFree(obj);
 //*/
//// #v1

// #v2
// 用到的数据结构有数组、链表、哈希表、小根堆
// 哈希表节点结构体
struct HashNode {
  int val, idx;
  struct HashNode *next;
};

// 哈希表结构体
// 把 index 映射到 number
struct HashTable {
  int capacity;
  struct HashNode **t;
};

// 小根堆结构体
struct Heap {
  int *a, val, size, capacity;
  struct Heap *next;
};

// 小根堆结合哈希表结构体, 把 number 映射到 index
// 一个 number 可能对应多个 index, 需要选择最小的
struct HeapTable {
  int capacity;
  struct Heap **t;
};

// 小根堆操作
// 交换堆中的两个节点
void HeapSwap(struct Heap *h, int i, int j);
// 向上调整堆
void HeapUp(struct Heap *h, int p);
// 向下调整堆
void HeapDown(struct Heap *h, int p);
// 向队中添加元素
void HeapInsert(struct Heap *h, int v);
// 弹出堆顶元素
void HeapExtract(struct Heap *h);
// 释放小根堆内存
void DestroyHeap(struct Heap *h);
// 新建小根堆
struct Heap* NewHeap(int capacity, int val);
// 映射 number 到 index 的哈希函数
int HeapHashFunc(struct HeapTable *t, int key);
// 新建小根堆哈希表
struct HeapTable* NewHeapTable(int capacity);
// 小根堆哈希表查找, 根据 number 查找对应的小根堆
struct Heap* HeapTableFind(struct HeapTable *t, int val);
// 小根堆哈希表添加元素, 向 number 对应的小根堆中添加 index
void HeapTableAdd(struct HeapTable *t, int val, int idx);

// 哈希表操作
// 新建哈希表节点
struct HashNode* NewHashNode(int val, int idx);
// 新建哈希表
struct HashTable* NewHashTable(int capacity);
// 哈希表的哈希函数
int HashFunc(struct HashTable *t, int key);
// 哈希表查找, 根据 key 的值查找
struct HashNode* HashTableFind(struct HashTable *t, int val);
// 哈希表查找, 根据 key 和 value 的值查找
struct HashNode* HashTableFind1(struct HashTable *t, int val, int idx);
// 向哈希表添加元素
void HashTableAdd(struct HashTable *t, int val, int idx);

void HeapSwap(struct Heap *h, int i, int j) {
  int t = h->a[i];
  h->a[i] = h->a[j];
  h->a[j] = t;
}

void HeapUp(struct Heap *h, int p) {
  while (p > 1) {
    if (h->a[p] < h->a[p>>1]) {
      HeapSwap(h, p, p>>1);
      p >>= 1;
    } else {
      return ;
    }
  }
}

void HeapDown(struct Heap *h, int p) {
  int s = p << 1;
  int n = h->size;

  while (s <= n) {
    if (s < n && h->a[s] > h->a[s+1]) s++;
    if (h->a[s] < h->a[p]) {
      HeapSwap(h, s, p);
      p = s;
      s = p<<1;
    } else {
      return ;
    }
  }
}

void HeapInsert(struct Heap *h, int v) {
  // 动态调整内存
  if (h->size + 1 >= h->capacity) {
    h->capacity <<= 1;
    int *t = (int *)malloc(sizeof(int) * h->capacity);
    for (int i = 1; i <= h->size; i++) {
      t[i] = h->a[i];
    }
    free(h->a);
    h->a = t;
  }
  h->a[++(h->size)] = v;
  HeapUp(h, h->size);
}

void HeapExtract(struct Heap *h) {
  h->a[1] = h->a[(h->size)--];
  HeapDown(h, 1);
}

void DestroyHeap(struct Heap *h) {
  if (!h) return ;
  free(h->a);
  free(h);
}

struct Heap* NewHeap(int capacity, int val) {
  struct Heap *ret = (struct Heap *)malloc(sizeof(struct Heap));

  ret->a = (int *)malloc(sizeof(int) * capacity);
  ret->size = 0;
  ret->capacity = capacity;
  ret->val = val;
  ret->next = NULL;

  return ret;
}

int HeapHashFunc(struct HeapTable *t, int key) {
  int ret = key % t->capacity;
  return ((ret < 0) ? (ret + t->capacity) : ret);
}

struct HeapTable* NewHeapTable(int capacity) {
  struct HeapTable *ret = (struct HeapTable *)malloc(sizeof(struct HeapTable));
  ret->capacity = capacity;
  int table_bytes = sizeof(struct Heap*) * capacity;
  ret->t = (struct Heap **)malloc(table_bytes);
  memset(ret->t, 0, table_bytes);

  return ret;
}

struct Heap* HeapTableFind(struct HeapTable *t, int val) {
  int h = HeapHashFunc(t, val);
  struct Heap *p = (t->t)[h];

  while (p) {
    if (p->val == val) return p;
    p = p->next;
  }

  return NULL;
}

void HeapTableAdd(struct HeapTable *t, int val, int idx) {
  int h = HeapHashFunc(t, val);
  struct Heap *n, *p = (t->t)[h], *q = NULL;

  // p == NULL
  if (!p) {
    n = NewHeap(100, val);
    HeapInsert(n, idx);
    (t->t)[h] = n;
    return ;
  }

  // p != NULL
  q = HeapTableFind(t, val);
  if (q) {
    HeapInsert(q, idx);
  } else {
    n = NewHeap(100, val);
    HeapInsert(n, idx);
    n->next = p;
    (t->t)[h] = n;
  }
}

struct HashNode* NewHashNode(int val, int idx) {
  struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  ret->val = val;
  ret->idx = idx;
  ret->next = NULL;
  return ret;
}

struct HashTable* NewHashTable(int capacity) {
  struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  ret->capacity = capacity;
  int table_bytes = sizeof(struct HashNode *) * capacity;
  ret->t = (struct HashNode **)malloc(table_bytes);
  memset(ret->t, 0, table_bytes);

  return ret;
}

int HashFunc(struct HashTable *t, int key) {
  int ret = key % t->capacity;
  return ((ret < 0) ? (ret + t->capacity) : ret);
}

struct HashNode* HashTableFind(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *p = (t->t)[h];

  while (p) {
    if (p->val == val) return p;
    p = p->next;
  }

  return NULL;
}

struct HashNode* HashTableFind1(struct HashTable *t, int val, int idx) {
  int h = HashFunc(t, val);
  struct HashNode *p = (t->t)[h];

  while (p) {
    if (p->val == val && p->idx == idx) return p;
    p = p->next;
  }

  return NULL;
}

void HashTableAdd(struct HashTable *t, int val, int idx) {
  int h = HashFunc(t, val);
  struct HashNode *n, *p = (t->t)[h], *q = NULL;

  n = NewHashNode(val, idx);

  // p == NULL
  if (!p) {
    (t->t)[h] = n;
    return ;
  }

  // p != NULL
  n->next = p;
  (t->t)[h] = n;
}

//void HashTableRemove(struct HashTable *t, int val, int idx) {
//  int h = HashFunc(t, val);
//  struct HashNode *p = (t->t)[h], *prev = NULL;
//
//  while (p) {
//    if (p->val == val && p->idx == idx) {
//      break;
//    }
//    prev = p;
//    p = p->next;
//  }
//
//  if (p) {
//    if (prev) {
//      prev->next = p->next;
//    } else {
//      (t->t)[h] = (t->t)[h]->next;
//    }
//    free(p);
//  }
//}

typedef struct {
  // h2: 把 index 映射到 number
  struct HashTable *h2;
  // h3: 存储每个 number 对应的 index
  // 每个 number 都会对应一个小根堆, 小根堆的元素是 index
  struct HeapTable *h3;
} NumberContainers;

NumberContainers* numberContainersCreate() {
  NumberContainers *ret = (NumberContainers *)malloc(sizeof(NumberContainers));
  ret->h2 = NewHashTable(5007);
  ret->h3 = NewHeapTable(5007);
  return ret;
}

void numberContainersChange(NumberContainers* obj, int index, int number) {
  int idx = index - 1;

  struct HashNode *p = NULL;
  struct Heap* q = NULL;
  p = HashTableFind(obj->h2, idx);
  if (p) { // update
    p->idx = number;
  } else { // new
    HashTableAdd(obj->h2, idx, number);
  }

  q = HeapTableFind(obj->h3, number);
  if (q && q->a[1] == idx) return ;
  HeapTableAdd(obj->h3, number, idx);
}

int numberContainersFind(NumberContainers* obj, int number) {
  struct Heap *h = HeapTableFind(obj->h3, number);
  struct HashNode *p;
  while (h && h->size >= 1) {
    // 查看最小索引对应的值是否为 number, 因为有可能是过期的(被覆盖了)
    p = HashTableFind1(obj->h2, h->a[1], number);

    // 最小索引对应的值就是 number
    if (p) return h->a[1] + 1;

    // 在这里删除过期的索引
    HeapExtract(h);
  }
  return -1;
}

void numberContainersFree(NumberContainers* obj) {
  if (!obj) return ;

  free(obj->h2);
  free(obj->h3);
  free(obj);
}
// #v2

int main(int argc, char *argv[])
{
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
