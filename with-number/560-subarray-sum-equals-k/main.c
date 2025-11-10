#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 560. 和为 K 的子数组 - 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
// 子数组是数组中元素的连续非空序列。
//  
// 示例 1：
// 输入：nums = [1,1,1], k = 2
// 输出：2
// 示例 2：
// 输入：nums = [1,2,3], k = 3
// 输出：2
//  
// 提示：
//  * 1 <= nums.length <= 2 * 104
//  * -1000 <= nums[i] <= 1000
//  * -107 <= k <= 107

//// #v1
//// prefix sum, count
//struct HashNode {
  //int val, cnt;
  //struct HashNode *next;
//};
//
//struct HashTable {
  //int c;
  //struct HashNode **a;
//};
//
//struct HashNode* NewHashNode(int val) {
  //struct HashNode *ret = calloc(1, sizeof(struct HashNode));
//
  //ret->val = val;
  //ret->cnt = 1;
//
  //return ret;
//}
//
//struct HashTable* NewHashTable(int c) {
  //struct HashTable *ret = calloc(1, sizeof(struct HashTable));
//
  //ret->c = c;
  //ret->a = calloc(c, sizeof(struct HashNode *));
  //for (int i = 0; i < c; i++) ret->a[i] = NULL;
//
  //return ret;
//}
//
//int HashFunc(struct HashTable *t, int key) {
  //return (key % t->c + t->c) % t->c;
//}
//
//struct HashNode* HashTableFind(struct HashTable *t, int val) {
  //int h = HashFunc(t, val);
  //struct HashNode *p = t->a[h];
  //while (p) {
    //if (p->val == val) return p;
    //p = p->next;
  //}
  //return NULL;
//}
//
//void HashTableAdd(struct HashTable *t, int val) {
  //int h = HashFunc(t, val);
  //struct HashNode *n, *p = t->a[h], *q;
//
  //q = HashTableFind(t, val);
  //if (q) {
    //q->cnt += 1;
    //return ;
  //}
//
  //n = NewHashNode(val);
  //t->a[h] = n;
  //n->next = p;
//}
//
//int subarraySum(int* nums, int numsSize, int k) {
  //int prefixSum[numsSize+1], ret = 0, v;
  //struct HashTable *ht = NewHashTable(3727);
  //struct HashNode *p;
//
  //// prefix sum
  //// nums[0] + nums[1] + ... + nums[i] == prefixSum[i+1]
  //prefixSum[0] = 0;
  //for (int i = 0; i < numsSize; i++) {
    //prefixSum[i+1] = prefixSum[i] + nums[i];
  //}
//
  //for (int i = 1; i <= numsSize; i++) {
    //// prefixSum[i] - v == k
    //v = prefixSum[i] - k;
    //p = HashTableFind(ht, v);
    //// ret += count(prefixSum[1..(i-1)] == v)
    //if (p) ret += p->cnt;
//
    //// 计数当前前缀和
    //HashTableAdd(ht, prefixSum[i]);
  //}
//
  //// 将前缀和为 k 的次数计入结果
  //p = HashTableFind(ht, k);
  //if (p) ret += p->cnt;
//
  //return ret;
//}
//// #v1

// #v2
// prefix sum, count
struct HashNode {
  int val, cnt;
  struct HashNode *next;
};

struct HashTable {
  int c;
  struct HashNode **a;
};

struct HashTable* NewHashTable(int c) {
  struct HashTable *ret = calloc(1, sizeof(struct HashTable));

  ret->c = c;
  ret->a = calloc(c, sizeof(struct HashNode *));
  for (int i = 0; i < c; i++) ret->a[i] = NULL;

  return ret;
}

#define HashFunc(t, k) ((k % t->c + t->c) % t->c)

struct HashNode* HashTableFind(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *p = t->a[h];
  while (p) {
    if (p->val == val) return p;
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *p = t->a[h], *q;

  q = HashTableFind(t, val);
  if (q) {
    q->cnt += 1;
    return ;
  }

  struct HashNode *n = calloc(1, sizeof(struct HashNode));

  n->val = val;
  n->cnt = 1;
  n->next = p;

  t->a[h] = n;
}

int subarraySum(int* nums, int numsSize, int k) {
  int prefixSum[numsSize+1], ret = 0, v;
  struct HashTable *ht = NewHashTable(2027);
  struct HashNode *p;

  // prefix sum
  // nums[0] + nums[1] + ... + nums[i] == prefixSum[i+1]
  prefixSum[0] = 0;
  for (int i = 0; i < numsSize; i++) {
    prefixSum[i+1] = prefixSum[i] + nums[i];
  }

  for (int i = 1; i <= numsSize; i++) {
    // prefixSum[i] - v == k
    v = prefixSum[i] - k;
    p = HashTableFind(ht, v);
    // ret += count(prefixSum[1..(i-1)] == v)
    if (p) ret += p->cnt;

    // 计数当前前缀和
    HashTableAdd(ht, prefixSum[i]);
  }

  // 将前缀和为 k 的次数计入结果
  p = HashTableFind(ht, k);
  if (p) ret += p->cnt;

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
  int n, k, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);
  printf("%d\n", subarraySum(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
