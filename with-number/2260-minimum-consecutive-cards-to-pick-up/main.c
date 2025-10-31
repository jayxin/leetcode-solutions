#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2260. 必须拿起的最小连续卡牌数 - 给你一个整数数组 cards ，其中 cards[i] 表示第 i 张卡牌的 值 。如果两张卡牌的值相同，则认为这一对卡牌 匹配 。
// 返回你必须拿起的最小连续卡牌数，以使在拿起的卡牌中有一对匹配的卡牌。如果无法得到 一对匹配的卡牌，返回 -1 。
//  
// 示例 1：
// 输入：cards = [3,4,2,3,4,7]
// 输出：4
// 解释：拿起卡牌 [3,4,2,3] 将会包含一对值为 3 的匹配卡牌。注意，拿起 [4,2,3,4] 也是最优方案。
// 示例 2：
// 输入：cards = [1,0,5,3]
// 输出：-1
// 解释：无法找出含一对匹配卡牌的一组连续卡牌。
//  
// 提示：
//  * 1 <= cards.length <= 105
//  * 0 <= cards[i] <= 106

//// #v1
//struct HashNode {
  //int val, lastPos;
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
//struct HashNode* HashTableFind(struct HashTable *t, int val) {
  //int h = val % t->c;
  //struct HashNode *p = t->a[h];
  //while (p) {
    //if (p->val == val) return p;
    //p = p->next;
  //}
  //return NULL;
//}
//
//void HashTableAdd(struct HashTable *t, int val, int lastPos) {
  //int h = val % t->c;
  //struct HashNode *p = t->a[h];
//
  //struct HashNode *n = calloc(1, sizeof(struct HashNode));
//
  //n->val = val;
  //n->lastPos = lastPos;
//
  //// add to hash table
  //t->a[h] = n;
  //n->next = p;
//}
//
//#define LIMIT 0x7fffffff
//
//int minimumCardPickup(int* cards, int cardsSize) {
  //struct HashTable *ht = NewHashTable(7001);
  //struct HashNode *p;
//
  //int ret = LIMIT;
//
  //HashTableAdd(ht, cards[0], 0);
//
  //for (int i = 1; i < cardsSize; i++) {
    //p = HashTableFind(ht, cards[i]);
//
    //if (p) {
      //int tmp = i - p->lastPos + 1;
      //if (tmp < ret) ret = tmp;
      //p->lastPos = i;
    //} else {
      //HashTableAdd(ht, cards[i], i);
    //}
//
    //if (ret == 2) return 2;
  //}
//
  //if (ret == LIMIT) return -1;
//
  //return ret;
//}
//// #v1

// #v2
#define LIMIT 0x7fffffff

int minimumCardPickup(int* cards, int cardsSize) {
  int ht[1000001] = {0};

  int ret = LIMIT;

  ht[cards[0]] = 1;

  for (int i = 1; i < cardsSize; i++) {
    if (ht[cards[i]]) {
      int tmp = i - ht[cards[i]] + 2;
      if (tmp < ret) ret = tmp;
    }

    ht[cards[i]] = i + 1;
  }

  if (ret == LIMIT) return -1;

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
  printf("%d\n", minimumCardPickup(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
