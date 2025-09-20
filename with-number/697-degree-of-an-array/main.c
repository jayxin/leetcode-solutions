#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 697. 数组的度 - 给定一个非空且只包含非负数的整数数组 nums，数组的 度 的定义是指数组里任一元素出现频数的最大值。
// 你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
//  
// 示例 1：
// 输入：nums = [1,2,2,3,1]
// 输出：2
// 解释：
// 输入数组的度是 2 ，因为元素 1 和 2 的出现频数最大，均为 2 。
// 连续子数组里面拥有相同度的有如下所示：
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// 最短连续子数组 [2, 2] 的长度为 2 ，所以返回 2 。
// 示例 2：
// 输入：nums = [1,2,2,3,1,4,2]
// 输出：6
// 解释：
// 数组的度是 3 ，因为元素 2 重复出现 3 次。
// 所以 [2,2,3,1,4,2] 是最短子数组，因此返回 6 。
//  
// 提示：
//  * nums.length 在 1 到 50,000 范围内。
//  * nums[i] 是一个在 0 到 49,999 范围内的整数。

//// #v1
//struct HashNode {
  //int val, cnt, minIdx, maxIdx;
  //struct HashNode *next;
//};
//
//struct HashTable {
  //int capacity;
  //int size;
  //struct HashNode **t;
//};
//
//struct HashNode* NewHashNode(int val, int idx) {
  //struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  //ret->val = val;
  //ret->minIdx = ret->maxIdx = idx;
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
  //return ret;
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
//int HashTableAdd(struct HashTable *t, int val, int idx) {
  //int h;
  //struct HashNode *n, *p, *q;
//
  //q = HashTableFind(t, val);
  //if (q) {
    //q->cnt += 1;
    //if (idx < q->minIdx) q->minIdx = idx;
    //if (idx > q->minIdx) q->maxIdx = idx;
    //return q->cnt;
  //}
//
  //h = HashFunc(t, val);
  //p = (t->t)[h];
  //n = NewHashNode(val, idx);
  //if (!p) {
    //(t->t)[h] = n;
    //return n->cnt;
  //}
  //n->next = p;
  //(t->t)[h] = n;
  //return n->cnt;
//}
//
//int findShortestSubArray(int* nums, int numsSize) {
  //int cnt = 0, tmp, ret = 0x7fffffff, tt;
  //struct HashTable *t = NewHashTable(73331);
  //struct HashNode *p;
//
  //for (int i = 0; i < numsSize; i++) {
    //tmp = HashTableAdd(t, nums[i], i);
    //if (tmp >= cnt) cnt = tmp;
  //}
//
  //for (int i = 0; i < numsSize; i++) {
    //p = HashTableFind(t, nums[i]);
    //if (p->cnt == cnt) {
      //tt = p->maxIdx - p->minIdx + 1;
      //if (tt < ret) ret = tt;
    //}
  //}
//
  //free(t->t);
  //free(t);
//
  //return ret;
//}
//// #v1

// #v2
struct HashNode {
  int val, cnt, minIdx, maxIdx;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  int size;
  struct HashNode **t;
};

struct HashNode* NewHashNode(int val, int idx) {
  struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  ret->val = val;
  ret->minIdx = ret->maxIdx = idx;
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
  return ret;
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

int HashTableAdd(struct HashTable *t, int val, int idx) {
  int h;
  struct HashNode *n, *p, *q;

  q = HashTableFind(t, val);
  if (q) {
    q->cnt += 1;
    if (idx < q->minIdx) q->minIdx = idx;
    if (idx > q->minIdx) q->maxIdx = idx;
    return q->cnt;
  }

  h = HashFunc(t, val);
  p = (t->t)[h];
  n = NewHashNode(val, idx);
  if (!p) {
    (t->t)[h] = n;
    return n->cnt;
  }
  n->next = p;
  (t->t)[h] = n;
  return n->cnt;
}

// hash table
int findShortestSubArray(int* nums, int numsSize) {
  int cnt = 0, tmp, ret = 0x7fffffff, tt, maxEls[20000], len = 0;
  struct HashTable *t = NewHashTable(7331);
  struct HashNode *p;

  for (int i = 0; i < numsSize; i++) {
    tmp = HashTableAdd(t, nums[i], i);
    if (tmp >= cnt) {
      // 有更大的, 数组清零
      if (tmp > cnt) len = 0;
      maxEls[len++] = nums[i];

      cnt = tmp;
    }
  }

  for (int i = 0; i < len; i++) {
    p = HashTableFind(t, maxEls[i]);
    if (p->cnt == cnt) {
      tt = p->maxIdx - p->minIdx + 1;
      if (tt < ret) ret = tt;
    }
  }

  free(t->t);
  free(t);

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
  printf("%d\n", findShortestSubArray(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
