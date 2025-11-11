#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3185. 构成整天的下标对数目 II - 给你一个整数数组 hours，表示以 小时 为单位的时 间，返回一个整数，表示满足 i < j 且 hours[i] + hours[j] 构成 整天 的下标对 i, j 的数目。
// 整天 定义为时间持续时间是 24 小时的 整数倍 。
// 例如，1 天是 24 小时，2 天是 48 小时，3 天是 72 小时，以此类推。
//  
// 示例 1：
// 输入： hours = [12,12,30,24,24]
// 输出： 2
// 解释：
// 构成整天的下标对分别是 (0, 1) 和 (3, 4)。
// 示例 2：
// 输入： hours = [72,48,24,3]
// 输出： 3
// 解释：
// 构成整天的下标对分别是 (0, 1)、(0, 2) 和 (1, 2)。
//  
// 提示：
//  * 1 <= hours.length <= 5 * 105
//  * 1 <= hours[i] <= 109

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
//#define HashFunc(t, k) ((k) % t->c)
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
  //struct HashNode *q = HashTableFind(t, val);
//
  //if (q) {
    //q->cnt += 1;
    //return ;
  //}
//
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
//long long countCompleteDayPairs(int* hours, int hoursSize) {
  //long long ret = 0LL;
  //struct HashTable *ht = NewHashTable(3727);
  //struct HashNode *q;
//
  //for (int i = 0; i < hoursSize; i++) {
    //int r = hours[i] % 24;
    //q = HashTableFind(ht, (24-r)%24);
    //if (q) ret += q->cnt;
    //HashTableAdd(ht, r);
  //}
//
  //return ret;
//}
//// #v1

// #v2
long long countCompleteDayPairs(int* hours, int hoursSize) {
  long long ret = 0LL;
  int ht[24] = {0};

  for (int i = 0; i < hoursSize; i++) {
    int r = hours[i] % 24;
    ret += ht[(24-r)%24];
    ++ht[r];
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

int main(int argc, char *argv[])
{
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%lld\n", countCompleteDayPairs(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
