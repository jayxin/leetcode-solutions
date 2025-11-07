#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2364. 统计坏数对的数目 - 给你一个下标从 0 开始的整数数组 nums 。如果 i < j 且 j - i != nums[j] - nums[i] ，那么我们称 (i, j) 是一个 坏数对 。
// 请你返回 nums 中 坏数对 的总数目。
//  
// 示例 1：
// 输入：nums = [4,1,3,3]
// 输出：5
// 解释：数对 (0, 1) 是坏数对，因为 1 - 0 != 1 - 4 。
// 数对 (0, 2) 是坏数对，因为 2 - 0 != 3 - 4, 2 != -1 。
// 数对 (0, 3) 是坏数对，因为 3 - 0 != 3 - 4, 3 != -1 。
// 数对 (1, 2) 是坏数对，因为 2 - 1 != 3 - 1, 1 != 2 。
// 数对 (2, 3) 是坏数对，因为 3 - 2 != 3 - 3, 1 != 0 。
// 总共有 5 个坏数对，所以我们返回 5 。
// 示例 2：
// 输入：nums = [1,2,3,4,5]
// 输出：0
// 解释：没有坏数对。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 1 <= nums[i] <= 109

//// #v1
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
//#define HashFunc(t, k) ((((k) % (t)->c) + (t)->c) % (t)->c)
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
  //struct HashNode *n, *p = t->a[h];
//
  //n = NewHashNode(val);
  //t->a[h] = n;
  //n->next = p;
//}
//
//long long countBadPairs(int* nums, int numsSize) {
  //long long ret = 0LL;
  //struct HashTable *ht = NewHashTable(7001);
//
  //for (int i = 0; i < numsSize; i++) {
    //int v = nums[i] - i;
    //struct HashNode *p = HashTableFind(ht, v);
//
    //ret += i;
//
    //if (p) ret -= (p->cnt)++;
    //else HashTableAdd(ht, v);
  //}
//
  //return ret;
//}
//// #v1

//// #v2
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
//#define HashFunc(t, k) ((((k) % (t)->c) + (t)->c) % (t)->c)
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
  //struct HashNode *p = t->a[h];
  //struct HashNode *n = calloc(1, sizeof(struct HashNode));
//
  //n->val = val;
  //n->cnt = 1;
  //n->next = p;
//
  //t->a[h] = n;
//}
//
//long long countBadPairs(int* nums, int numsSize) {
  //long long ret = 0LL;
  //struct HashTable *ht = NewHashTable(7001);
//
  //for (int i = 0; i < numsSize; i++) {
    //int v = nums[i] - i;
    //struct HashNode *p = HashTableFind(ht, v);
//
    //ret += i;
//
    //if (p) ret -= (p->cnt)++;
    //else HashTableAdd(ht, v);
  //}
//
  //return ret;
//}
//// #v2

// #v3
struct HashNode {
  int val, cnt;
  struct HashNode *next;
};

long long countBadPairs(int* nums, int numsSize) {
  long long ret = 0LL;
  int c;
  struct HashNode **ht;

  c = 5527;
  ht = calloc(c, sizeof(struct HashNode *));
  memset(ht, 0, sizeof(struct HashNode *) * c);

  for (int i = 0; i < numsSize; i++) {
    int v = nums[i] - i, h = (v % c + c) % c;
    struct HashNode *p = ht[h];

    // find
    while (p && p->val != v) p = p->next;

    ret += i;
    if (p) ret -= (p->cnt)++;
    else { // new node
      p = ht[h];
      struct HashNode *n = calloc(1, sizeof(struct HashNode));

      n->val = v;
      n->cnt = 1;
      n->next = p;

      ht[h] = n;
    }
  }

  return ret;
}
// #v3

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
  printf("%lld\n", countBadPairs(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
