#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1015. 可被 K 整除的最小整数 - 给定正整数 k ，你需要找出可以被 k 整除的、仅包含数 字 1 的最 小 正整数 n 的长度。
// 返回 n 的长度。如果不存在这样的 n ，就返回-1。
// 注意： n 可能不符合 64 位带符号整数。
//  
// 示例 1：
// 输入：k = 1
// 输出：1
// 解释：最小的答案是 n = 1，其长度为 1。
// 示例 2：
// 输入：k = 2
// 输出：-1
// 解释：不存在可被 2 整除的正整数 n 。
// 示例 3：
// 输入：k = 3
// 输出：3
// 解释：最小的答案是 n = 111，其长度为 3。
//  
// 提示：
//  * 1 <= k <= 105

//// #v1
//// hash table, math
//struct HashNode {
  //int val;
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
//
  //struct HashNode *n = calloc(1, sizeof(struct HashNode));
//
  //n->val = val;
  //n->next = p;
//
  //t->a[h] = n;
//}
//
//int smallestRepunitDivByK(int k) {
  //int c = 0, r = 0;
  //struct HashTable *ht = NewHashTable(3727);
//
  //while (1) {
    //++c;
    //r = (10LL * r + 1) % k;
//
    //if (!r) break;
//
    //if (HashTableFind(ht, r)) return -1;
    //HashTableAdd(ht, r);
  //}
//
  //return c;
//}
//// #v1

// #v2
// hash table, math
int smallestRepunitDivByK(int k) {
  char ht[k];
  int c = 0, r = 0;

  memset(ht, 0, sizeof(ht));

  while (1) {
    ++c;
    r = (10 * r + 1) % k;

    if (!r) break;

    if (ht[r]) return -1;
    ht[r] = 1;
  }

  return c;
}
// #v2

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", smallestRepunitDivByK(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
