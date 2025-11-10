#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1590. 使数组和能被 P 整除 - 给你一个正整数数组 nums，请你移除 最短 子数组（可以为  空），使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
// 请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。
// 子数组 定义为原数组中连续的一组元素。
//  
// 示例 1：
// 输入：nums = [3,1,4,2], p = 6
// 输出：1
// 解释：nums 中元素和为 10，不能被 p 整除。我们可以移除子数组 [4] ，剩余元素的和为 6 。
// 示例 2：
// 输入：nums = [6,3,5,2], p = 9
// 输出：2
// 解释：我们无法移除任何一个元素使得和被 9 整除，最优方案是移除子数组 [5,2] ，剩余 元素为 [6,3]，和为 9 。
// 示例 3：
// 输入：nums = [1,2,3], p = 3
// 输出：0
// 解释：和恰好为 6 ，已经能被 3 整除了。所以我们不需要移除任何元素。
// 示例  4：
// 输入：nums = [1,2,3], p = 7
// 输出：-1
// 解释：没有任何方案使得移除子数组后剩余元素的和被 7 整除。
// 示例 5：
// 输入：nums = [1000000000,1000000000,1000000000], p = 3
// 输出：0
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 1 <= nums[i] <= 109
//  * 1 <= p <= 109

//// #v1
//// NOTE: stack overflow
//// prefix sum, math
//#define INF 0x7fffffff
//
//int minSubarray(int* nums, int numsSize, int p) {
  //long long prefixSum[numsSize+1];
  //int ret = INF, r, r0;
  //// 将前缀和根据 (mod p) 的余数分为 p 类, [0, p-1]
  //int map[p]; // stack overflow
//
  //memset(map, 0, sizeof(map));
//
  //// prefix sum
  //// nums[0] + nums[1] + ... + nums[i] == prefixSum[i+1]
  //prefixSum[0] = 0LL;
  //for (int i = 0; i < numsSize; i++) {
    //prefixSum[i+1] = prefixSum[i] + nums[i];
  //}
//
  //r0 = prefixSum[numsSize] % p;
//
  //// edge case
  //if (r0 == 0) return 0;
//
  //// sum(nums[i...j]) == nums[i] + nums[i+1] + ... + nums[j] == prefixSum[j+1] - prefixSum[i]
  //// (prefixSum[numsSize] - sum(nums[i...j])) % p == 0
  //// a = q * b + r
  //// p * q = prefixSum[numsSize] - prefixSum[j+1] + prefixSum[i]
  //// prefixSum[j+1] = prefixSum[numsSize] + prefixSum[i] - p * q
  //// 同余
  //// (prefixSum[numsSize] + prefixSum[i]) % p == prefixSum[j+1] % p
  //for (int i = 1; i <= numsSize; i++) {
    //// 移除子数组 nums[i...j], i > 0
    //// (prefixSum[numsSize] + prefixSum[i]) % p == prefixSum[j+1] % p
    //r = prefixSum[i] % p;
    //if (map[r]) {
      //int tmp = i - map[r];
      //if (tmp < ret) ret = tmp;
    //}
//
    //// edge case
    //// 移除子数组 nums[0...(i-1)]
    //// (prefixSum[numsSize] + 0) % p == prefixSum[j+1] % p
    //if (r == r0 && i != numsSize) {
      //if (i < ret) ret = i;
    //}
//
    //// update
    //r = (prefixSum[numsSize] + prefixSum[i]) % p;
    //map[r] = i;
  //}
//
  //if (ret == INF) return -1;
//
  //return ret;
//}
//// #v1

//// #v2
//// NOTE: 通过
//// prefix sum, math, hash table, array, subarray
//#define INF 0x7fffffff
//
//struct HashNode {
  //int r, i;
  //struct HashNode *next;
//};
//
//struct HashTable {
  //int c;
  //struct HashNode **a;
//};
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
//#define HashFunc(t, k) ((k % t->c + t->c) % t->c)
//
//struct HashNode* HashTableFind(struct HashTable *t, int r) {
  //int h = HashFunc(t, r);
  //struct HashNode *p = t->a[h];
  //while (p) {
    //if (p->r == r) return p;
    //p = p->next;
  //}
  //return NULL;
//}
//
//void HashTableAdd(struct HashTable *t, int remainder, int idx) {
  //int h = HashFunc(t, remainder);
  //struct HashNode *p = t->a[h];
  //struct HashNode *n = calloc(1, sizeof(struct HashNode));
//
  //n->r = remainder;
  //n->i = idx;
  //n->next = p;
//
  //t->a[h] = n;
//}
//
//int minSubarray(int* nums, int numsSize, int p) {
  //long long prefixSum[numsSize+1];
  //int ret = INF, r, r0;
  //struct HashTable *ht = NewHashTable(3727);
  //struct HashNode *q;
//
  //// prefix sum
  //// nums[0] + nums[1] + ... + nums[i] == prefixSum[i+1]
  //prefixSum[0] = 0LL;
  //for (int i = 0; i < numsSize; i++) {
    //prefixSum[i+1] = prefixSum[i] + nums[i];
  //}
//
  //r0 = prefixSum[numsSize] % p;
//
  //// edge case
  //if (r0 == 0) return 0;
//
  //// sum(nums[i...j]) == nums[i] + nums[i+1] + ... + nums[j] == prefixSum[j+1] - prefixSum[i]
  //// (prefixSum[numsSize] - sum(nums[i...j])) % p == 0
  //// a = q * b + r
  //// p * q = prefixSum[numsSize] - prefixSum[j+1] + prefixSum[i]
  //// prefixSum[j+1] = prefixSum[numsSize] + prefixSum[i] - p * q
  //// 同余
  //// (prefixSum[numsSize] + prefixSum[i]) % p == prefixSum[j+1] % p
  //for (int i = 1; i <= numsSize; i++) {
    //// 移除子数组 nums[i...j], i > 0
    //// (prefixSum[numsSize] + prefixSum[i]) % p == prefixSum[j+1] % p
    //r = prefixSum[i] % p;
    //q = HashTableFind(ht, r);
    //if (q) {
      //int tmp = i - q->i;
      //if (tmp < ret) ret = tmp;
    //}
//
    //// edge case
    //// 移除子数组 nums[0...(i-1)]
    //// (prefixSum[numsSize] + 0) % p == prefixSum[j+1] % p
    //if (r == r0 && i != numsSize) {
      //if (i < ret) ret = i;
    //}
//
    //// update
    //r = (prefixSum[numsSize] + prefixSum[i]) % p;
    //q = HashTableFind(ht, r);
    //if (q) q->i = i;
    //else HashTableAdd(ht, r, i);
  //}
//
  //if (ret == INF) return -1;
//
  //return ret;
//}
//// #v2

//// #v3
//// prefix sum, math, hash table, array, subarray
//#define INF 0x7fffffff
//
//struct HashNode {
  //// remainder, max index
  //int r, i;
  //struct HashNode *next;
//};
//
//struct HashTable {
  //int c;
  //struct HashNode **a;
//};
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
//#define HashFunc(t, k) ((k) % (t->c))
//
//struct HashNode* HashTableFind(struct HashTable *t, int r) {
  //int h = HashFunc(t, r);
  //struct HashNode *p = t->a[h];
  //while (p) {
    //if (p->r == r) return p;
    //p = p->next;
  //}
  //return NULL;
//}
//
//void HashTableAdd(struct HashTable *t, int remainder, int idx) {
  //int h = HashFunc(t, remainder);
  //struct HashNode *p = t->a[h];
  //struct HashNode *n = calloc(1, sizeof(struct HashNode));
//
  //n->r = remainder;
  //n->i = idx;
  //n->next = p;
//
  //t->a[h] = n;
//}
//
//int minSubarray(int* nums, int numsSize, int p) {
  //long long prefixSum[numsSize+1];
  //int ret = INF, r, r0;
  //struct HashTable *ht = NewHashTable(2027);
  //struct HashNode *q;
//
  //// prefix sum
  //// nums[0] + nums[1] + ... + nums[i] == prefixSum[i+1]
  //prefixSum[0] = 0LL;
  //for (int i = 0; i < numsSize; i++) {
    //prefixSum[i+1] = prefixSum[i] + nums[i];
  //}
//
  //r0 = prefixSum[numsSize] % p;
//
  //// edge case, 整个数组的和已经可以被 p 整除
  //if (r0 == 0) return 0;
//
  //// sum(nums[i...j]) == nums[i] + nums[i+1] + ... + nums[j] == prefixSum[j+1] - prefixSum[i]
  //// (prefixSum[numsSize] - sum(nums[i...j])) % p == 0
  //// a = q * b + r
  //// p * q = prefixSum[numsSize] - prefixSum[j+1] + prefixSum[i]
  //// prefixSum[j+1] = prefixSum[numsSize] + prefixSum[i] - p * q
  //// 同余
  //// (prefixSum[numsSize] + prefixSum[i]) % p == prefixSum[j+1] % p
  //for (int i = 1; i <= numsSize; i++) {
    //// 移除子数组 nums[i...j], i > 0
    //// (prefixSum[numsSize] + prefixSum[i]) % p == prefixSum[j+1] % p
    //r = prefixSum[i] % p;
    //q = HashTableFind(ht, r);
    //if (q) {
      //int tmp = i - q->i;
      //if (tmp < ret) ret = tmp;
    //}
//
    //// edge case
    //// 移除子数组 nums[0...(i-1)]
    //// (prefixSum[numsSize] + 0) % p == prefixSum[j+1] % p
    //if (r == r0 && i != numsSize) { // i != numsSize 因为不能全部移除
      //if (i < ret) ret = i;
    //}
//
    //// update
    ////r = (prefixSum[numsSize] + prefixSum[i]) % p;
    //r = (r0 + r) % p;
    //q = HashTableFind(ht, r);
    //if (q) q->i = i;
    //else HashTableAdd(ht, r, i);
  //}
//
  //if (ret == INF) return -1;
//
  //return ret;
//}
//// #v3

// #v4
// 空间优化
// prefix sum, math, hash table, array, subarray
#define INF 0x7fffffff

struct HashNode {
  // remainder, max index
  int r, i;
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

#define HashFunc(t, k) ((k) % (t->c))

struct HashNode* HashTableFind(struct HashTable *t, int r) {
  int h = HashFunc(t, r);
  struct HashNode *p = t->a[h];
  while (p) {
    if (p->r == r) return p;
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int remainder, int idx) {
  int h = HashFunc(t, remainder);
  struct HashNode *p = t->a[h];
  struct HashNode *n = calloc(1, sizeof(struct HashNode));

  n->r = remainder;
  n->i = idx;
  n->next = p;

  t->a[h] = n;
}

int minSubarray(int* nums, int numsSize, int p) {
  long long prefixSum, tot;
  int ret = INF, r, r0;
  struct HashTable *ht = NewHashTable(7919);
  struct HashNode *q;

  tot = 0LL;
  for (int i = 0; i < numsSize; i++) tot += nums[i];

  r0 = tot % p;
  // edge case, 整个数组的和已经可以被 p 整除
  if (r0 == 0) return 0;

  // sum(nums[i...j]) == nums[i] + nums[i+1] + ... + nums[j] == prefixSum[j+1] - prefixSum[i]
  // (prefixSum[numsSize] - sum(nums[i...j])) % p == 0
  // a = q * b + r
  // p * q = prefixSum[numsSize] - prefixSum[j+1] + prefixSum[i]
  // prefixSum[j+1] = prefixSum[numsSize] + prefixSum[i] - p * q
  // 同余
  // (prefixSum[numsSize] + prefixSum[i]) % p == prefixSum[j+1] % p
  prefixSum = 0LL;
  for (int i = 1; i <= numsSize; i++) {
    prefixSum = prefixSum + nums[i-1];

    // 移除子数组 nums[i...j], i > 0
    // (prefixSum[numsSize] + prefixSum[i]) % p == prefixSum[j+1] % p
    r = prefixSum % p;
    q = HashTableFind(ht, r);
    if (q) {
      int tmp = i - q->i;
      if (tmp < ret) ret = tmp;
    }

    // edge case
    // 移除子数组 nums[0...(i-1)]
    // (prefixSum[numsSize] + 0) % p == prefixSum[j+1] % p
    if (r == r0 && i != numsSize) { // i != numsSize 因为不能全部移除
      if (i < ret) ret = i;
    }

    // update
    //r = (prefixSum[numsSize] + prefixSum[i]) % p;
    r = (r0 + r) % p;
    q = HashTableFind(ht, r);
    if (q) q->i = i;
    else HashTableAdd(ht, r, i);
  }

  if (ret == INF) return -1;

  return ret;
}
// #v4

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
  printf("%d\n", minSubarray(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
