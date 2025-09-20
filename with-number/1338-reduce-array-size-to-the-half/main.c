#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1338. 数 组大小减半 - 给你一个整数数组 arr。你可以从中选出一个整数集合，并删除这些整数在数组中的每次出现。
// 返回 至少 能删除数组中的一半整数的整数集合的最小大小。
//  
// 示例 1：
// 输入：arr = [3,3,3,3,5,5,5,2,2,7]
// 输出：2
// 解释：选择 {3,7} 使得结果数组为 [5,5,5,2,2]、长度为 5（原数组长度的一半）。
// 大小为 2 的可行集合有 {3,5},{3,2},{5,2}。
// 选择 {2,7} 是不可行的，它的结果数组为 [3,3,3,3,5,5,5]，新数组长度大于原数组的二分之一。
// 示例 2：
// 输入：arr = [7,7,7,7,7,7]
// 输出：1
// 解释：我们只能选择集合 {7}，结果数组为空。
//  
// 提示：
//  * 1 <= arr.length <= 105
//  * arr.length 为偶数
//  * 1 <= arr[i] <= 105

//// #v1
//// 哈希表, 大根堆
//struct HashNode {
  //int val, cnt;
  //struct HashNode *next;
//};
//
//struct HashTable {
  //int capacity;
  //int size;
  //struct HashNode **t;
//};
//
//struct HashNode* NewHashNode(int val) {
  //struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  //ret->val = val;
  //ret->cnt = 1;
  //ret->next = NULL;
  //return ret;
//}
//
//struct HashTable* NewHashTable(int capacity) {
  //struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  //ret->capacity = capacity;
  //ret->size = 0;
  //int table_bytes = sizeof(struct HashNode *) * capacity;
  //ret->t = (struct HashNode **)malloc(table_bytes);
  //memset(ret->t, 0, table_bytes);
//
  //return ret;
//}
//
//int HashFunc(struct HashTable *t, int key) {
  //int ret = key % t->capacity;
  //return (ret < 0 ? ret + t->capacity : ret);
//}
//
//struct HashNode* HashTableFind(struct HashTable *t, int val) {
  //int h = HashFunc(t, val);
  //struct HashNode *p = (t->t)[h];
  //while (p) {
    //if (p->val == val) return p;
    //p = p->next;
  //}
  //return NULL;
//}
//
//void HashTableAdd(struct HashTable *t, int val) {
  //int h;
  //struct HashNode *n, *p, *q;
//
  //q = HashTableFind(t, val);
  //if (q) { // use existed node
    //q->cnt += 1;
    //return ;
  //}
//
  //// new node
  //h = HashFunc(t, val);
  //p = (t->t)[h];
//
  //n = NewHashNode(val);
  //t->size += 1;
//
  //if (!p) {
    //(t->t)[h] = n;
    //return ;
  //}
//
  //n->next = p;
  //(t->t)[h] = n;
//}
//
//void DestroyHashTable(struct HashTable *t) {
  //free(t->t);
  //free(t);
//}
//
//struct MaxHeap {
  //int *a;
  //int size, capacity;
//};
//
//struct MaxHeap* NewHeap(int capacity) {
  //struct MaxHeap *ret = (struct MaxHeap *)malloc(sizeof(struct MaxHeap));
//
  //ret->a = (int *)malloc(sizeof(int) * capacity);
  //ret->size = 0;
  //ret->capacity = capacity;
//
  //return ret;
//}
//
//void HeapSwap(struct MaxHeap *h, int i, int j) {
  //int t = heap[i];
  //heap[i] = heap[j];
  //heap[j] = t;
//}
//
//void HeapUp(struct MaxHeap *h, int p) { // 向上调整
  //while (p > 1) {
    //if (heap[p] > heap[p>>1]) { // 子节点 > 父节点, 不满足大根堆性质
      //HeapSwap(h, p, p>>1);
      //p >>= 1;
    //} else {
      //return;
    //}
  //}
//}
//
//void HeapDown(struct MaxHeap *h, int p) { // 向下调整
  //int s = p << 1; // p 的左子节点
  //int n = h->size;
//
  //while (s <= n) {
    //if (s < n && heap[s] < heap[s+1]) s++; //左右子节点取较大
    //if (heap[s] > heap[p]) { // 子节点 > 父节点
      //HeapSwap(h, s, p);
      //p = s;
      //s <<= 1;
    //} else {
      //return;
    //}
  //}
//}
//
//void HeapInsert(struct MaxHeap *h, int v) {
  //heap[++(h->size)] = v;
  //HeapUp(h, h->size);
//}
//
//void HeapExtract(struct MaxHeap *h) {
  //heap[1] = heap[(h->size)--];
  //HeapDown(h, 1);
//}
//
//void DestroyHeap(struct MaxHeap *h) {
  //free(heap);
  //free(h);
//}
//
//int minSetSize(int* arr, int arrSize) {
  //struct HashTable *t = NewHashTable(13331);
  //struct HashNode *p, *tmp;
  //int ret = 0, del = 0, half = arrSize >> 1, i;
  //struct MaxHeap *h;
//
  //// add to hash table and count
  //for (i = 0; i < arrSize; i++) HashTableAdd(t, arr[i]);
//
  //// heap init
  //h = NewHeap(t->size + 1);
//
  //// add to heap
  //for (i = 0; i < t->capacity; i++) {
    //p = (t->t)[i];
    //while (p) {
      //tmp = p;
      //HeapInsert(h, tmp->cnt);
      //p = p->next;
      //free(tmp);
    //}
  //}
//
  //while (del < half) {
    //del += heap[1];
    //HeapExtract(h);
    //++ret;
  //}
//
  //DestroyHeap(h);
  //DestroyHashTable(t);
//
  //return ret;
//}
//// #v1

// #v2
// 哈希表, 大根堆
struct HashNode {
  int val, cnt;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  int size;
  struct HashNode **t;
};

struct HashNode* NewHashNode(int val) {
  struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  ret->val = val;
  ret->cnt = 1;
  ret->next = NULL;
  return ret;
}

struct HashTable* NewHashTable(int capacity) {
  struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  ret->capacity = capacity;
  ret->size = 0;
  int table_bytes = sizeof(struct HashNode *) * capacity;
  ret->t = (struct HashNode **)malloc(table_bytes);
  memset(ret->t, 0, table_bytes);

  return ret;
}

int HashFunc(struct HashTable *t, int key) {
  int ret = key % t->capacity;
  return (ret < 0 ? ret + t->capacity : ret);
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

void HashTableAdd(struct HashTable *t, int val) {
  int h;
  struct HashNode *n, *p, *q;

  q = HashTableFind(t, val);
  if (q) { // use existed node
    q->cnt += 1;
    return ;
  }

  // new node
  h = HashFunc(t, val);
  p = (t->t)[h];

  n = NewHashNode(val);
  t->size += 1;

  if (!p) {
    (t->t)[h] = n;
    return ;
  }

  n->next = p;
  (t->t)[h] = n;
}

void DestroyHashTable(struct HashTable *t) {
  free(t->t);
  free(t);
}

int *heap, heapSize, tmp;

void HeapSwap(int i, int j) {
  tmp = heap[i];
  heap[i] = heap[j];
  heap[j] = tmp;
}

void HeapUp(int p) {
  while (p > 1) {
    if (heap[p] > heap[p>>1]) {
      HeapSwap(p, p>>1);
      p >>= 1;
    } else {
      return;
    }
  }
}

void HeapDown(int p) {
  int s = p << 1;

  while (s <= heapSize) {
    if (s < heapSize && heap[s] < heap[s+1]) s++; //左右子节点取较大
    if (heap[s] > heap[p]) { // 子节点 > 父节点
      HeapSwap(s, p);
      p = s;
      s <<= 1;
    } else {
      return;
    }
  }
}

void HeapInsert(int v) {
  heap[++heapSize] = v;
  HeapUp(heapSize);
}

void HeapExtract() {
  heap[1] = heap[heapSize--];
  HeapDown(1);
}

int minSetSize(int* arr, int arrSize) {
  struct HashTable *t = NewHashTable(17331);
  struct HashNode *p, *tmp;
  int ret = 0, del = 0, half = arrSize >> 1, i;

  // add to hash table and count
  for (i = 0; i < arrSize; i++) HashTableAdd(t, arr[i]);

  // heap init
  heap = (int *)malloc(sizeof(int) * (t->size + 1));
  heapSize = 0;

  // add to heap
  for (i = 0; i < t->capacity; i++) {
    p = (t->t)[i];
    while (p) {
      tmp = p;
      HeapInsert(tmp->cnt);
      p = p->next;
      free(tmp);
    }
  }

  while (del < half) {
    del += heap[1];
    HeapExtract();
    ++ret;
  }

  free(heap);
  DestroyHashTable(t);

  return ret;
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
  printf("%d\n", minSetSize(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
