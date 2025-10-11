#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3186. 施咒的最大总伤害 - 一个魔法师有许多不同的咒语。
// 给你一个数组 power ，其中每个元素表示一个咒语的伤害值，可能会有多个咒语有相同的伤害值。
// 已知魔法师使用伤害值为 power[i] 的咒语时，他们就 不能 使用伤害为 power[i] - 2 ，power[i] - 1 ，power[i] + 1 或者 power[i] + 2 的咒语。
// 每个咒语最多只能被使用 一次 。
// 请你返回这个魔法师可以达到的伤害值之和的 最大值 。
//  
// 示例 1：
// 输入：power = [1,1,3,4]
// 输出：6
// 解释：
// 可以使用咒语 0，1，3，伤害值分别为 1，1，4，总伤害值为 6 。
// 示例 2：
// 输入：power = [7,1,6,6]
// 输出：13
// 解释：
// 可以使用咒语 1，2，3，伤害值分别为 1，6，6，总伤害值为 13 。
//  
// 提示：
//  * 1 &lt;= power.length &lt;= 105
//  * 1 &lt;= power[i] &lt;= 109

// #v1
// hash table, dynamic programming, sort, double pointer
struct HashNode {
  int val, cnt;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  int size;
  struct HashNode **table;
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
  ret->table = (struct HashNode **)malloc(table_bytes);
  memset(ret->table, 0, table_bytes);

  return ret;
}

#define HashFunc(t, key) (key % t->capacity)

struct HashNode* HashTableFind(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *p = (t->table)[h];
  while (p) {
    if (p->val == val) return p;
    p = p->next;
  }
  return NULL;
}

int HashTableAdd(struct HashTable *t, int val) {
  struct HashNode *q = HashTableFind(t, val);

  if (!q) {
    int h = HashFunc(t, val);
    struct HashNode *n, *p = (t->table)[h];
    n = NewHashNode(val);
    if (!p) {
      (t->table)[h] = n;
    } else {
      n->next = p;
      (t->table)[h] = n;
    }
    return 0;
  } else {
    q->cnt += 1;
    return 1;
  }
}

int cmp(const void *a, const void *b)  {
  return *(int *)a - *(int *)b;
}

#define max(a, b) ((a) >= (b) ? (a) : (b))

long long maximumTotalDamage(int* power, int powerSize) {
  struct HashTable *h = NewHashTable(13331);
  struct HashNode *p;
  int arr[powerSize], arrLen = 0, i, j;
  long long *dp, ret, m;

  // count
  for (i = 0; i < powerSize; i++) {
    if (HashTableAdd(h, power[i]) == 0) arr[arrLen++] = power[i];
  }
  // sort
  qsort(arr, arrLen, sizeof(int), cmp);

  dp = (long long *)malloc(sizeof(long long) * arrLen);

  // dynamic programming
  // init
  p = HashTableFind(h, arr[0]);
  dp[0] = 1LL * p->cnt * arr[0];
  ret = dp[0];
  m = 0LL;

  // compute
  for (i = 1, j = 0; i < arrLen; i++) {
    p = HashTableFind(h, arr[i]);

    // double pointer
    while (j < i && arr[j] < arr[i] - 2) {
      m = max(m, dp[j]);
      ++j;
    }

    // update dp[i]
    dp[i] = m + 1LL * p->cnt * arr[i];
    // update max value
    if (dp[i] > ret) ret = dp[i];
  }

  free(dp);

  return ret;
}
// #v1

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
  long long ret;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = maximumTotalDamage(a, n);
  printf("%lld\n", ret);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
