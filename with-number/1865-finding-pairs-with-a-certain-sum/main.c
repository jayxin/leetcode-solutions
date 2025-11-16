#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1865. 找出和为指定值的下标对 - 给你两个整数数组 nums1 和 nums2 ，请你实现一个支 持下述两类查询的数据结构：
//  1. 累加 ，将一个正整数加到 nums2 中指定下标对应元素上。
//  2. 计数 ，统计满足 nums1[i] + nums2[j] 等于指定值的下标对 (i, j) 数目（0 <= i < nums1.length 且 0 <= j < nums2.length）。
// 实现 FindSumPairs 类：
//  * FindSumPairs(int[] nums1, int[] nums2) 使用整数数组 nums1 和 nums2 初始化 FindSumPairs 对象。
//  * void add(int index, int val) 将 val 加到 nums2[index] 上，即，执行 nums2[index] += val 。
//  * int count(int tot) 返回满足 nums1[i] + nums2[j] == tot 的下标对 (i, j) 数目。
//  
// 示例：
// 输入：
// ["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
// [[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]
// 输出：
// [null, 8, null, 2, 1, null, null, 11]
// 解释：
// FindSumPairs findSumPairs = new FindSumPairs([1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]);
// findSumPairs.count(7);  // 返回 8 ; 下标对 (2,2), (3,2), (4,2), (2,4), (3,4), (4,4) 满足 2 + 5 = 7 ，下标对 (5,1), (5,5) 满足 3 + 4 = 7
// findSumPairs.add(3, 2); // 此时 nums2 = [1,4,5,4,5,4]
// findSumPairs.count(8);  // 返回 2 ；下标对 (5,2), (5,4) 满足 3 + 5 = 8
// findSumPairs.count(4);  // 返回 1 ；下标对 (5,0) 满足 3 + 1 = 4
// findSumPairs.add(0, 1); // 此时 nums2 = [2,4,5,4,5,4]
// findSumPairs.add(1, 1); // 此时 nums2 = [2,5,5,4,5,4]
// findSumPairs.count(7);  // 返回 11 ；下标对 (2,1), (2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) 满足 2 + 5 = 7 ，下标对 (5,3), (5,5) 满足 3 + 4 = 7
//  
// 提示：
//  * 1 <= nums1.length <= 1000
//  * 1 <= nums2.length <= 105
//  * 1 <= nums1[i] <= 109
//  * 1 <= nums2[i] <= 105
//  * 0 <= index < nums2.length
//  * 1 <= val <= 105
//  * 1 <= tot <= 109
//  * 最多调用 add 和 count 函数各 1000 次

// #v1
struct HashNode {
  int val, cnt;
  struct HashNode *next;
};

struct HashTable {
  int c;
  struct HashNode **a;
};

struct HashTable* NewHashTable(int c) {
  struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));

  ret->c = c;
  ret->a = (struct HashNode **)malloc(c * sizeof(struct HashNode *));
  for (int i = 0; i < c; i++) ret->a[i] = NULL;

  return ret;
}

#define HashFunc(t, k) ((k) % (t)->c)

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
  struct HashNode *q = HashTableFind(t, val);

  if (q) {
    ++q->cnt;
    return ;
  }

  int h = HashFunc(t, val);
  struct HashNode *p = t->a[h];
  struct HashNode *n = malloc(sizeof(struct HashNode));

  n->val = val;
  n->cnt = 1;

  t->a[h] = n;
  n->next = p;
}

typedef struct {
  int *a0, n0, *a1, n1;
  struct HashTable *ht;
} FindSumPairs;

FindSumPairs* findSumPairsCreate(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  FindSumPairs *p = (FindSumPairs *)malloc(sizeof(FindSumPairs));
  p->a0 = nums1;
  p->n0 = nums1Size;
  p->a1 = nums2;
  p->n1 = nums2Size;
  p->ht = NewHashTable(101177);

  // init hash table
  for (int i = 0; i < nums2Size; i++) HashTableAdd(p->ht, nums2[i]);

  return p;
}

void findSumPairsAdd(FindSumPairs* obj, int index, int val) {
  struct HashNode *p = HashTableFind(obj->ht, obj->a1[index]);

  if (p && p->cnt) --p->cnt;

  obj->a1[index] += val;
  HashTableAdd(obj->ht, obj->a1[index]);
}

int findSumPairsCount(FindSumPairs* obj, int tot) {
  int ret = 0;
  struct HashNode *p;

  for (int i = 0; i < obj->n0; i++) {
    if (tot < obj->a0[i]) continue;
    p = HashTableFind(obj->ht, tot - obj->a0[i]);
    if (p) ret += p->cnt;
  }

  return ret;
}

void findSumPairsFree(FindSumPairs* obj) {
  for (int i = 0; i < obj->ht->c; i++) {
    struct HashNode *p = obj->ht->a[i], *q;
    while (p) {
      q = p;
      p = p->next;
      free(q);
    }
  }

  free(obj->ht->a);
  free(obj->ht);
  free(obj);
}

/**
 * Your FindSumPairs struct will be instantiated and called as such:
 * FindSumPairs* obj = findSumPairsCreate(nums1, nums1Size, nums2, nums2Size);
 * findSumPairsAdd(obj, index, val);

 * int param_2 = findSumPairsCount(obj, tot);

 * findSumPairsFree(obj);
*/
// #v1

int main(int argc, char *argv[])
{
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
