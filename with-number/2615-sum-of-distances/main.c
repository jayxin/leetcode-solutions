#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2615. 等值 距离和 - 给你一个下标从 0 开始的整数数组 nums 。现有一个长度等于 nums.length 的数组 arr 。对于满足 nums[j] == nums[i] 且 j != i 的所有 j ，arr[i] 等于所有 |i - j| 之和。如果不存在这样的 j ，则令 arr[i] 等于 0 。
// 返回数组 arr 。
//  
// 示例 1：
// 输入：nums = [1,3,1,1,2]
// 输出：[5,0,3,4,0]
// 解释：
// i = 0 ，nums[0] == nums[2] 且 nums[0] == nums[3] 。因此，arr[0] = |0 - 2| + |0 - 3| = 5 。
// i = 1 ，arr[1] = 0 因为不存在值等于 3 的其他下标。
// i = 2 ，nums[2] == nums[0] 且 nums[2] == nums[3] 。因此，arr[2] = |2 - 0| + |2 - 3| = 3 。
// i = 3 ，nums[3] == nums[0] 且 nums[3] == nums[2] 。因此，arr[3] = |3 - 0| + |3 - 2| = 4 。
// i = 4 ，arr[4] = 0 因为不存在值等于 2 的其他下标。
// 示例 2：
// 输入：nums = [0,5,3]
// 输出：[0,0,0]
// 解释：因为 nums 中的元素互不相同，对于所有 i ，都有 arr[i] = 0 。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 0 <= nums[i] <= 109

//// #v1
//// prefix sum, hash table
//typedef long long LL;
//
//struct HashNode {
  //int val;
  //int *idx, idxLen, idxCapacity;
  //LL *prefixSum;
//
  //struct HashNode *next;
//};
//
//struct HashTable {
  //int capacity;
  //struct HashNode **table;
//};
//
//struct HashTable* NewHashTable(int capacity) {
  //struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
//
  //ret->capacity = capacity;
  //ret->table = calloc(capacity, sizeof(struct HashNode *));
//
  //for (int i = 0; i < capacity; i++) ret->table[i] = NULL;
//
  //return ret;
//}
//
//#define HashFunc(t, k) ((k) % (t->capacity))
//
//struct HashNode* HashTableFind(struct HashTable *t, int val) {
  //int h = HashFunc(t, val);
  //struct HashNode *p = t->table[h];
  //while (p) {
    //if (p->val == val) return p;
    //p = p->next;
  //}
  //return NULL;
//}
//
//void HashTableAdd(struct HashTable *t, int v, int idx) {
  //int h = HashFunc(t, v);
  //struct HashNode *p = t->table[h], *q;
//
  //q = HashTableFind(t, v);
//
  //if (q) {
    //if (q->idxLen == q->idxCapacity) {
      //q->idxCapacity <<= 1;
      //q->idx = reallocarray(q->idx, q->idxCapacity, sizeof(int));
      //q->prefixSum = reallocarray(q->prefixSum, q->idxCapacity + 1, sizeof(LL));
    //}
//
    //q->idx[(q->idxLen)++] = idx;
    //q->prefixSum[q->idxLen] = q->prefixSum[q->idxLen - 1] + idx;
  //} else {
    //struct HashNode *n = calloc(1, sizeof(struct HashNode));
//
    //n->idx = calloc(2, sizeof(int));
    //n->prefixSum = calloc(3, sizeof(LL));
//
    //n->val = v;
    //n->idxLen = 1;
    //n->idxCapacity = 2;
    //n->prefixSum[0] = 0;
    //n->idx[0] = n->prefixSum[1] = idx;
//
    //// add to hash table
    //t->table[h] = n;
    //n->next = p;
  //}
//}
//
//long long* distance(int* nums, int numsSize, int* returnSize) {
  //*returnSize = numsSize;
//
  //LL *ret = calloc(numsSize, sizeof(LL)), *p;
  //int *a, end, i;
  //struct HashTable *h = NewHashTable(3727);
  //struct HashNode *q;
//
  //for (i = 0; i < numsSize; i++) {
    //HashTableAdd(h, nums[i], i);
  //}
//
  //for (i = 0; i < h->capacity; i++) {
    //q = h->table[i];
//
    //while (q) {
      //a = q->idx, end = q->idxLen;
      //p = q->prefixSum;
//
      //for (int j = 0; j < end; j++) {
        ////ret[a[j]] = p[end] - p[j] - a[j] * (end - j) +
        ////  a[j] * j - p[j];
//
        //ret[a[j]] = p[end] - (p[j] << 1) + (int64_t)a[j] * ((j << 1) - end);
      //}
//
      //q = q->next;
    //}
  //}
//
  //return ret;
//}
//// #v1

// #v2
typedef long long LL;

struct HashNode {
  int val;
  int *idx, idxLen, idxCapacity;
  LL *prefixSum;

  struct HashNode *next;
};

struct HashTable {
  int c; // capacity
  struct HashNode **table;
};

struct HashTable* NewHashTable(int c) {
  struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));

  ret->c = c;
  ret->table = calloc(c, sizeof(struct HashNode *));

  for (int i = 0; i < c; i++) ret->table[i] = NULL;

  return ret;
}

#define HashFunc(t, k) ((k) % (t->c))

void HashTableAdd(struct HashTable *t, int v, int idx) {
  int h = HashFunc(t, v);
  struct HashNode *p = t->table[h], *q = p;

  // find
  while (q) {
    if (q->val == v) break;
    q = q->next;
  }

  if (q) {
    if (q->idxLen == q->idxCapacity) {
      q->idxCapacity <<= 1;
      q->idx = reallocarray(q->idx, q->idxCapacity, sizeof(int));
      q->prefixSum = reallocarray(q->prefixSum, q->idxCapacity + 1, sizeof(LL));
    }

    q->idx[(q->idxLen)++] = idx;
    q->prefixSum[q->idxLen] = q->prefixSum[q->idxLen - 1] + idx;
  } else { // new node
    struct HashNode *n = calloc(1, sizeof(struct HashNode));

    n->idx = calloc(2, sizeof(int));
    n->prefixSum = calloc(3, sizeof(LL));

    n->val = v;
    n->idxLen = 1;
    n->idxCapacity = 2;
    n->prefixSum[0] = 0;
    n->idx[0] = n->prefixSum[1] = idx;

    // add to hash table
    t->table[h] = n;
    n->next = p;
  }
}

long long* distance(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;

  LL *ret = calloc(numsSize, sizeof(LL)), *p;
  int *a, end, i;
  struct HashTable *h = NewHashTable(3727);
  struct HashNode *q;

  for (i = 0; i < numsSize; i++) HashTableAdd(h, nums[i], i);

  for (i = 0; i < h->c; i++) {
    q = h->table[i];

    while (q) {
      a = q->idx, end = q->idxLen;
      p = q->prefixSum;

      for (int j = 0; j < end; j++) {
        ret[a[j]] = p[end] - (p[j] << 1) + (int64_t)a[j] * ((j << 1) - end);
      }

      q = q->next;
    }
  }

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

void print_1d_arr(long long *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%lld", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int n, s, *a;
  long long *ret;
  scanf("%d", &n);
  a = read_1d_arr(n);

  ret = distance(a, n, &s);
  print_1d_arr(ret, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
